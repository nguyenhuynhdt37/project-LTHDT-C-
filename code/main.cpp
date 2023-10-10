#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
#include "graphics.h"
using namespace std;
bool check;
class Vector
{
private:
    int m;
    double *v;

public:
    Vector();
    Vector(int);
    ~Vector() { delete v; }
    void add();
    void add(ifstream &);
    void xuat();
    void xuat(ofstream &file);
    Vector(const Vector &A);
    void ktra_Vector_doiXung();
    void ktra_Vector_hoanVi();
    friend Vector Cong_2_Vector(Vector &, Vector &);
    friend Vector Tru_2_Vector(Vector &, Vector &);
    friend Vector Nhan_2_Vector(Vector &, Vector &);
    friend Vector nhan_1_so_voi_1_vector(Vector &, double &);
    int getM() { return m; }
};
Vector::Vector(const Vector &A)
{
    this->m = A.m;
    this->v = new double[m];
    for (int i = 0; i < m; i++)
    {
        v[i] = A.v[i];
    }
}
Vector::Vector()
{
    this->m = 0;
    this->v = nullptr;
}
Vector::Vector(int m)
{
    this->m = m;
    this->v = new double[m];
}
void Vector::add()
{
    cout << "\t\t\t\t\t\t\tnhap so luong cac phan tu trong vector: ";
    cin >> m;
    this->v = new double[m];
    for (int i = 0; i < m; i++)
    {
        cout << "\t\t\t\t\t\t\tnhap phan tu thu " << i + 1 << ": ";
        cin >> v[i];
    }
}
void Vector::add(ifstream &file)
{
    file >> m;
    this->v = new double[m];
    for (int i = 0; i < m; i++)
    {
        file >> v[i];
    }
}
Vector Cong_2_Vector(Vector &A, Vector &B)
{
    check = true;
    Vector C(A.m);
    if (A.m != B.m)
    {
        check = false;
        cout << "\t\t\t\t\t\t\t2 Vector khong cung cap";
    }
    if (check == true)
    {

        for (int i = 0; i < A.m; i++)
        {
            C.v[i] = 0;
            C.v[i] = A.v[i] + B.v[i];
        }
    }
    return C;
}

Vector Tru_2_Vector(Vector &A, Vector &B)
{
    Vector C(A.m);
    check = true;
    if (A.m != B.m)
    {
        check == false;
        cout << "\t\t\t\t\t\t\t2 Vector khong cung cap ";
    }
    if (check = true)
    {

        for (int i = 0; i < A.m; i++)
        {
            C.v[i] = A.v[i] - B.v[i];
        }
        return C;
    }
}
Vector Nhan_2_Vector(Vector &A, Vector &B)
{
    check = true;
    Vector C(A.m);
    if (A.m != B.m)
    {
        check = false;
        cout << "\t\t\t\t\t\t\t2 Vector khong cung cap ";
    }
    if (check == true)
    {
        for (int i = 0; i < A.m; i++)
        {
            C.v[i] = A.v[i] * B.v[i];
        }
    }
    return C;
}
Vector nhan_1_so_voi_1_vector(Vector &A, double &x)
{
    check = true;
    for (int i = 0; i < A.m; i++)
    {
        A.v[i] *= x;
    }
    return A;
}
void Vector::ktra_Vector_doiXung()
{
    check = true;
    for (int i = 0; i < m / 2; i++)
    {
        if (v[i] != v[m - 1 - i])
        {
            check = false;
        }
    }
    if (check == false)
    {
        cout << "\t\t\t\t\t\t\tVector tren khong phai la Vector doi xung";
    }
    else
    {
        cout << "\t\t\t\t\t\t\tVector tren la Vector doi xung";
    }
}
void Vector::ktra_Vector_hoanVi()
{
    check = true;
    for (int i = 0; i < m - 1; i++)
        for (int j = i + 1; j < m; j++)
        {
            if (v[i] == v[j])
            {
                check = false;
            }
        }
    if (check == false)
    {
        cout << "\t\t\t\t\t\t\tVector tren khong phai la Vector hoan vi";
    }
    else
    {
        cout << "\t\t\t\t\t\t\tVector tren la Vector hoan vi";
    }
}
void Vector::xuat(ofstream &file)
{
    file << "\t\t\t";
    for (int i = 0; i < m; i++)
    {
        file << v[i] << " ";
    }
    if (m == 1)
    {
        file << "\t\t\t\t";
    }
    if (m == 2)
    {
        file << "\t\t\t";
    }
    if (m == 3)
    {
        file << "\t\t\t";
    }
    if (m == 4)
    {
        file << "\t\t";
    }
    if (m == 5)
    {
        file << "\t\t";
    }
    if (m == 6)
    {
        file << "\t  ";
    }
    if (m == 7)
    {
        file << "\t";
    }
    file << "\t\t\t\t  |";
    file << endl;
    file << setw(15) << left << "|_______|________________|____________________________________________|" << endl;
}
void Vector::xuat()
{
    for (int i = 0; i < m; i++)
    {
        cout << v[i] << " ";
    }
}
void show_danh_sach_Vector(vector<Vector> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << "\t\t\t\t\t\t\tVECTOR THU " << i + 1 << ": ";
        arr[i].xuat();
        cout << endl;
    }
}
void xuat_mang_file_Vector(ofstream &file, vector<Vector> &arr)
{

    file.open("Output_Mang_VECTOR.docx", ios::out);
    file << "\t\t\t\t=== Hien thi danh sach Vector ===" << endl;
    file << setw(15) << left << "_______________________________________________________________________" << endl;
    file << setw(8) << "| STT";
    file << setw(16) << "|   SO PHAN TU   ";
    file << setw(15) << "|    \t\t        GIA TRI     \t\t\t  |" << endl;
    file << setw(15) << left << "|_______|________________|____________________________________________|" << endl;
    for (int i = 0; i < arr.size(); i++)
    {

        file << setw(2) << "|  " << i + 1 << "\t|\t\t";
        file << setw(7) << arr[i].getM() << "\t |";
        arr[i].xuat(file);
    }
    file.close();
}
void xuat_vector_dacbiet_or_tinh_toan(Vector &A, ofstream &file)
{
    file << setw(15) << left << "_______________________________________________________________________" << endl;
    file << setw(8) << "| STT";
    file << setw(16) << "|   SO PHAN TU   ";
    file << setw(15) << "|    \t\t        GIA TRI     \t\t\t  |" << endl;
    file << setw(15) << left << "|_______|________________|____________________________________________|" << endl;
    file << setw(2) << "|  " << 1 << "\t|\t\t";
    file << setw(7) << A.getM() << "\t |";
    A.xuat(file);
    file.close();
}
void input_Vector(ifstream &file, vector<Vector> &arr)
{
    check = false;
    int sl;
    file.open("input_Vector.txt", ios::in);
    if (file.fail() == true)
    {
        cout << "\t\t\t\t\t\t\tKhong the mo file\n";
    }
    else
    {
        check = true;
        file >> sl;
        file.ignore();
        for (int i = 0; i < sl; i++)
        {
            Vector a;
            a.add(file);
            file.ignore();
            arr.push_back(a);
        }
        file.close();
        cout << "\t\t\t\t\t\t\tDa nhap file thanh cong\n";
    }
}
//=====================================================================================================
class Matrix
{
private:
    int m;
    int n;
    double **v;

public:
    Matrix();
    Matrix(int, int);
    Matrix(int, int, double **);
    void add(ifstream &);
    void xuat();
    void xuat(ofstream &);
    void add();
    friend Matrix Cong_2_Ma_Tran(Matrix &, Matrix &);
    friend Matrix Tru_2_Ma_Tran(Matrix &, Matrix &);
    friend Matrix Nhan_2_Ma_Tran(Matrix &, Matrix &);
    friend Matrix Nhan_1_so_voi_1_Ma_Tran(Matrix &, double &);
    friend Matrix MA_Tran_chuyen_vi(Matrix &);
    friend Matrix MA_Tran_Nghich_dao(Matrix &);
    void ktra_MaTranTamGiac();
    void ktra_MaTranDon_vi();
    void Ktra_MaTran_DuongCheo();
    void ktra_Ma_Tran_doi_xung();
    int getSoHang() { return m; }
    int getSoCot() { return n; }
    Matrix(const Matrix &A);
};
void Matrix::ktra_MaTranDon_vi()
{
    check = true;
    if (m != n)
    {
        check = false;
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j && v[i][j] != 1)
            {
                check = false;
                break;
            }
            else if (i != j && v[i][j] != 0)
            {
                check = false;
                break;
            }
        }
        if (!check)
        {
            break;
        }
    }
    if (check == true)
    {
        cout << "\t\t\t\t\t\t\tDAY LA MATRAN DON VI\n";
    }
    else
    {
        cout << "\t\t\t\t\t\t\tDAY KHONG PHAI LA MATRAN DON VI \n";
    }
}
Matrix MA_Tran_chuyen_vi(Matrix &A)
{
    Matrix B(A.m, A.n);
    for (int i = 0; i < A.m; i++)
    {
        for (int j = 0; j < A.n; j++)
        {
            B.v[j][i] = A.v[i][j];
        }
    }
    return B;
}

Matrix::Matrix(const Matrix &A)
{
    this->m = A.m;
    this->n = A.n;
    this->v = new double *[m];
    for (int i = 0; i < m; i++)
    {
        v[i] = new double[n];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            this->v[i][j] = A.v[i][j];
        }
    }
}
void Matrix::xuat()
{
    for (int i = 0; i < m; i++)
    {
        cout << "\t\t\t\t\t\t\t";
        for (int j = 0; j < n; j++)
        {
            cout << v[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}
void Matrix::xuat(ofstream &file)
{
    file << "\t\t";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            file << setw(1) << v[i][j] << "\t";
        }
        if (n == 3)
        {
            file << "\t\t";
        }
        if (n == 2)
        {
            file << "\t\t\t";
        }
        if (n == 1)
        {
            file << "\t\t\t\t";
        }
        if (n == 4)
        {
            file << "\t";
        }
        file << "\t\t |";
        file << endl;
        file << setw(1) << "|       ";
        file << setw(1) << "|               ";
        file << setw(1) << "|                |\t\t";
    }
    file << "\t\t\t\t\t\t\t |";
    file << endl;
    file << setw(15) << left << "|_______|_______________|________________|___________________________________|" << endl;
}
void Matrix::add(ifstream &filein)
{
    filein >> m >> n;
    this->m = m;
    this->n = n;
    this->v = new double *[m];
    for (int i = 0; i < m; i++)
    {
        v[i] = new double[n];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {

            filein >> v[i][j];
        }
    }
}
void Matrix::add()
{
    cout << "\t\t\t\t\t\t\tNhap so hang: ";
    cin >> m;
    cout << "\t\t\t\t\t\t\tnhap so cot: ";
    cin >> n;
    this->m = m;
    this->n = n;
    this->v = new double *[m];
    for (int i = 0; i < m; i++)
    {
        v[i] = new double[n];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "\t\t\t\t\t\t\tphan tu arr[" << i << "][" << j << "]: ";
            cin >> v[i][j];
        }
    }
}
Matrix::Matrix()
{
    m = n = 0;
    v = nullptr;
}
Matrix::Matrix(int m, int n)
{
    this->m = m;
    this->n = n;
    this->v = new double *[m];
    for (int i = 0; i < m; i++)
    {
        v[i] = new double[n];
    }
}
Matrix::Matrix(int m, int n, double **v)
{
    this->m = m;
    this->n = n;
    this->v = new double *[m];
    for (int i = 0; i < m; i++)
    {
        v[i] = new double[n];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            this->v[i][j] = v[i][j];
        }
    }
}
Matrix Cong_2_Ma_Tran(Matrix &A, Matrix &B)
{

    check = true;
    if (A.m != B.m && A.n != B.n)
    {
        check = false;
        cout << "\t\t\t\t\t\t\tma tran khong cung cap";
    }
    if (check == true)
    {
        Matrix C(A.m, A.n);
        for (int i = 0; i < A.m; i++)
        {
            for (int j = 0; j < A.n; j++)
            {
                C.v[i][j] = 0;
                C.v[i][j] = A.v[i][j] + B.v[i][j];
            }
        }
        cout << "\n\t\t\t\t\t\t\ttong 2 ma tran la: \n\n";
        return C;
    }
}
Matrix Tru_2_Ma_Tran(Matrix &A, Matrix &B)
{
    check = true;
    if (A.m != B.m && A.n != B.n)
    {
        cout << "\t\t\t\t\t\t\tma tran khong cung cap\n";
        check = false;
    }
    if (check == true)
    {
        Matrix C(A.m, A.n);
        for (int i = 0; i < A.m; i++)
        {
            for (int j = 0; j < A.n; j++)
            {
                C.v[i][j] = 0;
                C.v[i][j] = A.v[i][j] - B.v[i][j];
            }
        }
        cout << "\t\t\t\t\t\t\tHieu 2 MATRAN la: \n\n";
        return C;
    }
}
Matrix Nhan_2_Ma_Tran(Matrix &A, Matrix &B)
{
    check = true;
    if (A.n != B.m)
    {
        cout << "\t\t\t\t\t\t\tKhong the nhan hai ma tran." << endl;
        check = false;
    }
    Matrix C(A.m, B.n);
    if (check == true)
    {
        for (int i = 0; i < A.m; i++)
        {
            for (int j = 0; j < B.n; j++)
            {
                C.v[i][j] = 0;
                for (int k = 0; k < A.n; k++)
                {
                    C.v[i][j] += A.v[i][k] * B.v[k][j];
                }
            }
        }
        return C;
    }
}

Matrix Nhan_1_so_voi_1_Ma_Tran(Matrix &A, double &x)
{
    check == true;
    for (int i = 0; i < A.m; i++)
    {
        for (int j = 0; j < A.n; j++)
        {
            A.v[i][j] *= x;
        }
    }
    return A;
}
void Matrix::ktra_MaTranTamGiac()
{
    check = true;
    if (m != n)
    {
        check = false;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[i][j] != 0)
            {
                check = false;
            }
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (v[i][j] != 0)
            {
                check = false;
            }
        }
    }
    if (check == false)
    {
        cout << "\n\t\t\t\t\t\t\tday khong phai la ma tran tam giac";
    }
    else
    {
        cout << "\n\t\t\t\t\t\t\tday la ma tran tam giac";
    }
}
void Matrix::Ktra_MaTran_DuongCheo()
{
    check = true;
    if (m != n)
    {
        check = false;
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && v[i][j] != 0)
            {
                check = false;
                break;
            }
        }
    }
    if (check == false)
    {
        cout << "\t\t\t\t\t\t\tDay khong phai la ma tran duong cheo";
    }
    else
    {
        cout << "\t\t\t\t\t\t\tDay la ma tran duong cheo";
    }
}
void Matrix::ktra_Ma_Tran_doi_xung()
{
    check = true;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[i][j] != v[j][i])
            {
                check = false;
                break;
            }
        }
    }
    if (check == false)
    {
        cout << "\t\t\t\t\t\t\tday khong phai la ma tran doi xung";
    }
    else
    {
        cout << "\t\t\t\t\t\t\tday la ma tran doi xung";
    }
}
void nhap_file_ma_tran(ifstream &file, vector<Matrix> &ptr)
{
    check = false;

    file.open("input_Matrix.txt", ios::in);

    if (file.fail() == true)
    {
        cout << "\t\t\t\t\t\t\tko lay duoc thong tin file";
    }
    else
    {
        check = true;
        int x;
        file >> x;
        for (int i = 0; i < x; i++)
        {
            Matrix a;
            a.add(file);
            ptr.push_back(a);
        }
        file.close();
    }
}
void xuat_DS_file_ma_tran(ofstream &file, vector<Matrix> &arr)
{
    file.open("output_mang_Ma_Tran.txt", ios::out);
    file << "\t\t\t\t\t=== HIEN THI DANH SACH MATRAN ===\n";
    file << setw(15) << left << "______________________________________________________________________________" << endl;
    file << setw(8) << "| STT";
    file << setw(16) << "|   SO HANG    ";
    file << setw(17) << "|   SO COT     ";
    file << setw(15) << "|              MA TRAN              |" << endl;
    file << setw(15) << left << "|_______|_______________|________________|___________________________________|" << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        file << setw(2) << "|   " << i + 1 << "\t|      ";
        file << setw(7) << arr[i].getSoHang() << "\t|       ";
        file << setw(7) << arr[i].getSoCot() << "\t |";

        arr[i].xuat(file);
    }
    file.close();
}
void xuat_matran_dacbiet_or_phep_tinh_MT(Matrix &A, ofstream &file)
{
    file << setw(15) << left << "______________________________________________________________________________" << endl;
    file << setw(8) << "| STT";
    file << setw(16) << "|   SO HANG    ";
    file << setw(17) << "|   SO COT     ";
    file << setw(15) << "|              MA TRAN              |" << endl;
    file << setw(15) << left << "|_______|_______________|________________|___________________________________|" << endl;

    file << setw(2) << "|   " << 1 << "\t|      ";
    file << setw(7) << A.getSoHang() << "\t|       ";
    file << setw(7) << A.getSoCot() << "\t |";
    A.xuat(file);
    file << endl;
    file.close();
}
void show_danh_sach_MATRAN(vector<Matrix> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << "\t\t\t\t\t\t\tMAtrix THU " << i + 1 << ": \n\n";
        arr[i].xuat();
    }
}
void Menu_vector_dacbiet()
{
    SetColor(12);
    cout << "\t\t\t\t\t\t\t-------------------------------------------" << endl;
    cout << "\t\t\t\t\t\t\t|      KIEM TRA LOAI VEC TO DAC BIET      |" << endl;
    cout << "\t\t\t\t\t\t\t-------------------------------------------" << endl;
    cout << "\t\t\t\t\t\t\t|1. Kiem tra Vec to doi xung              |" << endl;
    cout << "\t\t\t\t\t\t\t|2. Kiem tra Vec to la hoan vi tu 1 den n |" << endl;
    cout << "\t\t\t\t\t\t\t|0. Quay lai menu chinh                   |" << endl;
    cout << "\t\t\t\t\t\t\t-------------------------------------------" << endl;
    SetColor(6);
    cout << "\t\t\t\t\t\t\tNhap lua chon cua ban (1-3): ";
}
void Menu_MAtran_dacbiet()
{
    SetColor(11);
    cout << "\t\t\t\t\t\t\t-------------------------------------------" << endl;
    cout << "\t\t\t\t\t\t\t|      KIEM TRA LOAI MA TRAN DAC BIET     |" << endl;
    cout << "\t\t\t\t\t\t\t-------------------------------------------" << endl;
    cout << "\t\t\t\t\t\t\t|1. Kiem tra Ma tran tam giac             |" << endl;
    cout << "\t\t\t\t\t\t\t|2. Kiem tra Ma tran don vi               |" << endl;
    cout << "\t\t\t\t\t\t\t|3. Kiem tra Ma tran duong cheo           |" << endl;
    cout << "\t\t\t\t\t\t\t|4. Kiem tra Ma tran doi xung             |" << endl;
    cout << "\t\t\t\t\t\t\t|0. Quay lai menu chinh                   |" << endl;
    cout << "\t\t\t\t\t\t\t-------------------------------------------" << endl;
    SetColor(5);
    cout << "\t\t\t\t\t\t\tNhap lua chon cua ban (1-5): ";
}
void hienThiMenu()
{
    SetColor(10);
    cout << "\t\t\t\t\t\t\t---------------------------------------" << endl;
    cout << "\t\t\t\t\t\t\t|                MENU                 |" << endl;
    cout << "\t\t\t\t\t\t\t---------------------------------------" << endl;
    cout << "\t\t\t\t\t\t\t|1. Quan ly Vec to                    |" << endl;
    cout << "\t\t\t\t\t\t\t|2. Quan ly Ma tran                   |" << endl;
    cout << "\t\t\t\t\t\t\t|3. Kiem tra cac loai Vec to dac biet |" << endl;
    cout << "\t\t\t\t\t\t\t|4. Kiem tra cac loai Ma tran dac biet|" << endl;
    cout << "\t\t\t\t\t\t\t|5. Thoat chuong trinh                |" << endl;
    cout << "\t\t\t\t\t\t\t---------------------------------------" << endl;
    SetColor(7);
    cout << "\t\t\t\t\t\t\tNhap lua chon cua ban (1-5): ";
}
void hienThiMenu_matran()
{
    SetColor(5);
    cout << "\t\t\t\t\t\t\t-------------------------------------------------" << endl;
    cout << "\t\t\t\t\t\t\t|                QUAN LY MA TRAN                |" << endl;
    cout << "\t\t\t\t\t\t\t-------------------------------------------------" << endl;
    cout << "\t\t\t\t\t\t\t|1. Tao moi Ma tran                             |" << endl;
    cout << "\t\t\t\t\t\t\t|2. Nhap danh sach MA tran tu file input_Matrix |" << endl;
    cout << "\t\t\t\t\t\t\t|3. Xoa phan tu trong mang Ma tran              |" << endl;
    cout << "\t\t\t\t\t\t\t|4. Hien thi danh sach Ma tran                  |" << endl;
    cout << "\t\t\t\t\t\t\t|5. Cong hai Ma tran cung cap                   |" << endl;
    cout << "\t\t\t\t\t\t\t|6. Tru hai Ma tran cung cap                    |" << endl;
    cout << "\t\t\t\t\t\t\t|7. Nhan hai Ma tran                            |" << endl;
    cout << "\t\t\t\t\t\t\t|8. Nhan mot so voi mot Ma tran                 |" << endl;
    cout << "\t\t\t\t\t\t\t|9. Lay Ma tran chuyen vi                       |" << endl;
    cout << "\t\t\t\t\t\t\t|0. Quay lai menu chinh                         |" << endl;
    cout << "\t\t\t\t\t\t\t-------------------------------------------------" << endl;
    SetColor(2);
    cout << "\t\t\t\t\t\t\tNhap lua chon cua ban (1-9): ";
}
void hienThiMenu_Vector()
{
    SetColor(7);
    cout << "\t\t\t\t\t\t\t-------------------------------------------------" << endl;
    cout << "\t\t\t\t\t\t\t|                QUAN LY VEC TO                 |" << endl;
    cout << "\t\t\t\t\t\t\t-------------------------------------------------" << endl;
    cout << "\t\t\t\t\t\t\t|1. Tao moi Vec to                              |" << endl;
    cout << "\t\t\t\t\t\t\t|2. Nhap danh sach Vec to tu file input_Vector  |" << endl;
    cout << "\t\t\t\t\t\t\t|3. Xoa phan tu trong mang Vec to               |" << endl;
    cout << "\t\t\t\t\t\t\t|4. Hien thi danh sach Vec to                   |" << endl;
    cout << "\t\t\t\t\t\t\t|5. Cong hai Vec to cung chieu                  |" << endl;
    cout << "\t\t\t\t\t\t\t|6. Tru hai Vec to cung chieu                   |" << endl;
    cout << "\t\t\t\t\t\t\t|7. Nhan hai Vec to cung chieu                  |" << endl;
    cout << "\t\t\t\t\t\t\t|8. Nhan mot so voi mot Vec to                  |" << endl;
    cout << "\t\t\t\t\t\t\t|0. Quay lai menu chinh                         |" << endl;
    cout << "\t\t\t\t\t\t\t-------------------------------------------------" << endl;
    SetColor(11);
    cout << "\t\t\t\t\t\t\tNhap lua chon cua ban (1-8): ";
}

template <class T>
void xoa_PT(vector<T> &arr, int c)
{
    if (c > 0 && c <= arr.size())
    {
        arr.erase(arr.begin() + c);
        cout << "\t\t\t\t\t\t\tDa xoa thanh cong\n";
    }
    else
    {
        cout << "\t\t\t\t\t\t\tBan nhap sai hoac vuot qua so luong phan tu co trong mang\n";
    }
}

void back_(int &luachon)
{
    SetColor(12);
    cout << "\t\t\t\t\t\t\tNhan phim bat ky roi nhan Enter de Quay Lai MENU chinh\n";
    SetColor(14);
    cout << "\t\t\t\t\t\t\tnhap: ";
    char e;
    cin >> e;
    switch (e)
    {
    default:
        luachon = 9;
        break;
    }
}
void menu_tong(int &luachon)
{
    system("cls");
    hienThiMenu();
    cin >> luachon;
    cin.ignore();
}
void quan_ly_vector(int &luachon, ifstream &filein, ofstream &file, vector<Vector> &v_arr, bool &check1)
{
    system("cls");
    hienThiMenu_Vector();
    int ok2;
    cin >> ok2;
    cin.ignore();
    switch (ok2)
    {
    case 1:
    {
        system("cls");
        SetColor(3);
        cout << "\t\t\t\t\t\t\t\t=== TAO MOI VECTOR ===" << endl;
        SetColor(4);
        Vector a;
        a.add();
        v_arr.push_back(a);
        SetColor(3);
        cout << "\t\t\t\t\t\t\tDa Tao moi Vector thanh cong \n";
        check1 = true;
        back_(luachon);
        break;
    }
    case 2:
    {
        input_Vector(filein, v_arr);
        if (check == true)
        {
            check1 = true;
        }
        back_(luachon);
        break;
    }
        if (check1 == false)
        {
            SetColor(3);
            cout << "\t\t\t\t\t\t\tChua Co Du Lieu\n";
            back_(luachon);
        }
    case 3:
    {
        SetColor(3);
        cout << "\t\t\t\t\t\t\t=== Xoa phan tu trong mang Vec to ===" << endl;
        SetColor(9);
        if (check1 == true)
        {
            int a;
            cout << "\t\t\t\t\t\t\tnhap phan stt ban muon xoa trong Vec to: ";
            cin >> a;
            xoa_PT(v_arr, a);
            if (v_arr.size() == 0)
            {
                check1 = false;
            }
            back_(luachon);
        }
        else
        {
            SetColor(5);
            cout << "\t\t\t\t\t\t\tchua co du lieu trong mang\n";
            back_(luachon);
        }

        break;
    }
    case 4:
    {
        system("cls");
        SetColor(3);
        cout << "\t\t\t\t\t\t\t=== Hien thi danh sach Vector ===" << endl;
        SetColor(2);
        if (check1 == true)
        {
            show_danh_sach_Vector(v_arr);
            cout << "\t\t\t\t\t\t\tBan co muon luu danh sach Vector vao file Output_Mang_VECTOR.txt\n";
            cout << "\t\t\t\t\t\t\t1. Dong Y\n";
            cout << "\t\t\t\t\t\t\t2. Quay Lai MENU chinh\n";
            SetColor(6);
            cout << "\t\t\t\t\t\t\tnhap lua chon cua ban(1-2): ";
            int k;
            cin >> k;
            cin.ignore();
            switch (k)
            {
            case 1:
            {
                xuat_mang_file_Vector(file, v_arr);
                SetColor(8);
                cout << "\t\t\t\t\t\t\tDa Luu Thanh Cong\n";
                back_(luachon);
                break;
            }
            case 2:
            {
                luachon = 9;
                break;
            }
            }
        }
        if (check1 == false)
        {
            SetColor(1);
            cout << "\t\t\t\t\t\t\tChua Co Du Lieu\n";
            back_(luachon);
        }

        break;
    }
    case 5:
    {
        system("cls");
        SetColor(10);
        cout << "\t\t\t\t\t\t\t==== CONG HAI VECTOR CUNG CHIEU ====" << endl;
        if (check1 == true)
        {
            SetColor(6);
            cout << "\t\t\t\t\t\t\tBAN HAY NHAP STT CUA 2 VECTOR CAN CONG\n";
            int chon1, chon2;
            cout << "\t\t\t\t\t\t\tNHAP STT CUA VECTOR 1: ";
            cin >> chon1;
            cin.ignore();
            cout << "\t\t\t\t\t\t\tNHAP STT CUA VECTOR 2: ";
            cin >> chon2;
            cin.ignore();
            if (chon1 - 1 < v_arr.size() && chon2 - 1 < v_arr.size())
            {
                Vector a(v_arr[chon1 - 1]);
                cout << "\t\t\t\t\t\t\tVector thu " << chon1 << ": ";
                a.xuat();
                Vector b(v_arr[chon2 - 1]);
                cout << "\n\t\t\t\t\t\t\tVector thu " << chon2 << ": ";
                b.xuat();
                Vector x = Cong_2_Vector(a, b);
                switch (check)
                {
                case true:
                {
                    cout << "\n\t\t\t\t\t\t\tTong cua 2 Vector cung chieu: ";
                    x.xuat();
                    cout << "\n\t\t\t\t\t\t\tBan co muon luu danh sach Vector vao file Output_Mang_VECTOR.txt\n";
                    cout << "\t\t\t\t\t\t\t1. Dong Y\n";
                    cout << "\t\t\t\t\t\t\t2. Quay Lai MENU chinh\n";
                    SetColor(7);
                    cout << "\t\t\t\t\t\t\tnhap lua chon cua ban: ";
                    SetColor(6);
                    int k;
                    cin >> k;
                    cin.ignore();
                    switch (k)
                    {
                    case 1:
                    {
                        file.open("output_VECTOR.txt", ios::app);
                        file << "\t\t\t\t\t==== CONG HAI VECTOR CUNG CHIEU ====\n";
                        xuat_vector_dacbiet_or_tinh_toan(x, file);
                        cout << "\t\t\t\t\t\t\tDa Luu Thanh Cong\n";
                        back_(luachon);
                        break;
                    }
                    case 2:
                    {
                        luachon = 9;
                        break;
                    }
                    }
                    break;
                }
                case false:
                {
                    back_(luachon);
                    break;
                }
                }
            }
            else
            {
                cout << "\t\t\t\t\t\t\tSTT Ban Nhap Vuot Qua So Luong VECTOR Co Trong Mang\n";
                back_(luachon);
            }
        }
        if (check1 == false)
        {

            SetColor(2);
            cout << "\t\t\t\t\t\t\tChua Co Du Lieu\n";
            back_(luachon);
        }
        break;
    }
    case 6:
    {
        system("cls");
        SetColor(6);
        cout << "\t\t\t\t\t\t\t==== Tru hai Vec to cung chieu ====" << endl;
        SetColor(7);
        if (check1 == true)
        {

            cout << "\t\t\t\t\t\t\tBan hay nhap STT cua 2 Vector can Tru\n";
            int chon1, chon2;
            cout << "\t\t\t\t\t\t\tnhap STT cua Vector 1: ";
            cin >> chon1;
            cin.ignore();
            cout << "\t\t\t\t\t\t\tnhap STT cua Vector 2: ";
            cin >> chon2;
            cin.ignore();
            if (chon1 - 1 < v_arr.size() && chon2 - 1 < v_arr.size())
            {

                Vector a(v_arr[chon1 - 1]);
                cout << "\t\t\t\t\t\t\tVector thu " << chon1 << ": ";
                a.xuat();
                Vector b(v_arr[chon2 - 1]);
                cout << "\n\t\t\t\t\t\t\tVector thu " << chon2 << ": ";
                b.xuat();
                Vector x = Cong_2_Vector(a, b);
                switch (check)
                {
                case true:
                {
                    cout << "\n\t\t\t\t\t\t\tHieu cua 2 Vector cung chieu: ";
                    x.xuat();
                    cout << "\n\t\t\t\t\t\t\tBan co muon luu danh sach Vector vao file output_VECTOR.txt\n";
                    cout << "\t\t\t\t\t\t\t1. Dong Y\n";
                    cout << "\t\t\t\t\t\t\t2. Quay Lai MENU chinh\n";
                    SetColor(6);
                    cout << "\t\t\t\t\t\t\tnhap lua chon cua ban: ";
                    SetColor(7);
                    int k;
                    cin >> k;
                    cin.ignore();
                    switch (k)
                    {
                    case 1:
                    {
                        file.open("output_VECTOR.txt", ios::app);
                        file << "\t\t\t\t\t==== Hieu HAI VECTOR CUNG CHIEU ====\n";
                        xuat_vector_dacbiet_or_tinh_toan(x, file);
                        cout << "\t\t\t\t\t\t\tDa Luu Thanh Cong\n";
                        back_(luachon);
                        break;
                    }
                    case 2:
                    {
                        luachon = 9;
                        break;
                    }
                    }
                    break;
                }
                case false:
                    back_(luachon);
                    break;
                }
            }
            else
            {
                SetColor(6);
                cout << "\t\t\t\t\t\t\tSTT Ban Nhap Vuot Qua So Luong VECTOR Co Trong Mang\n";
                back_(luachon);
            }
        }
        if (check1 == false)
        {
            SetColor(6);
            cout << "\t\t\t\t\t\t\tChua Co Du Lieu\n";
            back_(luachon);
        }
        break;
    }
    case 7:
    {
        system("cls");
        SetColor(6);
        cout << "\t\t\t\t\t\t\t==== Nhan hai Vec to cung chieu ====" << endl;
        SetColor(7);
        if (check1 == true)
        {

            cout << "\t\t\t\t\t\t\tBan hay nhap STT cua 2 Vector can nhan\n";
            int chon1, chon2;
            cout << "\t\t\t\t\t\t\tnhap STT cua Vector 1: ";
            cin >> chon1;
            cin.ignore();
            cout << "\t\t\t\t\t\t\tnhap STT cua Vector 2: ";
            cin >> chon2;
            cin.ignore();
            if (chon1 - 1 < v_arr.size() && chon2 - 1 < v_arr.size())
            {

                Vector a(v_arr[chon1 - 1]);
                cout << "\t\t\t\t\t\t\tVector thu " << chon1 << ": ";
                a.xuat();
                Vector b(v_arr[chon2 - 1]);
                cout << "\n\t\t\t\t\t\t\tVector thu " << chon2 << ": ";
                b.xuat();
                Vector x = Nhan_2_Vector(a, b);
                switch (check)
                {
                case true:
                {
                    cout << "\n\t\t\t\t\t\t\tTich cua 2 Vector cung chieu: ";
                    x.xuat();
                    cout << "\n\t\t\t\t\t\t\tBan co muon luu danh sach Vector vao file Output_Mang_VECTOR.txt\n";
                    cout << "\t\t\t\t\t\t\t1. Dong Y\n";
                    cout << "\t\t\t\t\t\t\t2. Quay Lai MENU chinh\n";
                    SetColor(8);
                    cout << "\t\t\t\t\t\t\tnhap lua chon cua ban: ";
                    SetColor(7);
                    int k;
                    cin >> k;
                    cin.ignore();
                    switch (k)
                    {
                    case 1:
                    {
                        file.open("\t\t\t\t\t\t\toutput_VECTOR.txt", ios::app);
                        file << "\t\t\t\t\t==== NHAN HAI VECTOR CUNG CHIEU ====\n";
                        xuat_vector_dacbiet_or_tinh_toan(x, file);
                        cout << "\t\t\t\t\t\t\tDa Luu Thanh Cong\n";
                        back_(luachon);
                        break;
                    }
                    case 2:
                    {
                        luachon = 9;
                        break;
                    }
                    }
                    break;
                }
                case false:
                    back_(luachon);
                    break;
                }
            }
            else
            {
                SetColor(6);
                cout << "\t\t\t\t\t\t\tSTT Ban Nhap Vuot Qua So Luong VECTOR Co Trong Mang\n";
                back_(luachon);
                luachon = 9;
            }
        }
        if (check1 == false)
        {
            SetColor(6);
            cout << "\t\t\t\t\t\t\tChua Co Du Lieu\n";
            back_(luachon);
        }
        break;
    }
    case 8:
    {
        system("cls");
        SetColor(6);
        cout << "\t\t\t\t\t\t\t==== Nhan 1 so voi Vec to ====" << endl;
        SetColor(7);
        if (check1 == true)
        {

            cout << "\t\t\t\t\t\t\tBan hay nhap STT cua  Vector can nhan\n";
            int chon1;
            cout << "\t\t\t\t\t\t\tnhap STT cua Vector: ";
            cin >> chon1;
            cin.ignore();
            cout << "\t\t\t\t\t\t\tnhap phan tu ban muon nhan vao Vector: ";
            double phantu;
            cin >> phantu;
            cin.ignore();
            if (chon1 - 1 < v_arr.size())
            {
                Vector a(v_arr[chon1 - 1]);
                cout << "\t\t\t\t\t\t\tVector thu " << chon1 << ": ";
                a.xuat();
                cout << endl
                     << "\t\t\t\t\t\t\tPhan tu muon nhan vao Vector: " << phantu << endl;
                Vector x = nhan_1_so_voi_1_vector(a, phantu);
                switch (check)
                {
                case true:
                {
                    cout << "\n\t\t\t\t\t\t\tTich 1 so nhan Vector: ";
                    x.xuat();
                    cout << "\n\t\t\t\t\t\t\tBan co muon luu danh sach Vector vao file Output_Mang_VECTOR.txt\n";
                    cout << "\t\t\t\t\t\t\t1. Dong Y\n";
                    cout << "\t\t\t\t\t\t\t2. Quay Lai MENU chinh\n";
                    SetColor(6);
                    cout << "\t\t\t\t\t\t\tnhap lua chon cua ban: ";
                    SetColor(7);
                    int k;
                    cin >> k;
                    cin.ignore();
                    switch (k)
                    {
                    case 1:
                    {
                        file.open("output_VECTOR.txt", ios::app);
                        file << "\t\t\t\t\t==== NHAN VECTOR VOI 1 SO ====\n";
                        xuat_vector_dacbiet_or_tinh_toan(x, file);
                        cout << "\t\t\t\t\t\t\tDa Luu Thanh Cong";
                        back_(luachon);
                        break;
                    }
                    case 2:
                    {
                        luachon = 9;
                        break;
                    }
                    }
                    break;
                }
                }
            }
            else
            {
                SetColor(6);
                cout << "\t\t\t\t\t\t\tSTT Ban Nhap Vuot Qua So Luong VECTOR Co Trong Mang, hoac ban chua thiet lap gia tri cua mang\n";
                back_(luachon);
            }
        }
        if (check1 == false)
        {
            cout << "\t\t\t\t\t\t\tChua Co Du Lieu\n";
            back_(luachon);
        }
        break;
    }
    case 0:
    {
        luachon = 9;
        break;
    }
    default:
    {
        luachon = 1;
    }
    }
}
void quan_ly_Matrix(int &luachon, ifstream &filein, ofstream &file, vector<Matrix> &m_arr, bool &check2)
{
    system("cls");
    hienThiMenu_matran();
    int ok2;
    cin >> ok2;
    cin.ignore();
    switch (ok2)
    {
    case 1:
    {
        system("cls");
        SetColor(6);
        cout << "\t\t\t\t\t\t\t=== TAO MOI MATRAN ===" << endl;
        SetColor(7);
        Matrix a;
        a.add();
        m_arr.push_back(a);
        SetColor(8);
        cout << "\t\t\t\t\t\t\tDA TAO MOI MATRAN THANH CONG \n";
        SetColor(7);
        check2 = true;
        back_(luachon);
        break;
    }
    case 2:
    {
        SetColor(7);
        nhap_file_ma_tran(filein, m_arr);
        SetColor(8);
        if (check == true)
        {
            check2 = true;
        }
        SetColor(8);
        cout << "\t\t\t\t\t\t\tnhap file thanh cong ^^" << endl;
        back_(luachon);
        break;
    }
    case 3:
    {
        if (check2 == true)
        {

            int a;
            SetColor(8);
            cout << "\t\t\t\t\t\t\tnhap stt phan tu ban muon xoa trong Ma tran: ";
            SetColor(7);
            cin >> a;
            xoa_PT(m_arr, a);
            if (m_arr.size() == 0)
            {
                check2 = false;
            }
        }
        else
        {
            SetColor(8);
            cout << "\t\t\t\t\t\t\tSTT ko hop le\n";
        }
        back_(luachon);
        break;
    }
    case 4:
    {
        system("cls");
        SetColor(8);
        cout << "\t\t\t\t\t\t\t=== HIEN THI DANH SACH MATRAN ===" << endl;
        SetColor(7);
        if (check2 == true)
        {
            show_danh_sach_MATRAN(m_arr);
            cout << "\t\t\t\t\t\t\tBan co muon luu danh sach Vector vao file Output_Mang_VECTOR.txt\n";
            cout << "\t\t\t\t\t\t\t1. Dong Y\n";
            cout << "\t\t\t\t\t\t\t2. Quay Lai MENU chinh\n";
            SetColor(8);
            cout << "\t\t\t\t\t\t\tnhap lua chon cua ban(1-2): ";
            SetColor(7);
            int k;
            cin >> k;
            cin.ignore();
            switch (k)
            {
            case 1:
            {
                xuat_DS_file_ma_tran(file, m_arr);
                SetColor(8);
                cout << "\t\t\t\t\t\t\tDa Luu Thanh Cong\n";
                back_(luachon);
                break;
            }
            case 2:
            {
                luachon = 9;
                break;
            }
            }
        }
        if (check2 == false)
        {
            SetColor(8);
            cout << "\t\t\t\t\t\t\tCHUA CO DU LIEU TRONG MANG MATRAN ^^\n";
            back_(luachon);
        }
        break;
    }
    case 5:
    {
        system("cls");
        SetColor(8);
        cout << "\t\t\t\t\t\t\t==== CONG HAI MATRAN CUNG CAP ====" << endl;
        SetColor(7);
        if (check2 == true)
        {

            cout << "\t\t\t\t\t\t\tBAN HAY NHAP STT CUA 2 MATRAN CAN CONG\n";
            int chon1, chon2;
            SetColor(6);
            cout << "\t\t\t\t\t\t\tNHAP STT CUA MATRAN 1: ";
            cin >> chon1;
            cin.ignore();
            SetColor(5);
            cout << "\t\t\t\t\t\t\tNHAP STT CUA MATRAN 2: ";
            cin >> chon2;
            cin.ignore();
            SetColor(9);
            if (chon1 - 1 < m_arr.size() && chon2 - 1 < m_arr.size())
            {
                Matrix a(m_arr[chon1 - 1]);
                Matrix b(m_arr[chon2 - 1]);
                cout << "\t\t\t\t\t\t\tDU LIEU MATRAN THU " << chon1 << ": \n\n";
                a.xuat();
                cout << "\t\t\t\t\t\t\tDU LIEU MATRAN THU " << chon2 << ": \n\n";
                b.xuat();
                Matrix x = Cong_2_Ma_Tran(a, b);
                switch (check)
                {
                case true:
                {
                    x.xuat();
                    cout << "\t\t\t\t\t\t\tBan co muon luu MATRAN vao file output_MATRAN.txt\n";
                    cout << "\t\t\t\t\t\t\t1. Dong Y\n";
                    cout << "\t\t\t\t\t\t\t2. Quay Lai MENU chinh\n";
                    SetColor(5);
                    cout << "\t\t\t\t\t\t\tnhap lua chon cua ban(1-2): ";
                    SetColor(7);
                    int k;
                    cin >> k;
                    cin.ignore();
                    switch (k)
                    {
                    case 1:
                    {
                        file.open("output_MATRAN.txt", ios::app);
                        file << "\t\t\t\t\t==== CONG HAI MATRAN CUNG CAP ====" << endl;
                        xuat_matran_dacbiet_or_phep_tinh_MT(x, file);
                        SetColor(5);
                        cout << "\t\t\t\t\t\t\tDa Luu Thanh Cong\n";
                        back_(luachon);
                        break;
                    }
                    case 2:
                    {
                        luachon = 9;
                        break;
                    }
                    }
                    break;
                }
                case false:
                    back_(luachon);
                    break;
                }
            }
            else
            {
                SetColor(8);
                cout << "\t\t\t\t\t\t\tSTT BAN NHAP VUOT QUA SO LUONG MATRAN CO TRONG MANG , VUI LONG THU LAI\n";
                back_(luachon);
            }
        }
        if (check2 == false)
        {
            SetColor(8);
            cout << "\t\t\t\t\t\t\tCHUA CO DU LIEU TRONG MANG MATRAN ^^\n";
            back_(luachon);
        }
        break;
    }
    case 6:
    {
        system("cls");
        SetColor(7);
        cout << "\t\t\t\t\t\t\t==== TRU HAI MATRAN CUNG CAP ====" << endl;
        SetColor(8);
        if (check2 == true)
        {
            SetColor(9);
            cout << "\t\t\t\t\t\t\tBAN HAY NHAP STT CUA 2 MATRAN CAN TRU\n";
            SetColor(8);
            int chon1, chon2;
            cout << "\t\t\t\t\t\t\tNHAP STT CUA MATRAN 1: ";
            cin >> chon1;
            cin.ignore();
            SetColor(7);
            cout << "\t\t\t\t\t\t\tNHAP STT CUA MATRAN 2: ";
            cin >> chon2;
            cin.ignore();
            if (chon1 - 1 < m_arr.size() && chon2 - 1 < m_arr.size())
            {
                Matrix a(m_arr[chon1 - 1]);
                Matrix b(m_arr[chon2 - 1]);
                cout << "\t\t\t\t\t\t\tDU LIEU MATRAN THU " << chon1 << ": \n\n";
                a.xuat();
                cout << "\t\t\t\t\t\t\tDU LIEU MATRAN THU " << chon2 << ": \n\n";
                b.xuat();
                Matrix x = Tru_2_Ma_Tran(a, b);
                switch (check)
                {
                case true:
                {
                    SetColor(8);
                    x.xuat();
                    SetColor(7);
                    cout << "\t\t\t\t\t\t\tBan co muon luu MATRAN vao file output_MATRAN.txt\n";
                    cout << "\t\t\t\t\t\t\t1. Dong Y\n";
                    cout << "\t\t\t\t\t\t\t2. Quay Lai MENU chinh\n";
                    SetColor(6);
                    cout << "\t\t\t\t\t\t\tnhap lua chon cua ban(1-2): ";
                    int k;
                    cin >> k;
                    cin.ignore();
                    switch (k)
                    {
                    case 1:
                    {
                        file.open("output_MATRAN.txt", ios::app);
                        file << "\t\t\t\t\t==== TRU HAI MATRAN CUNG CAP ====" << endl;
                        xuat_matran_dacbiet_or_phep_tinh_MT(x, file);
                        cout << "\t\t\t\t\t\t\tDa Luu Thanh Cong\n";
                        back_(luachon);
                        break;
                    }
                    case 2:
                    {
                        luachon = 9;
                        break;
                    }
                    }
                    break;
                }
                case false:
                    back_(luachon);
                    break;
                }
            }
            else
            {
                SetColor(7);
                cout << "\t\t\t\t\t\t\tSTT BAN NHAP VUOT QUA SO LUONG MATRAN CO TRONG MANG , VUI LONG THU LAI\n";
                back_(luachon);
            }
        }
        if (check2 == false)
        {
            SetColor(7);
            cout << "\t\t\t\t\t\t\tCHUA CO DU LIEU TRONG MANG MATRAN ^^\n";
            back_(luachon);
        }
        break;
    }
    case 7:
    {
        system("cls");
        SetColor(7);
        cout << "\t\t\t\t\t\t\t==== NHAN HAI MATRAN CUNG CAP ====" << endl;
        SetColor(8);
        if (check2 == true)
        {
            cout << "\t\t\t\t\t\t\tBAN HAY NHAP STT CUA 2 MATRAN CAN NHAN\n";
            int chon1, chon2;
            SetColor(6);
            cout << "\t\t\t\t\t\t\tNHAP STT CUA MATRAN 1: ";
            cin >> chon1;
            cin.ignore();
            SetColor(7);
            cout << "\t\t\t\t\t\t\tNHAP STT CUA MATRAN 2: ";
            cin >> chon2;
            cin.ignore();
            SetColor(5);
            if (chon1 - 1 < m_arr.size() && chon2 - 1 < m_arr.size())
            {
                Matrix a(m_arr[chon1 - 1]);
                Matrix b(m_arr[chon2 - 1]);
                cout << "\t\t\t\t\t\t\tDU LIEU MATRAN THU " << chon1 << ": \n\n";
                a.xuat();

                cout << "\t\t\t\t\t\t\tDU LIEU MATRAN THU " << chon2 << ": \n\n";
                b.xuat();
                Matrix x = Nhan_2_Ma_Tran(a, b);
                switch (check)
                {
                case true:
                {
                    SetColor(4);
                    cout << "\n\t\t\t\t\t\t\tTich 2 matran\n\n";
                    x.xuat();
                    cout << "\t\t\t\t\t\t\tBan co muon luu MATRAN vao file output_MATRAN.txt\n";
                    cout << "\t\t\t\t\t\t\t1. Dong Y\n";
                    cout << "\t\t\t\t\t\t\t2. Quay Lai MENU chinh\n";
                    SetColor(7);
                    cout << "\t\t\t\t\t\t\tnhap lua chon cua ban(1-2): ";
                    int k;
                    cin >> k;
                    cin.ignore();
                    switch (k)
                    {
                    case 1:
                    {
                        file.open("output_MATRAN.txt", ios::app);
                        file << "\t\t\t\t\t==== TICH HAI MATRAN CUNG CAP ====" << endl;
                        xuat_matran_dacbiet_or_phep_tinh_MT(x, file);
                        cout << "\t\t\t\t\t\t\tDa Luu Thanh Cong\n";
                        back_(luachon);
                        break;
                    }
                    case 2:
                    {
                        luachon = 9;
                        break;
                    }
                    }
                    break;
                }
                case false:
                    back_(luachon);
                    break;
                }
            }
            else
            {
                SetColor(7);
                cout << "\t\t\t\t\t\t\tSTT BAN NHAP VUOT QUA SO LUONG MATRAN CO TRONG MANG\n";
                back_(luachon);
            }
        }
        if (check2 == false)
        {
            SetColor(7);
            cout << "\t\t\t\t\t\t\tCHUA CO DU LIEU TRONG MANG MATRAN ^^\n";
            back_(luachon);
        }
        break;
    }
    case 8:
    {
        system("cls");
        SetColor(7);
        cout << "\t\t\t\t\t\t\t==== NHAN MATRAN VOI 1 SO ====" << endl;
        SetColor(6);
        if (check2 == true)
        {
            cout << "\t\t\t\t\t\t\tBAN HAY NHAP STT CUA MATRAN CAN NHAN\n";
            int chon1;
            double chon2;
            SetColor(7);
            cout << "\t\t\t\t\t\t\tNHAP STT CUA MATRAN: ";
            cin >> chon1;
            cin.ignore();
            SetColor(5);
            cout << "\t\t\t\t\t\t\tNHAP PHAN TU CAN NHAN VAO MATRAN: ";
            SetColor(6);
            cin >> chon2;
            cin.ignore();
            if (chon1 - 1 < m_arr.size())
            {
                Matrix a(m_arr[chon1 - 1]);
                cout << "\t\t\t\t\t\t\tDU LIEU MATRAN THU " << chon1 << ": \n\n";
                a.xuat();
                cout << "\t\t\t\t\t\t\tSo duoc nhan vao MATRAN: " << chon2 << endl;
                Matrix x = Nhan_1_so_voi_1_Ma_Tran(a, chon2);
                switch (check)
                {
                case true:
                {
                    x.xuat();
                    cout << "\t\t\t\t\t\t\tBan co muon luu MATRAN vao file output_MATRAN.txt\n";
                    cout << "\t\t\t\t\t\t\t1. Dong Y\n";
                    cout << "\t\t\t\t\t\t\t2. Quay Lai MENU chinh\n";
                    SetColor(7);
                    cout << "\t\t\t\t\t\t\tnhap lua chon cua ban(1-2): ";
                    int k;
                    cin >> k;
                    cin.ignore();
                    switch (k)
                    {
                    case 1:
                    {
                        x.xuat();
                        file.open("output_MATRAN.txt", ios::app);
                        file << "\t\t\t\t\t==== TICH HAI MATRAN CUNG CAP ====" << endl;
                        xuat_matran_dacbiet_or_phep_tinh_MT(x, file);
                        cout << "\t\t\t\t\t\t\tDa Luu Thanh Cong\n";
                        back_(luachon);
                        break;
                    }
                    case 2:
                    {
                        luachon = 9;
                        break;
                    }
                    }
                }
                case false:
                {
                    back_(luachon);
                    break;
                }
                }
            }
            else
            {
                SetColor(8);
                cout << "\t\t\t\t\t\t\tSTT BAN NHAP VUOT QUA SO LUONG MATRAN CO TRONG MANG\n";
                back_(luachon);
            }
        }
        if (check2 == false)
        {
            SetColor(8);
            cout << "\t\t\t\t\t\t\tCHUA CO DU LIEU TRONG MANG MATRAN ^^\n";
            back_(luachon);
        }
        break;
    }
    case 9:
    {
        system("cls");
        SetColor(7);
        cout << "\t\t\t\t\t\t\t==== LAY MATRAN CHUYEN VI ====" << endl;
        SetColor(6);

        if (check2 == true)
        {
            SetColor(7);
            cout << "\t\t\t\t\t\t\tBAN HAY NHAP STT CUA MATRAN MUON LAY MATRAN CHUYEN VI\n";
            int chon1;
            SetColor(6);
            cout << "\t\t\t\t\t\t\tNHAP STT CUA MATRAN: ";
            SetColor(3);
            cin >> chon1;
            cin.ignore();
            if (chon1 - 1 < m_arr.size())
            {
                Matrix a(m_arr[chon1 - 1]);
                cout << "\t\t\t\t\t\t\tDU LIEU MATRAN THU " << chon1 << ": \n\n";
                a.xuat();
                if (a.getSoHang() == a.getSoCot())
                {
                    Matrix x = MA_Tran_chuyen_vi(a);
                    cout << "\t\t\t\t\t\t\tMatran chuyen vi\n\n";
                    x.xuat();
                    cout << "\t\t\t\t\t\t\tBan co muon luu MATRAN vao file output_MATRAN.txt\n";
                    cout << "\t\t\t\t\t\t\t1. Dong Y\n";
                    cout << "\t\t\t\t\t\t\t2. Quay Lai MENU chinh\n";
                    cout << "\t\t\t\t\t\t\tnhap lua chon cua ban(1-2): ";
                    int k;
                    cin >> k;
                    cin.ignore();
                    switch (k)
                    {
                    case 1:
                    {
                        x.xuat();
                        file.open("output_MATRAN.txt", ios::app);
                        file << "\t\t\t\t\t==== LAY MATRAN HOAN VI ====" << endl;
                        xuat_matran_dacbiet_or_phep_tinh_MT(x, file);
                        cout << "\t\t\t\t\t\t\tDa Luu Thanh Cong\n";
                        back_(luachon);
                        break;
                    }
                    case 2:
                    {
                        luachon = 9;
                        break;
                    }
                    }
                }
                else
                {
                    SetColor(7);
                    cout << "\t\t\t\t\t\t\tMATRAN NAY KHONG PHAI LA MA TRAN VUONG\n";
                    back_(luachon);
                }
            }
            else
            {
                SetColor(7);
                cout << "\t\t\t\t\t\t\tSTT BAN NHAP VUOT QUA SO LUONG MATRAN CO TRONG MANG\n";
                back_(luachon);
            }
        }
        else
        {
            cout << "\t\t\t\t\t\t\tCHUA CO DU LIEU TRONG MANG MATRAN :((\n";
            back_(luachon);
        }

        break;
    }
    case 0:
    {
        luachon = 9;
        break;
    }
    }
}
void quan_ly_vector_dac_biet(int &luachon, ofstream &file, vector<Vector> &v_arr, bool &check1)
{
    system("cls");
    Menu_vector_dacbiet();
    int luachon_vector_dacbiet;
    cin >> luachon_vector_dacbiet;
    switch (luachon_vector_dacbiet)
    {
    case 0:
    {
        luachon = 9;
        break;
    }
    case 2:
    {
        system("cls");
        SetColor(7);
        cout << "\n\t\t\t\t\t\t\t=== Kiem Tra Vec to Hoan Vi ===\n";
        SetColor(6);
        if (check1 == true)
        {
            cout << "\t\t\t\t\t\t\tBan hay nhap STT cua Vector can kiem tra Vector hoan vi\n";
            int chon1;
            SetColor(7);
            cout << "\t\t\t\t\t\t\tnhap STT cua Vector: ";
            SetColor(6);
            cin >> chon1;
            cin.ignore();
            if (chon1 - 1 < v_arr.size())
            {
                cout << "\t\t\t\t\t\t\tVector thu " << chon1 << ": ";
                v_arr[chon1 - 1].xuat();
                cout << endl;
                v_arr[chon1 - 1].ktra_Vector_hoanVi();
                switch (check)
                {
                case true:
                {
                    cout << "\n\t\t\t\t\t\t\tBan co muon luu Vector hoan vi vao file Vector_DacBiet.txt\n";
                    cout << "\t\t\t\t\t\t\t1. Dong Y\n";
                    cout << "\t\t\t\t\t\t\t2. Quay Lai MENU chinh\n";
                    SetColor(5);
                    cout << "\t\t\t\t\t\t\tnhap lua chon cua ban: ";
                    int k;
                    cin >> k;
                    cin.ignore();
                    switch (k)
                    {
                    case 1:
                    {
                        file.open("Vector_DacBiet.txt", ios::app);
                        file << "\t\t\t\t\t==== VECTOR HOAN VI ====\n";
                        xuat_vector_dacbiet_or_tinh_toan(v_arr[chon1 - 1], file);
                        cout << "\n\t\t\t\t\t\t\tDa Luu Thanh Cong\n";
                        back_(luachon);
                        break;
                    }
                    case 2:
                    {
                        luachon = 9;
                        break;
                    }
                    }

                    break;
                }
                case false:
                {
                    cout << '\n';
                    back_(luachon);
                    break;
                }
                }
            }
            else
            {
                SetColor(4);
                cout << "\t\t\t\t\t\t\tSTT Ban Nhap Vuot Qua So Luong VECTOR Co Trong Mang, hoac ban chua thiet lap gia tri cua mang\n";
                back_(luachon);
            }
        }

        if (check1 == false)
        {
            SetColor(4);
            cout << "\t\t\t\t\t\t\tChua Co Du Lieu\n";
            back_(luachon);
        }
        break;
    }
    case 1:
    {
        system("cls");
        SetColor(7);
        cout << "\n\t\t\t\t\t\t\t=== Kiem Tra Vec to Doi Xung ===\n";
        SetColor(6);
        if (check1 == true)
        {
            cout << "\t\t\t\t\t\t\tBan hay nhap STT cua Vector can kiem tra Vector Doi Xung\n";
            int chon1;
            SetColor(7);
            cout << "\t\t\t\t\t\t\tnhap STT cua Vector: ";
            SetColor(6);
            cin >> chon1;
            cin.ignore();
            if (chon1 - 1 < v_arr.size())
            {
                cout << "\t\t\t\t\t\t\tVector thu " << chon1 << ": ";
                v_arr[chon1 - 1].xuat();
                cout << endl;
                v_arr[chon1 - 1].ktra_Vector_doiXung();
                switch (check)
                {
                case true:
                {
                    cout << "\n\t\t\t\t\t\t\tBan co muon luu danh sach Vector vao file Vector_DacBiet.txt\n";
                    cout << "\t\t\t\t\t\t\t1. Dong Y\n";
                    cout << "\t\t\t\t\t\t\t2. Quay Lai MENU chinh\n";
                    cout << "\t\t\t\t\t\t\tnhap lua chon cua ban: ";
                    int k;
                    cin >> k;
                    cin.ignore();
                    switch (k)
                    {
                    case 1:
                    {
                        file.open("Vector_DacBiet.txt", ios::app);
                        file << "\t\t\t\t\t==== VECTOR DOI XUNG ====\n";
                        xuat_vector_dacbiet_or_tinh_toan(v_arr[chon1 - 1], file);
                        cout << "\t\t\t\t\t\t\tDa Luu Thanh Cong\n";
                        back_(luachon);
                        break;
                    }
                    case 2:
                    {
                        luachon = 9;
                        break;
                    }
                    }

                    break;
                }
                case false:
                {
                    cout << "\n";
                    back_(luachon);
                    break;
                }
                }
            }
            else
            {
                SetColor(4);
                cout << "\n\t\t\t\t\t\t\tSTT Ban Nhap Vuot Qua So Luong VECTOR Co Trong Mang, hoac ban chua thiet lap gia tri cua mang\n";
                back_(luachon);
            }
        }

        if (check1 == false)
        {
            SetColor(4);
            cout << "\t\t\t\t\t\t\tChua Co Du Lieu\n";
            back_(luachon);
        }
        break;
    }
    default:
    {
        luachon = 9;
        break;
    }
    }
}
void quan_ly_matrix_dac_biet(int &luachon, ofstream &file, vector<Matrix> &m_arr, bool &check2)
{
    system("cls");
    Menu_MAtran_dacbiet();
    int q;
    cin >> q;
    switch (q)
    {
    case 1:
    {
        SetColor(7);
        cout << "\t\t\t\t\t\t\t=== KIEM TRA MA TRAN TAM GIAC ===" << endl;
        SetColor(6);
        if (check2 == true)
        {
            cout << "\t\t\t\t\t\t\tBAN HAY NHAP STT CUA MATRAN MUON KIEM TRA\n";
            int chon1;
            SetColor(7);
            cout << "\t\t\t\t\t\t\tNHAP STT CUA MATRAN: ";
            cin >> chon1;
            cin.ignore();
            if (chon1 - 1 < m_arr.size())
            {
                Matrix a(m_arr[chon1 - 1]);
                SetColor(3);
                cout << "\t\t\t\t\t\t\tDU LIEU MATRAN THU " << chon1 << ": \n\n";
                a.xuat();
                a.ktra_MaTranTamGiac();
                if (check == true)
                {
                    cout << "\n\t\t\t\t\t\t\tBan co muon luu MATRAN tam giac vao file output_MATRAN.txt\n";
                    cout << "\t\t\t\t\t\t\t1. Dong Y\n";
                    cout << "\t\t\t\t\t\t\t2. Quay Lai MENU chinh\n";
                    SetColor(2);
                    cout << "\t\t\t\t\t\t\tnhap lua chon cua ban(1-2): ";
                    int k;
                    cin >> k;
                    cin.ignore();
                    switch (k)
                    {
                    case 1:
                    {
                        file.open("output_MATRAN_dac_biet.txt", ios::app);
                        file << "\t\t\t\t\t=== MA TRAN TAM GIAC ===" << endl;
                        xuat_matran_dacbiet_or_phep_tinh_MT(a, file);
                        cout << "\t\t\t\t\t\t\tDa Luu Thanh Cong\n";
                        back_(luachon);
                        break;
                    }
                    case 2:
                    {
                        luachon = 9;
                        break;
                    }
                    }
                }
                else
                {
                    cout << '\n';
                    back_(luachon);
                }
            }
            else
            {
                SetColor(4);
                cout << "\t\t\t\t\t\t\tSTT BAN NHAP VUOT QUA SO LUONG MATRAN CO TRONG MANG , VUI LONG THU LAI\n";
                back_(luachon);
            }
        }
        if (check2 == false)
        {
            SetColor(9);
            cout << "\t\t\t\t\t\t\tCHUA CO DU LIEU TRONG MANG MATRAN ^^\n";
            back_(luachon);
        }
        break;
    }
    case 2:
    {
        SetColor(5);
        cout << "\t\t\t\t\t\t\t=== KIEM TRA MA TRAN DON VI ===" << endl;
        SetColor(7);
        if (check2 == true)
        {
            cout << "\t\t\t\t\t\t\tBAN HAY NHAP STT CUA MATRAN MUON KIEM TRA\n";
            int chon1;
            SetColor(5);
            cout << "\t\t\t\t\t\t\tNHAP STT CUA MATRAN: ";
            SetColor(7);
            cin >> chon1;
            cin.ignore();
            if (chon1 - 1 < m_arr.size())
            {
                Matrix a(m_arr[chon1 - 1]);
                cout << "\t\t\t\t\t\t\tDU LIEU MATRAN THU " << chon1 << ": \n\n";
                a.xuat();
                a.ktra_MaTranDon_vi();
                if (check == true)
                {
                    cout << "\n\t\t\t\t\t\t\tBan co muon luu MATRAN DON VI vao file output_MATRAN.txt\n";
                    cout << "\t\t\t\t\t\t\t1. Dong Y\n";
                    cout << "\t\t\t\t\t\t\t2. Quay Lai MENU chinh\n";
                    SetColor(2);
                    cout << "\t\t\t\t\t\t\tnhap lua chon cua ban(1-2): ";
                    int k;
                    cin >> k;
                    cin.ignore();
                    switch (k)
                    {
                    case 1:
                    {
                        file.open("output_MATRAN_dac_biet.txt", ios::app);
                        file << "\t\t\t\t\t==== MATRAN DON VI ====" << endl;
                        xuat_matran_dacbiet_or_phep_tinh_MT(a, file);
                        cout << "\t\t\t\t\t\t\tDa Luu Thanh Cong\n";
                        back_(luachon);
                        break;
                    }
                    case 2:
                    {
                        luachon = 9;
                        break;
                    }
                    }
                }
                else
                {
                    cout << '\n';
                    back_(luachon);
                }
            }
            else
            {
                SetColor(2);
                cout << "\t\t\t\t\t\t\tSTT BAN NHAP VUOT QUA SO LUONG MATRAN CO TRONG MANG , VUI LONG THU LAI\n";
                back_(luachon);
            }
        }
        if (check2 == false)
        {
            SetColor(2);
            cout << "\t\t\t\t\t\t\tCHUA CO DU LIEU TRONG MANG MATRAN ^^\n";
            back_(luachon);
        }
        break;
    }
    case 3:
    {
        SetColor(2);
        cout << "\t\t\t\t\t\t\t=== KIEM TRA MA TRAN DUONG CHEO ===" << endl;
        SetColor(3);
        if (check2 == true)
        {
            cout << "\t\t\t\t\t\t\tBAN HAY NHAP STT CUA MATRAN MUON KIEM TRA\n";
            int chon1;
            SetColor(4);
            cout << "\t\t\t\t\t\t\tNHAP STT CUA MATRAN: ";
            SetColor(6);
            cin >> chon1;
            cin.ignore();
            if (chon1 - 1 < m_arr.size())
            {
                Matrix a(m_arr[chon1 - 1]);
                cout << "\t\t\t\t\t\t\tDU LIEU MATRAN THU " << chon1 << ": \n\n";
                a.xuat();
                a.Ktra_MaTran_DuongCheo();
                if (check == true)
                {
                    cout << "\n\t\t\t\t\t\t\tan co muon luu MATRAN duong cheo vao file output_MATRAN.txt\n";
                    cout << "\t\t\t\t\t\t\t1. Dong Y\n";
                    cout << "\t\t\t\t\t\t\t2. Quay Lai MENU chinh\n";
                    SetColor(1);
                    cout << "\t\t\t\t\t\t\tnhap lua chon cua ban(1-2): ";
                    int k;
                    cin >> k;
                    cin.ignore();
                    switch (k)
                    {
                    case 1:
                    {
                        file.open("output_MATRAN_dac_biet.txt", ios::app);
                        file << "\t\t\t\t\t==== MATRAN DUONG CHEO ====" << endl;
                        xuat_matran_dacbiet_or_phep_tinh_MT(a, file);
                        cout << "\t\t\t\t\t\t\tDa Luu Thanh Cong\n";
                        back_(luachon);
                        break;
                    }
                    case 2:
                    {
                        luachon = 9;
                        break;
                    }
                    }
                }
                else
                {
                    cout << '\n';
                    back_(luachon);
                }
            }
            else
            {
                SetColor(7);
                cout << "\t\t\t\t\t\t\tSTT BAN NHAP VUOT QUA SO LUONG MATRAN CO TRONG MANG , VUI LONG THU LAI\n";
                back_(luachon);
            }
        }
        if (check2 == false)
        {
            SetColor(7);
            cout << "\t\t\t\t\t\t\tCHUA CO DU LIEU TRONG MANG MATRAN ^^\n";
            back_(luachon);
        }
        break;
    }
    case 4:
    {
        SetColor(7);
        cout << "\t\t\t\t\t\t\t=== KIEM TRA MA TRAN DOI XUNG ===" << endl;
        SetColor(6);
        if (check2 == true)
        {
            cout << "\t\t\t\t\t\t\tBAN HAY NHAP STT CUA MATRAN MUON KIEM TRA\n";
            int chon1;
            SetColor(7);
            cout << "\t\t\t\t\t\t\tNHAP STT CUA MATRAN: ";
            cin >> chon1;
            cin.ignore();
            if (chon1 - 1 < m_arr.size())
            {
                Matrix a(m_arr[chon1 - 1]);
                cout << "\t\t\t\t\t\t\tDU LIEU MATRAN THU " << chon1 << ": \n\n";
                a.xuat();
                a.ktra_Ma_Tran_doi_xung();
                if (check == true)
                {
                    cout << "\t\t\t\t\t\t\tBan co muon luu MATRAN doi xung vao file output_MATRAN.txt\n";
                    cout << "\t\t\t\t\t\t\t1. Dong Y\n";
                    cout << "\t\t\t\t\t\t\t2. Quay Lai MENU chinh\n";
                    SetColor(2);
                    cout << "\t\t\t\t\t\t\tnhap lua chon cua ban(1-2): ";
                    int k;
                    cin >> k;
                    cin.ignore();
                    switch (k)
                    {
                    case 1:
                    {
                        file.open("output_MATRAN.txt", ios::app);
                        xuat_matran_dacbiet_or_phep_tinh_MT(a, file);
                        cout << "\t\t\t\t\t\t\tDa Luu Thanh Cong\n";
                        back_(luachon);
                        break;
                    }
                    case 2:
                    {
                        luachon = 9;
                        break;
                    }
                    }
                }
                else
                {
                    cout << '\n';
                    back_(luachon);
                }
            }
            else
            {
                SetColor(2);
                cout << "\t\t\t\t\t\t\tSTT BAN NHAP VUOT QUA SO LUONG MATRAN CO TRONG MANG , VUI LONG THU LAI\n";
                back_(luachon);
            }
        }
        if (check2 == false)
        {
            SetColor(2);
            cout << "\t\t\t\t\t\t\tCHUA CO DU LIEU TRONG MANG MATRAN ^^\n";
            back_(luachon);
        }
        break;
    }
    case 0:
    {
        luachon = 9;
        break;
    }
    default:
    {
        luachon = 4;
        break;
    }
    }
}
void MENU_MAIN(ofstream &file, ifstream &filein, int &luachon, vector<Vector> &v_arr, vector<Matrix> &m_arr)
{
    bool check2 = false;
    bool check1 = false;
    while (true)
    {
        switch (luachon)
        {
        case 9:
        {
            menu_tong(luachon);
            break;
        }
        case 1:
        {
            quan_ly_vector(luachon, filein, file, v_arr, check1);
            break;
        }
        case 2:
        {
            quan_ly_Matrix(luachon, filein, file, m_arr, check2);
            break;
        }
        case 3:
        {
            quan_ly_vector_dac_biet(luachon, file, v_arr, check1);
            break;
        }
        case 4:
        {
            quan_ly_matrix_dac_biet(luachon, file, m_arr, check2);
            break;
        }
        case 5:
        {
            cout << "\t\t\t\t\t\t\tCAM ON BAN DA SU DUNG CHUONG TRINH ^^\n";
            cout << "\t\t\t\t\t\t\t\t === KET THUC ===";
            exit(1);
            break;
        }
        default:
        {
            luachon = 9;
            break;
        }
        }
    }
}
int main()
{
    vector<Vector> v_arr;
    vector<Matrix> m_arr;
    ofstream fileout;
    ifstream filein;
    int luachon = 9;
    MENU_MAIN(fileout, filein, luachon, v_arr, m_arr);
    return 0;
}