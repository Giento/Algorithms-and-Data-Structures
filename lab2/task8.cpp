#include <iostream>
#include <ctime>
using namespace std;

class Red {
   struct Cvor {
      int broj;
      Cvor *next;
   };

   Cvor *ulaz = nullptr;
   Cvor *izlaz = nullptr;

   public:
      bool dodaj(int broj) {
         Cvor *newElement = new (nothrow) Cvor;
         if (!newElement)
            return false;
         newElement->broj = broj;
         newElement->next = nullptr;
         if (ulaz == nullptr)
            izlaz = newElement;
         else
            ulaz->next = newElement;
         ulaz = newElement;
         return true; 
      }

      bool poljeURed(int polje[], int n) {
         if (n < 1)
            return true;
         else if (dodaj(polje[n - 1])) {
            cout << "Dodavanje " << n << ". elementa u red: " << polje[n - 1] << endl;
            return poljeURed(polje, n - 1);
         }
         return false;
      }
};

int main(void) {
   Red *r = new (nothrow) Red;
   int arr[10];
   srand(time(NULL));
   for (int i = 0; i < 10; i++) {
      arr[i] = rand() % 10 + 1;
      if (i != 9)
         cout << arr[i] << ", ";
      else 
         cout << arr[i] << endl;
   }

   r->poljeURed(arr, 10);
   
   delete arr;
   delete r;
   return 0;
}