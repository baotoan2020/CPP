// ThaoTacVoiTapTin.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS // define tat warning ham scanf()
#define MAX_LEN 256// so ki tu toi da ham fgets co the lay trong mot hang cua tap tin van ban
#include <iostream>
// khai bao nguyen mau ham
int TaoTapTin(char* tenTapTin);
int DocTapTinVB(char* tenTapTin);
int GhiThemVaoTapTinVB(char* tenTapTin);
int GhepHaiTapTinVB(char* taptin1, char* taptin2);

int main()
{
	char tentaptin[100] = "taptinso1.txt", tentaptin2[100] = "taptinso2.txt";
	
	TaoTapTin(tentaptin);
	DocTapTinVB(tentaptin);
	GhiThemVaoTapTinVB(tentaptin);
	GhepHaiTapTinVB(tentaptin, tentaptin2);
	printf("tap tin sau khi ghep:\n");
	DocTapTinVB(tentaptin);
}
int TaoTapTin(char* tenTapTin)
{
	// tao mot tap tin moi, neu co tap tin trung ten se bi xoa va ghi de(wt: write text)
    FILE* filePoint = fopen(tenTapTin, "wt");

	// kiem tra tao tap tin thanh cong
	if (filePoint != NULL)
	{
		// ghi noi dung vao tap tin
		fprintf(filePoint, "Que huong la chum khe ngot\n");
		fprintf(filePoint, "Cho con treo hai moi ngay\n");

		// dong tap tin
		fclose(filePoint);
		return 1;
	}
	return 0;
}
int DocTapTinVB(char *tenTapTin)
{
	char s[MAX_LEN];
	// mo tap tin van ban de doc(rt: read text)
	FILE* filePoint = fopen(tenTapTin, "rt");
	// kiem tra mo file thanh cong
	if ( filePoint != NULL)
	{
		// kiem tra da den cuoi file chua
		while (!feof(filePoint))
			// luu noi dung cua dong vao s,kiem tra s co null khong,
			if (fgets(s,MAX_LEN,filePoint) != NULL)// chi doc duoc 256 ki tu
				// in noi dung ra man hinh
				printf("%s", s);
		// dong tap tin
		fclose(filePoint);
		return 1;
	}
	return 0;
}
int GhiThemVaoTapTinVB(char* tenTapTin)
{
	char s[MAX_LEN];
	// mo tap tin van ban de doc(at: add text)
	FILE* filePoint = fopen(tenTapTin, "at");
	// kiem tra mo file thanh cong
	if (filePoint != NULL)
	{
		printf("nhap du lieu muon them:\n");
		// luu chuoi tren man hinh vao s
		gets_s(s, MAX_LEN);
		// ghi chuoi s vao file
		fprintf(filePoint, "%s\n", s);
		// dong tap tin
		fclose(filePoint);
		return 1;
	}
	return 0;
}
int GhepHaiTapTinVB(char* taptin1, char* taptin2)
{
	char s[MAX_LEN];
	FILE *filePoint1, *filePoint2;
	// mo tap tin 1 de ghi them
	filePoint1 = fopen(taptin1, "at");
	// mo tap tin 2 de doc
	filePoint2 = fopen(taptin2, "rt");
	// kiem tra mo tap tin thanh cong
	if (filePoint1 == NULL && filePoint2 == NULL)// khong mo duoc ca hai file
		return -2;
	else if (filePoint1 == NULL)// chi file 1 khong mo duoc
	{
		// dong lai file 2 va ket thuc
		fclose(filePoint2);
		return -1;
	}
	else if (filePoint2 == NULL)// chi file 2 khong mo duoc
	{
		// dong lai file 1 va ket thuc
		fclose(filePoint1);
		return -1;
	}
	else// mo hai file thanh cong
	{
		// kiem tra da den cuoi file 2 chua
		while (!feof(filePoint2))
			// luu noi dung cua dong vao s,kiem tra s co null khong,
			if (fgets(s, MAX_LEN, filePoint2) != NULL)// chi doc duoc 256 ki tu
				// ghi chuoi s vao file 1
				fprintf(filePoint1, "%s", s);
		//dong 2 file
		fclose(filePoint1);
		fclose(filePoint2);
		return 1;
	}
}
