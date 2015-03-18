/*
 * uppgift4.cc
 */
#include <iostream>
using namespace std;

enum Weekday { Mon, Tue, Wed, Thu, Fri, Sat, Sun };

// Definiera operatorerna här
ostream& operator<<(ostream& os, const Weekday& w)
{
    switch (w)
    {
    case Mon:
	os << "Mon"; break;
    case Tue:
	os << "Tue"; break;
    case Wed:
	os << "Wed"; break;
    case Thu:
	os << "Thu"; break;
    case Fri:
	os << "Fri"; break;
    case Sat:
	os << "Sat"; break;
    case Sun:
	os << "Sun"; break;
    default:
	os << "NaWeekday"; break;
    }
    return os;
}

Weekday& operator++(Weekday& w)
{
    return w = (w == Sun) ? Mon : Weekday(w+1);
}

Weekday operator++(Weekday& w, int)
{
    Weekday tmp(w);
    ++w;
    return tmp;
}

int main()
{
   Weekday w{ Mon };

   // Testa utskrift med << och semantiken för postfix och prefix ++
   cout << w++ << " - " << w << '\n';    // postfix
   cout << ++w << " - " << w << "\n\n";  // prefix

   // Testa "wrap around"
   for (int i = 0; i < 12; ++i)
   {
      cout << w++ << " - " << w << '\n';
   }

   return 0;
}
