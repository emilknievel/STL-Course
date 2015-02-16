#include "Direction.h"

// 3.
std::ostream& operator<<(std::ostream& os, const Direction& dir)
{
   switch (dir)
   {
      case Up:
         os << "Up";
         break;
      case Down:
         os << "Down";
         break;
      case Left:
         os << "Left";
         break;
      case Right:
         os << "Right";
   }
   return os;
}
