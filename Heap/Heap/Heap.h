#define _CRT_SECURE_NO_WARNINGS 1
#define MAXSIZE 50
typedef int(*Compare)(HDataType, HDataType);
typedef int HDataType;
typedef struct Heap
{
	HDataType* _array;
	int _capacity;//����
	int _size;//�Ѿ�ʹ�õĴ�С
	Compare _com;//������ѻ���С��
}Heap;
#include<stdlib.h>
#include<assert.h>
#include<stdio.h>
/////////////////////////////
void InitHeap(Heap* hp, Compare com);
void CreateHeap_Personal(Heap* hp, HDataType* array, int size, Compare com);
void CreateHeap(Heap* hp, HDataType* array, int size,Compare com);
void _AdjustDown(Heap* hp, int Root);
void _AdjustUp(Heap* hp, int Root);
void InsertHeap(Heap* hp, HDataType data);
int SizeHeap(Heap* hp);
int EmptyHeap(Heap* hp);
void DeleteHeapTop(Heap* hp);
void PrintHeap(Heap hp);
void _CheckCapacity(Heap* hp);
int Less(HDataType Left, HDataType Right);
int Greater(HDataType Left, HDataType Right);
void TestHeap();
