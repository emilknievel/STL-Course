/*
 * plot.cc
 *
 * Anv�nder curses sk�rmhanteringsfunktioner f�r att  i ett terminalf�nster
 * plotta en v�g, som best�ms av en sekvens av Up, Down, Left och Right.
 *
 * Kompileras med l�nkflaggan -lcurses
 */
#include "Direction.h"
#include <curses.h>
// Vissa namn i curses kommer i konflikt med namn i C++ standardbibliotek, s�
// dessa namn tas bort (det �r funktionsmakron som definierats med #define):
#undef box
#undef clear
#undef erase
#undef move
#undef refresh
// F�ljande alternativa funktioner kan anv�ndas i st�llet:
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
      cout << "anv�ndning: " << argv[0] << " fil\n";
      return 1;
   }

   ifstream input{ argv[1]) };

   if (! input)
   {
      cout << "kunde inte �ppna filen: " << argv[1] << '\n';
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
      cout << "Ok�nt undantag f�ngat\n";
   }

   return 0;
}

void read_route(istream& is, int& start_line, int& start_col, Route& route)
{
   is >> start_line >> start_col;

   // Anm. istream_iterator kr�ver att operator>> �r definierad f�r
   // instansieringstypen i fr�ga, dvs Direction i detta fall.
   copy(istream_iterator<Direction>(is), istream_iterator<Direction>(), 
	back_inserter(route));
}

void plot_route(int start_line, int start_col, const Route& route)
{
   // Initiera standardsk�rmen (stdscr) - utg�rs av terminalf�nstret.
   initscr();

   // Kontrollera att startpositionen hamnar inom sk�rmen.
   if (start_line < 0 || start_line >= LINES || start_col < 0 || start_col >= COLS)
   {
      cout << "Terminalen rymmer inte startpositionen\n";
      exit(3);
   }

   // Rama in sk�rmen.
   wborder(stdscr, '|', '|', '-', '-', '+', '+', '+', '+');
   // G�m mark�ren.
   curs_set(0);
   // Skriv ut ett 'S' i startpositionen.
   wmove(stdscr, start_line, start_col);
   echochar('S');
   // V�nta 1 sek (1000 ms) i startpositionen.
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
      // V�nta 200 ms innan n�sta steg tas.
      napms(200);
   }

   // Skriv ett 'X' i slutpositionen.
   wmove(stdscr, line, col);
   echochar('X');
   // Ta fram mark�ren.
   curs_set(1);
   // V�nta 3 sekunder p� inmatning vid getch(), annars forts�tt �nd�.
   halfdelay(30);
   getch();

   endwin();
}
