#include <iostream>
using namespace std;

int provjeri_sortiranost(int *niz, int n) {
   if (n  <= 1)
      return 1;
   if (niz[n - 2] > niz[n - 1])
      return 0;
   return provjeri_sortiranost(niz, n - 1);
}

int main(void) {
   int niz[] = {1, 2, 3};
   if (provjeri_sortiranost(niz, 3))
      cout << "sortiran je" << endl;
   else 
      cout << "nije sortiran";

   return 0;
}