/*
 * multiset-test.cc    TDIU04 Fö 4-5
 */
#include <set>
#include <utility>
#include <iterator>
#include <iostream>
using namespace std;

template<typename T>
ostream& operator<<(ostream& os, const multiset<T>& s)
{
   copy(begin(s), end(s), ostream_iterator<T>(os, " "));
   return os;
}

int main()
{
   multiset<int> ms1;

   cout << "Sätter in 5, 1, 8, 4, 1 i ett tomt multiset ms1.\n";
   ms1.insert(5);
   ms1.insert(1);
   ms1.insert(8);
   ms1.insert(4);
   ms1.insert(1);
   cout << '\n';

   if (ms1.empty())
      cout << "ms1 är tom\n";
   else
      cout << "ms1 är inte tom\n";

   cout << "ms1.size()....: " << ms1.size()     << '\n';
   cout << "ms1.max_size(): " << ms1.max_size() << '\n';
   cout << "ms1.count(1)..: " << ms1.count(1)   << "\n\n";

   cout << "ms1 innehåller: " << ms1 << '\n';
   
   cout << "\nSöker på nyckel 1: ";
   if (ms1.find(1) != end(ms1)) cout << "Hittades!\n";

   cout << "Söker på nyckel 0: ";
   if (ms1.find(0) == end(ms1)) cout << "Hittades inte!\n";

   cout << "\nms2 initieras med ms1 (kopieringskonstruktorn används).\n";
   multiset<int> ms2{ms1};
   
   cout << "ms2 innehåller: " << ms2 << '\n';

   if (ms2 == ms1)
      cout << "ms2 är lika med ms1.\n";
   else
      cout << "ms2 är inte lika med ms1.\n";

   cout << "\nSätter in 1, 1, 3, 4, 4, 4 i ms2\n";
   ms2.insert(1);  ms2.insert(1);
   ms2.insert(3);
   ms2.insert(4);  ms2.insert(4);  ms2.insert(4);
   cout << "ms2 innehåller: " << ms2 << '\n';

   cout << "\nms3 defaultinitieras (defaultkonstruktorn används).\n";
   multiset<int> ms3;
   cout << "\nms3 tilldelas ms1, ";
   ms3 = ms1;
   cout << "ms3 innehåller: " << ms3 << '\n';

   if (ms3 < ms2)
      cout << "ms3 är mindre än ms2.\n";
   else
      cout << "ms3 är inte mindre än ms2.\n";

   cout << "\nms4 initieras genom att iterera över hela ms2.";
   multiset<int> ms4{begin(ms2), end(ms2)};
   
   cout << "ms4 innehåller: " << ms4 << '\n';

   cout << "\nSätter in 0 i ms4, tar emot returvärdet i iterator.\n";

   auto it = ms4.insert(0);  // multiset<int>::iterator

   if (it != end(ms4)) cout << "Iteratorn anger nyckel: " << *it << '\n';

   cout << "ms4 innehåller: " << ms4 << '\n';

   cout << "\nSätter in 9 i ms4, anger ms4.end() för att hjälpa till...\n";

   it = ms4.insert(end(ms4), 9);

   cout << "Kollar insättningen via returnerad iterator: " << *it << '\n';

   cout << "ms4 innehåller: " << ms4 << '\n';

   cout << "\nSöker alla par i ms4 med nyckel 4: ";
   auto p = ms4.equal_range(4);  // pair<multiset<int, char>::iterator, multiset<int, char>::iterator>

   copy(p.first, p.second, ostream_iterator<int>(cout, " "));
   cout << "\n\n";

   auto lb = ms4.lower_bound(4);  // multiset<int, char>::iterator
   auto ub = ms4.upper_bound(4);  // multiset<int, char>::iterator

   cout << "lower_bound(4): " << *lb << '\n';
   cout << "upper_bound(4): " << *ub << '\n';

   cout << "\nms5 defaultinitieras.\n";
   multiset<int> ms5;

   cout << "\nKopierar ms4 till ms5 med ms5.insert(begin(ms4), end(ms4)).\n";
   ms5.insert(begin(ms4), end(ms4));

   cout << "ms5 innehåller: " << ms5 << "\n\n";

   cout << "Tar bort nyckel 1 ur ms5, erase(1) retunerar antalet borttagna: " 
	<< ms5.erase(1) << '\n';
   cout << "Försöker ta bort nyckel 1 ur ms5 en gång till, erase(1) returnerar: " 
	<< ms5.erase(1) << '\n';
   cout << "ms5 innehåller: " << ms5 << '\n';

   cout << "\nTar bort nyckel 3 ur ms5, med ms5.erase(ms5.find(3)).\n";
   ms5.erase(ms5.find(3));
   cout << "ms5 innehåller: " << ms5 << '\n';
   
   cout << "\nTömmer ms5 med ms5.clear()\n"; 
   ms5.clear();

   if (ms5.empty()) cout << "ms5 är tom.\n"; 

   return 0;
}
