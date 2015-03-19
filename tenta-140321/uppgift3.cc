/*
 * uppgift3.cc
 */
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

// Definiera enum RGB med uppräknarna Red, Green, Blue och NaRGB samt
// undantaget rgb_error och operator<< och operator>> för RGB.
enum RGB {Red, Green, Blue};

class rgb_error : public std::logic_error
{
public:
    explicit rgb_error (const std::string& what_arg)
        : std::logic_error{what_arg} {}
    explicit rgb_error (const char* what_arg)
        : std::logic_error{what_arg} {}
};

ostream& operator<<(ostream& os, const RGB& rgb)
{
    if (rgb == Red) return os << "Red";
    else if (rgb == Green) return os << "Green";
    else if (rgb == Blue) return os << "Blue";
    else return os << "NaRGB";
}

istream& operator>>(istream& is, RGB& rgb)
{
    string input;
    is >> input;

    if (input == "Red") rgb = Red;
    else if (input == "Green") rgb = Green;
    else if (input == "Blue") rgb = Blue;
    else
        throw rgb_error("operator>>: otillåtet RGB-värde");
    return is;
}

int main()
{
    // Test av operator<< för RGB
    for (RGB rgb = Red; rgb <= Blue; rgb = RGB(rgb + 1))
    {
        cout << rgb << '\n';
    }

    // Test av operator>> för RGB och rgb_error
    RGB x;

    cout << "Skriv RGB-värden:\n";
    try
    {
        while (cin >> x)
        {
            cout << x << '\n';
        }
    }
    catch (const exception& e)
    {
	cerr << e.what() << '\n';
    }
    catch (...)
    {
	cerr << "Ett okänt fel har inträffat\n";
    }

    // Lägg ett try-block kring ovanstående while-sats. Om ett undantag
    // kastas ska det fångas, meddelandet som undantaget lagrar skrivas
    // ut och programmet sedan avslutas.

    return 0;
}
