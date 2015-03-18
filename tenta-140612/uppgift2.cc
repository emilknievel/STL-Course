#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
#include <iomanip>
#include <utility>

using namespace std;

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        cerr << "Användning: " << argv[0] << " filen\n";
        return 1;
    }

    ifstream is{argv[1]};
    if (!is)
    {
        cerr << "Filen kunde inte läsas\n";
        return 2;
    }

    string country;
    int score;
    map<string, int> scoremap;
    while (is >> country >> score)
    {
        scoremap[country] += score;
    }

    multimap<int, string, greater<int>> resultmap;
    for (auto& p : scoremap)
    {
        resultmap.emplace(p.second, p.first);
    }

    cout << "European Song Contenst 2014\n"
         << "---------------------------\n";
    for (auto& p : resultmap)
    {
        cout << p.second << setw(5) << right << p.first << endl;
    }

    return 0;
}
