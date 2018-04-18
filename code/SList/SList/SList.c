#include"SList.h"
void SListInit(PNode* pHead)
{
	assert(pHead);
	*pHead = NULL;//让pHead最开始指向NULL,因为此时链表中没有内容
}
void SListPushBack(PNode* pHead, DataType data)
{
	assert(pHead);
	PNode phand = *pHead;
	PNode NextNode = NULL;
	if (*pHead == NULL)
	{
		*pHead = (PNode)malloc(sizeof(Node));
		if (NULL == pHead)
			printf("开辟空间失败\n");
		(*pHead)->_pNext = NULL;
		(*pHead)->_data = data;
	}
	else
	{
		while (phand->_pNext != NULL)
			phand = phand->_pNext;
		//phand->_data = data;
		NextNode = (PNode)malloc(sizeof(Node));
		if (NULL == NextNode)
			printf("开辟下一个空间失败\n");
		phand->_pNext = NextNode;
		NextNode->_pNext = NULL;
		NextNode->_data = data;
	}	
}
void SListPopBack(PNode* pHead)
{
	PNode plast = *pHead;
	PNode pbefore = *pHead;
	assert(pHead);
	if (NULL == *pHead)
		printf("链表为空\n");
	else
	{
		while (plast->_pNext)
		{
			plast = plast->_pNext;
			if (plast->_pNext)
				pbefore = pbefore->_pNext;
		}
		free(plast);
		pbefore->_pNext = NULL;
		plast = NULL;
	}
}
void SListPushFront(PNode* pHead, DataType data)
{
	PNode pfirst = *pHead;
	PNode insert = NULL;
	assert(pHead);
	if (NULL == *pHead)
		SListPushBack(pHead, data);
	else
	{
		insert = (PNode)malloc(sizeof(Node));
		insert->_pNext = pfirst;
		insert->_data = data;
		*pHead = insert;
	}
}
void SListPopFront(PNode * pHead)
{
	PNode pfirst = *pHead;
	assert(pHead);
	if (NULL == *pHead)
		printf("链表为空\n");
	else
	{
		*pHead = pfirst->_pNext;
		free(pfirst);
		pfirst = NULL;
	}
}
PNode SListFind(PNode* pHead, DataType data)
{
	PNode pfind = *pHead;
	assert(pHead);
	if (NULL == *pHead)
	{
		return NULL;
	}
	else
	{
		while (pfind != NULL && pfind->_data != data)
		{
			pfind = pfind->_pNext;
		}
		if (NULL == pfind)
		{
			printf("没有找到该数据\n");
			return NULL;
		}
		return pfind;
	}
}
void SListInsert(PNode* pHead, PNode pos, DataType data)
{
	PNode phand = *pHead;
	PNode pnew = NULL;
	assert(pHead);
	if (NULL == *pHead)
	{
		printf("链表为空\n");
		SListPushBack(pHead, data);
	}
	else
	{
		while (phand != pos)
		{
			phand = phand->_pNext;
		}
		if (NULL == phand->_pNext)
		{
			SListPushBack(pHead, data);
		}
		else
		{
			pnew = (PNode)malloc(sizeof(Node));
			pnew->_pNext = phand->_pNext;
			pnew->_data = data;
			phand->_pNext = pnew;
		}
	}
}
void SListErase(PNode pHead, PNode pos)
{
	PNode pdel = pHead;
	PNode pback = pHead;
	//assert(pHead);
	if (NULL == pHead)
	{
		printf("链表为空\n");
	}
	else
	{
		while (pdel != pos)
		{
			pdel = pdel->_pNext;
			if (pdel != pos)
				pback = pback->_pNext;
		}
		pback->_pNext = pdel->_pNext;
		free(pdel);
		pdel = NULL;
	}
}
void SListDestory(PNode* pHead)
{
	PNode pdel = *pHead;
	assert(pHead);
	if (NULL==*pHead)
	{
		pHead = NULL;
	}
	else
	{
		while (NULL != *pHead)
		{
			*pHead = (*pHead)->_pNext;
			free(pdel);
			pdel = *pHead;
		}
	}
}
int SListSize(PNode pHead)
{
	int count = 0;
	while (pHead != NULL)
	{
		pHead = pHead->_pNext;
		count++;
	}
	return count;
}
void SListClear(PNode* pHead)
{
	PNode pdel = *pHead;
	assert(pHead);
	while (*pHead != NULL)
	{
		*pHead = (*pHead)->_pNext;
		free(pdel);
		pdel = *pHead;
	}
	pHead = NULL;
}
PNode SListBack(PNode pHead)
{
	while (pHead->_pNext != NULL)
	{
		pHead = pHead->_pNext;
	}
	return pHead;
}
///////////////////////////////////////////面试题///////////////////////////////////////////
//从尾到头打印单链表
//递归思想
void SListPrintRever(PNode pHead)
{
	PNode pfirst = pHead;
	//assert(pHead);
	if (NULL == pHead)
		printf("单链表为空\n");
	else
	{
		if (pfirst->_pNext != NULL)
		{
			SListPrintRever(pfirst->_pNext);
		}
		printf("--->%d", pfirst->_data);
	}
}
//删除一个无头单链表的非尾节点（不能遍历列表）
//将要删除位置的节点内容覆盖掉
void DelSListNodeWithoutLast(PNode *pHead, PNode pos)
{
	PNode pdel = *pHead;
	assert(pHead);
	assert(pos);
	if (NULL == *pHead)
	{
		printf("单链表为空\n");
	}
	else
	{
		while (pos->_pNext->_pNext)
		{
			pos->_data = pos->_pNext->_data;
			pos = pos->_pNext;
		}
		pos->_data = pos->_pNext->_data;
		free(pos->_pNext);
		pos->_pNext = NULL;
	}
}
//在无头单链表的一个节点前插入一个节点（不能遍历链表）
//在要插入的位置后面开辟一个节点 将该位置的数据存入开辟的节点里 再将要插入的节点存入该节点
void SListNodeInsertFront(PNode pos,DataType data)
{
	PNode NewNode = NULL;
	if (NULL == pos)
	{
		printf("插入地址无效\n");
		return 0;
	}
	else
	{
		NewNode = (PNode)malloc(sizeof(Node));
		NewNode->_pNext = pos->_pNext;
		pos->_pNext = NewNode;
		NewNode->_data = pos->_data;
		pos->_data = data;
	}
}

//单链表实现约瑟夫环（JosephCircle）
void SListJosephCircle(PNode * pHead)
{
	PNode pdel = NULL;
	PNode pCur = *pHead;
	int count = 3;
	assert(pHead);
	if (NULL == *pHead)
	{
		printf("单链表为空\n");
		return 0;
	}
	while (pCur->_pNext)
	{
		pCur = pCur->_pNext;
	}
	pCur->_pNext = *pHead;
	pCur = *pHead;
	while ((*pHead)->_pNext != *pHead)
	{
		while (--count)
		{
			pCur = pCur->_pNext;
		}
		pdel = pCur;
		pCur = pCur->_pNext;
		SListErase(pHead, pdel);
		count = 3;
	}
}

//逆置/反转单链表
//1------>将尾节点挪动到头节点的后面---头插法
void SListRever(PNode* pHead)
{
	PNode pInsertPre = *pHead;
	PNode pInsert = *pHead;
	PNode pLast = *pHead;
	PNode pLastPre = *pHead;
	PNode pPre = *pHead;
	assert(pHead);
	if (NULL == *pHead)
	{
		return 0;
	}
	while (pInsert->_pNext)
	{
		while (pLast->_pNext)
		{
			pLast = pLast->_pNext;
			if (NULL != pLast->_pNext)
				pLastPre = pLastPre->_pNext;
		}
		if (*pHead == pInsert)
		{
			pLast->_pNext = pInsert;
			*pHead = pLast;
		}
		else
		{
			pLast->_pNext = pInsert;
			pInsertPre->_pNext = pLast;
		}
		pInsertPre = pLast;
		pLastPre->_pNext = NULL;
		pLast = pInsert;
		pLastPre = pInsert;
	}
}
//////////////////////单链表的逆置---头插----2---只在链表头部插入
void SlistRever_PushFront(PNode pHead)
{
	PNode pfirst = pHead;
	PNode pdel = NULL;
	PNode pCur = pHead->_pNext;
	while (pCur != NULL)
	{
		//SListPushFront(&pHead, pCur->_data);
		SListNodeInsertFront(pfirst, pCur->_data);
		pdel = pCur;
		pCur = pCur->_pNext;
		SListErase(pHead, pdel);
		pfirst = pHead;		
	}
}
//单链表的逆置---三个指针

PNode SListRever_ThreePoint(PNode pHead)
{
	PNode pFirst = pHead;
	PNode pMid = pHead->_pNext;
	PNode pLast = pHead->_pNext->_pNext;
	if (NULL == pHead)
		return NULL;
	pMid->_pNext = pFirst;
	pFirst->_pNext = NULL;
	pFirst = pMid;
	pMid = pLast;
	pLast = pLast->_pNext;
	while (pLast)
	{
		pMid->_pNext = pFirst;
		pFirst = pMid;
		pMid = pLast;
		pLast = pLast->_pNext;
	}
	pMid->_pNext = pFirst;
	return pMid;
}
//单链表排序（冒泡排序&快速排序）
void BubbleSList(PNode * pHead)
{
	DataType tmp = 0;
	PNode pstop = NULL;
	PNode pFirst = *pHead;
	PNode pSecond = (*pHead)->_pNext;
	assert(pHead);
	if (NULL == *pHead)
		return 0;
	while (pstop != (*pHead)->_pNext)
	{
		while (pSecond!=pstop)
		{
			if (pFirst->_data > pSecond->_data)
			{
				tmp = pFirst->_data;
				pFirst->_data = pSecond->_data;
				pSecond->_data = tmp;
			}
			pFirst = pFirst->_pNext;
			pSecond = pSecond->_pNext;
		}
		pstop = pFirst;
		pFirst = *pHead;
		pSecond = (*pHead)->_pNext;
	}
}

//快速排序  找到最大/最小的放两边
void SelectSlist(PNode* pHead)
{
	PNode pStopFlag = *pHead;
	PNode pMax = *pHead;
	PNode pMin = *pHead;
	DataType tmp = 0;
	PNode pCur = *pHead;
	PNode pStop = *pHead;
	PNode pStart = *pHead;
	assert(pHead);
	if (NULL == *pHead)
		return 0;
	while (NULL != pStop->_pNext)
		pStop = pStop->_pNext;
	while (pStart != pStop)
	{
		while (pCur != pStop)
		{
			if (pCur->_data > pMax->_data)
			{
				pMax = pCur;
			}
			else if (pCur->_data<pMin->_data)
			{
				pMin = pCur;
			}
			pCur = pCur->_pNext;
			if (pCur != pStop)
				pStopFlag = pStopFlag->_pNext;
		}
		if (pMin != pStart)
		{
			tmp = pMin->_data;
			pMin->_data = pStart->_data;
			pStart->_data = tmp;
		}
		if (pMax != pStop)
		{
			tmp = pMax->_data;
			pMax->_data = pStop->_data;
			pStop->_data = tmp;
		}
		pStart = pStart->_pNext;
		pStop = pStopFlag;
		pCur = pStart;
		pMax = pStart;
		pMin = pStart;
	}
}
//合并两个有序链表，合并之后依然有序
PNode MergeSList(PNode pHead1, PNode pHead2)
{
	PNode NewList = NULL;
	PNode pCur = NULL;
	PNode pList1 = pHead1;
	PNode pList2 = pHead2;
	if (NULL == pHead1 && NULL == pHead2)
		return NULL;
	if (NULL == pHead1)
		return pHead2;
	if (NULL == pHead2)
		return pHead1;
	if (pList1->_data > pList2->_data)
	{
		NewList = pList2;
		pList2 = pList2->_pNext;
	}
	else
	{
		NewList = pList1;
		pList1 = pList1->_pNext;
	}
	pCur = NewList;
	while (pList1&&pList2)
	{
		if (pList1->_data < pList2->_data)
		{
			pCur->_pNext = pList1;
			pList1 = pList1->_pNext;
			pCur = pCur->_pNext;
		}
		else
		{
			pCur->_pNext = pList2;
			pList2 = pList2->_pNext;
			pCur = pCur->_pNext;
		}
	}
	pCur->_pNext = pList1 ? pList1 : pList2;
	return NewList;
}
//查找中间节点---只遍历一次链表
PNode FindMiddleNode(PNode pHead)
{
	PNode pfast = pHead;
	PNode pslow = pHead;
	if (NULL == pHead)
		return NULL;
	while (pfast&&pfast->_pNext)
	{
		pfast = pfast->_pNext->_pNext;
		pslow = pslow->_pNext;
	}
	return pslow;
}
//查找链表的倒数第K个节点---只遍历一次链表
PNode FindLastKNode(PNode pHead,int K)
{
	PNode pfirst = pHead;
	PNode psecond = pHead;
	int i = 0;
	if (NULL == pHead)
		return NULL;
	for (i = 0; i < K; i++)
	{
		if (NULL == pfirst)
			return NULL;
		pfirst = pfirst->_pNext;
	}
	while (pfirst)
	{
		psecond = psecond->_pNext;
		pfirst = pfirst->_pNext;
	}
	return psecond;
}
PNode DeleteLastKNode(PNode pHead, int K)
{
	PNode pfirst = pHead;
	PNode psecond = pHead;
	PNode pdel = NULL;
	int i = 0;
	if (NULL == pHead)
		return NULL;
	for (i = 0; i < K; i++)
	{
		if (NULL == pfirst)
			return NULL;
		pfirst = pfirst->_pNext;
	}
	while (pfirst->_pNext)
	{
		psecond = psecond->_pNext;
		pfirst = pfirst->_pNext;
	}
	pdel = psecond->_pNext;
	psecond->_pNext = psecond->_pNext->_pNext;
	free(pdel);
	return pHead;
}
//判断两个链表是否相交--不带环---相交返回1 不想交返回0
int IsCrossWithoutCircle(PNode pHead1, PNode pHead2)
{
	PNode pCur1 = pHead1;
	PNode pCur2 = pHead2;
	if (NULL == pHead1 || NULL == pHead2)
		return 0;
	while (pCur1->_pNext)
		pCur1 = pCur1->_pNext;
	while (pCur2->_pNext)
		pCur2 = pCur2->_pNext;
	if (pCur1 == pCur2)
		return 1;
	return 0;
}
//求不带环单链表相交交点
PNode GetCrossNode(PNode pHead1, PNode pHead2)
{
	PNode pCur1 = pHead1;
	PNode pCur2 = pHead2;
	int count1 = 0;
	int count2 = 0;
	int count = 0;
	if (0 == IsCrossWithoutCircle(pHead1, pHead2))
		return NULL;
	while (pCur1->_pNext)
	{
		pCur1 = pCur1->_pNext;
		count1++;
	}
	while (pCur2->_pNext)
	{
		pCur2 = pCur2->_pNext;
		count2++;
	}
	pCur1 = pHead1;
	pCur2 = pHead2;
	if (count1 >= count2)
	{
		count = count1 - count2;
		while (count--)
		{
			pCur1 = pCur1->_pNext;
		}
	}
	else
	{
		count = count2 - count1;
		while (count--)
		{
			pCur2 = pCur2->_pNext;
		}
	}
	while (pCur1 != pCur2)
	{
		pCur1 = pCur1->_pNext;
		pCur2 = pCur2->_pNext;
	}
	return pCur1;
}
//判断链表是否带环
PNode IsCircle(PNode pHead)
{
	PNode pfast = pHead;
	PNode pslow = pHead;
	if (NULL == pHead)
		return NULL;
	pfast = pfast->_pNext->_pNext;
	pslow = pslow->_pNext;
	while (pfast != pslow)
	{
		if (pfast==NULL || pfast->_pNext == NULL || pslow->_pNext == NULL)
			return NULL;
		pfast = pfast->_pNext->_pNext;
		pslow = pslow->_pNext;
	}
	return pslow;
}
//求环的长度
int GetCircleLen(PNode pHead)
{
	int count = 1;
	PNode pCur = NULL;
	PNode pMeet = IsCircle(pHead);
	if (NULL == pMeet)
		return 0;
	pCur = pMeet->_pNext;
	while (pCur != pMeet)
	{
		pCur = pCur->_pNext;
		count++;
	}
	return count;
}
//求环的入口点---注意推导过程
PNode GetEnterNode(PNode pHead)
{
	PNode pMeet = IsCircle(pHead);
	PNode pCur = pHead;
	if (NULL == pMeet)
		return NULL;
	while (pCur != pMeet)
	{
		pCur = pCur->_pNext;
		pMeet = pMeet->_pNext;
	}
	return pCur;
}
//判断链表是否相交---链表可能带环
int IsCrossWithCross(PNode pHead1, PNode pHead2)
{
	PNode pMeet1 = IsCircle(pHead1);
	PNode pMeet2 = IsCircle(pHead2);
	PNode pCur = NULL;
	if (pMeet1 == NULL || pMeet2 == NULL)
		return 0;
	pCur = pMeet1;
	do
	{
		if (pCur == pMeet2)
			return 1;
		pCur = pCur->_pNext;
	} while (pMeet1 != pCur);
	return 0;
}
//复杂链表的复制(未测试)
PCListNode CopyComplexList(PCListNode pHead)
{
	PCListNode pfirst = pHead;
	PCListNode plist = NULL;
	PCListNode pCur = NULL;
	if (NULL == pHead)
		return NULL;
	pCur = (PCListNode)malloc(sizeof(CNode));
	plist = pCur;
	while (pfirst)
	{
		pCur->_pNext = pfirst->_pNext;
		pCur->_data = pfirst->_data;
		pCur->_pNext = (PCListNode)malloc(sizeof(CNode));
		pCur = pCur->_pNext;
		pfirst = pfirst->_pNext;
	}
	pCur = plist;
	pfirst = pHead;
	while (pfirst)
	{
		pCur->_random = pfirst->_random;
		pCur = pCur->_pNext;
		pfirst = pfirst->_pNext;
	}
	return plist;
}