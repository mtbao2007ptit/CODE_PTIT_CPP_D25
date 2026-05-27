#include <bits/stdc++.h>
using namespace std;

int dem1 = 0, dem2 = 0, dem3 = 0;

class KhachHang{
    public:
        string maKH, tenKH, gt, ns, diachi;
};

class MatHang{
    public:
        string maMH, tenMH, dvt;
        long long mua, ban;
};

class HoaDon{
    public:
        string maHD;
        KhachHang kh;
        MatHang mh;
        long long soluong;
};


int main(){
    KhachHang a[50];
    MatHang b[50];
    HoaDon c[101];

    int n; cin >> n;
    for(int i = 0; i < n; i++){
        ++dem1;
        a[i].maKH = to_string(dem1);
        while(a[i].maKH.size() < 3) a[i].maKH = "0" + a[i].maKH;
        a[i].maKH = "KH" + a[i].maKH;
        getline(cin >> ws, a[i].tenKH);
        cin >> a[i].gt >> a[i].ns;
        getline(cin >> ws, a[i].diachi);
        if(a[i].ns[2] != '/') a[i].ns = "0" + a[i].ns;
        if(a[i].ns[5] != '/') a[i].ns.insert(3, "0");  
    }

    int m; cin >> m;
    for(int i = 0; i < m; i++){
        ++dem2;
        b[i].maMH = to_string(dem2);
        while(b[i].maMH.size() < 3) b[i].maMH = "0" + b[i].maMH;
        b[i].maMH = "MH" + b[i].maMH;
        getline(cin >> ws, b[i].tenMH);
        getline(cin >> ws, b[i].dvt);
        cin >> b[i].mua >> b[i].ban;    
    }

    int k; cin >> k;
    for(int i = 0; i < k; i++){
        ++dem3;
        c[i].maHD = to_string(dem3);
        while(c[i].maHD.size() < 3) c[i].maHD = "0" + c[i].maHD;
        c[i].maHD = "HD" + c[i].maHD;

        string x, y;
        cin >> x >> y >> c[i].soluong;
        
        for(int j = 0; j < n; j++){
            if(x == a[j].maKH){
                c[i].kh = a[j];
                break;
            }
        }  

        for(int j = 0; j < m; j++){
            if(y == b[j].maMH){
                c[i].mh = b[j];
                break;
            }   
        }   
    }

    for(int i = 0; i < k; i++){
        cout << c[i].maHD << " "
             << c[i].kh.tenKH << " "
             << c[i].kh.diachi << " "
             << c[i].mh.tenMH << " "
             << c[i].mh.dvt << " "
             << c[i].mh.mua << " "
             << c[i].mh.ban << " "
             << c[i].soluong << " "
             << c[i].mh.ban * c[i].soluong << "\n";
    }

    return 0;
}