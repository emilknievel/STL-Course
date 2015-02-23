#include "Direction.h"

// 3.
std::ostream& operator<<(std::ostream& os, const Direction& dir)
{
   try // 5.
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
   }
   // 5.
   catch (const bad_direction& e)
   {
      os << "bad_direction: " << e.what() << '\n';
   }

   return os;
}

// 6.
std::istream& operator>>(std::istream& is, Direction& dir)
{
   std::string dirstr;
   if (is >> dirstr) // Lyckas inläsningen?
   {
      try
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
      }
      catch (const bad_direction& e)
      {
         std::cerr << "bad_direction: " << e.what() << '\n';
      }

      return is;
   }

   is.setstate(std::ios_base::failbit); // Regga fel om inläsning misslyckades
   return is;
}
