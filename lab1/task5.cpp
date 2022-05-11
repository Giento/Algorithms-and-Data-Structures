#include <iostream>
#include <iomanip>
using namespace std;

template <typename T> int binarnoTrazi (T polje[], int n, T x) {
   int l = 0;
   int r = n - 1;
   while (l <= r) {
      int mid = (l + r) / 2;
      if (abs(x - polje[mid]) < 1e-8)
         return mid;
      else if (x < polje[mid])
         r = mid - 1;
      else 
         l = mid + 1;
   }
   return -1;
}

int main(void) {
   int n;
   cout << "Unesite broj elemenata n: ";
   cin >> n;

   float x;
   cout << "Unesite broj x: ";
   cin >> x;

   float *A = new float[n];
   cout << "Clanovi polja su: ";
   for (int i = 0; i < n; i++) {
      A[i] = i * 1.1;
      if (i == 0)
         cout << A[i];
      else
         cout << ", " << A[i];
   }

   cout << endl;

   int ind = binarnoTrazi(A, n, x);

   if (ind == -1)
      cout << "Broj se ne nalazi u polju";
   else 
      cout << "Broj x nalazi se na indexu " << ind;

   return 0;
}