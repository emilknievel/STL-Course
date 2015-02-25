/*
 * exempel-13.cc    TDIU04 F� 5-6
 */
#include <iterator>
#include <iostream>
#include <set>
using namespace std;

ostream& operator<<(ostream& os, const set<int>& s)
{
   copy(begin(s), end(s), ostream_iterator<int>(os, " "));
   return os;
}

int main()
{
   set<int> s;
   int x;

   cout << "S�tter in 5, 1, 8, 4, 1 i ett tomt set s.\n";
   s.insert(5);
   s.insert(1);
   s.insert(8);
   s.insert(4);
   s.insert(1);

   cout << "\nAntalet v�rden i s �r " << s.size() << '\n';
   cout << "s inneh�ller:\n";
   cout << s << '\n';

   do
   {
      cout << "\nS�k p� v�rdet (0 avbryter): ";
      cin >> x;

      if (x != 0)
      {
	 if (s.find(x) != s.end())
	    cout << x << " hittades!\n";
	 else
	    cout << x << " hittades inte!\n";
      }
   }
   while (x != 0);

   return 0;
}

/*
 * Visar anv�ndning av standardcontainern set (associativ cointainer). 
 */
