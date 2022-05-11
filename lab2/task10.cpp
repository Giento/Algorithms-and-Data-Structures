#include<iostream>

using namespace std;

void selection2Sort (int A[], int n, char smjer) {
    int i,j,k ,max,min;
    if(smjer == '0') {
        for(int i =0,j = n-1;i<j;i++,j--) {
            int min = A[i];
            int max = A[j];
            int min_index =i;
            int max_index = j;
            for(int k =i;k<=j;k++) {
                if(A[k] > max){
                     max_index = k;
                     max = A[k];
                }

                else if(A[k] < min){
                    min = A[k];
                    min_index = k;
                }
            }
            swap(A[i], A[min_index]);
            if(A[min_index]==max) swap(A[j], A[min_index]);
            else swap(A[j],A[max_index]);
        }
    } else {
      for(int i =0,j = n-1;i<j;i++,j--) {
            int min = A[j];
            int max = A[i];
            int min_index =j;
            int max_index = i;
            for(int k =i;k<=j;k++) {
                if(A[k] > max){
                     max_index = k;
                     max = A[k];
                }

                else if(A[k] < min){
                    min = A[k];
                    min_index = k;
                }
            }
            swap(A[i], A[max_index]);
            if(A[max_index]==min) swap(A[j], A[max_index]);
            else swap(A[j],A[min_index]);
        }
    }
}
int main () {
    int n = 10;
    int A[n];
    for(int i =0;i<n;i++) {
        int broj;
        cin >> broj;
        A[i] = broj;
    }
    selection2Sort(A,n,'1');
    cout << "Sada polje izgleda ovako" << endl;
    for(int i =0;i<n;i++) {
        cout << A[i] << " ";
    }
    return 0;
}