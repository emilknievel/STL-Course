#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <iterator>
#include <utility>

using namespace std;

struct Word_Entry {
    string word;
    unsigned int word_count;
};

using Word_List = vector<Word_Entry>;

string lower_case(string str);
void insert(const string& ord, Word_List& ordlista);
void print(const Word_List& ordlista);

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

void print(const Word_List& ordlista)
{
    for (auto it = ordlista.cbegin(); it != ordlista.cend(); ++it)
    {
        cout << setw(20) << right << it->word << "  " << left
             << it->word_count << endl;
    }
}

void insert(const string& ord, Word_List& ordlista)
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
            Word_Entry entry{ ord ,1 };

            // Markera plats för nytt element
            int index = distance(begin(ordlista), it);

            ordlista.resize(ordlista.size() + 1);

            for (unsigned i = ordlista.size() - 1;
                 i > static_cast<unsigned>(index); --i)
            {
                // Flytta elementen ett steg åt höger
                swap(ordlista.at(i), ordlista.at(i - 1));
            }
            // Nytt element på rätt plats
            ordlista.at(index) = entry;
            return;
        }
    }

    ordlista.push_back( {ord, 1} );
    return;
}
