/*
 * exempel-15.cc    TDIU04 Fö 5-6
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
 * grundläggande användning. Syftet är normalt att använda funktionsobjekt
 * tillsammans med andra programkomponenter, t.ex. en algoritm.
 *
 * Manipulatorn 'boolalpha' medför att bool-värden skrivs ut som "false"
 * och "true", i stället för som defaultmässigt 0 och 1.
 *
 * Observera att 'xor' finns som ersättningssymbol för operator^ (bitvis xor).
 */
