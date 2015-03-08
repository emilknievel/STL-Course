#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <algorithm>
#include <iterator>

namespace std
{
   ostream& operator<<(ostream& os, const pair<char, int>& p)
   {
      return os << p.first << ": " << p.second;
   }
}

using namespace std;

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

   vector< pair<char, int> > v(m.size());

   copy(m.cbegin(), m.cend(), v.begin());

   // I detta fall gör stable_sort så att man slipper
   // jämföra dubbelt som tidigare med descending.
   stable_sort(begin(v), end(v),
               [](pair<char, int> const &p1, pair<char, int> const &p2)->bool
                  { return p1.second > p2.second; });

   cout << "Utskrift av map: " << '\n';
   copy(begin(m), end(m), ostream_iterator< pair<char, int> >{cout, "\n"});
   cout << endl;

   cout << "Utskrift av vector: " << '\n';
   copy(begin(v), end(v), ostream_iterator< pair<char, int> >{cout, "\n"});

   return 0;
}
