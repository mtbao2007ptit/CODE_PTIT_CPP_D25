#include <bits/stdc++.h>
using namespace std;

class SinhVien{
    private:
        string maSV, ten, lop, mail;
    public:
        friend ostream& operator << (ostream&, SinhVien);
        friend istream& operator >> (istream&, SinhVien&);
        string getLop(){
            return lop;
        }  
        string getmaSV(){
            return maSV;
        }
};

bool cmp(SinhVien a, SinhVien b){
    if(a.getLop() == b.getLop()) return a.getmaSV() < b.getmaSV();
    return a.getLop() < b.getLop();
}

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

int main(){
    int n;
    cin >> n;
    SinhVien ds[n];
    for(int i = 0; i < n; i++){
        cin >> ds[i];
    }
    sort(ds, ds + n, cmp);
    for(int i = 0; i < n; i++){
        cout << ds[i];
    }
}