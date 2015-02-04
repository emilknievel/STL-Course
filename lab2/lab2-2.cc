#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

struct Word_Entry {
    string word;
    unsigned int word_count;
};

using Word_List = vector<Word_Entry>;

string lower_case(string str);
void insert(string ord, Word_List& ordlista);
void print(Word_List ordlista);

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        cerr << "Ingen fil angiven. Skriv "
             << argv[0] << " filnamnet" << endl;

        return 1;
    }

    ifstream file{ argv[1] };

    if (!file)
    {
        cerr << "Gick inte att läsa filen. Kolla att filen finns" << endl;

        return 2;
    }

    Word_List wl;
    string inword;

    while(file >> inword)
    {
        insert(lower_case(inword), wl);
        inword = "";
    }
    file.close();

    print(wl);

    return 0;
}

string lower_case(string str)
{
    for (auto it = begin(str); it != end(str); ++it)
    {
        *it = tolower(*it);
    }
    return str;
}

void print(Word_List ordlista)
{
    for (auto it = begin(ordlista); it != end(ordlista); ++it)
    {
        cout << setw(20) << right << it->word << "  " << left
             << it->word_count << endl;
    }
}

void insert(string ord, Word_List& ordlista)
{
    if (ordlista.empty())
    {
        ordlista.push_back( {ord, 1} );
        return;
    }

    for (auto it = begin(ordlista); it != end(ordlista); ++it)
    {
        if (it->word == ord)
        {
            it->word_count++;
            return;
        }

        else if (it->word > ord) // Rätt plats funnen
        {
            Word_List temp(make_move_iterator(it),
			   make_move_iterator(end(ordlista)));

            ordlista.erase(it, end(ordlista));
            ordlista.push_back( {ord, 1} );

            copy(begin(temp), end(temp), back_inserter(ordlista));
            return;
        }
    }

    ordlista.push_back( {ord, 1} );
    return;
}
