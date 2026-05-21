#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

class GiangVien{
    public:
        string maGV, ten, mon;
};

void nhap(GiangVien a[], int n){
    for(int i = 0; i < n; i++){
        ++cnt;
        a[i].maGV = to_string(cnt);
        while(a[i].maGV.size() < 2) a[i].maGV = "0" + a[i].maGV;
        a[i].maGV = "GV" + a[i].maGV;
        getline(cin >> ws, a[i].ten);
        getline(cin >> ws, a[i].mon);
        stringstream ss(a[i].mon);
        string word, res = "";
        while(ss >> word){
            res += toupper(word[0]);
        }
        a[i].mon = res;
    }
}

void in(GiangVien a[], int n){
    int q; cin >> q;
    while(q--){
        string tmp;
        getline(cin >> ws, tmp);
        stringstream ss(tmp);
        string x, word = "";
        while(ss >> x){
            word += toupper(x[0]);            
        }
        cout << "DANH SACH GIANG VIEN BO MON " << word << ":" << "\n";
        for(int i = 0; i < n; i++){
            if(a[i].mon == word){
                cout << a[i].maGV << " "
                     << a[i].ten << " "
                     << a[i].mon << "\n";
            }
        }
    }
}

int main(){
    GiangVien ds[50];
    int n; cin >> n;
    nhap(ds, n);
    in(ds, n);

    return 0;
}