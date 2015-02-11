/*
 * le3-1.cc    TDIU04 Lektion 3, uppgift 1
 */
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int main()
{
   priority_queue< pair<int, int> > pq;

   int n = 0;
   int i;

   while (cin >> i)
   {
      pq.push(make_pair(i, ++n));
   }

   while (! pq.empty())
   {
      cout << pq.top().first << ": " << pq.top().second << '\n';
      pq.pop();
   }
   
   return 0;
}
