#include <iostream>
#include <cmath>
using namespace std;

double pi(int n) {
   if(n == 1)
      return 4;
   return (4 * pow(-1., n + 1) / (2. * n - 1.) + pi(n - 1));
}

int main(void) {
   int n;
   cout << "Upisite broj elemenata: ";
   cin >> n;
   cout << endl;
   double *A = new double[n];

   cout << "Svi clanovi polja : " << endl; 

   for (int i = 0; i < n; i++) {
      A[i] = pi(i + 1);
      cout << A[i] << endl;
   }

   cout << endl;
   cout << "vrijednost pi za n = " << n 
      << " iznosi " << A[n - 1]; 

   return 0;
}