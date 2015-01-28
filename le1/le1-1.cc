/*
 * le1-1.cc    TDIU04 Lektion 1, uppgift 1
 */
#include <algorithm>
#include <cstring>
#include <iostream>
#include <iterator>
#include <string>
using namespace std;

int main()
{
   const int LINE_BUFFER_SIZE{ 32 } ;  // Max 32 tecken per rad, inkl. '\0'.

   char buffer[LINE_BUFFER_SIZE];

   while (cin.getline(buffer, LINE_BUFFER_SIZE))
   {
      reverse(buffer, buffer + strlen(buffer));
      cout << buffer << '\n';

      string line;

      copy(buffer, buffer + strlen(buffer), back_inserter(line));

      reverse(line.begin(), line.end());

      cout << line << '\n';
   }

   return 0;
}
