/*
 * cstr_cmp.cc    TDIU04 Fö 5-6
 */
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

struct cstr_cmp
{
   bool operator()(const char* s) { return !strcmp(s, "C++"); }
};

int main()
{
   const char* a[]{ "A", "C++", "CPP", "C++", "Cxx", "ZZZ" };

   auto n = count_if(begin(a), end(a), cstr_cmp());

   cout << "Det finns " << n << " strängar i a som är lika med \"C++\"\n";

   return 0;
}
