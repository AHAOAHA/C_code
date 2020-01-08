#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"
typedef struct PriorityQueue
{
	Heap _hp;
}PriorityQueue;
void PriorityQueueInit(PriorityQueue* q, Compare com);
void PriorityQueuePush(PriorityQueue* q, HDataType data);
void PriorityQueuePop(PriorityQueue* q);
int PriorityQueueSize(PriorityQueue* q);
int PriorityEmpty(PriorityQueue* q);
HDataType PriorityQueueTop(PriorityQueue* q);
void PriorityQueueDestroy(PriorityQueue* q);
TestPriorityQueue();
