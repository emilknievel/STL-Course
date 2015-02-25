/*
 * exempel-18.cc    TDIU04 Fö 5-6
 */
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

class Fibonacci	
{
public:		
   Fibonacci() : F_n(0), F_n1(1) {}

   unsigned long long int operator()() const					
   {
      unsigned long long int next_fib = F_n;
      F_n  = F_n1;		
      F_n1 = next_fib + F_n;
      return next_fib;
   }

private:					
   mutable unsigned long long int F_n;
   mutable unsigned long long int F_n1;	
};

int main()
{
   vector<unsigned long long int> v(21);

   generate(begin(v), end(v), Fibonacci());

   copy(begin(v), end(v), ostream_iterator<unsigned long long int>(cout, " "));
   cout << '\n';

   return 0;
}
