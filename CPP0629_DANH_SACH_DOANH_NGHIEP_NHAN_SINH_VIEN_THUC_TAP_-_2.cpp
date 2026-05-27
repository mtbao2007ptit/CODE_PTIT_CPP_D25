#include <bits/stdc++.h>
using namespace std;

class DoanhNghiep{
    public:
        string maDN, tenDN;
        int soSV;
};

bool cmp(DoanhNghiep a, DoanhNghiep b){
    if(a.soSV != b.soSV) return a.soSV > b.soSV;
    return a.maDN < b.maDN;
}

void nhap(DoanhNghiep a[], int n){
    for(int i = 0; i < n; i++){
        cin >> a[i].maDN;
        getline(cin >> ws, a[i].tenDN);
        cin >> a[i].soSV;
    }
}

void in(DoanhNghiep ds[], int n){
    int q; cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        vector<DoanhNghiep> v;
        for(int i = 0; i < n; i++){
            if(ds[i].soSV >= a && ds[i].soSV <= b){
                v.push_back(ds[i]);
            }
        }
        sort(v.begin(), v.end(), cmp);
        cout << "DANH SACH DOANH NGHIEP NHAN TU " << a << " DEN " << b << " SINH VIEN:\n"; 
        for(DoanhNghiep x : v){
            cout << x.maDN << " "
                 << x.tenDN << " "
                 << x.soSV << "\n";
        }
    }
}

int main(){
    DoanhNghiep ds[50];
    int n; cin >> n;
    nhap(ds, n);
    in(ds, n);

    return 0;
}