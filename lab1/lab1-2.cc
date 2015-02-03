#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>

using namespace std;

bool greater_than(int x, int y);

int main(int argc, char* argv[])
{
    // 1.
    if (argc != 2)
    {
        cerr << "Hrrm! Kanske är bra att säga vad filen heter va? Typ "
             << argv[0] << " filnamnet" << endl;

        return 1;
    }
    string filename{ argv[1] };

    // 2.
    ifstream file{ filename };
    if (!file)
    {
        cerr << "Gick inte att läsa filen. Skrivit fel namn kanske?" << endl;

        return 2;
    }

    // 3.
    istream_iterator<int> file_it{ file };
    istream_iterator<int> eos{};

    vector<int> v(file_it, eos);

    file.close();

    // 4.
    cout << "Filens innehåll: " << endl;
    copy(begin(v), end(v), ostream_iterator<int>(cout, " "));
    cout << endl << endl;

    // 5.
    auto minmax_pair = minmax_element(begin(v), end(v));
    cout << "Minst: " << *minmax_pair.first << endl
         << "Störst: " << *minmax_pair.second << endl << endl;

    // 6.
    sort(begin(v), end(v), greater_than);

    // 7.
    cout << "Sorterat, fallande:" << endl;
    copy(begin(v), end(v), ostream_iterator<int>(cout, " "));

    cout << endl << endl;

    // 8.
    int sum{};
    sum = accumulate(begin(v), end(v), sum);

    // 9.
    cout << "Summa: " << sum << endl;

    double mean = sum / static_cast<double>(v.size());
    cout << "Medelvärde: " << mean << endl << endl;

    // 10.
    reverse(begin(v), end(v));

    // 11.
    cout << "Innehåll v, efter reverse:" << endl;
    copy(begin(v), end(v), ostream_iterator<int>(cout, " "));
    cout << endl << endl;

    // 12.
    replace(begin(v), end(v), 21, -1);

    // 13.
    cout << "Innehåll v, efter replace:" << endl;
    copy(begin(v), end(v), ostream_iterator<int>(cout, " "));
    cout << endl << endl;

    // 14.
    remove(begin(v), end(v), -1);

    // 15.
    cout << "Innehåll v, efter remove:" << endl;
    copy(begin(v), end(v), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}

bool greater_than(int x, int y)
{
    return y < x;
}
