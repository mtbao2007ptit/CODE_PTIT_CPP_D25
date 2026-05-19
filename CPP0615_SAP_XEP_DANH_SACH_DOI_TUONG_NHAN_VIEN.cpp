#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

class NhanVien{
    private:
        string maNV, ten, gt, ns, diachi, maThue, HD;
    public:
        friend ostream& operator << (ostream&, NhanVien);
        friend istream& operator >> (istream&, NhanVien&);
        string getNS(){
            return ns;
        }
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
    if(a.ns[2] != '/') a.ns = "0" + a.ns;
    if(a.ns[5] != '/') a.ns.insert(3, "0");
    getline(in >> ws, a.diachi);
    in >> a.maThue >> a.HD;
    if(a.HD[2] != '/') a.HD = "0" + a.HD;
    if(a.HD[5] != '/') a.HD.insert(3, "0");
    return in;
}

bool cmp(NhanVien a, NhanVien b){
    string x = a.getNS();
    string y = b.getNS();
    x = x.substr(6) + x.substr(0, 2) + x.substr(3, 2);
    y = y.substr(6) + y.substr(0, 2) + y.substr(3, 2);
    return x < y;
}

void sapxep(NhanVien a[], int n){
    sort(a, a + n, cmp);
}

int main(){
    NhanVien ds[50];
    int N,i;
    cin >> N;
    for(i=0;i<N;i++) cin >> ds[i];
    sapxep(ds, N);
    for(i=0;i<N;i++) cout << ds[i];
    return 0;
}