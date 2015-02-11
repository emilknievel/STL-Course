#include <iostream>
#include <queue>
#include <utility>
#include <string>
#include <stdexcept>
using namespace std;

int main()
{
    priority_queue< pair<int, string> > pq;
    int priority;
    string task;

    cin.exceptions(ios::failbit);
    cout << "Ange på varje rad prioritet (1-9) och uppgift "
         << "(prioritet 0 avslutar):\n";


    for (;;)
    {
        try
        {
            while(cin >> priority && priority != 0 && getline(cin, task))
            {
                if (priority < 1 || priority > 9)
                {
                    cerr << "Felaktigt värde på prioriteten. "
                         << "Ska vara ett tal mellan 1 och 9.\n"
                         << "Försök igen\n";
                }
                else pq.push(make_pair(priority, task));
            }
            break;
        }
        catch (const ios::failure& e)
        {
            cout << "Nu vart det tokigt här!\n";
            cin.clear();
            cin.ignore(256, '\n');
        }
        catch (...)
        {
            cout << "Ett oväntat fel har inträffat!\n";
            cin.clear();
            cin.ignore(256, '\n');
        }
    }


    cout << "Att göra:\n";
    while (!pq.empty()) {
        cout << pq.top().first << ":" << pq.top().second << '\n';
        pq.pop();
    }

    return 0;
}
