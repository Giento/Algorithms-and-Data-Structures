#include <iostream>
using namespace std;

int poljeEkstrema(int *a, int n) {
   if (n <= 2)
      return 1;
   if (!(((a[n - 3] < a[n - 2]) && (a[n - 2] > a[n - 1]))
      || ((a[n - 3] > a[n - 2]) && (a[n - 2] < a[n - 1])))) 
      return 0;
   return poljeEkstrema(a, n - 1);
}


int main(void) {
   int A[] = {1,3,2,7,4,9,-1,3};
   int B[] = {1,3,2,-2,4,1,-1,3};
   cout << poljeEkstrema(A, 8) << " " << poljeEkstrema(B, 8);
   return 0;
}