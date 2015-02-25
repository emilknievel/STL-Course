/*
 * exempel-11.cc    TDIU04 F� 5-6
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

   cout << m.size() << "nyckel/v�rde-par inl�sta:\n";

   for (const auto& p : m)  // pair<int, string>
   {
      cout << p.first << ": " << p.second << '\n';
   }
}

/*
 * Visar anv�ndning av standardcontainern map (associativ container).
 *
 * '(const auto& p' g�r att elementen i m inte kopieras, const ser till
 * att det inte g�r att modifiera objektet som refereras av p.
 */
