#include <iostream>
using namespace std;

class Red {
   private:
      struct Cvor {
         double element;
         Cvor *next;
      };
      Cvor *ulaz = nullptr;
      Cvor *izlaz = nullptr;
   
   public:
      bool dodaj(double broj) {
         Cvor *newElement = new (nothrow) Cvor;
         if (!newElement)
            return false;
         newElement->element = broj;
         newElement->next = nullptr;
         if (!ulaz) 
            izlaz = newElement;
         else 
            ulaz->next = newElement;
         ulaz = newElement;
         return true;
      }

      bool skini(double *broj) {
         if (!izlaz)
            return false;
         *broj = izlaz->element;
         izlaz = izlaz->next;
         if (!izlaz)
            ulaz = nullptr;
         return true;
      }
};

int main(void) {
   int n;
   cout << "Upisite broj elemenata: ";
   cin >> n;

   Red *r = new Red;
   for (int i = 0; i < n; i++) {
      double element;
      cin >> element;
      r->dodaj(element);
   }
   cout << endl;

   double element;
   while(r->skini(&element)) 
      cout << element << " ";

   delete r;
   return 0;
}