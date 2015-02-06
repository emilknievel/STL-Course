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

typedef vector<Word_Entry> Word_List;

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
    for (unsigned int i{0}; i < str.size(); ++i)
    {
        str.at(i) = tolower(str.at(i));
    }
    return str;
}

void print(Word_List ordlista)
{
    for (unsigned int i{0}; i < ordlista.size(); ++i)
    {
        cout << setw(20) << right << ordlista.at(i).word << "  " << left
             << ordlista.at(i).word_count << endl;
    }
}

void insert(string ord, Word_List& ordlista)
{
    if (!ordlista.empty())
    {
        for (unsigned int i{0}; i < ordlista.size(); ++i)
        {
            if (ordlista.at(i).word == ord)
            {
                ordlista.at(i).word_count += 1;
                return;
            }
        }
    }

    Word_Entry w_entry{ord, 1};

    ordlista.push_back(w_entry);
    return;

}
