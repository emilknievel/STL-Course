#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iomanip>

using namespace std;

int main()
{
    double mintemp;
    double maxtemp;
    vector<double> minv{};
    vector<double> maxv{};

    while (cin >> mintemp >> maxtemp)
    {
	// 1
	minv.push_back(mintemp);
	maxv.push_back(maxtemp);
    }

    // 2
    fixed(cout << setprecision(1));
    cout << "mintemp: ";
    copy(minv.cbegin(), minv.cend(), ostream_iterator<double>(cout, " "));

    // 3
    cout << '\n' << '\n' << "maxtemp: ";
    copy(maxv.cbegin(), maxv.cend(), ostream_iterator<double>(cout, " "));
    cout << endl << endl;

    // 4
    cout << "lägsta temp: " << *min_element(minv.cbegin(), minv.cend());
    cout << endl << "högsta temp: " << *max_element(maxv.cbegin(), maxv.cend());
    // 5
    vector<double> meanv(minv.size());
    transform(minv.cbegin(), minv.cend(), maxv.cbegin(), meanv.begin(),
	      [](double minval, double maxval)
	      {
		  return ((minval + maxval) / 2);
	      });

    // 6
    cout << endl << endl << "dygnsvisa medeltemp: ";
    copy(meanv.cbegin(), meanv.cend(), ostream_iterator<double>(cout, " "));

    // 7
    double sum{0};
    for (auto it = meanv.cbegin(); it != meanv.cend(); ++it)
    {
	sum += *it;
    }

    cout << endl << endl << "medeltemperatur, månad: " << sum / meanv.size()
	 << endl;

    return 0;
}
