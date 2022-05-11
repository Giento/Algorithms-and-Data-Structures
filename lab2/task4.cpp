#include <iostream>
#include <ctime>
using namespace std;

class Stog {
   private:
      struct StogElement{
         int element;
         StogElement *next;
      };
      StogElement *top = nullptr;
   public:
      bool push(int element) {
         StogElement *newElement = new (nothrow) StogElement;
         if (!newElement)
            return false;
         newElement->element = element;
         newElement->next = top;
         top = newElement;
         return true;
      }
      void ispis() {
         StogElement **p = &top;
         while (*p) {
            cout << (*p)->element << endl;
            p = &((*p)->next);
         }
         return;
      }
};

int main(void) {
   Stog *s = new Stog;
   srand(time(NULL));
   for (int i = 0; i < 101; i++) {
      int element = rand();
      s->push(element);
   }
   s->ispis();
   delete s;
   return 0;
}