#include <iostream>
using namespace std;

template <typename T> class Lista {
   template <class X> struct Cvor{
      T element;
      Cvor<X> *prev;
      Cvor<X> *next;
   };

   Cvor<T> *head = nullptr;
   Cvor<T> *tail = nullptr;

   public:
      bool upis(T element) {
         Cvor<T> *newElement = new (nothrow) Cvor<T>;
         if (!newElement)
            return false;
         newElement->element = element;
         newElement->prev = tail;
         newElement->next = nullptr;

         if (tail == nullptr) 
            head = newElement;
         else
            tail->next = newElement;
         tail = newElement;
         return true;
      }

      void ispis() {
         Cvor<T> **p = &head;
         while (*p) {
            cout << (*p)->element << endl;
            p = &((*p)->next);
         }
   	   return;
      }
};

int main(void) {
   Lista<string> *l = new (nothrow) Lista<string>;
   int n;
   cout << "Upisite broj stringova: ";
   cin >> n;
   cout << "Upisite " << n << " stringova: " << endl;
   for (int i = 0; i < n; i++) {
      string s;
      getline(cin, s);
      l->upis(s);
   }
   cout << endl;
   l->ispis();
   return 0;
}