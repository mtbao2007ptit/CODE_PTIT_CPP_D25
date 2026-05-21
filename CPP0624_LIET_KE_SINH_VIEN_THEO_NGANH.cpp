#include <bits/stdc++.h>
using namespace std;

class SinhVien{
    private:
        string maSV, ten, lop, mail;
    public:
        friend ostream& operator << (ostream&, SinhVien);
        friend istream& operator >> (istream&, SinhVien&);
        string getmaSV(){
            return maSV;
        }
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
        string tmp; getline(cin >> ws, tmp);
        string tenNganh = "";
        for(char &x : tmp){
            x = toupper(x);
        }
        if(tmp == "KE TOAN") tenNganh = "DCKT";
        else if(tmp == "CONG NGHE THONG TIN") tenNganh = "DCCN";
        else if(tmp == "AN TOAN THONG TIN") tenNganh = "DCAT";
        else if(tmp == "VIEN THONG") tenNganh = "DCVT";
        else if(tmp == "DIEN TU") tenNganh = "DCDT";
        cout << "DANH SACH SINH VIEN NGANH " << tmp << ":\n";
        for(int i = 0; i < n; i++){
            if(ds[i].getmaSV().substr(3, 4) == tenNganh){
                if((tenNganh == "DCCN" || tenNganh == "DCAT")
                    && ds[i].getLOP()[0] == 'E'){
                    continue;
                }
                cout << ds[i];
            }
        }
    }

    return 0;
}