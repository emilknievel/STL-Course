#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    vector<string> ordv;
    // 1
    copy(istream_iterator<string>{cin}, istream_iterator<string>{}, back_inserter(ordv));

    // 2
    cout << ordv.size() << " ord har lästs in.\n";

    // 3
    sort(begin(ordv), end(ordv));
    ordv.erase(unique(begin(ordv), end(ordv)), end(ordv));

    // 4
    cout << ordv.size() << " unika ord hittade\n";

    // 5
    cout << "\nDe unika orden i alfabetisk ordning:\n";
    copy(ordv.cbegin(), ordv.cend(), ostream_iterator<string>(cout, " "));

    // 6
    stable_sort(begin(ordv), end(ordv), [](const string& a, const string& b)
		{ return a.size() < b.size(); });

    // 7
    cout << "\n\nDe unika orden ordnade efter längd:\n";
    copy(ordv.cbegin(), ordv.cend(), ostream_iterator<string>(cout, " "));
    return 0;
}
