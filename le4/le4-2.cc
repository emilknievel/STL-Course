/*
 * le4-2.cc    TDIU04 Lektion 4, uppgift 2
 */
#include <iostream>
#include <map>
#include <utility>
using namespace std;

namespace std
{
   template<typename T1, typename T2>
   ostream& operator<<(ostream& os, const pair<T1, T2>& p)
   {
      return os << p.first << ": " << p.second;
   }
}

int main()
{
   map<int, int> count;
   int value;
    
   while (cin >> value)
   {
      ++count[value];
   }
   
   for (auto x : count)
   {
      cout << x << '\n';
   }
    
   return 0;
}
