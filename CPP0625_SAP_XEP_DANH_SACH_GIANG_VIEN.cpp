#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

class GiangVien{
    public:
        string maGV, ten, mon;      
};

void in(GiangVien a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i].maGV << " "
             << a[i].ten << " "
             << a[i].mon << "\n";
    }
}

string LayTen(string s){
    stringstream ss(s);
    string word, last;
    while(ss >> word){
        last = word;
    }
    return last;
}

bool cmp(GiangVien a, GiangVien b){
    string tmp = LayTen(a.ten);
    string tmp1 = LayTen(b.ten);
    if(tmp != tmp1) return tmp < tmp1;
    return a.maGV < b.maGV;
}

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

int main(){
    GiangVien ds[50];
    int n; cin >> n;
    nhap(ds, n);
    sort(ds, ds + n, cmp);
    in(ds, n);

    return 0;
}