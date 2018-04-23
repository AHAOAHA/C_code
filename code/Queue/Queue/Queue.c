#include"Queue.h"
//���еĳ�ʼ��
void QueueInit(Queue* q)
{
	assert(q);
	q->_pHead = NULL;
	q->_pTail = NULL;
}
//�����
void QueuePush(Queue* q, DataType data)
{
	PNode PNewNode = NULL;
	assert(q);
	if (QueueEmpty(q))
	{
		q->_pTail = q->_pHead = BuyNode(data);
		return;
	}
	PNewNode = BuyNode(data);
	PNewNode->_pNext = q->_pHead;
	q->_pHead = PNewNode;
}
PNode BuyNode(DataType data)
{
	PNode PNewNode = NULL;
	PNewNode = (PNode)malloc(sizeof(Node));
	PNewNode->_data = data;
	PNewNode->_pNext = NULL;
	return PNewNode;
}
//������
void QueuePop(Queue* q)
{
	PNode pCur = NULL;
	assert(q);
	pCur = q->_pHead;
	while (pCur->_pNext != q->_pTail)
	{
		pCur = pCur->_pNext;
	}
	pCur->_pNext = NULL;
	free(q->_pTail);
	q->_pTail = pCur;
}
//ȡ��ͷԪ��
DataType QueueFront(Queue* q)
{
	assert(q);
	return q->_pHead->_data;
}
//ȡ��βԪ��
DataType QueueBack(Queue* q)
{
	assert(q);
	return q->_pTail->_data;
}
//��ȡ������Ԫ�ظ���
int QueueSize(Queue* q)
{
	int count = 0;
	PNode pCur = NULL;
	assert(q);
	pCur = q->_pHead;
	while (pCur)
	{
		count++;
		pCur = pCur->_pNext;
	}
	return count;
}
//�������Ƿ�Ϊ��
int QueueEmpty(Queue* q)
{
	assert(q);
	return NULL == q->_pHead;
}
////////////////////////
void TestQueue()
{
	DataType num = 0;
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePop(&q);
	num = QueueBack(&q);
	num = QueueFront(&q);
}