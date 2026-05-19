#include <bits/stdc++.h>
using namespace std;

class SinhVien{
    private:
        string maSV, ten, lop, mail;
    public:
        friend ostream& operator << (ostream&, SinhVien);
        friend istream& operator >> (istream&, SinhVien&);
        string getMASV(){
            return maSV;
        }
};

ostream& operator << (ostream& out, SinhVien a){
    out << a.maSV << " "
        << a.ten << " "
        << a.lop << " "
        << a.mail << "\n";
    return out;
}

istream& operator >> (istream& in, SinhVien &a){
    in >> a.maSV;
    getline(in >> ws, a.ten);
    in >> a.lop >> a.mail;
    return in;
}

bool cmp(SinhVien a, SinhVien b){
    return a.getMASV() < b.getMASV();
}

int main(){
    SinhVien ds[1000];
    int n = 0;
    while(cin >> ds[n]){
        n++;
    }
    sort(ds, ds + n, cmp);
    for(int i = 0; i < n; i++){
        cout << ds[i];
    }

    return 0;
}