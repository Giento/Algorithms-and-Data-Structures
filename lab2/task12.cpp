#include<iostream>

using namespace std;

class Osoba {
    private :
    string ime;
    unsigned short int godine;
    public:
    Osoba() : ime(), godine(0) {};
    Osoba(string ime,unsigned short int godine) : ime(ime), godine(godine) {};
    ~Osoba(){}

    string getIme() {
        return ime;
    }
    void setIme(string ime) {
        this->ime = ime;
    }
    unsigned short int getGodine() {
        return godine;
    }
    void setGodine(int godine) {
        this->godine = godine;
    }
    bool operator<(const Osoba &other) const {
        int i = other.godine - godine;
        if(i == 0) i = other.ime[0]- ime[0];
        if(i < 0) return false;
        return true;
    }
    Osoba& operator=(Osoba other) noexcept {
    swap(ime, other.ime); 
    swap(godine, other.godine);
    return *this;
    } 
};
template <class T>
void InsertionSort(T A[], int N) {
    int i,j;
    T temp;
    for(int i =1;i<N;i++) {
        temp = A[i];
        for(j = i;j >= 1 && temp<A[j-1];j--) {
            A[j] = A[j-1];
        }
        A[j] = temp;
    }

}
int main() {
    int n = 5;
    Osoba osobe[n];
    for(int i =0;i<n;i++) {
        string s;
        unsigned short int godine;
        cin >> s >> godine;
        osobe[i] = Osoba(s,godine);
    }
    InsertionSort(osobe,n);
    cout << "Sada polje izgleda ovako" << endl;
    for(int i =0;i<n;i++) {
        cout << osobe[i].getIme() << " " << osobe[i].getGodine() << endl;
    }
    return 0;
}