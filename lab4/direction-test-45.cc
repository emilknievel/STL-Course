/*
 * direction-test-45.cc
 */
#include "Direction.h"
#include <iostream>
using namespace std;

int main()
{
   // Notera asymmetrin: automatisk typomvandling fr�n uppr�kningstyp
   // till int men inte tv�rt om - explicit typomvandling kr�vs d�.

   for (Direction d = Up; d <= Right; d = static_cast<Direction>(d + 1))
   {
      cout << d << '\n';
   }

   cout << Direction(Up - 1) << '\n';

   cout << Direction(Right + 1) << '\n';

   return 0;
}

/*
 * I de senare utskrifterna anv�nds typomvandling p� funktionsform,
 * exempelvis 'Direction(Up - 1)'. Skillnaden j�mf�rt med typomvandling
 * med 'static_cast<Direction>(Up - 1)', liksom med dynamic_cast,
 * reinterpret_cast och const_cast, �r att f�r dessa "specialiserade"
 * typomvandlingar g�rs kontroll att de anv�nds i r�tt sammahang, dvs
 * f�r det slags typomvandlingar de �r avsedda f�r. Fel anv�ndning
 * medf�r kompileringsfel.
 */
