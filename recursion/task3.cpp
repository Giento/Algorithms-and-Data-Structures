#include <iostream>
using namespace std;

float kamrac(float g, float p, int n, float rez) {
   if (n == 0)
      return g * rez;
   float percentage = (1 + p/100);
   rez *= percentage;
   return kamrac(g, p, n - 1, rez); 
}

int main(void) {
   cout << kamrac(1000.0, 5.0, 5, 1.0);
   return 0;
}