/*
 * exempel-21.cc    TDIU04 Fö 5-6
 */
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
using namespace std;
using namespace std::placeholders;

int main()
{
   vector<bool> b1{ false, false, true, true };
   vector<bool> b2{ false, true, false, true };	
   vector<bool> b3(b1.size());

   transform(begin(b1), end(b1), begin(b2), begin(b3), logical_and<bool>());

   cout << boolalpha;
   copy(begin(b3), end(b3), ostream_iterator<bool>(cout, " "));
   cout << '\n';

   return 0;
}
