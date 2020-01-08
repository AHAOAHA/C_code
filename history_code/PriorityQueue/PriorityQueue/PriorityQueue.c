#include"PriorityQueue.h"
//���ȼ����еĳ�ʼ��
void PriorityQueueInit(PriorityQueue* q, Compare com)
{
	assert(q);
	
	//��ʼ�����ȼ������еĶ�
	InitHeap(&q->_hp, com);
}

//������в���Ԫ��
void PriorityQueuePush(PriorityQueue* q, HDataType data)
{
	assert(q);
	InsertHeap(&q->_hp, data);
}

//ɾ�����ȼ���ߵ�Ԫ��
void PriorityQueuePop(PriorityQueue* q)
{
	assert(q);
	DeleteHeapTop(&q->_hp);
}

//��ȡ���ȼ�����Ԫ�ظ���
int PriorityQueueSize(PriorityQueue* q)
{
	assert(q);
	return SizeHeap(&q->_hp);
}

//������ȼ������Ƿ�Ϊ��
int PriorityEmpty(PriorityQueue* q)
{
	assert(q);
	return EmptyHeap(&q->_hp);
}

//��ȡ���ȼ����еĶѶ�Ԫ��
HDataType PriorityQueueTop(PriorityQueue* q)
{
	assert(q);
	return (q->_hp)._array[0];
}

//�������ȼ�����
void PriorityQueueDestroy(PriorityQueue* q)
{
	assert(q);
	DestroyHeap(&q->_hp);
}
/////////////////////////���Ժ���
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
