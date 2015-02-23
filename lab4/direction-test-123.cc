/*
 * direction-test-123.cc
 */
#include "Direction.h"
#include <iostream>
using namespace std;

// 7.
//using namespace Direction_ns;

int main()
{
   // Notera asymmetrin: automatisk typomvandling från uppräkningstyp
   // till int men inte tvärt om - explicit typomvandling krävs där.

   for (Direction d = Up; d <= Right; d = static_cast<Direction>(d + 1))
   {
      cout << d << '\n';
   }

   return 0;
}

/*
 * I ett uttryck som 'd <= Right' typomvandlas först d och Right till int
 * och sedan görs jämförelsem med avseende på int-värdena.
 *
 * I uttrycket 'd + 1' typomvandlas först d till int och sedan adderas 1
 * static_cast för att omvandla till Direction innan tilldelningen av d.
 */
