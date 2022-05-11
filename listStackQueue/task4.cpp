#include <iostream>
using namespace std;


template <class T> class Stack {
   public:
      Stack();
      bool push(T item);
      bool pop(T &item);
};

template <class T> class Queue {
   public:
      Queue();
      bool enqueue(T data);
      bool dequeue(T &data);
};
 
template <class T> bool transfer(Stack<T> *s, Queue<T> *q) {
   T i;
   if (s->pop(i)) {
      if (!q->enqueue(i))
         return false;
      return transfer(s, q);
   }
   return true;
} 


template <class T> Queue<T> *selectMultiples(Queue<T> *q, int number) {
   Queue<T> pom = new Queue<T>();
   Queue<T> novi = new Queue<T>();
   int i;
   while(q->dequeue(i)) {
      if (i % number == 0) {
         novi.enqueue(i);
      } else {
         pom.enqueue(i);
      }
   }
   while (pom.dequeue(i))
      q->enqueue(i);
   delete pom;
   return novi;
} 

template <class T> void remove(Stack<T> *s) {
   Stack<T> *s1;
   Stack<T> *s2;
   int el, x;
   while(s->pop(el)) {
      s1->push(el);
      while(s->pop(x))
         if (x != el)
            s2->push(x);
      while(s2->pop(x))
         s->push(x);
   }
   while(s1->pop(el))
      s->push(el);
}
