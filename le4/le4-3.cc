/*
 * le-4.3.cc    TDIU04 Lektion 4, uppgift 3
 */
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
using namespace std;

void init_set(istream& is, set<string>& s)
{
   string word;

   while (is >> word)
   {
      s.insert(word);
   }
}

int main(int argc,char* argv[])
{
   if (argc != 3)
   {
      cout << "usage: " << argv[0] << " file1 file2\n";
      return 1;
   }

   ifstream in1{ argv[1] };

   if (!in1)
   {
      cout << argv[0] << ": can't open file " << argv[1] << '\n';
      return 2;
   }

   ifstream in2{ argv[2] };

   if (!in2)
   {
      cout << argv[0] << ": can't open file " << argv[2] << '\n';
      in1.close();
      return 3;
   }

   set<string> set1, set2, res;

   init_set(in1, set1);
   init_set(in2, set2);
    
   set_intersection(begin(set1), end(set1),
		    begin(set2), end(set2),
		    inserter(res, begin(res)));

   cout << "Resultat:\n\n";
   copy(begin(res), end(res), ostream_iterator<string>{ cout, "\n" });
              
   return 0;
}
