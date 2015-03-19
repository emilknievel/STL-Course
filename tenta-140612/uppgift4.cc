/*
 * uppgift4.cc
 */
#include <iostream>
#include <iomanip>

using namespace std;

struct Time
{
    Time(int h, int m, int s) : hour{ h }, min{ m }, sec{ s } {}
    int hour;
    int min;
    int sec;
};

Time operator+(const Time& t1, const Time& t2)
{
    Time temp{0, 0, 0};
    temp.sec = t1.sec + t2.sec;
    while (temp.sec >= 60)
    {
        temp.min++;
        temp.sec -= 60;
    }

    temp.min += t1.min + t2.min;
    while (temp.min >= 60)
    {
        temp.hour++;
        temp.min -= 60;
    }

    temp.hour += t1.hour + t2.hour;

    return temp;
}

Time& operator+=(Time& t1, const Time& t2)
{
    return t1 = t1 + t2;
}

ostream& operator<<(ostream& os, const Time& t)
{
    if (t.hour >= 0) os << t.hour << ":"<< setw(2) << t.min << ":" << setw(2) << t.sec;
    os.fill('0');
    return os;
}

int main()
{
    Time t1{ 1, 59, 59 };
    cout << t1 << '\n';

    Time t2{ 23, 59, 59 };
    cout << t2 << '\n';

    t1 += t2;
    cout << t1 << '\n';

    cout << (t1 + t2) << '\n';

    return 0;
}
