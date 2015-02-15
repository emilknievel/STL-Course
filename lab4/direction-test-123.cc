/*
 * direction-test-123.cc
 */
#include "Direction.h"
#include <iostream>
using namespace std;

int main()
{
   // Notera asymmetrin: automatisk typomvandling fr�n uppr�kningstyp
   // till int men inte tv�rt om - explicit typomvandling kr�vs d�r.

   for (Direction d = Up; d <= Right; d = static_cast<Direction>(d + 1))
   {
      cout << d << '\n';
   }

   return 0;
}

/*
 * I ett uttryck som 'd <= Right' typomvandlas f�rst d och Right till int
 * och sedan g�rs j�mf�relsem med avseende p� int-v�rdena.
 *
 * I uttrycket 'd + 1' typomvandlas f�rst d till int och sedan adderas 1
 * static_cast f�r att omvandla till Direction innan tilldelningen av d.
 */
