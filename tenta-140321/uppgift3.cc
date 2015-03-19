/*
 * uppgift3.cc
 */
#include <iostream>
using namespace std;

// Definiera enum RGB med uppräknarna Red, Green, Blue och NaRGB samt
// undantaget rgb_error och operator<< och operator>> för RGB.

int main()
{
   // Test av operator<< för RGB
   for (RGB rgb = Red; rgb <= Blue; rgb = RGB(rgb + 1))
   {
      cout << rgb << '\n';
   }

   // Test av operator>> för RGB och rgb_error
   RGB x;

   cout << "Skriv RGB-värden:\n";

   while (cin >> x)
   {
      cout << x << '\n';
   }

   // Lägg ett try-block kring ovanstående while-sats. Om ett undantag
   // kastas ska det fångas, meddelandet som undantaget lagrar skrivas
   // ut och programmet sedan avslutas.

   return 0;
}
