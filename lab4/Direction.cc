#include "Direction.h"

// 3.
std::ostream& operator<<(std::ostream& os, const Direction dir)
{
   if (dir == Up)
   {
      return os << "Up";
   }
   else if (dir == Down)
   {
      return os << "Down";
   }
   else if (dir == Left)
   {
      return os << "Left";
   }
   else
   {
      return os << "Right";
   }
}
