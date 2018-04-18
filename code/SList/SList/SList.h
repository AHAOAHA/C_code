#ifndef __SLIST__
#define __SLIST__
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int DataType;
typedef struct Node
{
	struct Node* _pNext;
	DataType _data;
}Node,*PNode;
typedef struct CNode
{
	DataType _data;
	struct CNode* _pNext;
	struct CNode* _random;
}CNode,*PCListNode;
void SListInit(PNode* pHead);
void SListPushBack(PNode* pHead, DataType data);
void SListPopBack(PNode* pHead);
void SListPushFront(PNode* pHead, DataType data);
void SListPopFront(PNode * pHead);
PNode SListFind(PNode* pHead, DataType data);
void SListInsert(PNode* pHead, PNode pos, DataType data);
void SListErase(PNode* pHead, PNode pos);
void SListDestory(PNode* pHead);
int SListSize(PNode pHead);
void SListClear(PNode* pHead);
PNode SListBack(PNode pHead);
void SListPrintRever(PNode pHead);
void SListNodeInsertFront(PNode * pHead, PNode pos,DataType data);
void SListRever(PNode* pHead);
void SListJosephCircle(PNode * pHead);
void BubbleSList(PNode * pHead);
void SelectSlist(PNode* pHead);
void SlistRever_PushFront(PNode pHead);
PNode MergeSList(PNode pHead1, PNode pHead2);
PNode SListRever_ThreePoint(PNode pHead);
PNode FindMiddleNode(PNode pHead);
PNode FindLastKNode(PNode pHead, int K);
PNode DeleteLastKNode(PNode pHead, int K);
int IsCrossWithoutCircle(PNode pHead1, PNode pHead2);
PNode GetCrossNode(PNode pHead1, PNode pHead2);
PNode IsCircle(PNode pHead);
int GetCircleLen(PNode pHead);
PNode GetEnterNode(PNode pHead);

#endif //__SLIST__