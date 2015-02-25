/*
 * exempel-24.cc    TDIU04 Fö 5-6
 */
#include <algorithm>
#include <cstring>
#include <functional>
#include <iostream>
using namespace std;
using namespace std::placeholders;

int main()
{
   const char* a[]{ "A", "C++", "CPP", "C++", "Cxx", "ZZZ" };

   auto n = count_if(begin(a), end(a),
		     not1(function<int(const char*)>(bind(strcmp, _1, "C++")))
                     );

   cout << "Det finns " << n << " strängar i a som är lika med \"C++\"\n";

   return 0;
}
