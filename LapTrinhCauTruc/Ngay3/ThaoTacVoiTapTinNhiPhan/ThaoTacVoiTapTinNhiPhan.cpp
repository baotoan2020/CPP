// ThaoTacVoiTapTinNhiPhan.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS// define tat warning ham fopen
#define SIZE 20
#include <iostream>

struct SINHVIEN
{
    char MaSo[10];
    char HoTen[30];
    int NamSinh;
    double Diem;
};
struct DSSV
{
    int n;
    SINHVIEN arr[SIZE];
};

// khai bao nguyen mau ham
int TaoTapTinDSSV(char* tentaptin, DSSV u);// tao tap tin luu mang cau truc danh sach sinh vien
int DocTapTinDSSV(char* tentaptin);// doc danh sach sinh vien chua trong tap tin nhi phan
void Xuat1SV(SINHVIEN& sv);// xuat thong tin mot sinh vien ra man hinh
int DocTapTinDSSVLuuVaoBien(char* tentaptin, DSSV* u);//doc DSSV tu tap tin nhi phan, luu vao bien u
int GhiThemSvVaoTapTinDSSV(char* tentaptin, SINHVIEN sv);// ghi them mot SV vao tap tin nhi phan
int TimMaSvSuaNamSinhTrongTTNhiPhanDSSV(char* tentaptin, char* maSo, int namSinhMoi);// sua nam sinh tai vi tri trung voi ma sinh vien
int DoiHoaTapTin(char* tentaptin);// doi hoa toan noi dung tap tin

int main()
{
    std::cout << "Hello World!\n";
}

int TaoTapTinDSSV(char* tentaptin, DSSV u)
{
    // khai bao bien con tro file
    FILE *filePoint;
    // mo tap tin nhi phan de ghi, neu tap tin da ton tai se bi xoa(wb: write binary)
    filePoint = fopen(tentaptin, "wb");
    // kiem tra mo file thanh cong
    if (filePoint != NULL)
    {
        //ghi u.n cau truc, moi cau truc kich thuoc sizeof(SINHVIEN) chua trong mang u.arr vao file filePoint
        fwrite(u.arr, sizeof(SINHVIEN), u.n, filePoint);
        // dong tap tin sau khi ghi xong
        fclose(filePoint);
        return 1;
    }
    return 0;
}
int DocTapTinDSSV(char* tentaptin)
{
    FILE* filePoint;
    SINHVIEN sv;
    // mo tap tin nhi phan de doc, tap tin can ton tai, neu khong se bao loi(rb: read bianry)
    filePoint = fopen(tentaptin, "rb");
    // kiem tra mo file thanh cong
    if (filePoint != NULL)
    {
        // kiem tra da doc het file hay chua
        while (!feof(filePoint))
            // doc mot cau truc kich thuoc SINHVIEN tu tap tin filePoint, ghi vao bien sv. 
            // ham tra ve so phan tu thuc su doc duoc.
            if (fread(&sv, sizeof(SINHVIEN), 1, filePoint) == 1)
                // in ra thong tin sinh vien vua doc duoc
                Xuat1SV(sv);
        // dong tap tin sau khi doc xong
        fclose(filePoint);
        return 1;
    }
    return 0;
}
void Xuat1SV(SINHVIEN &sv)
{
    printf("Ho Ten : %s\n", sv.HoTen);
    printf("Ma so: %s\n", sv.MaSo);
    printf("Nam Sinh: %d\n", sv.NamSinh);
    printf("Diem: %.2f", sv.Diem);
}
int DocTapTinDSSVLuuVaoBien(char *tentaptin, DSSV *u)
{
    SINHVIEN sv;
    // mo tap tin nhi phan de doc, tap tin can ton tai, neu khong se bao loi(rb: read bianry)
    FILE* filePoint = fopen(tentaptin, "rb");
    // kiem tra mo file thanh cong
    if (filePoint != NULL)
    {
        // cau lenh nay y nghia la gi ???
        // kha giong toan tu "." co the la tuong duong cua u.n
        u -> n = 0;
        // kiem tra da doc het file hay chua
        while (!feof(filePoint) && u -> n < SIZE)// cho n < SIZE co nghia la gi.
            // doc mot cau truc kich thuoc SINHVIEN tu tap tin filePoint, ghi vao bien sv. 
            // ham tra ve so phan tu thuc su doc duoc.
            if (fread(&u ->  arr[u -> n], sizeof(SINHVIEN), 1, filePoint) == 1)
                // cau lenh nay la gi
                u -> n++;
        // dong tap tin sau khi doc xong
        fclose(filePoint);
        return 1;
    }
    return 0;
}
int GhiThemSvVaoTapTinDSSV(char* tentaptin, SINHVIEN sv)
{
    // mo tap tin nhi phan de ghi them, neu tap tin chua ton tai se duoc tao moi(ab: add binary)
    FILE* filePoint = fopen(tentaptin, "ab");
    // kiem tra mo file thanh cong
    if (filePoint != NULL)
    {
        // ghi mot cau truc co kich thuoc SINHVIEN chua trong bien sv vao file filePoint
        fwrite(&sv, sizeof(SINHVIEN), 1, filePoint);
        // dong tap tin sau khi doc xong
        fclose(filePoint);
        return 1;
    }
    return 0;
}
int TimMaSvSuaNamSinhTrongTTNhiPhanDSSV(char* tentaptin, char* maSo, int namSinhMoi)
{
    SINHVIEN sv;
    int timThay = 0, viTri;
    // mo tap tin nhi phan de doc va ghi, tap tin can ton tai, neu khong se bao loi(r+b: read+ bianry)
    FILE* filePoint = fopen(tentaptin, "r+b");
    // kiem tra mo file thanh cong
    if (filePoint != NULL)
    {
        // kiem tra da doc het file hay chua
        while (!feof(filePoint))
        {
            // xac dinh vi tri con tro
            viTri = ftell(filePoint);
            // doc mot cau truc kich thuoc SINHVIEN tu tap tin filePoint, ghi vao bien sv. 
            // ham tra ve so phan tu thuc su doc duoc.
            if (fread(&sv, sizeof(SINHVIEN), 1, filePoint) == 1)
                // kiem tra ma so trung voi ma so sinh vien can doi nam sinh
                if (strcmp(sv.MaSo, maSo) == 0)
                {
                    // doi nam sinh moi
                    sv.NamSinh = namSinhMoi;
                    // di chuyen con tro cua tap tin den viTri
                    fseek(filePoint, viTri, SEEK_SET);
                    // ghi mot cau truc co kich thuoc SINHVIEN chua trong bien sv vao file filePoint vao vi tri con tro hien tai
                    fwrite(&sv, sizeof(SINHVIEN), 1, filePoint);
                    timThay = 1;
                    break;
                }
        }
        // dong tap tin sau khi doc xong
        fclose(filePoint);
        return(timThay ? 1 : -1);
    }
    return 0;
}
int DoiHoaTapTin(char* tentaptin)
{
    int viTri;
    char ch;
    // mo tap tin nhi phan de doc va ghi, tap tin can ton tai, neu khong se bao loi(r+b: read+ bianry)
    FILE* filePoint = fopen(tentaptin, "r+b");
    // kiem tra mo file thanh cong
    if (filePoint != NULL)
    {
        // kiem tra da doc het file hay chua
        while (!feof(filePoint))
            // doc mot ki tu trong tap tin filePoint, ghi vao bien ch 
            // ham tra ve ma 256 doc duoc, neu that bai hoac gap cuoi tap tin ham tra ve EOF.
            if (ch = fgetc(filePoint) != EOF)
                // kiem tra la chu thuong
                if (ch >= 'a' && ch <= 'z')
                {
                    // doi thuong thanh hoa
                    ch -= 32;
                    // luu vi tri se doc tiep
                    viTri = ftell(filePoint);
                    // lui con tro lai mot byte
                    fseek(filePoint, -1, SEEK_CUR);
                    // thay ki tu hoa vao file
                    fputc(ch, filePoint);
                    // chuyen con tro tro lai vi tri tiep theo
                    fseek(filePoint, viTri, SEEK_SET);
                }
        // dong tap tin sau khi doc xong
        fclose(filePoint);
        return 1;
    }
    return 0;
}