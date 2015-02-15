/*
 * plot.cc
 *
 * Använder curses skärmhanteringsfunktioner för att  i ett terminalfönster
 * plotta en väg, som bestäms av en sekvens av Up, Down, Left och Right.
 *
 * Kompileras med länkflaggan -lcurses
 */
#include "Direction.h"
#include <curses.h>
// Vissa namn i curses kommer i konflikt med namn i C++ standardbibliotek, så
// dessa namn tas bort (det är funktionsmakron som definierats med #define):
#undef box
#undef clear
#undef erase
#undef move
#undef refresh
// Följande alternativa funktioner kan användas i stället:
// box(win, vch, hch)  wborder(win, vch, vch, hch, hch , 0, 0, 0, 0)
// clear()             wclear(stdscr)
// erase()             werase(stdscr)
// move(x, y)          wmove(stdscr, y, x)
// refresh()           wrefresh(stdscr)
//
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <iterator>
using namespace std;
using namespace Direction_ns;

typedef vector<Direction> Route;

void read_route(istream& is, int& start_line, int& start_col, Route& route);
void plot_route(int start_line, int start_col, const Route& route);

int main(int argc, char* argv[])
{
   if (argc != 2)
   {
      cout << "användning: " << argv[0] << " fil\n";
      return 1;
   }

   ifstream input{ argv[1]) };

   if (! input)
   {
      cout << "kunde inte öppna filen: " << argv[1] << '\n';
      return 2;
   }

   int   start_line, start_col;
   Route route;
   
   try
   {
      read_route(input, start_line, start_col, route);
      input.close();
      plot_route(start_line, start_col, route);
   }
   catch (const exception& e)
   {
      cout << e.what() << '\n';
   }
   catch (...)
   {
      cout << "Okänt undantag fångat\n";
   }

   return 0;
}

void read_route(istream& is, int& start_line, int& start_col, Route& route)
{
   is >> start_line >> start_col;

   // Anm. istream_iterator kräver att operator>> är definierad för
   // instansieringstypen i fråga, dvs Direction i detta fall.
   copy(istream_iterator<Direction>(is), istream_iterator<Direction>(), 
	back_inserter(route));
}

void plot_route(int start_line, int start_col, const Route& route)
{
   // Initiera standardskärmen (stdscr) - utgörs av terminalfönstret.
   initscr();

   // Kontrollera att startpositionen hamnar inom skärmen.
   if (start_line < 0 || start_line >= LINES || start_col < 0 || start_col >= COLS)
   {
      cout << "Terminalen rymmer inte startpositionen\n";
      exit(3);
   }

   // Rama in skärmen.
   wborder(stdscr, '|', '|', '-', '-', '+', '+', '+', '+');
   // Göm markören.
   curs_set(0);
   // Skriv ut ett 'S' i startpositionen.
   wmove(stdscr, start_line, start_col);
   echochar('S');
   // Vänta 1 sek (1000 ms) i startpositionen.
   napms(1000);

   Route::const_iterator route_end = route.end();
   int line = start_line;
   int col  = start_col;

   for (auto d : route)
   {
      if (d == Up)
      {
	 wmove(stdscr, --line, col);
	 echochar('.');
      }
      else if (d == Down)
      {
	 wmove(stdscr, ++line, col);
	 echochar('.'); 
      }
      else if (d == Left)
      {
	 wmove(stdscr, line, --col);
	 echochar('.'); 
      }
      else if (d == Right)
      {
	 wmove(stdscr, line, ++col);
	 echochar('.'); 
      }
      // Vänta 200 ms innan nästa steg tas.
      napms(200);
   }

   // Skriv ett 'X' i slutpositionen.
   wmove(stdscr, line, col);
   echochar('X');
   // Ta fram markören.
   curs_set(1);
   // Vänta 3 sekunder på inmatning vid getch(), annars fortsätt ändå.
   halfdelay(30);
   getch();

   endwin();
}
