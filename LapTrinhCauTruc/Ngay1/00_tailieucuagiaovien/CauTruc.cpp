#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define SIZE 100

struct NgayThang
{
	int Ngay, Thang, Nam;
};

void NhapNgayThang(NgayThang& nt)
{
	printf("\nNhap Ngay thang (dd/mm/yyyy): ");
	scanf("%d/%d/%d", &nt.Ngay, &nt.Thang, &nt.Nam);
}

void InNgayThang(NgayThang nt)
{
	printf("%02d/%02d/%04d", nt.Ngay, nt.Thang, nt.Nam);
}

struct SinhVien
{
	int Ma;
	char Ten[50];
	NgayThang NamSinh;
	float DTB;
};

void NhapSinhVien(SinhVien& sv)
{
	printf("\n Nhap Ma: ");
	scanf("%d", &sv.Ma);
	printf("\n Nhap Ten: ");
	rewind(stdin);
	gets_s(sv.Ten);
	printf("\n Nhap Nam sinh: ");
	NhapNgayThang(sv.NamSinh);
	printf("\n Nhap DTB: ");
	scanf("%f", &sv.DTB);
}

void InSinhVien(SinhVien sv)
{
	printf("\n %-2d %-20s ", sv.Ma, sv.Ten);
	InNgayThang(sv.NamSinh);
	printf(" %-4.2f", sv.DTB);
}

void NhapTongSoPhanTu(int& n)
{
	do
	{
		printf("\n Nhap tong so phan tu (0 < n <= %d) = ", SIZE);
		scanf("%d", &n);
	} while (!(n > 0 && n <= SIZE));
}

void NhapMang(SinhVien sv[SIZE], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("\n Nhap thong tin sinh vien sv[%d] = ", i);
		NhapSinhVien(sv[i]);
	}
}

void InHeader()
{
	printf("\n %-2s %-20s %10s %-4s", "Ma", "Ten", "Nam Sinh", "DTB");
}

void XuatMang(SinhVien sv[SIZE], int n)
{
	InHeader();
	for (int i = 0; i < n; i++)
	{
		// printf("\n Thong tin sinh vien sv[%d] = ", i);
		InSinhVien(sv[i]);
	}
}

void InSinhVienTheoNam(SinhVien sv[SIZE], int n, int Nam)
{
	printf("\n\n Sinh vien co nam sinh >= %d", Nam);
	InHeader();
	for (int i = 0; i < n; i++)
	{
		if (sv[i].NamSinh.Nam >= Nam)
			InSinhVien(sv[i]);
	}
}

void TaoDuLieuTest(SinhVien sv[SIZE], int& n)
{
	n = 7;
	sv[0] = { 1, "Nguyen Trai", { 1, 1, 2005 }, 6.88 };
	sv[1] = { 2, "Nguyen Thi Minh Khai", { 19, 12, 2005 }, 5 };
	sv[2] = { 3, "Le Hong Phong", {1, 1, 2003 }, 7 };
	sv[3] = { 4, "An Duong Vuong", {20, 3, 2006 }, 9.8 };
	sv[4] = { 5, "Thanh Thai", {30, 4, 2007}, 6 };
	sv[5] = { 6, "Au Co", {22, 3, 2003}, 7 };
	sv[6] = { 7, "Lac Long Quan", {23, 2, 2006}, 9.8 };
	sv[7] = { 8, "Le Dai Hanh", {12, 5, 2007}, 6 };
}

void main()
{
	SinhVien sv[SIZE];
	int n = 0;

	// NhapTongSoPhanTu(n);
	// NhapMang(sv, n);
	TaoDuLieuTest(sv, n);
	XuatMang(sv, n);

	InSinhVienTheoNam(sv, n, 2005);
}