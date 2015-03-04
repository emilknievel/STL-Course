/*
 * le5-1-lambda.cc    TDIU04 Lektion 5, uppgift 1, lambdauttryck
 */
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

int main()
{
   vector<int> v{ istream_iterator<int>{ cin }, istream_iterator<int>{} };

   copy(begin(v), end(v), ostream_iterator<int>{cout, " "});
   cout << '\n';

   cout << "Två intilliggande lika element:\n";
   auto it = adjacent_find(begin(v), end(v));

   if (it != end(v))
   {
      auto d = it - begin(v);
      cout << *it << ", position " << d << " och " << d+1 << '\n';
   }
   else
   {
      cout << "Det finns inte två sådana element.\n";
   }

   cout << "Två intilliggande element där det andra är dubbelt så stort som det första:\n";
   it = adjacent_find(begin(v), end(v), [](int a, int b){ return 2*a == b; });

   if (it != end(v))
   {
      auto d = it - begin(v);
      cout << *it << " och " << *(it+1) << ", position " << d
	   << " och " << d+1 << '\n';
   }
   else
   {
      cout << "Det finns inte två sådana element.\n";
   }

   return 0;
}
