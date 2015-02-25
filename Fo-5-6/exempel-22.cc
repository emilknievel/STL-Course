/*
 * exempel-22.cc    TDIU04 Fö 5-6
 */
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
using namespace std;
using namespace std::placeholders;

int main()
{
   vector<int> v1{ 0, 2, 4, 5, 5, 7, 8, 8, 9 };			
   vector<int> v2{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };	

   vector<bool> v3(v1.size());

   transform(begin(v1), end(v1), begin(v2), begin(v3), greater<int>());
   // v3 innehåller true i alla positioner för vilka v1[i] > v2[i] , false i övriga

   cout << boolalpha;
   copy(begin(v3), end(v3), ostream_iterator<bool>(cout, " "));
   cout << '\n';

   vector<bool> v4(v1.size());

   transform(begin(v1), end(v1), begin(v2), begin(v4), not2(greater<int>()));
   // v4 innehåller true i alla positioner för vilka !(v1[i] > v2[i]), false i övriga 

   copy(begin(v4), end(v4), ostream_iterator<bool>(cout, " "));
   cout << '\n';

   return 0;
}
