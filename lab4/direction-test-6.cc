/*
 * direction-test-6.cc
 */
#include "Direction.h"
#include <iostream>
using namespace std;

int main()
{
   Direction d;

   cout << "Ge ett v�rde av Up, down, Left eller Right i taget "
	<< "(avbryt med Control-C):\n";

   while (true)
   {
      cin >> d;
      cout << "V�rdet var: " << d << '\n';
   }

   return 0;
}
