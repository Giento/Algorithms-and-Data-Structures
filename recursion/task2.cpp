#include <iostream>
using namespace std;

template <typename T> class LinearSearchRec: public ISearch<T> {
   public:
      RetValSearch search(const T A[], const size_t n, const T &item) override {
         if (n == 0) {
            bool found = false;
            int index = -1;
            return RetValSearch{found, index};
         }
         if (A[n - 1] == item) {
            bool found = true; 
            int index = n - 1;
            return RetValSearch{found, index};
         }
         return search(A, n - 1, item);
      }
};