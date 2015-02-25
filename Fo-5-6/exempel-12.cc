/*
 * exempel-12.cc    TDIU04 Fö 5-6
 */
#include <iostream>
#include <map>
#include <string>
#include <utility>
using namespace std;

using Map = multimap<int, string>;

int main()
{
   Map    m;
   int    key;
   string value;

   cout << "Ange nyckel/värde-par (0 avslutar):\n";

   while (cin >> key && key != 0)
   {
      cin >> value >> ws;
      m.emplace(key, value);  // m.insert(make_pair(key, value));
   }
   
   do
   {
      cout << "\nAnge en söknyckel (0 avslutar): ";
      cin >> key;

      if (key != 0)
      {
	 cout << "Det finns " << m.count(key) << " sådana poster:\n";

	 auto p = m.equal_range(key);  // pair<Map::iterator, Map::iterator>

	 for (Map::const_iterator it = p.first; it != p.second; ++it)
	 {
	    cout << it->first << ": " << it->second << '\n';
	 }
      }
   }
   while (key != 0);

   return 0;
}

/*
 * Visar användning av standardcontainern multimap (associativ container)
 * och emplace() i stället för insert().
 */
