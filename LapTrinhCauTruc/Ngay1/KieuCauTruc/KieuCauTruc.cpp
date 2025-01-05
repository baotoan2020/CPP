// BaiTap1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
struct NgayThang
{
    int Ngay, Thang, Nam;
};
struct NguoiDung
{
    char TenDangNhap[100];
    char MatKhau[100];
    char HoTen[100];
    NgayThang NgaySinh;
    int CCMND;
    char DiaChi[500];
    bool GioiTinh;
    bool TinhTrang;//(activated hoac block)
};
// bien toan cuc
bool TRANGTHAIDANGNHAP;
// khai bao nguyen mau ham
void TaoDuLieuNguoiDung(NguoiDung nguoidung[100], int& n);
void DangNhap(NguoiDung nguoidung[], int n);
void DoiMatKhau();
void DangXuat();

int main()
{
    NguoiDung nguoidung[100];
    int n;
    TaoDuLieuNguoiDung( nguoidung, n);
    DangNhap(nguoidung, n);
    DoiMatKhau;
    DangXuat;

}
void TaoDuLieuNguoiDung(NguoiDung nguoidung[100], int& n)
{
    n = 7;
    nguoidung[0] = {"tendangnhap1", "matkhau1", "Nguyen Trai",          {01, 01, 2005}, 574869485, "Tp. Ho Chi Minh", 0, 1};
    nguoidung[1] = {"tendangnhap2", "matkhau2", "Nguyen Thi Minh Khai", {19, 12, 2005}, 758183745, "Sai gon",         1, 0};
    nguoidung[2] = {"tendangnhap3", "matkhau3", "Le Hong Phong",        {01, 01, 2003}, 758675647, "Cho Lon",         0, 0};
    nguoidung[3] = {"tendangnhap4", "matkhau4", "An Duong Vuong",       {20, 03, 2006}, 678403968, "Thu Duc",         0, 1};
    nguoidung[4] = {"tendangnhap5", "matkhau5", "Thanh Thai",           {30, 04, 2007}, 867506867, "quan 9",          0, 0};
    nguoidung[5] = {"tendangnhap6", "matkhau6", "Au Co",                {22, 03, 2003}, 768594768, "Dong Nai",        1, 0};
    nguoidung[6] = {"tendangnhap7", "matkhau7", "Lac Long Quan",        {23, 02, 2006}, 365748985, "Tp. Ho Chi Minh", 0, 1};
    nguoidung[7] = {"tendangnhap8", "matkhau8", "Le Dai Hanh",          {12, 05, 2007}, 576890987, "Bien Hoa",        0, 0};
}
void DangNhap(NguoiDung nguoidung[], int n)
{
    char tenDangNhap[100], matkhau[100];
    // nhap ten dang nhap
    printf("ten dang nhap: ");
    gets_s(tenDangNhap);
    //nhap mat khau
    printf("\nmat khau: ");
    gets_s(matkhau);
    //kiem tra tren du lieu
    for (int i = 0; i < n; i++)
        if (strcmp(tenDangNhap, nguoidung[i].TenDangNhap) == 0 && strcmp(matkhau, nguoidung[i].MatKhau) == 0)
        {
            TRANGTHAIDANGNHAP = 1;
            break;
        }
    printf("%s",TRANGTHAIDANGNHAP ? "dang nhap thanh cong" : "dang nhap that bai");
}
void DangXuat()
{
    TRANGTHAIDANGNHAP = 0;
}
void DoiMatKhau()
{

}