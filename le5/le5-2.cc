/*
 * le5-2.cc    TDIU04 Lektion 5, uppgift 2, funktionsobjekt
 */
#include <algorithm>
#include <iostream>
#include <list>
#include <iterator>
#include <numeric>
using namespace std;

struct odd_by_twos
{
   int operator()() const
   {
      static int seed = -1;
      return seed += 2;
   }
};

int main()
{
   list<int> lst(10);

   generate(begin(lst), end(lst), odd_by_twos{});

   copy(begin(lst), end(lst), ostream_iterator<int>{cout, " "});
   cout << '\n';

   auto result = inner_product(begin(lst), end(lst), begin(lst), 0);

   cout << "Innerprodukten av listan med sig själv är: " << result << '\n';

   return 0;
}
