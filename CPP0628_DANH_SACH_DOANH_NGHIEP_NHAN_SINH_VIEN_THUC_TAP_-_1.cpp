#include <bits/stdc++.h>
using namespace std;

class DoanhNghiep{
    public:
        string maDN, tenDN;
        int soSV;
};

bool cmp(DoanhNghiep a, DoanhNghiep b){
    if(a.soSV != b.soSV)
        return a.soSV > b.soSV;

    return a.maDN < b.maDN;
}

void nhap(DoanhNghiep a[], int n){
    for(int i = 0; i < n; i++){
        cin >> a[i].maDN;
        getline(cin >> ws, a[i].tenDN);
        cin >> a[i].soSV;
    }
}

void in(DoanhNghiep a[], int n){
    sort(a, a + n, cmp);
    for(int i = 0; i < n; i++){
        cout << a[i].maDN << " "
             << a[i].tenDN << " "
             << a[i].soSV << "\n";
    }
}

int main(){
    DoanhNghiep ds[50];
    int n; cin >> n;
    nhap(ds, n);
    in(ds, n);

    return 0;
}