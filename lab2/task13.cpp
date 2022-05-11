#include<iostream>
#include<string>

using namespace std;

class Vozilo {
    private: 
    string model;
    int godina;
    public :
    Vozilo(string model, int godina) : model(model), godina(godina) {}
    Vozilo() : model(" "), godina(0) {}
    ~Vozilo() {}

    string getModel() {
        return model;
    }
    int getGodina() {
        return godina;
    }
    void setModel(string model) {
        this->model = model;
    } 
    void setGodina(int godina) {
        this->godina = godina;
    }
    bool operator<(const Vozilo &other) {
       int i = model.compare(other.model);
        if (i == 0) i = other.godina - godina;
        if (i < 0) return true;
        return false;
    }
    Vozilo& operator=(Vozilo other) noexcept {
        swap(godina,other.godina);
        swap(model,other.model);
        return *this;
    }
    
   

};
void Zamijeni(Vozilo &prvi, Vozilo &drugi) noexcept {
        Vozilo v = prvi;
        prvi = drugi;
        drugi = v;
}
template <class T> static void SelectionSort(T A[], int N) {
    int i,j,min;
    for(int i =0;i<N;i++) {
        min = i;
        for(int j = i+1;j<N;j++) {
            if(A[j]< A[min]) min = j;
        }
        Zamijeni(A[i],A[min]);
    }
}
int main () {
    int n = 5;
    Vozilo A[n];
    for(int i =0;i<n;i++) {
        string s;
        int god;
        cin >> s >> god;
        A[i] = Vozilo(s,god);

    }
    SelectionSort(A,n);
    cout << "Sada polje izgleda ovako "<<endl;
    for(int i =0;i<n;i++) {
        cout << A[i].getModel() << " " << A[i].getGodina() << endl;
    }
    return  0;
}