#include <iostream>
using namespace std;


template <class T> class List { 
   private: 
      struct Atom { 
         T data; 
         Atom *next; 
      }; 
      Atom *head = nullptr; 
   public: 
      bool insert(T data);    //dod. na početak 

      void kopirajParne(List<T> &dstList) {
         Atom *dstListTail = nullptr;
         for (auto curr = head; curr != nullptr; curr = curr->next) {
            if (curr->data % 2 == 0) {
               Atom *newAtom = new (nothrow) Atom;
               if (newAtom == nullptr)
                  return;
               newAtom->data = curr->data;
               newAtom->next = nullptr;

               if (dstListTail == nullptr) {
                  dstList.head = newAtom;
                  dstListTail = newAtom;
                  dstListTail->next = nullptr;
               } else {
                  dstListTail->next = newAtom;
                  dstListTail = dstListTail->next;
               }
            }
         }

      }
};