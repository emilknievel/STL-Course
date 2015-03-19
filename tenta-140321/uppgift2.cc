#include <iostream>
#include <map>
#include <fstream>
#include <iomanip>
#include <functional>

using namespace std;

int main(int argc, char* argv[])
{
    // 1
    if (argc != 2)
    {
        cerr << "Användning: " << argv[0] << " filnamn\n";
        return 1;
    }

    ifstream is{argv[1]};

    if (!is)
    {
        cerr << "Det gick inte att hitta filen\n";
        return 2;
    }

    // 2
    map<string, int> alfabet;
    string namn;
    while (is >> namn)
    {
        ++alfabet[namn];
    }

    cout << "Hundnamn i bokstavsordning:\n";
    for (const auto& x : alfabet)
    {
        cout << setw(8) << left << x.first << x.second << endl;
    }

    // 3
    multimap<int, string, greater<int>> popularitet;
    for (const auto& x : alfabet)
    {
        popularitet.emplace(x.second, x.first);
    }
    cout << "\nHundnamn i popularitetsordning:\n";
    for (const auto& x : popularitet)
    {
        cout << setw(8) << left << x.second << x.first << endl;
    }

    return 0;
}
