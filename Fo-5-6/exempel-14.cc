/*
 * exempel-14.cc    TDIU04 Fö 5-6
 */
#include <iostream>
#include <iterator>
#include <set>
#include <utility>
using namespace std;
template<typename T>
ostream& operator<<(ostream& os, const multiset<T>& s)
{
   copy(begin(s), end(s), ostream_iterator<T>(os, " "));
   return os;
}
int main()
{
   multiset<int> ms;

   cout << "Sätter in 5, 1, 8, 4, 1 i ett tomt multiset ms.\n";
   ms.insert(5);
   ms.insert(1);
   ms.insert(8);
   ms.insert(4);
   ms.insert(1);

   if (ms.empty())
      cout << "ms är tom\n";
   else
      cout << "ms är inte tom\n";

   cout << "ms har storlekan " << ms.size() << "\n\n";
   cout << "ms innehåller:\n" << ms << "\n\n";
   cout << "Det finns " << ms.count(1) << " 1:or i ms.\n";
   return 0;
}
