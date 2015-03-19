/*
 * uppgift4.cc
 */
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <fstream>
#include <iomanip>
using namespace std;

// Definiera print_link h�r
template<typename T>
class print_link
{
public:
    print_link(ostream& os) : os_{&os} {}
    void operator()(const T& x) const
    {
	*os_ << " -> " << x;
    }

private:
    ostream* os_;
};

int main()
{
    vector<int> a{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    vector<double> b{ 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.0 };

    // Anv�nd n�gon l�mplig standardalgoritm f�r att applicera print_link
    // p� elementen i vectorerna a och b vid utskrifterna nedan.

    cout << "vector a inneh�ller:\n";
    // Skriv ut inneh�llet i a p� cout.
    for_each(a.cbegin(), a.cend(), print_link<int>{cout});

    cout << "\nElementen i vector b skrivs p� filen utdata.txt\n";
    // Skriv ut elementen i b p� en textfil med namnet "utdata.txt".
    ofstream utdata{"utdata.txt"};
    utdata << fixed << setprecision(1);
    for_each(b.cbegin(), b.cend(), print_link<double>{utdata});
    utdata.close();

    return 0;
}
