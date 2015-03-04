/*
 * le5-1-template.cc    TDIU04 Lektion 5, uppgift 1, template
 */
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

template<typename T>
struct twice_over
{
   bool operator()(const T& a, const T& b) const
   {
      return 2*a == b;
   }

   using first_argument_type = T;
   using second_argument_type = T;
   using result_type = bool;
};

int main()
{
   vector<int> v{ istream_iterator<int>{ cin }, istream_iterator<int>{} };

   copy(begin(v), end(v), ostream_iterator<int>{cout, " "});
   cout << '\n';

   cout << "Två intilliggande, lika element:\n";
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
   it = adjacent_find(begin(v), end(v), twice_over<int>{});

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
