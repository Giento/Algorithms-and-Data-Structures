#include <iostream>
using namespace std;

int provjeriZagrade(char *niz, int *zastavica) {
   if (*niz == '\0') {
      return (*zastavica == 0 ? 1 : 0);
   } else {
      if (*niz == '[')
         ++(*zastavica);
      else
         --(*zastavica);
      return provjeriZagrade(niz + 1, zastavica);
   }
}


int main(void) {
   int zastavica = 0;
   char A[] = {'[', '[', ']'};
   cout << provjeriZagrade("[[]", &zastavica) ? 
      "Sve zagrade su uparene" : "Neke zagrade nisu uparene";
   return 0;
}