#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Word_Entry {
    string word;
    unsigned int word_count;
};

using Word_List = vector<Word_Entry>;

string lower_case(string str);
void insert(string ord, Word_List& ordlista);
void print(Word_List ordlista);

int main()
{
    Word_List wl;
    string x;

    while(cin >> x)
    {
        insert(lower_case(x), wl);
        x = "";
    }
    print(wl);

    return 0;
}

string lower_case(string str)
{
    for (unsigned int i = 0; i < str.size(); ++i)
    {
        str.at(i) = tolower(str.at(i));
    }
    return str;
}

void print(Word_List ordlista)
{
    for (unsigned int i = 0; i < ordlista.size(); ++i)
    {
        cout << setw(20) << right << ordlista.at(i).word << "  " << left
             << ordlista.at(i).word_count << endl;
    }
}

void insert(string ord, Word_List& ordlista)
{
    if (ordlista.size() > 0)
    {
        for (unsigned int i = 0; i < ordlista.size(); ++i)
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
