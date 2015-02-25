/*
 * set-test.cc    TDIU04 Fö 4-5
 */
#include <iostream>
#include <set>
#include <utility>
#include <iterator>
using namespace std;

/* Här kräver ostream_iterator<int> att operator<< finns för elementtypen
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

   cout << "Sätter in 5, 1, 8, 4, 1 i ett tomt set s1.\n";
   s1.insert(5);
   s1.insert(1);
   s1.insert(8);
   s1.insert(4);
   s1.insert(1);
   cout << '\n';

   if (s1.empty())
      cout << "s1 är tom\n";
   else
      cout << "s1 är inte tom\n";

   cout << "s1.size()....: " << s1.size()     << '\n';
   cout << "s1.max_size(): " << s1.max_size() << '\n';
   cout << "s1.count(1)..: " << s1.count(1)   << '\n';

   cout << "s1 innehåller: " << s1 << '\n';
   
   cout << "\nSöker på nyckel 3: ";
   if (s1.find(1) != s1.end())
      cout << "Hittades!\n";

   cout << "Söker på nyckel 0: ";
   if (s1.find(0) == end(s1))
      cout << "Hittades inte!\n";

   cout << "\ns2 skapas som en kopia av s1, ";

   set<int> s2{s1};
   
   cout << "s2 innehåller: " << s2 << '\n';

   if (s2 == s1)
      cout << "s2 är lika med s1.\n";
   else
      cout << "s2 är inte lika med s1.\n";

   set<int> s3;
   
   cout << "\ns3 tilldelas s1, ";
   s3 = s1;
   cout << "s3 innehåller: " << s3 << '\n';

   if (s3 < s1)
      cout << "s3 är mindre än s1.\n";
   else
      cout << "s3 är inte mindre än s1.\n";

   cout << "\ns4 initieras genom att iterera över hela s1, ";
   set<int> s4(begin(s1), end(s1));
   
   cout << "s4 innehåller: " << s4 << '\n';

   cout << "\nSätter in 0 i s4.\n";

   auto p = s4.insert(0);  // pair<set<int>::iterator, bool>

   if (p.second == true)
   {
      cout << "Insättning lyckad, iteratorn anger: " << *p.first << '\n';
   }

   cout << "Försöker sätta in 0 en gång till i s4.\n";
   p = s4.insert(0);

   if (p.second == false)
   {
      cout << "Insättning misslyckad, iteratorn anger: " << *p.first << '\n';
   }

   cout << "\ns4 innehåller: " << s4 << '\n';

   cout << "Sätter in 9 i s4.\n";

   auto it = s4.insert(end(s4), 9);  // set<int>::iterator

   cout << "Kollar insättningen via returnerad iterator: " << *it << '\n';

   cout << "s4 innehåller: " << s4 << '\n';

   set<int> s5;

   cout << "\nKopierar s4 till s5, "; 
   s5.insert(begin(s4), end(s4));

   cout << "s5 innehåller: " << s5 << '\n';

   cout << "Tar bort 1 ur s5, erase(1) retunerar: " << s5.erase(1) << '\n';
   cout << "Försöker ta bort 1 ur s5 en gång till, erase(1) returnerar: " 
	<< s5.erase(1) << '\n';
   cout << "s5 innehåller: " << s5 << '\n';

   cout << "\nTar bort 3 ur s5, med find() och erase().\n";
   s5.erase(s5.find(3));
   cout << "s5 innehåller: " << s5 << '\n';
   
   cout << "\nTömmer s5 med s5.clear()\n"; 
   s5.clear();

   if (s5.empty()) cout << "s5 är tom.\n"; 

   return 0;
}
