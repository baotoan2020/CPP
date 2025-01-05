// DeQuy.cpp : This file contains the 'main' function. Program execution begins and ends there.
// de quy la mot dang cua vong lap
// 1/ xac dinh dieu kien dung
// 2/ xac dinh tham so truyen vao ham de quy
// 3/ 
// cac loai de quy
// - de quy tuyen tinh: than ham chi co mot loi goi de quy
// - de quy nhi phan: co hai loi goi ham de quy
// - de quy phi tuyen: goi de quy nam trong vong lap
// - de quy ho tuong: co hai ham, trong than ham nay goi ham kia va nguoc lai

#include <iostream>
// khai bao nguyen mau ham
void InSoNguyenNden1(int n);
void InSoNguyen1denN(int n);
void InSoChan1denN(int n);
void InSoLeNden1(int n);

int main()
{
	int n = 10;
	//InSoNguyenNden1(n);
	//InSoNguyen1denN(n);
	//InSoChan1denN(n);
	InSoLeNden1(n);
}
// in ra nhung so nguyen tu 1 den n
void InSoNguyenNden1(int n)
{
    // 1. dieu kien dung
	if (n < 1)
		return;
	// 2. nhung lenh thuc thi moi lan lap: in ra n
	printf("%5d", n);

	// 3. goi de quy
	InSoNguyenNden1(n - 1);//tham so truyen vao ham de quy: n - 1

	// 4. nhung cau lenh nam trong ngan xep
}
void InSoNguyen1denN(int n)
{
	// 1. dieu kien dung
	if (n < 1)
		return;
	// 2. nhung lenh thuc thi moi lan lap: in ra n
	
	// 3. goi de quy
	InSoNguyen1denN(n - 1);//tham so truyen vao ham de quy: n - 1

	// 4. nhung cau lenh nam trong ngan xep
	printf("%5d", n);
}
void InSoChan1denN(int n)
{
	// 1. dieu kien dung
	if (n < 1)
		return;
	// 2. nhung lenh thuc thi moi lan lap: in ra n

	// 3. goi de quy
	InSoChan1denN(n - 1);//tham so truyen vao ham de quy: n - 1

	// 4. nhung cau lenh nam trong ngan xep
	if (n % 2 == 0)
		printf("%5d", n);
}
void InSoLeNden1(int n)
{
	// 1. dieu kien dung
	if (n < 1)
		return;
	// 2. nhung lenh thuc thi moi lan lap: in ra n le
	if (n % 2 != 0)
		printf("%5d", n);

	// 3. goi de quy
	InSoLeNden1(n - 1);//tham so truyen vao ham de quy: n - 1

	// 4. nhung cau lenh nam trong ngan xep
}