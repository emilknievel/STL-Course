#include <iostream>
#include <queue>
#include <utility>
#include <string>
using namespace std;

//TODO: Flytta exceptionshanteringen till del 2 istället och kontrollera
///////////////////////////////////////////////////////////////////////

int main()
{
    priority_queue< pair<int, string> > pq;
    int priority;
    string task;

    cout << "Ange på varje rad prioritet (1-9) och uppgift "
         << "(prioritet 0 avslutar):\n";

    while(cin >> priority && priority != 0 && getline(cin, task))
    {
        pq.push(make_pair(priority, task));
    }

    cout << "Att göra:\n";
    while (!pq.empty()) {
        cout << pq.top().first << ":" << pq.top().second << '\n';
        pq.pop();
    }

    return 0;
}
