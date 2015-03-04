/*
 * le5-3.cc    TDIU04 Lektion 5, uppgift 3
 */
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main()
{
   int a[]{ 0, 1, 2, 3, 3, 4, 5, 6, 6, 7, 8, 9 };

   cout << "\nUrsprungliga data:\n";
   copy(begin(a), end(a), ostream_iterator<int>{cout, " "});
   cout << '\n';

   vector<int> v;

   replace_copy_if(begin(a), end(a), back_inserter(v),
		   [](int x){ return x % 2 == 0; },
		   0);

   cout << "\nKopierade data - element med jämna tal har ersatts med nollor:\n";
   copy(begin(v), end(v), ostream_iterator<int>{cout, " "});
   cout << '\n';

   auto count = count_if(begin(v), end(v), [](int x){ return x == 0;});
   cout << "\nAntal nollor i kopierade data: " << count << '\n';

   return 0;
}
