/*
 * direction-test-45.cc
 */
#include "Direction.h"
#include <iostream>
using namespace std;

int main()
{
   // Notera asymmetrin: automatisk typomvandling från uppräkningstyp
   // till int men inte tvärt om - explicit typomvandling krävs då.

   for (Direction d = Up; d <= Right; d = static_cast<Direction>(d + 1))
   {
      cout << d << '\n';
   }

   cout << Direction(Up - 1) << '\n';

   cout << Direction(Right + 1) << '\n';

   return 0;
}

/*
 * I de senare utskrifterna används typomvandling på funktionsform,
 * exempelvis 'Direction(Up - 1)'. Skillnaden jämfört med typomvandling
 * med 'static_cast<Direction>(Up - 1)', liksom med dynamic_cast,
 * reinterpret_cast och const_cast, är att för dessa "specialiserade"
 * typomvandlingar görs kontroll att de används i rätt sammahang, dvs
 * för det slags typomvandlingar de är avsedda för. Fel användning
 * medför kompileringsfel.
 */
