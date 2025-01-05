// DanhSachKe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS //define nay dung de tat warning cua ham scanf()
#define MAX 100
// khai bao kieu danh sach ke
struct LIST
{
    int num;// so luong nut hien co
    int nodes[MAX];// moi nut la mot phan tu cua mang
};
#include <iostream>
// khai bao nguyen mau ham
void Initialize(LIST* list);
int ListSize(LIST* list);
bool Full(LIST* list);
bool Empty(LIST* list);
void Insert(LIST* list, int vitri, int x);
int Remove(LIST* list, int vitri);
void Replace(LIST* list, int vitri, int x);
void InterChangeSort(LIST* list);
int LinearSearch(LIST* list, int x);
int BinarySearch(LIST* list, int x);
void Traverse(LIST* list);
void Clear(LIST* list);
void Swap(int& a, int& b);
void TaoDSKeNgauNhien(LIST* list);
int main()
{
    int x = 5;
    LIST list;
    Initialize(&list);// vi sao phai khoi tao list, neu khong khoi tao co sao khong
    TaoDSKeNgauNhien(&list);
    printf("\ndanh sach ke ngau nhien: ");
    Traverse(&list);
    printf(LinearSearch(&list, x) >= 0 ? "\ntim thay %d tai vi tri %d" : "\nkhong tim thay %d", x, LinearSearch(&list, x));
    InterChangeSort(&list);
    printf("\ndanh sach ke sau khi sap xep: ");
    Traverse(&list);
    printf(BinarySearch(&list, x) >= 0 ? "\ntim thay %d tai vi tri %d" : "\nkhong tim thay %d", x, BinarySearch(&list, x));

}
void Initialize(LIST* list)// khoi dong danh sach ke
{
    list->num = 0;
}
int ListSize(LIST* list)// xac dinh so nut
{
    return list->num;
}
bool Full(LIST* list)// kiem tra sanh sach day chua
{
    return list->num == MAX;
}
bool Empty(LIST* list)// kiem tra danh sach ke rong
{
    return list->num == 0;
}
void Insert(LIST* list, int vitri, int x)
{
    // kiem tra vi tri hop le
    if (vitri < 0 || vitri > list->num)
        printf("vi tri khong hop le");
    // kiem tra danh sach co bi day
    else if (Full(list))
        printf("danh sach bi day");
    // bat dau chen
    else
    {
        // doi nhung phan tu tu vi tri tro ve sau sang phai mot don vi
        for (int i = list->num - 1; i >= vitri; i--)
            list->nodes[i + 1] = list->nodes[i];
        // chen x vao vi tri
        list->nodes[vitri] = x;
        // tang so phan tu len 1 don vi
        list->num++;
    }
}
int Remove(LIST* list, int vitri)
{
    int x;
    // kiem tra danh sach rong
    if (Empty(list))
    {
        printf("danh sach rong");
        return -1;
    }
    // kiem tra vi tri hop le
    else if (vitri < 0 || vitri >= list->num)
    {
        printf("vi tri khong hop le");
        return -2;
    }
    // bat dau xoa
    else
    {
        // luu gia tri se xoa vao x
        x = list->nodes[vitri];
        // doi cac node ben phai vi tri sang trai mot don vi
        for (int i = vitri; i < list->num - 1; i++)
            list->nodes[i] = list->nodes[i + 1];
        // giam so phan tu xuong 1 don vi
        list->num--;
        return x;
    }
}
void Replace(LIST* list, int vitri, int x)
{
    // kiem tra danh sach rong
    if (Empty(list))
        printf("danh sach rong");
    // kiem tra vi tri hop le
    else if (vitri < 0 || vitri >= list->num)
        printf("vi tri khong hop le");
    // bat dau thay the
    else
        list->nodes[vitri] = x;
}
void InterChangeSort(LIST* list)
{
    for (int i = 0; i < list->num - 1; i++)
        for (int j = i + 1; j < list->num; j++)
            if (list->nodes[i] > list->nodes[j])
                Swap(list->nodes[i], list->nodes[j]);
}
int LinearSearch(LIST* list, int x)
{
    for (int i = 0; i < list->num; i++)
        if (list->nodes[i] == x)
            return i;
    return -1;
}
int BinarySearch(LIST* list, int x)
{
    int left = 0, right = list->num - 1, middle;
    while (left <= right)
    {
        middle = (left + right) / 2;
        // tim thay, tra ve vi tri
        if (x == list->nodes[middle])
            return middle;
        // thu hep ben phai
        if (x < list->nodes[middle])
            right = middle - 1;
        // thu hep ben trai
        else
            left = middle + 1;
    }
    return -1;
}
void Traverse(LIST* list)
{
    // kiem tra danh sach rong
    if (Empty(list))
        printf("danh sach rong");
    // in danh sach
    for (int i = 0; i < list->num; i++)
        printf("%5d", list->nodes[i]);
}
void TaoDSKeNgauNhien(LIST* list)
{
    // kiem tra so phan tu hop le
    do
    {
        printf("\n Nhap tong so phan tu (0 < n <= %d) = ", MAX);
        scanf("%d", &list->num);// list la dia chi, nhung list->num la gia tri, nen them & de lay dia chi cua list->num
    } while (!(list->num > 0 && list->num <= MAX));
    // khoi dong bo tao so ngau nhien de cac so khong trung nhau
    srand((unsigned int)time(NULL));
    for (int i = 0; i < list->num; i++)
        list->nodes[i] = rand() % 20 + 1;// ham rand() tao ra so ngau nhien tu 0 den 32767
}
void Clear(LIST* list)
{
    list->num = 0;
}
void Swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}