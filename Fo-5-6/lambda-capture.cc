/*
 * lambda-capture.cc
 */
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main()
{
   vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };

   copy(begin(v), end(v), ostream_iterator<int>{cout, " "});
   cout << endl;

   int x;
   cout << "Hitta alla tal delbara med: ";
   cin >> x;

   v.erase(remove_if(begin(v), end(v), 
		     [x](int i) { return i % x != 0; }), 
	   end(v));

   copy(begin(v), end(v), ostream_iterator<int>{cout, " "});
   cout << endl;

   return 0;
}
