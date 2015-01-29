#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <deque>
#include <iomanip>

using namespace std;

double div_by_2(double d);
void print(double d);

int main()
{
    // 1.
    cout << "Ange indatafil: ";
    string filename;
    getline(cin, filename);

    // 2.
    ifstream file{ filename };
    if (!file)
    {
        cerr << "Gick inte att läsa filen. Skrivit fel namn kanske?" << endl;
        return 1;
    }

    // 3.
    vector<int> v{};
    int data;

    while (file >> data)
    {
        v.push_back(data);
    }
    file.close();

    // 4.
    cout << "Filens innehåll: " << endl;
    for (vector<int>::size_type i = 0; i < v.size(); ++i)
    {
        cout << v.at(i) << " ";
    }
    cout << endl << endl;

    // 5.
    cout << "Minst: " << *min_element(begin(v), end(v)) << endl
         << "Störst: " << *max_element(begin(v), end(v)) << endl << endl;

    // 6.
    sort(begin(v), end(v));

    // 7.
    cout << "Sorterat:" << endl;
    for (vector<int>::const_iterator it = v.cbegin(); it != v.cend(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl << endl;

    // 8.
    v.erase(unique(v.begin(), v.end()), v.end());

    // 9.
    cout << "Unika element sorterade:" << endl;
    for (auto it = v.cbegin(); it != v.cend(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl << endl;

    // 10.
    vector<int> v2{};
    v2.resize(v.size(), 0);
    reverse_copy(v.begin(), v.end(), v2.begin());

    // 11.
    cout << "Innehåll v2:" << endl;
    for (int x : v2)
    {
        cout << x << " ";
    }
    cout << endl << endl;

    // 12.
    list<int> lst(v.begin(), v.end());

    // 13.
    cout << "Innehåll lst:" << endl;
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl << endl;

    // 14.
    deque<double> deq(v.rbegin(), v.rend());

    // 15.
    transform(deq.begin(), deq.end(), deq.begin(), div_by_2);

    // 16.
    for_each(deq.begin(), deq.end(), print);

    cout << endl;
    return 0;
}

double div_by_2(double d)
{
    return d / 2.0;
}

void print(double d)
{
    cout.precision(1);
    cout << setw(8) << fixed << d;
}
