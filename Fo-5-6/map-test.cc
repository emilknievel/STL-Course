/*
 * map-test.cc    TDIU04 Fö 5-6
 */
#include <iostream>
#include <iterator>
#include <map>
#include <utility>
using namespace std;

ostream& operator<<(ostream& os, const map<int, char>& m)
{
   for (auto x : m)
   {
      os << x.first << ": " << x.second << '\n';
   }
   return os;
}

int main()
{
   map<int, char> m1;

   cout << "Sätter in <3,'C'> <4,'D'>, <2,'B'> och <1,'A'> i  m1.\n";

   m1.insert(make_pair(3, 'C'));
   m1[4] = 'D';
   m1[2] = 'B';
   m1.insert(make_pair(1, 'A'));

   if (m1.empty())
      cout << "m1 är tom\n";
   else
      cout << "m1 är inte tom\n";

   cout << "m1.size()....: "  << m1.size() << '\n';
   cout << "m1.max_size(): "  << m1.max_size() << '\n';
   cout << "m1.count(1)..: "  << m1.count(1) << '\n';
   cout << "m1 innehåller:\n" << m1 << "\n\n";
   
   cout << "Söker på nycket 3:" << m1.find(3)->second << '\n';
   cout << "Söker på nycket 0:" << m1.find(0)->second << '\n';

   map<int, char> m2{m1};
   
   cout << "m2 innehåller:\n" << m2 << '\n';

   if (m2 == m1)
      cout << "m2 är lika med m1.\n";
   else
      cout << "m2 är inte lika med m1.\n";

   map<int, char> m3;
   
   m3 = m1;

   cout << "m3 innehåller:\n" << m3 << '\n';

   if (m3 < m1)
      cout << "m3 är mindre än m1.\n";
   else
      cout << "m3 är inte mindre än m1.\n";

   map<int, char> m4{m1.begin(), m1.end()};
   
   cout << "m4 innehåller:\n" << m4 << '\n';

   cout << "Sätter in (9, '$') i m4.\n";

   auto it = m4.insert(end(m4), make_pair(9, '$'));  // map<int, char>::iterator

   cout << "Kollar insättningen via returnerad iterator: (" 
	<< it->first << ", " << it->second << ')' << "\n\n";

   cout << "m4 innehåller:\n" << m4 << '\n';

   cout << "Sätter in (0, '^') i m4.\n";

   auto p = m4.insert(make_pair(0, '^'));  // pair<map<int, char>::iterator, bool>

   if (p.second == true)
   {
      cout << "Insättningen lyckad, m4[0]: '" << p.first->second << "'\n";
   }

   cout << "\nFörsöker sätta in (0, '?') i m4.\n";
   p = m4.insert(make_pair(0, '?'));

   if (p.second == false)
   {
      cout << "Insättningen misslyckad, m4[0]: " << p.first->second << '\n';
   }

   cout << "\nm4 innehåller:\n" << m4 << '\n';

   map<int, char> m5;

   cout << "Kopierar m4 till m5.\n"; 
   m5.insert(begin(m4), end(m4));

   cout << "m5 innehåller:\n" << m5 << '\n';
   cout << "Tar bort paret med nyckel 1 ur m5: " << m5.erase(1) << '\n';
   cout << "Försöker ta bort par med nyckel 99 ur m5: " << m5.erase(99) << '\n';
   cout << "m5 innehåller:\n" << m5 << '\n';

   cout << "Tar bort paret med nyckel 3 ur m5 (använder find() och erase()).\n";
   m5.erase(m5.find(3));
   cout << "m5 innehåller:\n" << m5 << '\n';
   
   cout << "Tömmer m5 med m5.clear()\n"; 
   m5.clear();

   if (m5.empty()) cout << "m5 är tom.\n"; 

   return 0;
}
