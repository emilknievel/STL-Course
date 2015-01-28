/*
 * le1-2-1.cc    TDIU04 Lektion 1, uppgift 2
 */
#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
using namespace std;

int main()
{
    list<int> list_1;
    int x;

    while (cin >> x)
    {
        if (find(list_1.cbegin(), list_1.cend(), x) == list_1.cend())
        {
            list_1.push_back(x);
        }
    }

    cout << "lista 1 efter inläsning: ";

    list<int>::const_iterator past_end{ list_1.cend() };

    for (list<int>::const_iterator it = list_1.cbegin(); it != past_end; ++it)
    {
        cout << *it << ' ';
    }
    cout << '\n';

    list_1.sort();

    cout << "lista 1 efter sortering: ";

    copy(list_1.cbegin(), list_1.cend(), ostream_iterator<int>(cout, " "));
    cout << '\n';

    list<int> list_2{ list_1 };

    // Öka varje elements värde med 1
    past_end = list_2.cend();

    for (list<int>::iterator it = list_2.begin(); it != past_end; ++it)
    {
        ++*it;
    }

    cout << "lista 2 efter kopiering av lista 1 och uppstegning med 1: ";

    copy(list_2.cbegin(), list_2.cend(), ostream_iterator<int>(cout, " "));
    cout << '\n';

    // Samsortera lista 1 och lista 2; lista 2 töms
    list_1.merge(list_2);

    cout << "lista 1 efter samsortering med lista 2: ";

    copy(list_1.cbegin(), list_1.cend(), ostream_iterator<int>(cout, " "));
    cout << '\n';

    // Ta bort dubbletter
    list_1.unique();

    cout << "lista 1 efter att dubletter tagits bort: ";

    copy(list_1.cbegin(), list_1.cend(), ostream_iterator<int>(cout, " "));
    cout << '\n';

    return 0;
}
