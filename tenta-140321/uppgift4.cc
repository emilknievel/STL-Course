/*
 * uppgift4.cc
 */
#include <iostream>
#include <vector>
using namespace std;

// Definiera print_link h�r

int main()
{
   vector<int> a{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

   vector<double> b{ 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.0 };

   // Anv�nd n�gon l�mplig standardalgoritm f�r att applicera print_link 
   // p� elementen i vectorerna a och b vid utskrifterna nedan.

   cout << "vector a inneh�ller:\n";
   // Skriv ut inneh�llet i a p� cout.

   cout << "Elementen i vector b skrivs p� filen utdata.txt\n";
   // Skriv ut elementen i b p� en textfil med namnet "utdata.txt".

   return 0;
}
