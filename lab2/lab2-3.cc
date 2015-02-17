#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

class Word_Entry
{
public:
    Word_Entry(string the_word)
	: word{the_word}, word_count{1}
	{}

    string get_word() { return word; }
    unsigned int get_count() { return word_count; }
    void increment_count() { word_count++; }

private:
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
    for (char& c : str)
    {
        c = tolower(c);
    }
    return str;
}

void print(const Word_List& ordlista)
{
    for (Word_Entry entry : ordlista)
    {
        cout << setw(20) << right << entry.get_word() << "  " << left
             << entry.get_count() << endl;
    }
}

void insert(const string& ord, Word_List& ordlista)
{
    if (ordlista.empty())
    {
	     Word_Entry entry(ord);
	     ordlista.push_back(entry);
	     return;
    }

    for (auto it = begin(ordlista); it != end(ordlista); ++it)
    {
        if (it->get_word() == ord)
        {
            it->increment_count();
            return;
        }

        else if (it->get_word() > ord) // Hittat rätt plats!
        {
	         Word_Entry entry(ord);
	         ordlista.insert(it, entry);
            return;
        }
    }

    Word_Entry entry(ord);
    ordlista.push_back(entry);
    return;
}
