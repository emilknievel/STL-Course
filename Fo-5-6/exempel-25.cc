/*
 * exempel-25.cc    TDIU04 F� 5-6
 */
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
   const char* a[]{ "A", "C++", "CPP", "C++", "Cxx", "ZZZ" };

   auto n = count_if(begin(a), end(a), [](const char* s){ return !strcmp(s, "C++"); });

   cout << "Det finns " << n << " str�ngar i a som �r lika med \"C++\"\n";

   return 0;
}
