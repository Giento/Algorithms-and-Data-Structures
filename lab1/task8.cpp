#include <iostream>
#include <cctype>
using namespace std;


class SanitizedString {
   private: 
      string str;

   public:
      SanitizedString(string ulaz) {
         str = ulaz;
         removeDuplicateWhitespace();
         removeNonAlphaChars();
      }

      void removeDuplicateWhitespace() {
         for (int i = 1; i < str.length(); i++) {
            if (str[i - 1] == ' ' && str[i] == ' ') {
               str.erase(str.begin() + i);
               i--;
            }
         }
      }

      void removeNonAlphaChars() {
         for (int i = 0; i < str.length(); i++) {
            if (!(isalpha(str[i]))) {
                str.erase(str.begin() + i);
                i--;
            }
         }
      }

   friend ostream &operator<<(ostream &os, SanitizedString &str){
      os << str.str;
      return os;
   }
};


int main(void) {
   string s;
   cout << "Unesite znakovni niz: " << endl;
   getline(cin, s);

   SanitizedString sanitized(s);

   cout << sanitized << endl;

   return 0;
}