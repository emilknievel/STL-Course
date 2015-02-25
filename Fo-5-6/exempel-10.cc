/*
 * exempel-10.cc    TDIU04 F� 5-6
 */
#include <iostream>
#include <map>
#include <string>
#include <utility>
using namespace std;

int main()
{
   map<int, string> m;

   int    key;
   string value;

   while (cin >> key)
   {
      cin >> value;
      m[key] = value;
   }

   cout << m.size() << "nyckel/v�rde-par inl�sta:\n";

   for (map<int, string>::const_iterator it = begin(m); it != m.cend(); ++it)
   {
      cout << it->first << ": " << it->second << '\n';
   }
}

/*
 * Visar anv�ndning av standardcontainern map (associativ container).
 */
