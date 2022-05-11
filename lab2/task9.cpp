#include<iostream>

using namespace std;
struct Zapis {
    int PostanskiBroj;
    string naziv;
};
void insertionSort (Zapis A[], int n, char smjer)  {
    int i,j;
    Zapis temp;
    for (i = 1; i < n; i++) {
        temp = A[i];
        for (j = i; j >= 1 && (smjer == '0' && A[j - 1].PostanskiBroj > temp.PostanskiBroj ||
                                smjer == '1' && A[j - 1].PostanskiBroj < temp.PostanskiBroj); j--)
            A[j] = A[j - 1];
        A[j] = temp;
    }

}
int main () {
    int n = 10;
    Zapis zapisi[n];
    cout << " Upisite zapise:" << endl;
    for(int i =0;i<n;i++) {
        string s;
        int broj;
        cin >> broj;
        cin >> s;
        
        zapisi[i] = Zapis{broj,s};
    }
    cout << "Sada zapisi izgledaju ovako " << endl;
    for(int i =0;i<n;i++) {
        cout << zapisi[i].PostanskiBroj << " " << zapisi[i].naziv << endl;

    }
    insertionSort(zapisi,n,'0');
    cout << "Nakon sortiranja zapisi izgledaju ovako " << endl;
    for(int i =0;i<n;i++) {
        cout << zapisi[i].PostanskiBroj << " " << zapisi[i].naziv << endl;

    }
    return 0;
}