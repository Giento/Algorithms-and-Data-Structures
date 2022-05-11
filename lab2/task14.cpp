#include<iostream>
#include<string>
using namespace std;

void Zamijeni(string *prvi, string *drugi) {
    string s;
    s = *prvi;
    *prvi = *drugi;
    *drugi = s;

}
void BubbleSortPoboljsani(string A[], int N, int smjer) {
    int i,j;
    bool SwapHappened = 1;
    if(smjer = 1) {
        for(i =0;SwapHappened == 1;i++) {
            SwapHappened = 0;
            for(j =0;j<N-1-i;j++) {
                if(A[j+1].compare(A[j]) < 0) {
                    Zamijeni(&A[j],&A[j+1]);
                    SwapHappened = 1;
                }
            }
        }
    } else {
        for(i =0;SwapHappened == 1;i++) {
            SwapHappened = 0;
            for(j =0;j<N-1-i;j++) {
                if(A[j+1].compare(A[j]) > 0) {
                    Zamijeni(&A[j],&A[j+1]);
                    SwapHappened = 1;
                }
            }
        }

    }

}

int main () {
    int n = 5;
    string polje[n];
    for(int i = 0;i<n;i++) {
        string s;
        cin >> s;
        polje[i] = s;
    }
    BubbleSortPoboljsani(polje,n,1);
    cout << "Sada polje izglda ovako " << endl;
    for(int i = 0;i<n;i++) {
        cout << polje[i]<<endl;
    }
    return 0;
}
