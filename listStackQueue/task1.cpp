#include <iostream>
using namespace std;


template<class T> class Stack {
   private: 
      static const size_t increment = 100;
      size_t size = 100;
      T *stack;
      int top = -1;

   public:
      Stack() { 
         stack = (T*) malloc(size * sizeof(T)); 
      }
      Stack(size_t size) : size(size) {
         stack = (T*) malloc(size * sizeof(T));
      }

      bool push(T item) {
         if (top >= size - 1) {
            T* tmp = (T*) realloc(stack, (size + increment) * sizeof(T));
            if (!tmp)
               return false;
            stack = tmp;
            size += increment;
         }
         stack[++top] = item;
         return true;
      }

      bool pop(T &item) {
         if (top < 0)
            return false;
         item = stack[top--];
         if (top != -1 && top < (int) (size - increment)) {
            T *tmp = (T*) realloc(stack, (size - increment) * sizeof(T));
            if (!tmp)
               return false;
            stack = tmp;
            size -= increment;
         }
         return true;
      }

      bool peek(int &el, int index) {
         Stack<T> pom;
         T j;
         int i = -1;
         bool found = false;
         while(this->pop(j)) {
            pom.push(j);
            i++;
            if (i == index) {
               found = true;
               el = j;
               break;
            }
         }
         while(pom.pop(j)) 
            this->push(j);
         return found;
      }
}; 

template <class T> bool peek(Stack<T> s, T &el) {
   if (!s.pop(el)) {
      return false;
   }
   s.push(el);
   return true;
}