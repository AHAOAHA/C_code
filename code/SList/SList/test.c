#include"SList.h"
int main()
{
	PNode SList;
	PNode SList2;
	PNode NewList;
	int count = 0;
	int i = 4;
	SListInit(&SList);
	SListInit(&SList2);
	SListPushBack(&SList, 1);
	SListPushBack(&SList, 2);
	SListPushBack(&SList, 3);
	SListPushBack(&SList, 4);
	SListPushBack(&SList, 5);
	SListPushBack(&SList, 6);
	SListPushBack(&SList, 7);
	SListPushBack(&SList, 8);
	PNode pCur = SList;
	PNode pCur2 = SList;
	while (i--)
	{
		pCur = pCur->_pNext;
	}
	while (pCur2->_pNext)
	{
		pCur2 = pCur2->_pNext;
	}
	pCur2->_pNext = pCur;
	PNode pMeet = GetEnterNode(SList);
	/*while (SList->_pNext)
		SList = SList->_pNext;
	SList->_pNext = SList;
	count = GetCircleLen(SList);*/
	/*NewList = IsCircle(SList);
	if (NULL == NewList)
		printf("不带环");
	else
		printf("带环");*/
	/*SListPushBack(&SList2, 5);
	SListPushBack(&SList2, 6);
	SListPushBack(&SList2, 7);
	SListPushBack(&SList2, 8);
	while (SList2->_pNext)
		SList2 = SList2->_pNext;
	SList2->_pNext = SList;
	NewList = GetCrossNode(SList, SList2);*/
	/*int ret = IsCrossWithoutCircle(SList, SList2);
	if (ret)
		printf("相交\n");
	else
		printf("不想交\n");*/
	//DeleteLastKNode(SList, 2);
	//NewList = FindLastKNode(SList, 2);
	//NewList = FindMiddleNode(SList);
	//NewList = SListRever_ThreePoint(SList);
	/*SListPushBack(&SList2, 2);
	SListPushBack(&SList2, 4);
	SListPushBack(&SList2, 6);
	SListPushBack(&SList2, 8);
	NewList = MergeSList(SList, SList2);*/
	//SlistRever_PushFront(SList);
	//SListErase(&SList, SListFind(&SList, 2));
	//SListJosephCircle(&SList);
	//BubbleSList(&SList);
	//SelectSlist(&SList);
	//SListRever(&SList);
	//DelSListNodeWithoutLast(&SList, SListFind(&SList,2));
	//SListNodeInsertFront(&SList, SListFind(&SList, 2), 9);
	/*SListInsert(&SList, SListFind(&SList,2), 5);
	SListErase(&SList, SListFind(&SList, 2));*/
	//size = SListSize(SList);
	//SListDestory(&SList);
	//plast = SListBack(&SList);
	//SListPrintRever(SList);
	//SListPopFront(&SList);
	//SListPopBack(&SList);
	//SListPushFront(&SList, 0);
	//SListFind(&SList, 4);
	system("pause");
	return 0;
}
