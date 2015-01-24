#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

void print_size_and_capacity(const vector<int>& v)
{
    cout << setw(3) << v.size() << setw(10) << v.capacity() << '\n';
}

int main()
{
    cout << "size()  capacity()\n";

    vector<int> v;
    print_size_and_capacity(v);

    v.push_back(1);
    print_size_and_capacity(v);

    v.push_back(2);
    print_size_and_capacity(v);

    v.push_back(3);
    print_size_and_capacity(v);

    v.push_back(4);
    print_size_and_capacity(v);

    v.push_back(5);
    print_size_and_capacity(v);

    vector<int>(v).swap(v);
    print_size_and_capacity(v);

    v.push_back(6);
    print_size_and_capacity(v);

    v.push_back(7);
    print_size_and_capacity(v);

    vector<int>().swap(v);
    print_size_and_capacity(v);

    return 0;
}

// - Efter att ha kompilerat programmet ovan med g+ (t.ex.) och provkört,
//   vad kan vi dra för slutsatser om hur kapaciteten för vector hanteras?

//   Svar: Kapaciteten är 2^x, dvs den är en 2-potens.

// - Det finns två kul saker med medlemsfunktionen swap() inblandad.
//   Vad händer där?

//   Svar: Första: Skapar en kopia av v och byter ut v mot denna.
//         Andra:  

// - I programmet är v en defaultinitierad vector. Deklarera en ny vector
//   och använd den konstruktor som tar en önskad initialstorlek, säg 7,
//   och ett initialvärde för elementen. Kontrollera initiala kapaciteten.

// - Lägg till ett värde i den nya vectorn och kolla kapaciteten.

// - Använd shrink_to_fit() på den nya vectorn och kolla storleken och
//   kapaciteten.
