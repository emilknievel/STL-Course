/*
 * exempel-19.cc    TDIU04 Fö 5-6
 */
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
using namespace std;
using namespace std::placeholders;

int a[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

int main()
{
   vector<int> v1(begin(a), end(a));			
   vector<int> v2(begin(a), end(a));	
   vector<int> v3(v1.size());

   transform(begin(v1), end(v1), begin(v2), begin(v3), plus<int>());

   copy(begin(v3), end(v3), ostream_iterator<int>(cout, " "));
   cout << '\n';

   return 0;
}
