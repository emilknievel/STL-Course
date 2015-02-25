/*
 * exempel-15.cc    TDIU04 F� 5-6
 */
#include <iostream>
using namespace std;

struct logical_xor
{
   bool operator()(bool lhs, bool rhs) const
   {
      return (lhs && !rhs) || (!lhs && rhs); 
   }
};

int main()
{
   cout << boolalpha;

   cout << logical_xor{}(true,  false) << '\n';

   logical_xor XOR;

   cout << XOR(false, true) << '\n';

   cout << XOR.operator()(false, true) << "\n\n";

   return 0;
}


/*
 * Visar definition av enkelt funktionsobjektsklass, logical_xor, och 
 * grundl�ggande anv�ndning. Syftet �r normalt att anv�nda funktionsobjekt
 * tillsammans med andra programkomponenter, t.ex. en algoritm.
 *
 * Manipulatorn 'boolalpha' medf�r att bool-v�rden skrivs ut som "false"
 * och "true", i st�llet f�r som defaultm�ssigt 0 och 1.
 *
 * Observera att 'xor' finns som ers�ttningssymbol f�r operator^ (bitvis xor).
 */
