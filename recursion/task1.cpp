#include <iostream>
using namespace std;

int kvazi_binomni(int n, int m) {
    if ((n < 0) || (m > n)) 
      return 0; 
    if ((m == 0) || (n == m)) 
      return 1; 
    return kvazi_binomni(n - 1, m - 1) + m * kvazi_binomni(n - 1, m + 1); 
}

int main(void) {
   int n, m;
   cin >> n >> m;
   cout << kvazi_binomni(n, m);
   return 0;
}