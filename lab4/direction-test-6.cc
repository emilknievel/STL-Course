/*
 * direction-test-6.cc
 */
#include "Direction.h"
#include <iostream>
using namespace std;

int main()
{
   Direction d;

   cout << "Ge ett värde av Up, down, Left eller Right i taget "
  << "(avbryt med Control-C):\n";

   while (true)
   {
      cin >> d;
      cout << "Värdet var: " << d << '\n';
   }

   return 0;
}
