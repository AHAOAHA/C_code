#define _CRT_SECURE_NO_WARNINGS 1
extern struct BinTreeNode;
typedef struct BinTreeNode* QDataType;
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct QueueNode
{
	QDataType _data;
	struct QueueNode* _pNext;
}QueueNode,*PQueueNode;
typedef struct Queue
{
	PQueueNode _pHead;
	PQueueNode _pTail;
}Queue;
/////////////////////////////
void TestQueue();
void QueueInit(Queue* q);
void QueuePush(Queue* q, QDataType data);
PQueueNode BuyQueueNode(QDataType data);
void QueuePop(Queue* q);
QDataType QueueFront(Queue* q);
QDataType QueueBack(Queue* q);
int QueueSize(Queue* q);
int QueueEmpty(Queue* q);
void ClearQueue(Queue* q);