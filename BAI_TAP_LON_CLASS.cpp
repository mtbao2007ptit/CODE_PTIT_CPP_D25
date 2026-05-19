// Quản lý thông tin sinh viên và môn học như sau:

// - Mỗi môn học gồm:
//     + Mã môn học
//     + Tên môn học
//     + Số tín chỉ

// - Mỗi sinh viên gồm:
//     + Mã sinh viên
//     + Họ tên
//     + Lớp
//     + Danh sách các môn học đăng ký

// Mỗi sinh viên có thể đăng ký K môn học. Với mỗi môn học của sinh viên cần lưu:
//     + Điểm chuyên cần
//     + Điểm kiểm tra
//     + Điểm thi

// Điểm trung bình môn được tính theo công thức:
//     D = 0.1 * CC + 0.2 * KT + 0.7 * Thi

// Điểm trung bình chung của sinh viên được tính theo số tín chỉ:
//     TBC = Σ(Di * TCi) / ΣTCi

// Viết chương trình thực hiện:
// 1. Nhập danh sách N môn học.
// 2. Nhập danh sách M sinh viên.
// 3. Tính điểm trung bình chung cho từng sinh viên.
// 4. In ra danh sách sinh viên có điểm trung bình chung >= 7.
#include <iostream>
using namespace std;

class MonHoc{
    private:
        string ma;
        string ten;
        int tc;
        float diemCC, diemKT, diemThi, diemTB;
    public:
        friend istream& operator >> (istream&, MonHoc&);
        friend ostream& operator << (ostream&, MonHoc);
        string getMa() {
            return ma;
        }
        int getTC() {
            return tc;
        }
        float getDiemTB() {
            return diemTB;
        }
        void nhapDiem() {
            cin >> diemCC >> diemKT >> diemThi;
            diemTB = (diemCC * 10 + diemKT * 20 + diemThi * 70) / 100;
        }
};

istream& operator >> (istream& in, MonHoc &mh) {
    in >> mh.ma;
    getline(in >> ws, mh.ten);
    in >> mh.tc;
    return in;
}

ostream& operator << (ostream& out, MonHoc mh) {
    out << mh.ten << " "
        << mh.diemCC << " "
        << mh.diemKT << " "
        << mh.diemThi << " "
        << mh.diemTB;
    return out;
}

class SinhVien {
    private:
        string ma, ten, lop;
        int soMon;
        float tbc;
        MonHoc *mh;
    public:
        friend istream& operator >> (istream&, SinhVien&);
        friend ostream& operator << (ostream&, SinhVien);
        void nhapMonHoc(MonHoc dsMH[], int n) {
            cin >> soMon;
            mh = new MonHoc[soMon];
            for (int i = 0; i < soMon; i++) {
                string maMH;
                cin >> maMH;
                for (int j = 0; j < n; j++) {
                    if (dsMH[j].getMa() == maMH) {
                        mh[i] = dsMH[j];
                        mh[i].nhapDiem();
                    }
                }
            }
        }
        void tinhTBC() {
            float tong_diem = 0;
            int tong_tc = 0;
            for (int i = 0; i < soMon; i++) {
                tong_diem += mh[i].getDiemTB() * mh[i].getTC();
                tong_tc += mh[i].getTC();
            }
            tbc = tong_diem / tong_tc;
        }
        float getTBC() {
            return tbc;
        }
};

istream& operator >> (istream& in, SinhVien &sv) {
    in >> sv.ma;
    getline(in >> ws, sv.ten);
    in >> sv.lop;
    return in;
}

ostream& operator << (ostream& out, SinhVien sv) {
    out << sv.ma << " "
        << sv.ten << " "
        << sv.lop << endl;
    for (int i = 0; i < sv.soMon; i++) {
        out << sv.mh[i] << endl;
    }
    out << sv.tbc << endl;
    return out;
}

int main() {
    int n, m;
    cin >> n >> m;
    MonHoc dsMH[n];
    SinhVien dsSV[m];
    for (int i = 0; i < n; i++) {
        cin >> dsMH[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> dsSV[i];
        dsSV[i].nhapMonHoc(dsMH, n);
        dsSV[i].tinhTBC();
    }
    for (int i = 0; i < m; i++) {
        if (dsSV[i].getTBC() >= 7) {
            cout << dsSV[i] << endl;
        }
    }

    return 0;
}