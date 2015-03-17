/*
 * uppgift4.cc
 */
#include <iostream>
using namespace std;

enum Weekday { Mon, Tue, Wed, Thu, Fri, Sat, Sun };

// Definiera operatorerna här

int main()
{
   Weekday w{ Mon };

   // Testa utskrift med << och semantiken för postfix och prefix ++
   cout << w++ << " - " << w << '\n';    // postfix
   cout << ++w << " - " << w << "\n\n";  // prefix

   // Testa "wrap around"
   for (int i = 0; i < 12; ++i)
   {
      cout << w++ << " - " << w << '\n';
   }

   return 0;
}
