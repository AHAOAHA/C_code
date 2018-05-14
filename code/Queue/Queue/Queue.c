#include"Queue.h"
//队列的初始化
void QueueInit(Queue* q)
{
	assert(q);
	q->_pHead = NULL;
	q->_pTail = NULL;
}
//入队列
void QueuePush(Queue* q, QDataType data)
{
	PQueueNode PNewQueueNode = NULL;
	assert(q);
	if (QueueEmpty(q))
	{
		q->_pTail = q->_pHead = BuyQueueNode(data);
		return;
	}
	PNewQueueNode = BuyQueueNode(data);
	q->_pTail->_pNext = PNewQueueNode;
	q->_pTail = q->_pTail->_pNext;
	PNewQueueNode->_pNext = NULL;

}
PQueueNode BuyQueueNode(QDataType data)
{
	PQueueNode PNewQueueNode = NULL;
	PNewQueueNode = (PQueueNode)malloc(sizeof(QueueNode));
	if (NULL == PNewQueueNode)
	{
		printf("开辟空间失败\n");
		return NULL;
	}
	PNewQueueNode->_data = data;
	PNewQueueNode->_pNext = NULL;
	return PNewQueueNode;
}
//出队列
void QueuePop(Queue* q)
{
	PQueueNode pCur = NULL;
	assert(q);
	if (QueueEmpty(q))
		return;
	pCur = q->_pHead;
	if (pCur->_pNext == NULL)
	{
		free(pCur);
		pCur = NULL;
		q->_pTail = NULL;
		q->_pHead = NULL;
		return;
	}
	pCur = q->_pHead;
	q->_pHead = q->_pHead->_pNext;
	free(pCur);
	pCur = NULL;
}
//取队头元素
QDataType QueueFront(Queue* q)
{
	assert(q);
	if (QueueEmpty(q))
		return NULL;
	return q->_pHead->_data;
}
//取队尾元素
QDataType QueueBack(Queue* q)
{
	assert(q);
	return q->_pTail->_data;
}
//获取队列中元素个数
int QueueSize(Queue* q)
{
	int count = 0;
	PQueueNode pCur = NULL;
	assert(q);
	pCur = q->_pHead;
	while (pCur)
	{
		count++;
		pCur = pCur->_pNext;
	}
	return count;
}
//检测队列是否为空
int QueueEmpty(Queue* q)
{
	assert(q);
	return NULL == q->_pHead;
}
//清空队列
void ClearQueue(Queue* q)
{
	while (q->_pHead != q->_pTail)
		QueuePop(q);
	free(q->_pHead);
	q->_pHead = NULL;
	q->_pTail = NULL;
}
////////////////////////
//void TestQueue()
//{
//	DataType num = 0;
//	Queue q;
//	QueueInit(&q);
//
//	QueuePush(&q, 1);
//	QueuePush(&q, 2);
//	QueuePush(&q, 3);
//	QueuePop(&q);
//	num = QueueBack(&q);
//	num = QueueFront(&q);
//}