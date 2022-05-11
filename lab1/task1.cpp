#include <iostream>
using namespace std;

static int brojac = 0;

void ispis(float polje[], int n) {
   if (n != 0) {
      ispis(polje, n - 1);
   }
   if (polje[n] < 0) {
      if (brojac == 0)
         cout << polje[n];
      else 
         cout << ", " << polje[n];
      brojac++;
   }
}


int main(void) {
   int n;
   cin >> n;
   float *A = new float[n];
   for (int i = 0; i < n; i++) {
      cin >> A[i];
   }
   ispis(A, n);

   return 0;
}