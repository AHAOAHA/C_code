#define _CRT_SECURE_NO_WARNINGS 1
#define MAXSIZE 50
typedef int HDataType;
typedef struct Heap
{
	HDataType* _array;
	int _capacity;//容量
	int _size;//已经使用的大小
}Heap;
#include<stdlib.h>
#include<assert.h>
#include<stdio.h>
/////////////////////////////
void CreateHeap_Personal(Heap* hp, HDataType* array, int size);
void CreateHeap(Heap* hp, HDataType* array, int size);
void _AdjustDown(Heap* hp, int Root);
void InsertHeap(Heap* hp, HDataType data);
int SizeHeap(Heap* hp);
int EmptyHeap(Heap* hp);
void PrintHeap(Heap hp);
void TestHeap();
