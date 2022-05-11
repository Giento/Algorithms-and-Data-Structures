#include <iostream>
#include <cctype>
using namespace std;


char *ostaviSlova(string ulaz) {
   int brojac = 0;
   for (int i = 0; i < ulaz.length(); i++) {
      if (isalpha(ulaz[i]))
         brojac++;
   }

   char *novi = new char[brojac];
   brojac = 0;
   for (int i = 0; i < ulaz.length(); i++) {
      if (isalpha(ulaz[i])) {
         novi[brojac] = ulaz[i];
         brojac++;
      }
   }
   return novi;
}

int main(void) {
   string ulaz = "asp12_i_ASP13";
   
   char *niz = ostaviSlova(ulaz);

   for(int i = 0; niz[i] != '\0'; i++) {
      cout << niz[i];
   }

   return 0;
}