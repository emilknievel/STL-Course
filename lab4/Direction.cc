#include "Direction.h"

// 3.
std::ostream& operator<<(std::ostream& os, const Direction& dir)
{
   if (dir == Up)
   {
      std::cout << "Up";
   }
   else if (dir == Down)
   {
      std::cout << "Down";
   }
   else if (dir == Down)
   {
      std::cout << "Left";
   }
   else
   {
      std::cout << "Right";
   }

   return os;
}
