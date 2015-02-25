/*
 * exempel-20.cc    TDIU04 Fö 5-6
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

   transform(begin(v1), end(v1), begin(v2), begin(v3), equal_to<int>());

   cout << boolalpha;
   copy(begin(v3), end(v3), ostream_iterator<bool>(cout, " "));
   cout << '\n';

   return 0;
}
