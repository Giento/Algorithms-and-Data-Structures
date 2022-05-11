#include <iostream>
using namespace std;

template <typename T> class Lista {
   private:
      template <class X> struct Cvor {
         X element;
         Cvor<X> *next;
      };

      Cvor<T> *head = nullptr;

   public:
      bool upis(T element)
    {
        Cvor<T> *newElement = new (std::nothrow) Cvor<T>;
        if (!newElement)
            return false;
        newElement->element = element;
        newElement->next = nullptr;
        Cvor<T> **p = &head;
        while ((*p))
        {
            if ((**p).element < element)
                p = &((*p)->next);
            else
                break;
        }

        newElement->next = *p;
        *p = newElement;
        return true;
    }

    void ispis()
    {
        Cvor<T> **p = &head;
        while (*p)
        {
            std::cout << (*p)->element << " ";
            p = &((*p)->next);
        }
        return;
    }
};

int main(void) {
   Lista<int> *l = new Lista<int>;
   for (int i = 1; i <= 10; i++) 
      l->upis(i);
   l->ispis();
   delete l;
   return 0;
}