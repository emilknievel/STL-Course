/*
 * set-test.cc    TDIU04 F� 4-5
 */
#include <iostream>
#include <set>
#include <utility>
#include <iterator>
using namespace std;

/* H�r kr�ver ostream_iterator<int> att operator<< finns f�r elementtypen
 * i s, dvs int, och den operator<< finns i standardbiblioteket.
 */
ostream& operator<<(ostream& os, const set<int>& s)
{
   copy(begin(s), end(s), ostream_iterator<int>(os, " "));
   return os;
}

int main()
{
   set<int> s1;

   cout << "S�tter in 5, 1, 8, 4, 1 i ett tomt set s1.\n";
   s1.insert(5);
   s1.insert(1);
   s1.insert(8);
   s1.insert(4);
   s1.insert(1);
   cout << '\n';

   if (s1.empty())
      cout << "s1 �r tom\n";
   else
      cout << "s1 �r inte tom\n";

   cout << "s1.size()....: " << s1.size()     << '\n';
   cout << "s1.max_size(): " << s1.max_size() << '\n';
   cout << "s1.count(1)..: " << s1.count(1)   << '\n';

   cout << "s1 inneh�ller: " << s1 << '\n';
   
   cout << "\nS�ker p� nyckel 3: ";
   if (s1.find(1) != s1.end())
      cout << "Hittades!\n";

   cout << "S�ker p� nyckel 0: ";
   if (s1.find(0) == end(s1))
      cout << "Hittades inte!\n";

   cout << "\ns2 skapas som en kopia av s1, ";

   set<int> s2{s1};
   
   cout << "s2 inneh�ller: " << s2 << '\n';

   if (s2 == s1)
      cout << "s2 �r lika med s1.\n";
   else
      cout << "s2 �r inte lika med s1.\n";

   set<int> s3;
   
   cout << "\ns3 tilldelas s1, ";
   s3 = s1;
   cout << "s3 inneh�ller: " << s3 << '\n';

   if (s3 < s1)
      cout << "s3 �r mindre �n s1.\n";
   else
      cout << "s3 �r inte mindre �n s1.\n";

   cout << "\ns4 initieras genom att iterera �ver hela s1, ";
   set<int> s4(begin(s1), end(s1));
   
   cout << "s4 inneh�ller: " << s4 << '\n';

   cout << "\nS�tter in 0 i s4.\n";

   auto p = s4.insert(0);  // pair<set<int>::iterator, bool>

   if (p.second == true)
   {
      cout << "Ins�ttning lyckad, iteratorn anger: " << *p.first << '\n';
   }

   cout << "F�rs�ker s�tta in 0 en g�ng till i s4.\n";
   p = s4.insert(0);

   if (p.second == false)
   {
      cout << "Ins�ttning misslyckad, iteratorn anger: " << *p.first << '\n';
   }

   cout << "\ns4 inneh�ller: " << s4 << '\n';

   cout << "S�tter in 9 i s4.\n";

   auto it = s4.insert(end(s4), 9);  // set<int>::iterator

   cout << "Kollar ins�ttningen via returnerad iterator: " << *it << '\n';

   cout << "s4 inneh�ller: " << s4 << '\n';

   set<int> s5;

   cout << "\nKopierar s4 till s5, "; 
   s5.insert(begin(s4), end(s4));

   cout << "s5 inneh�ller: " << s5 << '\n';

   cout << "Tar bort 1 ur s5, erase(1) retunerar: " << s5.erase(1) << '\n';
   cout << "F�rs�ker ta bort 1 ur s5 en g�ng till, erase(1) returnerar: " 
	<< s5.erase(1) << '\n';
   cout << "s5 inneh�ller: " << s5 << '\n';

   cout << "\nTar bort 3 ur s5, med find() och erase().\n";
   s5.erase(s5.find(3));
   cout << "s5 inneh�ller: " << s5 << '\n';
   
   cout << "\nT�mmer s5 med s5.clear()\n"; 
   s5.clear();

   if (s5.empty()) cout << "s5 �r tom.\n"; 

   return 0;
}
