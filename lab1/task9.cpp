#include <iostream>
#include <cmath>
using namespace std;

void f(int polje[], int n, int m) {
   if (n >= 1) {
      polje[n - 1] = pow(m, n - 1);
      //rekurzija
      f(polje, n - 1, m);
   }
}


int main(void) {
   int n, m;
   cout << "Unesite cijele brojeve n i m: ";
   cin >> n >> m;

   int *A = new int[n];
   f(A, n, m);
   for(int i = 0; i < n; i++) {
      cout << A[i] << endl;
   }
   return 0;
}