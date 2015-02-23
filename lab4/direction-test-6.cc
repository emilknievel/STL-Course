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
      // 6.
      try
      {
         cin >> d;
         cout << "Värdet var: " << d << '\n';
      }
      catch (const bad_direction& e)
      {
         cout << "bad_direction: " << e.what() << '\n';
      }
   }

   return 0;
}
