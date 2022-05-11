#include <iostream>
#include <iomanip>
using namespace std;

double expo(double x, int n, int *fakt, double *xpot) {
   //e^x = sum( x^i / i! ) , i = 0,...,n
   if (n == 0)
      return 1.0;
   return (*xpot) / (*fakt) + expo(x, n - 1, fakt - 1, xpot - 1);
}

int main(void) {
   int n;
   double x;

   cout << "Unesite broj elemenata polja: ";
   cin >> n;
   cout << "Unesite broj x: ";
   cin >> x;

   double *A = new double[n];
   int *fakt = new int[n];
   double *xpot = new double[n];

   fakt[0] = 1;
   xpot[0] = 1.0;

   for (int i = 1; i < n; i++) {
      fakt[i] = fakt[i - 1] * i;
      xpot[i] = xpot[i - 1] * x;
   }
   cout << setprecision(6) << fixed;
   
   for(int i = 0; i < n; i++) {
      A[i] = expo(x, i, &fakt[i], &xpot[i]);
      cout << A[i] << endl;
   }

   return 0;
}