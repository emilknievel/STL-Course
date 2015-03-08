#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

bool descending(const pair<char, int>& p1, const pair<char, int>& p2);

int main()
{
   char letter;
   map<char, int> m;

   while (cin >> letter)
   {
      letter = toupper(letter); // tolka alla bokstäver som stora

      pair<map<char, int>::iterator, bool> check { m.emplace(letter, 1) };
      if (!check.second) ++check.first->second;
   }

   vector< pair<char, int> > v(m.size());

   copy(m.cbegin(), m.cend(), v.begin());

   sort(begin(v), end(v), descending);

   for (auto it = v.cbegin(); it != v.cend(); ++it)
   {
      cout << it->first << ": " << it->second << '\n';
   }

   return 0;
}

bool descending(const pair<char, int>& p1, const pair<char, int>& p2)
{
   return p1.second > p2.second ||
         (!(p2.second > p1.second) && p1.first < p2.first);
}
