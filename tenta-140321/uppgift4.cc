/*
 * uppgift4.cc
 */
#include <iostream>
#include <vector>
using namespace std;

// Definiera print_link här

int main()
{
   vector<int> a{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

   vector<double> b{ 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.0 };

   // Använd någon lämplig standardalgoritm för att applicera print_link 
   // på elementen i vectorerna a och b vid utskrifterna nedan.

   cout << "vector a innehåller:\n";
   // Skriv ut innehållet i a på cout.

   cout << "Elementen i vector b skrivs på filen utdata.txt\n";
   // Skriv ut elementen i b på en textfil med namnet "utdata.txt".

   return 0;
}
