#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

template <typename T>
class Sign_Counter
{
public:
    void operator()(const T& value) const
    {
	if (value > 0) ++pos;
	else if (value < 0) ++neg;
	else  ++zero;
    }

    int pos_count() const { return pos; }
    int neg_count() const { return neg; }
    int zero_count() const { return zero; }

private:
    mutable int pos{0};
    mutable int neg{0};
    mutable int zero{0};
};

int main()
{
    Sign_Counter<int> sc;
    sc = for_each(istream_iterator<int>(cin), istream_iterator<int>{}, sc);
    cout << "Antal positiva tal: " << sc.pos_count()
	 << "\nAntal negativa tal: " << sc.neg_count()
	 << "\nAntal nollor......: " << sc.zero_count();
    return 0;
}
