/*
 * le5-3-std.cc    TDIU04 Lektion 5, uppgift 3, standardkomponenter
 */
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;
using namespace std::placeholders;

int main()
{
   int a[]{ 0, 1, 2, 3, 3, 4, 5, 6, 6, 7, 8, 9 };

   cout << "\nUrsprungliga data:\n";
   copy(begin(a), end(a), ostream_iterator<int>{cout, " "});
   cout << '\n';

   vector<int> v;

   replace_copy_if(begin(a), end(a), back_inserter(v),
		   not1(function<bool(int)>(bind(modulus<int>{}, _1, 2))),
		   0);

   cout << "\nKopierade data - element med jämna tal har ersatts med nollor:\n";
   copy(begin(v), end(v), ostream_iterator<int>{cout, " "});
   cout << '\n';

   auto count = count_if(begin(v), end(v), bind(equal_to<int>{}, _1, 0));

   cout << "\nAntal nollor i kopierade data: " << count << '\n';

   return 0;
}
