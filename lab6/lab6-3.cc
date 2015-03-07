#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const string GILTIGT_STARTTECKEN {'"', '('};
const string GILTIGT_SLUTTECKEN  {'"', ',', '.', ':', ';',
                                  '?', '!', ')', '\''};

bool less_tolower(string s1, string s2);

class print_word
{
public:
   print_word() = default;
   print_word(const unsigned int& teckenmax)
      : MAX_TECKEN{teckenmax}, char_count{0}, outstream{cout}
   {}
   print_word(const unsigned int& teckenmax, const ostream& os)
      : MAX_TECKEN{teckenmax}, char_count{0}, outstream{os}
   {}

   void operator()(const string& ord)
   {
      char_count += ord.length() + 1; // öka med ordlängd + mellanrum

      if (char_count > MAX_TECKEN)
      {
         cout << '\n' << ord << " ";
         char_count = ord.length() + 1;
      }
      else
      {
         cout << ord << " ";
      }
   }

private:
   // Maximalt antal tecken per rad.
   const unsigned int MAX_TECKEN {72};
   // Håller koll på antalet tecken per rad.
   unsigned int char_count {0};
   const ostream& outstream {cout};
};

int main()
{
   vector<string> ordv{};
   string ord;

   while (cin >> ord)
   {
      // Ta bort alla giltiga starttecken
      while (ord.find_last_of(GILTIGT_STARTTECKEN, 0) != string::npos)
      {
         ord.erase(0, 1);
      }

      // Ta bort alla giltiga sluttecken
      while (ord.find_first_of(GILTIGT_SLUTTECKEN, ord.size() - 1) !=
             string::npos)
      {
         ord.pop_back();
      }

      // Ta bort engelsk genitivändelse
      if (ord.rfind("'s", ord.length() - 2) != string::npos)
         ord.erase(ord.length() - 2, 1);

      // Kontrollera att strängen endast innehåller bokstäver och bindesstreck
      if (all_of(ord.cbegin(), ord.cend(),
         [](char c){ return (isalpha(c) || c == '-'); }))
      {
         // Om det finns bindesstreck, kontrollera att endast enkla,
         // inneslutna sådana finns och att ordet är minst 2 bokstäver långt
         if ((ord.length() >= 2)    &&
             (ord.front()  != '-')  &&
             (ord.back()   != '-')  &&
             (count(ord.cbegin(), ord.cend(), '-') <= 1))
         {
            ordv.push_back(ord);
         }
      }
   }

   // Sortera
   sort(ordv.begin(), ordv.end(), less_tolower);

   // Ta bort dubletter
   ordv.erase(unique(ordv.begin(), ordv.end()), ordv.end());

   // Skriv ut orden
   for_each(ordv.cbegin(), ordv.cend(), print_word{72, cout});

   cout << endl;

   return 0;
}

bool less_tolower(string s1, string s2)
{
   transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
   transform(s2.begin(), s2.end(), s2.begin(), ::tolower);

   return s1 < s2;
}
