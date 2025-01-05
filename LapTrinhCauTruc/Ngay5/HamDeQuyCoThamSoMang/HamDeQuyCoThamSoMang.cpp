// HamDeQuyCoThamSoMang.cpp : This file contains the 'main' function. Program execution begins and ends there.
#define _CRT_SECURE_NO_WARNINGS //define nay dung de tat warning cua ham scanf()
#define SIZE 100
#include <iostream>

// khai bao nguyen mau ham
void NhapMangDQ(int a[SIZE], int n);
void XuatMangDQ(int a[SIZE], int n);
void TaoMangNgauNhienDQ(int a[SIZE], int n);
bool isPrime(int n);
void InSoNguyenToTrongMangDQ(int a[SIZE], int n);
float TinhTrungBinhCongMangDQ(int a[SIZE], int n);

int main()
{
	int mang1[SIZE];
	int n = 5;
	//isPrime(n) ? printf("%d la so nguyen to", n) : printf("%d khong phai so nguyen to", n);
	NhapMangDQ(mang1, n);
	//XuatMangDQ(mang1, n);
	//TaoMangNgauNhienDQ(mang1, n);
	XuatMangDQ(mang1, n);
	printf("\n so nguyen to co trong mang: ");
	InSoNguyenToTrongMangDQ(mang1, n);
	printf("\n trung binh cong = %f", TinhTrungBinhCongMangDQ(mang1, n));
}
void NhapMangDQ(int a[SIZE], int n)
{
    // 1. dieu kien dung
	if (n == 0)
		return;
	// 2. lenh thuc thi truoc khi goi de quy(khong co)
	// 3. goi de quy
	NhapMangDQ(a, n - 1); // tham so truyen vao ham de quy: n - 1
	// 4. lenh thuc thi sau khi goi de quy
	printf("\nnhap a[%d] = ", n - 1);
	scanf("%d", &a[n - 1]);
}
void XuatMangDQ(int a[SIZE], int n)
{
	// 1. dieu kien dung
	if (n == 0)
		return;
	// 2. lenh thuc thi truoc khi goi de quy(khong co)
	// 3. goi de quy
	XuatMangDQ(a, n - 1); // tham so truyen vao ham de quy: n - 1
	// 4. lenh thuc thi sau khi goi de quy
	printf("%6d", a[n - 1]);
}
void TaoMangNgauNhienDQ(int a[SIZE], int n)
{
	// 1. dieu kien dung
	if (n == 0)
		return;
	// 2. lenh thuc thi truoc khi goi de quy
	// khoi dong bo tao so ngau nhien de cac so khong trung nhau
	srand((unsigned int)time(NULL));
	// 3. goi de quy
	TaoMangNgauNhienDQ(a, n - 1); // tham so truyen vao ham de quy: n - 1
	// 4. lenh thuc thi sau khi goi de quy
	a[n - 1] = rand(); // ham rand() tao ra so ngau nhien tu 0 den 32767
}
void InSoNguyenToTrongMangDQ(int a[SIZE], int n)
{
	// 1. dieu kien dung
	if (n == 0)
		return;
	// 2. lenh thuc thi truoc khi goi de quy
	if (isPrime(a[n - 1]))
		printf("%6d", a[n - 1]);
	// 3. goi de quy
	InSoNguyenToTrongMangDQ(a, n - 1); // tham so truyen vao ham de quy: n - 1
	// 4. lenh thuc thi sau khi goi de quy
}
bool isPrime(int n)
{
	if (n <= 1)
		return false;
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return false;
	return true;
}
float TinhTrungBinhCongMangDQ(int a[SIZE], int n)
{
	//ham nay chua dung
	// 1. dieu kien dung
	if (n == 0)
		return 0;
	// 2. lenh thuc thi truoc khi goi de quy(khong co)
	// 3. goi de quy
	return (TinhTrungBinhCongMangDQ(a, n - 1) + a[n - 1]) / 2.0; // tham so truyen vao ham de quy: n - 1
	// 4. lenh thuc thi sau khi goi de quy(khong co)
}