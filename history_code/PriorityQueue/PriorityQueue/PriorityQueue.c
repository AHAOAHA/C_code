#include"PriorityQueue.h"
//优先级队列的初始化
void PriorityQueueInit(PriorityQueue* q, Compare com)
{
	assert(q);
	
	//初始化优先级队列中的堆
	InitHeap(&q->_hp, com);
}

//向队列中插入元素
void PriorityQueuePush(PriorityQueue* q, HDataType data)
{
	assert(q);
	InsertHeap(&q->_hp, data);
}

//删除优先级最高的元素
void PriorityQueuePop(PriorityQueue* q)
{
	assert(q);
	DeleteHeapTop(&q->_hp);
}

//获取优先级队列元素个数
int PriorityQueueSize(PriorityQueue* q)
{
	assert(q);
	return SizeHeap(&q->_hp);
}

//检测优先级队列是否为空
int PriorityEmpty(PriorityQueue* q)
{
	assert(q);
	return EmptyHeap(&q->_hp);
}

//获取优先级队列的堆顶元素
HDataType PriorityQueueTop(PriorityQueue* q)
{
	assert(q);
	return (q->_hp)._array[0];
}

//销毁优先级队列
void PriorityQueueDestroy(PriorityQueue* q)
{
	assert(q);
	DestroyHeap(&q->_hp);
}
/////////////////////////测试函数
TestPriorityQueue()
{
	PriorityQueue q;
	PriorityQueueInit(&q, Less);
	PriorityQueuePush(&q, 6);
	PriorityQueuePush(&q, 9);
	PriorityQueuePush(&q, 5);
	PriorityQueuePush(&q, 1);
	PriorityQueuePush(&q, 3);
	PriorityQueuePush(&q, 2);
}
