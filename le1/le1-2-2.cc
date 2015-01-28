/*
 * le1-2-2.cc    TDIU04 Lektion 1, uppgift 2, range based for, range access
 *
 * Anm. GCC 4.8 saknar full uppsättning range access-funktioner.
 */
#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
using namespace std;

int main()
{
   list<int> list_1;
   int x;

   while (cin >> x) 
   {
      if (find(begin(list_1), end(list_1), x) == end(list_1))
      {
	 list_1.push_back(x);
      }
   }

   cout << "lista 1 efter inläsning: ";

   for (auto x : list_1)
   {
      cout << x << ' ';
   }
   cout << '\n';

   list_1.sort();

   cout << "lista 1 efter sortering: ";

   copy(begin(list_1), end(list_1), ostream_iterator<int>(cout, " "));
   cout << '\n';

   list<int> list_2{ list_1 };

   // Öka varje elements värde med 1
   for (auto& x : list_2)
   {
      ++x;
   }

   cout << "lista 2 efter kopiering av lista 1 och uppstegning med 1: ";

   copy(begin(list_2), end(list_2), ostream_iterator<int>(cout, " "));
   cout << '\n';

   // Samsortera lista 1 och lista 2; lista 2 töms
   list_1.merge(list_2);

   cout << "lista 1 efter samsortering med lista 2: ";

   copy(begin(list_1), end(list_1), ostream_iterator<int>(cout, " "));
   cout << '\n';

   // Ta bort dubbletter
   list_1.unique();

   cout << "lista 1 efter att dubletter tagits bort: ";

   copy(begin(list_1), end(list_1), ostream_iterator<int>(cout, " "));
   cout << '\n';

   return 0;
}
