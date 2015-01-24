#include <iostream>
using namespace std;

#define LOSNING2

#ifdef LOSNING1
int main()
{
    int n{20};

    for (auto i=0; i<n; --n) // Byter ut --i mot --n
    {
        cout << 'x' << endl;
    }

    return 0;
}
#endif

#ifdef LOSNING2
int main()
{
    int n{20};

    for (auto i=0; i<n; --i)
    {
        cout << 'x' << endl;
    }

    return 0;
}
#endif

#ifdef LOSNING3
int main()
{
    int n{20};

    for (auto i=0; i<n; --i)
    {
        cout << 'x' << endl;
    }

    return 0;
}
#endif

// Bonus
// std::endl rensar output buffern, vilket \n inte gör.
