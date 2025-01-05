#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define SIZE 100

int DANG_NHAP_THANH_CONG = 0;
char TEN_DANG_NHAP[100];

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

struct NguoiDung
{
	char TenDangNhap[100];
	char MatKhau[100];
	char HoTen[100];
	NgayThang NgaySinh;
	bool TinhTrang;
	int LoaiNguoiDung; // 1. Quản lý thư viện 2. Chuyên viên
};

void InThongTinNguoiDung(NguoiDung nd)
{
	printf("\n %-15s %-15s %-20s ", nd.TenDangNhap, nd.MatKhau, nd.HoTen);
	InNgayThang(nd.NgaySinh);
	printf(" %-15s %-15s", nd.TinhTrang == true ? "activated" : "block", 
							nd.LoaiNguoiDung == 1 ? "QLTV" : "Chuyen vien");
}

void InHeader()
{
	printf("\n %-15s %-15s %-20s %10s %-10s %-10s", "TenDangNhap", "MatKhau", "HoTen", "NgaySinh", "TinhTrang", "LoaiNguoiDung");
}

void XuatMang(NguoiDung sv[SIZE], int n)
{
	InHeader();
	for (int i = 0; i < n; i++)
	{
		InThongTinNguoiDung(sv[i]);
	}
}

void TaoDuLieuTest(NguoiDung sv[SIZE], int& n)
{
	n = 5;
	sv[0] = { "nguyentrai", "123456", "Nguyen Trai", { 1, 1, 2005 }, 1, 1 };
	sv[1] = { "lehongphong", "123456", "Le Hong Phong", { 1, 1, 2005 }, 1, 1 };
	sv[2] = { "auco", "123456", "Au Co", { 1, 1, 2005 }, 1, 1 };
	sv[3] = { "laclongquan", "123456", "Lac Long Quan", { 1, 1, 2005 }, 1, 1 };
	sv[4] = { "thanhthai", "123456", "Thanh Thai", { 1, 1, 2005 }, 1, 1 };
}

int Login(NguoiDung nd[SIZE], int n, char TenDangNhap[100], char MatKhau[100])
{
	for (int i = 0; i < n; i++)
	{
		if (_stricmp(nd[i].TenDangNhap, TenDangNhap) == 0
			&& strcmp(nd[i].MatKhau, MatKhau) == 0)
		{
			DANG_NHAP_THANH_CONG = 1;
			strcpy(TEN_DANG_NHAP, nd[i].TenDangNhap);
			printf("Chao mung '%s' da quay tro lai he thong", nd[i].HoTen);
			return 1;
		}
	}
	return 0;
}

void ThayDoiMatKhau(NguoiDung nd[SIZE], int n, char TenDangNhap[100], char MatKhau[100])
{
	for (int i = 0; i < n; i++)
	{
		if (_stricmp(nd[i].TenDangNhap, TenDangNhap) == 0)
		{
			strcpy(nd[i].MatKhau, MatKhau);
		}
	}
}

void main()
{
	NguoiDung nd[SIZE];
	int n = 0;

	TaoDuLieuTest(nd, n);
	XuatMang(nd, n);

	char TenDangNhap[100];
	char MatKhau[100];

	int menu, subMenu;
	
	do
	{
		printf("\n*** Vui long chon chuc nang ***");
		printf("\n 1. Quan ly nguoi dung");
		printf("\n 2. Quan ly doc gia");
		printf("\n 0. Thoat");
		printf("\n Vui long chon chuc nang: ");
		scanf("%d", &menu);

		switch (menu)
		{
		case 1:
			do
			{
				printf("\n*** 1. Quan ly nguoi dung ***");
				printf("\n 11. Dang nhap");
				printf("\n 12. Dang xuat");
				printf("\n 13. Thay doi mat khau");
				printf("\n 14. Cap nhat thong tin");
				printf("\n 15. Tao nguoi dung");
				printf("\n 0. Thoat");
				printf("\n Vui long chon chuc nang: ");
				scanf("%d", &subMenu);

				switch (subMenu)
				{
				case 11:
					printf("\nNhap TenDangNhap: ");
					rewind(stdin);
					gets_s(TenDangNhap);
					printf("\nNhap MatKhau: ");					
					gets_s(MatKhau);
					if (Login(nd, n, TenDangNhap, MatKhau) == 0)
					{
						printf("\nLogin that bai");
					}
					break;
				case 12:
					if (DANG_NHAP_THANH_CONG == 0) 
					{
						printf("\n Vui long dang nhap de dang xuat");
					} 
					else
					{
						DANG_NHAP_THANH_CONG = 0;
					}
						
					break;
				case 13:
					if (DANG_NHAP_THANH_CONG == 0)
					{
						printf("\n Vui long dang nhap de dang xuat");
					}
					printf("\nNhap MatKhau: ");
					rewind(stdin);
					gets_s(MatKhau);
					ThayDoiMatKhau(nd, n, TEN_DANG_NHAP, MatKhau);
				}
			} while (subMenu != 0);
			break;
		}

		
	} while (menu != 0);
	
}