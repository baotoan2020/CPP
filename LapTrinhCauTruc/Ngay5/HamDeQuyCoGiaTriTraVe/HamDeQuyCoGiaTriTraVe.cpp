// HamDeQuyCoGiaTriTraVe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
// khai bao nguyen mau ham
int TinhTongDQ(int n); //1. tinh tong cac so nguyen 1 <= n
int TinhTongLeDQ(int n); // 2. tinh tong cac so le 1 <= n
void TachSoDQ(int n); // 3. tach so
int TinhTongChuSoDQ(int n); // 4. tinh tong chu so
int TinhTongChuSoChanDQ(int n); // 5. tinh tong chu so chan
int DemSoChanDQ(int n); // 6. dem so chan

int main()
{
	int n = 12345;
	TachSoDQ(n);
	printf("\ntong cac chu so: %2d", TinhTongChuSoDQ(n));
	printf("\ntong cac chu so chan: %2d", TinhTongChuSoChanDQ(n));
	printf("\nso cac chu so chan: %2d", DemSoChanDQ(n));

}
int TinhTongDQ(int n)
{
	// 1. dieu kien dung
	if (n == 0)
		return 0;
	// 2. lenh thuc thi truoc khi goi de quy(khong co)
	// 3.,4. goi de quy + lenh thuc thi sau khi goi de quy
	return TinhTongDQ(n - 1) + n; // tham so truyen vao ham de quy: n - 1
}
int TinhTongLeDQ(int n)
{
	// 1. dieu kien dung
	if (n == 0)
		return 0;
	// 2. lenh thuc thi truoc khi goi de quy(khong co)
	// 3.,4. goi de quy + lenh thuc thi sau khi goi de quy
	// * de quy nhi phan: than ham co hai loi goi de quy khong tuong minh
	return TinhTongLeDQ(n - 1) + (n % 2 == 0 ? 0 : n); // tham so truyen vao ham de quy: n - 1
}
void TachSoDQ(int n)
{
	// 1. dieu kien dung
	if (n == 0)
		return;
	// 2. lenh thuc thi truoc khi goi de quy(khong co)
	// 3. goi de quy
	TachSoDQ(n / 10); // tham so truyen vao ham de quy: n / 10
	// 4. lenh thuc thi sau khi goi de quy
	printf("%2d", n % 10);
}
int TinhTongChuSoDQ(int n)
{
	// 1. dieu kien dung
	if (n <= 0)
		return 0 ;
	// 2. lenh thuc thi truoc khi goi de quy(khong co)
	// 3.,4. goi de quy + lenh thuc thi sau khi goi de quy
	return TinhTongChuSoDQ(n / 10) + n % 10; // tham so truyen vao ham de quy: n / 10
}
int TinhTongChuSoChanDQ(int n)
{
	// 1. dieu kien dung
	if (n <= 0)
		return 0;
	// 2. lenh thuc thi truoc khi goi de quy(khong co)
	// 3.,4. goi de quy + lenh thuc thi sau khi goi de quy
	// * de quy nhi phan: than ham co hai loi goi de quy khong tuong minh
	return TinhTongChuSoChanDQ(n / 10) + ((n % 10) % 2 != 0 ? 0 : (n % 10)); // tham so truyen vao ham de quy: n / 10
}
int DemSoChanDQ(int n)
{
	// 1. dieu kien dung
	if (n == 0)
		return 0;
	// 2. lenh thuc thi truoc khi goi de quy(khong co)
	// 3.,4. goi de quy + lenh thuc thi sau khi goi de quy
	// * de quy nhi phan: than ham co hai loi goi de quy khong tuong minh
	return DemSoChanDQ(n / 10) + ((n % 10) % 2 != 0 ? 0 : 1); // tham so truyen vao ham de quy: n / 10
}