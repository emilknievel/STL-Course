/*
 * le3-2.cc    TDIU04 Lektion 3, uppgift 2
 */
#include <iostream>
#include <utility>
#include <queue>
using namespace std;

using int_pair = std::pair<int, int>;
using pair_pq  = std::priority_queue<int_pair>;

std::ostream& operator<<(std::ostream& os, const int_pair& p)
{
    return os << p.first << ": " << p.second;
}

int main()
{
    pair_pq pq;
    int     n = 0;
    int     i;

    while (cin >> i)
    {
        pq.push(make_pair(i, ++n));
    }

    while (! pq.empty())
    {
        cout << pq.top() << '\n';
        pq.pop();
    }

    return 0;
}
