#include <bits/stdc++.h>
using namespace std;

class SinhVien{
    private:
        string maSV, ten, lop, mail;
    public:
        friend ostream& operator << (ostream&, SinhVien);
        friend istream& operator >> (istream&, SinhVien&);
        string getLOP(){
            return lop;
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

int main(){
    SinhVien ds[1001];
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> ds[i];
    }
    int q; cin >> q;
    while(q--){
        string tmp; cin >> tmp;
        cout << "DANH SACH SINH VIEN KHOA " << tmp << ":" << "\n";
        for(int i = 0; i < n; i++){
            if(ds[i].getLOP().substr(1, 2) == tmp.substr(2, 2)){
                cout << ds[i];
            }
        }
    }

    return 0;
}