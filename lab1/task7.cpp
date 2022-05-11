#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

int *kvadrati(int polje[], int n) {
   int *squared = new int[n];
   srand(time(0));
   bool usedIndex[n] = {};
   int index;

   for (int i = 0; i < n; i++) {
      int x = pow(polje[i], 2);
      do {
         index = rand() % n;
         if (!(usedIndex[index])) {
            squared[index] = x;
         }
      } while(usedIndex[index]);
      usedIndex[index] = true;
   }

   return squared;
}


int main(void) {
   int n;
   cout << "Unesite cijeli broj n: ";
   cin >> n;

   int *polje = new int[n];
   cout << "Unesite clanove polja: " << endl;
   for (int i = 0; i < n; i++)
      cin >> polje[i];

   cout << endl;

   int *novoPolje = new int[n];
   novoPolje = kvadrati(polje, n);

   cout << "Kvadrirani elementi su: " << endl;
   for(int i = 0; i < n; i++)
      cout << novoPolje[i] << endl;

   return 0;
}