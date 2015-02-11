/*
 * le3-3.cc    TDIU04 Lektion 3, uppgift 3
 */
#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
   int  x;
   bool done = false;

   cin.exceptions(ios::failbit);
   cout << "Mata in heltal, avsluta med punkt (.):\n";

   while (!done)
   {
      try
      {
	 while (cin >> ws && cin.peek() != '.' && cin >> x)
	 {
	    cout << x << ' ';
	 }
	 done = true;
      }
      catch (const ios_base::failure& e)
      {
	 cout << "Felaktig indata: ";
	 cin.clear();
	 while (!isspace(cin.peek()))
	 {
	    cout << static_cast<char>(cin.peek());
	    cin.get();
	 }
	 cout << "\n";
      }
   }
   cout << "Slut.\n";

   return 0;
}
