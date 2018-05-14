#ifndef __HEAP__
#define __HEAP__
#define _CRT_SECURE_NO_WARNINGS 1
typedef int HeapDataType;
typedef struct Heap
{
	HeapDataType* _array;
	int _capacity;//容量
	int _size;//已经使用的大小
}Heap;
#include<stdlib.h>
/////////////////////////////
void CreateHeap(Heap* hp, HeapDataType* array, int size);
void TestHeap();
#endif//__HEAP__