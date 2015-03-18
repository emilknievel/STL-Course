#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    int indata;
    vector<int> container1;
    // 1
    while (cin >> indata)
    {
        container1.push_back(indata);
    }

    // 2
    cout << "Inlästa tal:\n";
    copy(container1.cbegin(), container1.cend(), ostream_iterator<int>(cout, " "));

    // 3
    vector<int> container2;
    remove_copy_if(container1.begin(), container1.end(), back_inserter(container2),
                   [](int x){ return x < 0; });
    container1.erase(remove_if(container1.begin(), container1.end(),
                               [](int x){ return !(x < 0); }),
                     container1.end());

    // 4
    cout << "\n\nPositiva tal:\n";
    copy(container2.cbegin(), container2.cend(), ostream_iterator<int>(cout, " "));
    cout << "\n\nNegativa tal:\n";
    copy(container1.cbegin(), container1.cend(), ostream_iterator<int>(cout, " "));

    // 5
    sort(begin(container2), end(container2));
    cout << "\n\nPositiva tal sorterade:\n";
    copy(container2.cbegin(), container2.cend(), ostream_iterator<int>(cout, " "));

    // 6
    sort(begin(container1), end(container1), [](int a, int b){ return a > b; });
    cout << "\n\nNegativa tal sorterade:\n";
    copy(container1.cbegin(), container1.cend(), ostream_iterator<int>(cout, " "));

    // 7
    auto cout_it = ostream_iterator<int>(cout, " ");
    cout << "\n\nResultatet av parvis summering:\n";

    if (container1.size() < container2.size())
        transform(container1.cbegin(), container1.cend(),
                  container2.cbegin(), cout_it,
                  [](int a, int b){ return a + b; });

    else if (container1.size() > container2.size())
        transform(container2.cbegin(), container2.cend(),
                  container1.cbegin(), cout_it,
                  [](int a, int b){ return a + b; });

    return 0;
}
