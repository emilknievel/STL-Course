/*
 * le1-3.cc    TDIU04 Lektion 1, uppgift 3
 */
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        cout << "använd: " << argv[0] << " infil utfil\n";
        return 1;
    }

    ifstream input{ argv[1] };

    if (!input)
    {
        cout << "filen " << argv[1] << " kunde ej öppnas\n";
        return 2;
    }

    ofstream output{ argv[2] };

    if (!output)
    {
        cout << "filen " << argv[2] << " kunde ej öppnas.\n";
        input.close();
        return 3;
    }

    vector<string> v;

    istream_iterator<string> start{ input };
    istream_iterator<string> end_of_file;

    copy(start, end_of_file, back_inserter(v));
    input.close();

    cout << "Före sortering: ";
    copy(begin(v), end(v), ostream_iterator<string>{cout, " "});
    cout << '\n';

    sort(begin(v), end(v));

    cout << "\nEfter sortering: ";

    copy(begin(v), end(v), ostream_iterator<string>{cout, " "});
    cout << '\n';

    // Spara på fil
    copy(begin(v), end(v), ostream_iterator<string>{output, "\n"});
    output.close();

    return 0;
}

/*
 * Alternativ inläsning 1:
 *
 *    istream_iterator<string> start{ input };
 *    istream_iterator<string> end_of_file;
 *    vector<string> v{ start, end_of_file };
 *
 * Alternativ inläsning 2:
 *
 *    vector<string> v{ istream_iterator<string>{input}, istream_iterator<string>{}  };
 */
