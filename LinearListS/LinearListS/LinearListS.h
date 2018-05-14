#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10
typedef int DataType;
typedef int size_t;
typedef struct LinearList
{
	DataType array[MAX_SIZE];
	size_t size;
}LinearList;
void InitList(LinearList* ps);
void InputList(LinearList* ps);
void LinearListPushBack(LinearList* ps, DataType data);
void LinearListPopBack(LinearList* ps);
void LinearListPushFront(LinearList* ps, DataType data);
int LinearListCheck(LinearList* ps);
void Swap(DataType* pa, DataType* pb);
void Move(DataType* pa, DataType* pb);
void LinearListErase(LinearList* ps, size_t pos);
void LinearListInsert(LinearList* ps, size_t pos, DataType data);
void LinearListPopFront(LinearList* ps);
int LinearListFind(LinearList* ps, DataType data);
void LinearListRemove(LinearList* ps, DataType data);
void LinearListRemoveAll(LinearList* ps, DataType data);
void BubbleSort(LinearList* ps);
void PrintList(LinearList* ps);
void SelectSort(LinearList* ps);