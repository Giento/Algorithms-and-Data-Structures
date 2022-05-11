#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

int zbrojiKvadrate(int polje[], int n) {
   int zbroj = 0;
   if (n == 0) {
      return 0;
   }
   if (floor(sqrt(polje[n - 1])) == ceil(sqrt(polje[n - 1])))
      zbroj += polje[n - 1];
   return (zbroj + zbrojiKvadrate(polje, n - 1));
}


int main(void) {
   int n;
   cout << "unesi broj elemenata: ";
   cin >> n;
   int *A = new int[n];
   srand(time(0));
   for (int i = 0; i < n; i++) 
      A[i] = (rand() % 100) + 1;
   
   for (int i = 0; i < n; i++) {
      cout << A[i];
      if (i < n - 1) {
         cout << ", ";
      }
   }

   cout << endl;
   cout << "zbroj kvadrata je: " << zbrojiKvadrate(A, n);

   return 0;
}