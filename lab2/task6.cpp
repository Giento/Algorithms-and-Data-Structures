#include <iostream>
using namespace std;

class Red {
   private:
      static const int MAX = 10;
      double red[MAX];
      int ulaz;
      int izlaz;
   
   public:
      Red() {
         ulaz = 0;
         izlaz = 0;
      }

      bool dodaj(double broj) {
         if ((ulaz + 1) % MAX == izlaz)
            return false;
         red[ulaz] = broj;
         ulaz = (ulaz + 1) % MAX;
         return true;
      }

      bool skini(double *broj) {
         if(ulaz == izlaz)
            return false;
        *broj = red[izlaz];
        izlaz = (izlaz + 1) % MAX;
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