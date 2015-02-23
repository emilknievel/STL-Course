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
         break;
      default:
         // 5.
         throw bad_direction(std::to_string(dir));
   }

   return os;
}

// 6.
std::istream& operator>>(std::istream& is, Direction& dir)
{
   std::string dirstr;
   if (is >> dirstr) // Lyckas inläsningen?
   {
      if (dirstr == "Up")
      {
         dir = Up;
      }
      else if (dirstr == "Down")
      {
         dir = Down;
      }
      else if (dirstr == "Left")
      {
         dir = Left;
      }
      else if (dirstr == "Right")
      {
         dir = Right;
      }
      else
      {
         throw bad_direction(dirstr);
      }

      return is;
   }

   is.setstate(std::ios_base::failbit); // Regga fel om inläsning misslyckades
   return is;
}
