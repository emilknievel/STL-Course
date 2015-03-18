#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <functional>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        cerr << "AnvÃ¤ndning: " << argv[0] << " fil\n";
        return 1;
    }
    fstream is{argv[1]};
    if (!is)
    {
        cerr << "Det gick inte att Öppna filen '" << argv[1] << "'\n";
        return 2;
    }

    multimap<double, string, greater<double>> mmkast{};
    string namn;
    double resultat;
    while (getline(is, namn, ';')) // stannar vid ';'
    {
        is >> resultat >> ws; // kör till eof
        // move(namn) ser till att namn är tom till nästa iteration
        mmkast.emplace(resultat, move(namn));
    }

    cout << "Spjut Kvinnor, samtliga kast:\n"
         << "-----------------------------" << endl;
    cout << fixed << setprecision(2);
    for (const auto& x : mmkast)
    {
        if (x.first == 0.0)
            cout << "X      ";
        else
            cout << x.first << "  ";
        cout << x.second << endl;
    }


    cout << "\nSpjut Kvinnor, slutresultat:\n"
         << "----------------------------" << endl;
    set<string> end_list;
    unsigned place_counter{0};
    for (const auto& p : mmkast)
    {
        if (end_list.find(p.second) == end_list.cend())
        {
            cout << ++place_counter << ". " << setw(22) << left << p.second;
            if (p.first == 0)
                cout << "X    " << endl;
            else
                cout << p.first << endl;
            end_list.insert(p.second);
        }
    }

    return 0;
}
