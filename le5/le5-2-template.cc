/*
 * le5-2-template.cc    TDIU04 Lektion 5, uppgift 2, mallfunktion
 */
#include <algorithm>
#include <iostream>
#include <list>
#include <iterator>
#include <numeric>
using namespace std;

template<typename T>
struct odd_by_twos
{
   T operator()() const
   {
      static T seed = -1;
      return seed += 2;
   }
};

int main()
{
   list<int> lst(10);

   generate(lst.begin(), lst.end(), odd_by_twos<int>());

   copy(begin(lst), end(lst), ostream_iterator<int>{cout, " "});
   cout << '\n';

   auto result = inner_product(begin(lst), end(lst), begin(lst), 0);

   cout << "Innerprodukten av listan med sig själv är: " << result << '\n';

   return 0;
}
