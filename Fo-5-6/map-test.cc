/*
 * map-test.cc    TDIU04 F� 5-6
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

   cout << "S�tter in <3,'C'> <4,'D'>, <2,'B'> och <1,'A'> i  m1.\n";

   m1.insert(make_pair(3, 'C'));
   m1[4] = 'D';
   m1[2] = 'B';
   m1.insert(make_pair(1, 'A'));

   if (m1.empty())
      cout << "m1 �r tom\n";
   else
      cout << "m1 �r inte tom\n";

   cout << "m1.size()....: "  << m1.size() << '\n';
   cout << "m1.max_size(): "  << m1.max_size() << '\n';
   cout << "m1.count(1)..: "  << m1.count(1) << '\n';
   cout << "m1 inneh�ller:\n" << m1 << "\n\n";
   
   cout << "S�ker p� nycket 3:" << m1.find(3)->second << '\n';
   cout << "S�ker p� nycket 0:" << m1.find(0)->second << '\n';

   map<int, char> m2{m1};
   
   cout << "m2 inneh�ller:\n" << m2 << '\n';

   if (m2 == m1)
      cout << "m2 �r lika med m1.\n";
   else
      cout << "m2 �r inte lika med m1.\n";

   map<int, char> m3;
   
   m3 = m1;

   cout << "m3 inneh�ller:\n" << m3 << '\n';

   if (m3 < m1)
      cout << "m3 �r mindre �n m1.\n";
   else
      cout << "m3 �r inte mindre �n m1.\n";

   map<int, char> m4{m1.begin(), m1.end()};
   
   cout << "m4 inneh�ller:\n" << m4 << '\n';

   cout << "S�tter in (9, '$') i m4.\n";

   auto it = m4.insert(end(m4), make_pair(9, '$'));  // map<int, char>::iterator

   cout << "Kollar ins�ttningen via returnerad iterator: (" 
	<< it->first << ", " << it->second << ')' << "\n\n";

   cout << "m4 inneh�ller:\n" << m4 << '\n';

   cout << "S�tter in (0, '^') i m4.\n";

   auto p = m4.insert(make_pair(0, '^'));  // pair<map<int, char>::iterator, bool>

   if (p.second == true)
   {
      cout << "Ins�ttningen lyckad, m4[0]: '" << p.first->second << "'\n";
   }

   cout << "\nF�rs�ker s�tta in (0, '?') i m4.\n";
   p = m4.insert(make_pair(0, '?'));

   if (p.second == false)
   {
      cout << "Ins�ttningen misslyckad, m4[0]: " << p.first->second << '\n';
   }

   cout << "\nm4 inneh�ller:\n" << m4 << '\n';

   map<int, char> m5;

   cout << "Kopierar m4 till m5.\n"; 
   m5.insert(begin(m4), end(m4));

   cout << "m5 inneh�ller:\n" << m5 << '\n';
   cout << "Tar bort paret med nyckel 1 ur m5: " << m5.erase(1) << '\n';
   cout << "F�rs�ker ta bort par med nyckel 99 ur m5: " << m5.erase(99) << '\n';
   cout << "m5 inneh�ller:\n" << m5 << '\n';

   cout << "Tar bort paret med nyckel 3 ur m5 (anv�nder find() och erase()).\n";
   m5.erase(m5.find(3));
   cout << "m5 inneh�ller:\n" << m5 << '\n';
   
   cout << "T�mmer m5 med m5.clear()\n"; 
   m5.clear();

   if (m5.empty()) cout << "m5 �r tom.\n"; 

   return 0;
}
