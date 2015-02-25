/*
 * le4-1.cc    TDIU04 Lektion 4, uppgift 1
 */
#include <iostream>
#include <map>
using namespace std;

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
      cout << x.first << ": " << x.second << '\n';
   }
    
   return 0;
}
