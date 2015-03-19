/*
 * uppgift3.cc
 */
#include <iostream>
using namespace std;

// Definiera enum RGB med uppr�knarna Red, Green, Blue och NaRGB samt
// undantaget rgb_error och operator<< och operator>> f�r RGB.

int main()
{
   // Test av operator<< f�r RGB
   for (RGB rgb = Red; rgb <= Blue; rgb = RGB(rgb + 1))
   {
      cout << rgb << '\n';
   }

   // Test av operator>> f�r RGB och rgb_error
   RGB x;

   cout << "Skriv RGB-v�rden:\n";

   while (cin >> x)
   {
      cout << x << '\n';
   }

   // L�gg ett try-block kring ovanst�ende while-sats. Om ett undantag
   // kastas ska det f�ngas, meddelandet som undantaget lagrar skrivas
   // ut och programmet sedan avslutas.

   return 0;
}
