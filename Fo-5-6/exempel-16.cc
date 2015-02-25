/*
 * exempel-16.cc    TDIU04 Fö 5-6
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

   // temporära logical_xor-objekt
   cout << logical_xor<bool>()(false, false) << '\n';
   cout << logical_xor<bool>()(true,  false) << '\n';
   cout << logical_xor<bool>()(false, true)  << '\n';
   cout << logical_xor<bool>().operator()(true, true) << "\n\n";

   // logical_xor-objekt
   logical_xor<bool> XOR;  // xor finns, ersättningssymbol för ^ (bitvis xor)

   // Objektet Kan användas p.s.s. som en vanlig funktion - funktionsobjekt!
   cout << XOR(false, true) << '\n';

   // Explicit syntax för anrop av funktionsoperatorn
   cout << XOR.operator()(false, true) << "\n\n";

   vector<bool> v1(begin(b1), end(b1));
   vector<bool> v2(begin(b2), end(b2));
   vector<bool> v3(4);

   // IRL - användning i algoritm
   transform(begin(v1), end(v1), begin(v2), begin(v3), logical_xor<bool>());

   copy(begin(v3), end(v3), ostream_iterator<bool>(cout, " "));
   cout << '\n';

   return 0;
}

/*
 * Generaliserad funktionsobjektsklass för logiskt exklusivt-eller. Ska kunna
 * användas för alla typer T för vilka exklusivt-eller är relevant.
 */
