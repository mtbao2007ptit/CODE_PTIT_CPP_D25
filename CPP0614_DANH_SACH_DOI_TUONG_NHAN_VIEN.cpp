#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

class NhanVien{
    private:
        string maNV, ten, gt, ns, diachi, maThue, HD;
    public:
        friend ostream& operator << (ostream&, NhanVien);
        friend istream& operator >> (istream&, NhanVien&);      
};

ostream& operator << (ostream& out, NhanVien a){
    out << a.maNV << " "
        << a.ten << " "
        << a.gt << " "
        << a.ns << " "
        << a.diachi << " "
        << a.maThue << " "
        << a.HD << "\n";
    return out;
}

istream& operator >> (istream& in, NhanVien &a){
    ++cnt;
    a.maNV = to_string(cnt);
    while(a.maNV.size() < 5) a.maNV = "0" + a.maNV;
    getline(in >> ws, a.ten);
    in >> a.gt >> a.ns;
    getline(in >> ws, a.diachi);
    in >> a.maThue >> a.HD;
    return in;
}

int main(){
    NhanVien ds[50];
    int N,i;
    cin >> N;
    for(i=0;i<N;i++) cin >> ds[i];
    for(i=0;i<N;i++) cout << ds[i];
    return 0;
}