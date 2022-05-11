#include <iostream>
using namespace std;

template<class T> class Queue {
   private:
      static const int MAX = 100;
      T queue[MAX];
      int read = 0;
      int write = 0;

   public:
      bool enqueue(T item) {
         if ((write + 1) % MAX == read) 
            return false;
         queue(write) = item;
         write = (write + 1) % MAX;
         return true;
      }

      bool dequeue(T &item) {
         if (write == read) 
            return false;
         item = queue[read];
         read = (read + 1) % MAX;
         return true;
      }

      int count() {
         if (write >= read)
            return (write - read);
         else 
            return (write - read + MAX);
      }

      bool peek(int &el) {
         Queue<T> pom;
         T i;
         if (!this->dequeue(i)) 
            return false;
         el = i;
         pom.enqueue(i);
         while(this->dequeue(i))
            pom.enqueue(i);
         while(pom.dequeue(i))
            this->enqueue(i);
         return true;
      }

      bool peek(int &el, int index) {
         Queue<T> pom;
         T i;
         int j = -1;
         bool found = false;
         if (!this->dequeue(i)) 
            return false;
         j++;
         if (j == index) {
            el = i;
            found = true;
         }
         pom.enqueue(i);
         while(this->dequeue(i)) {
            i++;
            if (i == index) {
               el = i;
               found = true;
            }
            pom.enqueue(i);
         }
         while(pom.dequeue(i))
            this->enqueue(i);
         return found;
      }
      
};