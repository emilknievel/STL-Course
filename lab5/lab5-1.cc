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

      // Returnerar en iterator till paret och ett bool-värde som returnerar
      // false om paret redan finns.
      pair<map<char, int>::iterator, bool> check { m.emplace(letter, 1) };

      // Öka antalet med 1 om bokstaven redan finns
      if (!check.second) ++check.first->second;
   }

   cout << m;

   return 0;
}
