#include <iostream>
#include <ctime>
using namespace std;

class Stog {
   private: 
      static const int MAX = 100;
      int stack[MAX];
      int top = -1;

   public:
      bool push(int element) {
         top++;
         if (top > MAX - 1) {
            top--;
            return false;
         }
         stack[top] = element;
         return true;
      }

      void ispis() {
         for (int i = 0; i < MAX; i++) {
            cout << stack[i] << endl;
         }
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
   return 0;
}