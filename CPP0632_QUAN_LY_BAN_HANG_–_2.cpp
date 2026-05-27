#include <bits/stdc++.h>
using namespace std;

int dem1 = 0, dem2 = 0, dem3 = 0;

string ma(string ten, int value){
    string tmp = to_string(value);
    while(tmp.size() < 3){
        tmp = "0" + tmp;
    }
    return ten + tmp;
}

class KhachHang{
public:
    static KhachHang ds[25];
    static int n;

    string maKH, tenKH, gt, ns, diachi;

    friend istream& operator >> (istream& in, KhachHang &a){
        a.maKH = ma("KH", ++dem1);
        getline(in >> ws, a.tenKH);
        in >> a.gt >> a.ns;
        getline(in >> ws, a.diachi);
        if(a.ns[2] != '/'){
            a.ns = "0" + a.ns;
        }
        if(a.ns[5] != '/'){
            a.ns.insert(3, "0");
        }
        KhachHang::ds[KhachHang::n++] = a;
        return in;
    }
};

KhachHang KhachHang::ds[25];
int KhachHang::n = 0;

class MatHang{
public:
    static MatHang ds[45];
    static int m;

    string maMH, tenMH, dvt;
    long long mua, ban;

    friend istream& operator >> (istream& in, MatHang &b){
        b.maMH = ma("MH", ++dem2);
        getline(in >> ws, b.tenMH);
        getline(in >> ws, b.dvt);
        in >> b.mua >> b.ban;
        MatHang::ds[MatHang::m++] = b;
        return in;
    }
};

MatHang MatHang::ds[45];
int MatHang::m = 0;

class HoaDon{
public:
    string maHD;
    KhachHang kh;
    MatHang mh;
    long long soluong, loinhuan, thanhtien;

    friend istream& operator >> (istream& in, HoaDon &c){
        c.maHD = ma("HD", ++dem3);
        string maKH, maMH;
        in >> maKH >> maMH >> c.soluong;
        for(int i = 0; i < KhachHang::n; i++){
            if(maKH == KhachHang::ds[i].maKH){
                c.kh = KhachHang::ds[i];
                break;
            }
        }

        for(int i = 0; i < MatHang::m; i++){
            if(maMH == MatHang::ds[i].maMH){
                c.mh = MatHang::ds[i];
                break;
            }
        }

        c.thanhtien = c.soluong * c.mh.ban;
        c.loinhuan = c.soluong * (c.mh.ban - c.mh.mua);

        return in;
    }

    friend ostream& operator << (ostream& out, HoaDon c){
        out << c.maHD << " "
            << c.kh.tenKH << " "
            << c.kh.diachi << " "
            << c.mh.tenMH << " "
            << c.soluong << " "
            << c.thanhtien << " "
            << c.loinhuan << "\n";

        return out;
    }
};

bool cmp(HoaDon a, HoaDon b){
    return a.loinhuan >= b.loinhuan;
}

void sapxep(HoaDon ds[], int k){
    sort(ds, ds + k, cmp);
}

int main(){
    KhachHang dskh[25];
    MatHang dsmh[45];
    HoaDon dshd[105];
    int N,M,K,i;
    cin >> N;
    for(i=0;i<N;i++) cin >> dskh[i];
    cin >> M;
    for(i=0;i<M;i++) cin >> dsmh[i];
    cin >> K;
    for(i=0;i<K;i++) cin >> dshd[i];

    sapxep(dshd, K);

    for(i=0;i<K;i++) cout << dshd[i];
    return 0;
}