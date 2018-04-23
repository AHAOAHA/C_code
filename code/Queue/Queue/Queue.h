#define _CRT_SECURE_NO_WARNINGS 1
typedef int DataType;
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct Node
{
	DataType _data;
	struct Node* _pNext;
}Node,*PNode;
typedef struct Queue
{
	PNode _pHead;
	PNode _pTail;
}Queue;
/////////////////////////////
void TestQueue();
void QueueInit(Queue* q);
void QueuePush(Queue* q, DataType data);
PNode BuyNode(DataType data);
void QueuePop(Queue* q);
DataType QueueFront(Queue* q);
DataType QueueBack(Queue* q);
int QueueSize(Queue* q);
int QueueEmpty(Queue* q);