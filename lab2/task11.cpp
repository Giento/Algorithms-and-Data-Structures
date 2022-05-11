#include<iostream>

using namespace std;
struct zapis {
    int sifra;
    string naziv;

};
void obicanBubbleSort (zapis A[], int n, char smjer) {
    int i,j;
    if(smjer == '0') {
    for(i =0;i<n-1;i++) {
        for(j = 0;j<n-1-i;j++) {
            if(A[j+1].sifra < A[j].sifra) {
                swap(A[j+1] , A[j]);
            }
        }
    }
    } else {
         for(i =0;i<n-1;i++) {
        for(j = 0;j<n-1-i;j++) {
            if(A[j+1].sifra > A[j].sifra) {
                swap(A[j+1] , A[j]);
            }
        }
    }

    }
}
int main () {
    int n = 10;
    zapis zapisi[n];
    cout << "Upisite zapise ";
    for(int i =0;i<n;i++) {
        int n;
        string s;
        cin >> n >> s;
        zapisi[i] = zapis{n,s};
    }
    obicanBubbleSort(zapisi,n,'0');
    cout << "Sada polje izgleda ovako :"<< endl;
    for(int i =0;i<n;i++) {
        cout << zapisi[i].sifra << " " << zapisi[i].naziv << endl;
    }
    return 0;
}
