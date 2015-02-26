#include <iostream>
#include <map>
#include <utility>

using namespace std;

ostream& operator<<(ostream& os, const map<char, int>& m)
{
   for (auto entry : m)
   {
      os << entry.first << ": " << entry.second << '\n';
   }
   return os;
}

int main()
{
   char letter;
   map<char, int> m;

   while (cin >> letter)
   {
      letter = toupper(letter); // tolka alla bokstäver som stora

      if (m.count(letter) == 0)
      {
         m.insert(make_pair(letter, 1)); // sätt in den nya bokstaven
      }
      else
      {
         m.at(letter)++; // öka antalet med 1
      }
   }

   cout << m;

   return 0;
}
