#include <iostream>
using namespace std;

template <class T> class Stack { 
   private: 
      struct Atom { 
         T data; 
         Atom *next; 
      };
      Atom *head = nullptr; 
   public: 
      bool push(T data); 
      bool pop(T &data); 
};

bool isPalindrome(string str) {
   Stack<char> s;
   char c;
   for(int i = 0; i < str.length(); i++) {
      if (i < (str.length() / 2)) {
         s.push(str[i]);
      } else if (i == (str.length() / 2) && (str.length() % 2) != 0) {
         //none
      } else {
         s.pop(c);
         if (c != str[i])
            return false;
      }
   }
   return true;
}