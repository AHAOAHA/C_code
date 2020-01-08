#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>
#define SIZE_INIT 4
typedef int DataType;
typedef unsigned int size_t;
typedef struct LinearListD
{
	DataType* array;
	size_t capacity;//µ×²ã¿Õ¼ä´óÐ¡
	size_t size;
}LinearListD;
void LinearListDInit(LinearListD* ps);
void LinearListPushBack(LinearListD* ps, DataType data);
int LinearListDEmpty(LinearListD* ps);
void LinearListDPopBack(LinearListD* ps);
void LinearListDClear(LinearListD* ps);
int CheckCapacity(LinearListD* ps);
void LinearListDDestroy(LinearListD* ps);