#include <bits/stdc++.h>
using namespace std;

int dem1 = 0, dem2 = 0, dem3 = 0;

class KhachHang {
    public:
        string maKH, tenKH, gt, ns, diachi;
};

class MatHang {
    public:
        string maMH, tenMH, dvt;
        long long mua, ban;
};

class HoaDon {
    public:
        string maHD;
        KhachHang kh;
        MatHang mh;
        long long soluong;
};

int main() {
    ifstream khFile("KH.in");
    ifstream mhFile("MH.in");
    ifstream hdFile("HD.in");

    KhachHang a[50];
    int n;
    khFile >> n;
    for (int i = 0; i < n; i++) {
        a[i].maKH = to_string(++dem1);
        while (a[i].maKH.size() < 3) {
            a[i].maKH = "0" + a[i].maKH;
        }
        a[i].maKH = "KH" + a[i].maKH;
        getline(khFile >> ws, a[i].tenKH);
        getline(khFile >> ws, a[i].gt);
        getline(khFile >> ws, a[i].ns);
        getline(khFile >> ws, a[i].diachi);
    }

    MatHang b[50];
    int m;
    mhFile >> m;
    for (int i = 0; i < m; i++) {
        b[i].maMH = to_string(++dem2);
        while (b[i].maMH.size() < 3) {
            b[i].maMH = "0" + b[i].maMH;
        }
        b[i].maMH = "MH" + b[i].maMH;
        getline(mhFile >> ws, b[i].tenMH);
        getline(mhFile >> ws, b[i].dvt);
        mhFile >> b[i].mua >> b[i].ban;
    }

    HoaDon c[105];
    int e;
    hdFile >> e;
    for (int i = 0; i < e; i++) {
        c[i].maHD = to_string(++dem3);
        while (c[i].maHD.size() < 3) {
            c[i].maHD = "0" + c[i].maHD;
        }
        c[i].maHD = "HD" + c[i].maHD;
        string x, y;
        hdFile >> x >> y >> c[i].soluong;
        for (int j = 0; j < n; j++) {
            if (a[j].maKH == x) {
                c[i].kh = a[j];
                break;
            }
        }
        for (int j = 0; j < m; j++) {
            if (b[j].maMH == y) {
                c[i].mh = b[j];
                break;
            }
        }
    }

    for (int i = 0; i < e; i++) {
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