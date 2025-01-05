#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX	50

struct LIST {
	int num;
	int nodes[MAX];
};

void Initialize(LIST* list) {
	list->num = 0;
}

int ListSize(LIST* list) {
	return list->num;
}

bool Empty(LIST* list) {
	return list->num == 0;
}

bool Full(LIST* list) {
	return list->num == MAX;
}

void ClearList(LIST* list) {
	list->num = 0;
}

void Insert(LIST* list, int pos, int x)
{
	if (pos < 0 || pos > list->num)
	{
		printf("\nVi tri % d khong hop le", pos);
		return;
	}
	if (Full(list))
	{
		printf("\nDanh sach bi day");
		return;
	}
	for (int i = list->num - 1; i >= pos; i--)
		list->nodes[i + 1] = list->nodes[i];
	list->nodes[pos] = x; // Thêm x vào vị trí pos
	list->num++; // Tăng số nút lên 1
}

int Remove(LIST* list, int pos) 
{
	if (Empty(list)) 
	{
		printf("Danh sach bi rong\n"); 
		return -1;
	}	
	if (pos < 0 || pos >= list->num) 
	{
		printf("Vi tri %d khong hop le\n", pos); 
		return -2;
	}
	int x = list->nodes[pos];
	// Dời các nút từ vt pos+1 xuống vt num–1 lên 1 vt
	for (int i = pos; i < list->num - 1; i++)
		list->nodes[i] = list->nodes[i + 1];
	list->num--; 	// Giảm số nút xuống 1
	return x;
}


void Traverse(LIST* list)
{
	if (Empty(list))
	{
		printf("\nDanh sach rong");
		return;
	}
	printf("\n*** Danh sach ke ***\n");
	for (int i = 0; i < list->num; i++)
		printf("%d\t", list->nodes[i]);
	printf("\n");
}

void RandomNodes(LIST* list)
{
	do
	{
		printf("\n Nhap tong so phan tu (0 < n <= %d) = ", MAX);
		scanf("%d", &list->num);
	} while (!(list->num > 0 && list->num <= MAX));

	for (int i = 0; i < list->num; i++)
	{
		list->nodes[i] = rand() % 20 + 1;
	}
}

void Sort(LIST* list) 
{
	for (int i = 0; i < list->num - 1; i++)
	{
		for (int j = i + 1; j < list->num; j++)
		{
			if (list->nodes[i] > list->nodes[j])
			{
				int tmp = list->nodes[i];
				list->nodes[i] = list->nodes[j];
				list->nodes[j] = tmp;
			}
		}
	}
}


void main()
{
	srand(unsigned int(time(NULL)));

	LIST list;

	Initialize(&list);
	// RandomNodes(&list);
	Traverse(&list);

	// Sort(&list);
	// Traverse(&list);
	printf("\n Xoa node: %d", Remove(&list, -1));
}
