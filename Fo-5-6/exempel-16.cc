/*
 * exempel-16.cc    TDIU04 F� 5-6
 */
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

template<typename T>
struct logical_xor
{
   bool operator()(const T& lhs, const T& rhs) const
   {
      return (lhs && !rhs) || (!lhs && rhs); 
   }
};

bool b1[]{ false, false, true, true };
bool b2[]{ false, true, false, true };

int main()
{
   cout << boolalpha;

   // tempor�ra logical_xor-objekt
   cout << logical_xor<bool>()(false, false) << '\n';
   cout << logical_xor<bool>()(true,  false) << '\n';
   cout << logical_xor<bool>()(false, true)  << '\n';
   cout << logical_xor<bool>().operator()(true, true) << "\n\n";

   // logical_xor-objekt
   logical_xor<bool> XOR;  // xor finns, ers�ttningssymbol f�r ^ (bitvis xor)

   // Objektet Kan anv�ndas p.s.s. som en vanlig funktion - funktionsobjekt!
   cout << XOR(false, true) << '\n';

   // Explicit syntax f�r anrop av funktionsoperatorn
   cout << XOR.operator()(false, true) << "\n\n";

   vector<bool> v1(begin(b1), end(b1));
   vector<bool> v2(begin(b2), end(b2));
   vector<bool> v3(4);

   // IRL - anv�ndning i algoritm
   transform(begin(v1), end(v1), begin(v2), begin(v3), logical_xor<bool>());

   copy(begin(v3), end(v3), ostream_iterator<bool>(cout, " "));
   cout << '\n';

   return 0;
}

/*
 * Generaliserad funktionsobjektsklass f�r logiskt exklusivt-eller. Ska kunna
 * anv�ndas f�r alla typer T f�r vilka exklusivt-eller �r relevant.
 */
