#include <iostream>
#include <ctime>
using namespace std;

class Stog {
   private: 
      static const int MAX = 10;
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
      bool pop(int &element) {
         if (top < 0) 
            return false;
         element = stack[top--];
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
   for (int i = 0; i < 10; i++) {
      int element = rand() % 10 + 1;
      s->push(element);
   }
   Stog *pomocni = new Stog;
   int el;
   while (s->pop(el))
      pomocni->push(el);

   pomocni->ispis();
   delete s;
   delete pomocni;
   return 0;
}