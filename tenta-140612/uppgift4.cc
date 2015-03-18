/*
 * uppgift4.cc
 */
#include <iostream>
using namespace std;

struct Time
{
   Time(int h, int m, int s) : hour{ h }, min{ m }, sec{ s } {}
   int hour;
   int min;
   int sec;
};

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
