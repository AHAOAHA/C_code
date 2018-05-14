#ifndef __HEAP__
#define __HEAP__
#define _CRT_SECURE_NO_WARNINGS 1
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
void PrintHeap(Heap hp);
void TestHeap();
#endif//__HEAP__