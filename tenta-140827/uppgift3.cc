/*
 * uppgift3.cc
 */
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <functional>

using namespace std;

// Definiera Poly_2 här
template<typename T, typename K>
class Poly_2
{
public:
    Poly_2(const K& a, const K& b, const K& c) : A{a}, B{b}, C{c} {}

    T operator()(const T& x, const T& y) const
    {
            return A*x*x + B*y + C;
    }

private:
    const K A;
    const K B;
    const K C;
};


int main()
{
    // Lite hjälp på traven med indata...
    vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    ostream_iterator<int> output(cout, " ");

    // Använd algoritmen transform för att testa Poly_2
    transform(v.begin(), v.end(), v.rbegin(), output, Poly_2<int, short>{2, 5, 1});
    cout << endl;

    return 0;
}
