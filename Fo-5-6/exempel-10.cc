/*
 * exempel-10.cc    TDIU04 Fö 5-6
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

   cout << m.size() << "nyckel/värde-par inlästa:\n";

   for (map<int, string>::const_iterator it = begin(m); it != m.cend(); ++it)
   {
      cout << it->first << ": " << it->second << '\n';
   }
}

/*
 * Visar användning av standardcontainern map (associativ container).
 */
