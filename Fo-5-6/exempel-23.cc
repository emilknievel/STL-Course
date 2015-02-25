/*
 * exempel-23.cc    TDIU04 Fö 5-6
 */
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;
using namespace std::placeholders;

int main()
{
   vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

   int n = count_if(begin(v), end(v), bind(greater<int>(), _1, 3));  // v[i] > 3?

   cout << n << " element i v är större än 3.\n";

   n = count_if(begin(v), end(v), [](int x){ return x > 3; });       // lambda 

   cout << n << " element i v är större än 3.\n";

   n = count_if(begin(v), end(v), bind(greater<int>(), 3, _1));     // 3 > v[i]?

   cout << n << " element i v är mindre än 3.\n";

   n = count_if(begin(v), end(v), bind(less<int>(), _1 , 3));       // v[i] < 3?

   cout << n << " element i v är mindre än 3.\n";

   return 0;
}
