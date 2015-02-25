/*
 * exempel-11.cc    TDIU04 Fö 5-6
 */
#include <iostream>
#include <map>
#include <string>
#include <utility>
using namespace std;

using Map = map<int, string>;

int main()
{
   Map    m;
   int    key;
   string value;

   while (cin >> key)
   {
      cin >> value;
      m[key] = value;
   }

   cout << m.size() << "nyckel/värde-par inlästa:\n";

   for (const auto& p : m)  // pair<int, string>
   {
      cout << p.first << ": " << p.second << '\n';
   }
}

/*
 * Visar användning av standardcontainern map (associativ container).
 *
 * '(const auto& p' gör att elementen i m inte kopieras, const ser till
 * att det inte går att modifiera objektet som refereras av p.
 */
