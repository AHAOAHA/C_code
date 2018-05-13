#include"BinTree.h"
void CreateBinTree(PNode* pRoot,DataType array[],int* index,int size,DataType unindex)
{
	assert(pRoot);
	if (size > *index && '#' != array[*index])
	{
		*pRoot = BuyBinTreeNode(array[*index]);
		(*index)++;
		CreateBinTree(&(*pRoot)->_pLeft, array, index, size, unindex);
		(*index)++;
		CreateBinTree(&(*pRoot)->_pRight, array, index, size, unindex);
	}
}
PNode BuyBinTreeNode(DataType data)
{
	PNode PNewNode = NULL;
	PNewNode = (PNode)malloc(sizeof(Node));
	if (NULL == PNewNode)
	{
		//assert(0);
		return NULL;
	}
	PNewNode->_data = data;
	PNewNode->_pLeft = NULL;
	PNewNode->_pRight = NULL;
	return PNewNode;
}
//ǰ���ӡ�������ڵ�
void PerOrder(PNode pRoot)
{
	if (NULL == pRoot)
		return;
	printf("%c   ", pRoot->_data);
	PerOrder(pRoot->_pLeft);
	PerOrder(pRoot->_pRight);
}
//����������   ��+������+������
PNode CopyBinTree(PNode pRoot)
{
	PNode pNewRoot = NULL;
	if (pRoot)
	{
		pNewRoot = BuyBinTreeNode(pRoot->_data);
		//����������
		pNewRoot->_pLeft = CopyBinTree(pRoot->_pLeft);
		//����������
		pNewRoot->_pRight = CopyBinTree(pRoot->_pRight);
	}
	return pNewRoot;
}
//ǰ���ӡ�������ڵ�---�ǵݹ�
void PerOrderNor(PNode pRoot)
{
	PNode pCur = NULL;
	PNode pPre = NULL;
	if (NULL == pRoot)
		return;
	pPre = pRoot;
	while (pPre)
	{
		pCur = pPre;
		while (pCur)
		{
			printf("%c   ", pCur->_data);
			pCur = pCur->_pLeft;
		}
		pPre = pPre->_pRight;
	}
}
//�����ӡ�������ڵ�
void InFixOrder(PNode pRoot)
{
	if (NULL == pRoot)
		return;
	InFixOrder(pRoot->_pLeft);
	printf("%c   ", pRoot->_data);
	InFixOrder(pRoot->_pRight);
}
//����һ---�����ӡ�������ڵ�---�ǵݹ�
//�ҵ�ǰ������ߵĽڵ㣬������������·���е����нڵ�
void InFixOrderNor_1(PNode pRoot)
{
	PNode pCur = NULL;
	Stack s;
	StackInit(&s);
	if (NULL == pRoot)
		return;
	pCur = pRoot;
	while (pCur || StackEmpty(&s))
	{
		if (pCur)
		{
			StackPush(&s, pCur);
			pCur = pCur->_pLeft;
		}
		else
		{
			pCur = StackTop(&s);
			printf("%c   ", pCur->_data);
			StackPop(&s);
			pCur=pCur->_pRight;
		}
	}
}
//������---�����ӡ�������ڵ�---�ǵݹ�
void InFixOrderNor_2(PNode pRoot)
{
	Stack s;
	PNode pCur = NULL;
	if (NULL == pRoot)
		return;
	StackInit(&s);
	pCur = pRoot;
	StackPush(&s, pCur);
	while (StackEmpty(&s))
	{
		while (pCur)
		{
			StackPush(&s, pCur->_pLeft);
			pCur = pCur->_pLeft;
		}
		if (!StackTop(&s))
			StackPop(&s);//ɾ��ջ���Ŀսڵ�
		pCur = StackTop(&s);
		printf("%c   ", pCur->_data);
		StackPop(&s);
		pCur = pCur->_pRight;
		if (pCur)//���Һ��Ӵ���ʱ������ջ
			StackPush(&s, pCur);
	}

}
//�����ӡ�������ڵ�
void PostOrder(PNode pRoot)
{
	if (NULL == pRoot)
		return;
	PostOrder(pRoot->_pLeft);
	PostOrder(pRoot->_pRight);
	printf("%c   ", pRoot->_data);
}
//�����ӡ�������ڵ�---�ǵݹ�
void PostOrderNor(PNode pRoot)
{
	PNode pCur = NULL;
	PNode pTop = NULL;
	PNode pPrev = NULL;//���������ʹ��Ľڵ�
	Stack s;
	if (NULL == pRoot)
		return;
	StackInit(&s);
	pCur = pRoot;
	while (pCur || StackEmpty(&s))
	{
		while (pCur)
		{
			StackPush(&s, pCur);
			pCur = pCur->_pLeft;
		}
		pTop = StackTop(&s);
		if (NULL == pTop->_pRight || pTop->_pRight == pPrev)//�������ջ���ڵ���Һ����Ѿ������ʹ�ʱ��ֱ�ӱ���ջ���ڵ�
		{
			printf("%c   ", pTop->_data);
			pPrev = pTop;
			StackPop(&s);
		}
		else
		{
			pCur = pTop->_pRight;
		}
	}
}
//���������ӡ�������ڵ�---��Ҫʹ�ö���
void LevelOrder(PNode pRoot)
{
	Queue q;
	QueueInit(&q);
	if (NULL == pRoot)
		return;
	QueuePush(&q, pRoot);
	while (!QueueEmpty(&q))
	{
		printf("%c   ", QueueFront(&q)->_data);
		if (pRoot->_pLeft)
			QueuePush(&q, pRoot->_pLeft);
		if (pRoot->_pRight)
			QueuePush(&q, pRoot->_pRight);
		QueuePop(&q);
		pRoot = QueueFront(&q);
	}
}
//������������
//���������Ӧ��
void DetoryBinTree(PNode* pRoot)
{
	assert(pRoot);
	if (*pRoot)
	{
		DetoryBinTree(&(*pRoot)->_pLeft);
		DetoryBinTree(&(*pRoot)->_pRight);
		free(*pRoot);
		*pRoot = NULL;
	}
}
//�������ľ���---�ݹ�
void SwapBinTreeNode(PNode pRoot)
{
	PNode tmp = NULL;
	tmp = pRoot->_pLeft;
	pRoot->_pLeft = pRoot->_pRight;
	pRoot->_pRight = tmp;
}
void MirrorBinTree(PNode pRoot)
{
	if (pRoot)
	{
		SwapBinTreeNode(pRoot);
		MirrorBinTree(pRoot->_pLeft);
		MirrorBinTree(pRoot->_pRight);
	}
}
//�������ľ���---�ǵݹ�
//������� �Ӻ���ǰ����
void MirrorBinTreeNor(PNode pRoot)
{
	Stack s;
	PNode pCur = NULL;
	PNode pTop = NULL;
	PNode pPrev = NULL;
	if (NULL == pRoot)
		return;
	StackInit(&s);
	pCur = pRoot;
	while (pCur || StackEmpty(&s))
	{
		while (pCur)
		{
			StackPush(&s, pCur);
			pCur = pCur->_pLeft;
		}
		pTop = StackTop(&s);
		if (NULL == pTop->_pRight || pTop->_pRight == pPrev)
		{
			SwapBinTreeNode(pTop);
			pPrev = pTop;
			StackPop(&s);
		}
		else
		{
			pCur = pTop->_pRight;
		}
	}
}
//��������нڵ�ĸ���
int BinTreeSize(PNode pRoot)
{
	if (NULL == pRoot)
		return 0;
	return 1 + BinTreeSize(pRoot->_pLeft) + BinTreeSize(pRoot->_pRight);//1��ʾ���ڵ�
}
//���������Ҷ�ӽڵ�ĸ���
int BinTreeLeaf(PNode pRoot)
{
	if (pRoot)
	{
		if (NULL == pRoot->_pLeft && NULL == pRoot->_pRight)
			return 1;
		return BinTreeLeaf(pRoot->_pLeft) + BinTreeLeaf(pRoot->_pRight);
	}
	return 0;
}
//��������е�K��ڵ�ĸ���
int BinTreeKLevelNode(PNode pRoot, int K)
{
	if (K > (BinTreeHight(pRoot) - 1) || NULL == pRoot)
		return 0;
	if (K == 0)
		return 1;
	return BinTreeKLevelNode(pRoot->_pLeft, K - 1) + BinTreeKLevelNode(pRoot->_pRight, K - 1);

}
//��������ĸ߶�
int BinTreeHight(PNode pRoot)
{
	if (NULL == pRoot)
		return 0;
	return (1 + BinTreeHight(pRoot->_pLeft)) >= (1 + BinTreeHight(pRoot->_pRight)) ? (1 + BinTreeHight(pRoot->_pLeft)) : (1 + BinTreeHight(pRoot->_pRight));
}
//��������Ѱ��ֵΪDATA�Ľڵ㣬�Ҳ�������NULL
PNode FindNode(PNode pRoot, DataType data)
{
	if (pRoot)
	{
		if (pRoot->_data == data)
			return pRoot;
		return FindNode(pRoot->_pLeft, data) ? FindNode(pRoot->_pLeft, data) : FindNode(pRoot->_pRight, data);
	}
	return NULL;
}
//���һ���ڵ��Ƿ��ڶ�������
int IsNodeInBinTree(PNode pRoot, PNode pNode)
{
	if (pRoot)
	{
		if (pRoot == pNode)
			return 1;
		return IsNodeInBinTree(pRoot->_pLeft, pNode) ? IsNodeInBinTree(pRoot->_pLeft, pNode) : IsNodeInBinTree(pRoot->_pRight, pNode);
	}
	return 0;
}
//���������Ƿ�Ϊ��ȫ������
int IsCompeteBinTree(PNode pRoot)
{
	PNode pCur = NULL;
	if (NULL == pRoot)
		return 0;
	pCur = pRoot;
	
}
///////////////////////////////////////////////////////���Ժ���
void TestBinTree()
{
	PNode pFindNode = NULL;
	int K = 0;
	PNode pRoot;
	PNode pNewRoot_TestCopyBinTree;
	int index = 0;
	DataType unindex = '#';
	DataType array[] = "ABD###CE##F";
	CreateBinTree(&pRoot, array, &index, strlen(array), unindex);
	//DetoryBinTree(&pRoot);
	printf("ǰ���ӡ��");
	PerOrder(pRoot);
	printf("\n");
	printf("ǰ���ӡ���ǵݹ飩��");
	PerOrderNor(pRoot);
	printf("\n");
	printf("�����ӡ��");
	InFixOrder(pRoot);
	printf("\n");
	printf("�����ӡ������һ�ǵݹ飩��");
	InFixOrderNor_1(pRoot);
	printf("\n");
	printf("�����ӡ���������ǵݹ飩��");
	InFixOrderNor_2(pRoot);
	printf("\n");
	printf("�����ӡ��");
	PostOrder(pRoot);
	printf("\n");
	printf("�����ӡ���ǵݹ飩��");
	PostOrderNor(pRoot);
	printf("\n");
	printf("�����ӡ��");
	LevelOrder(pRoot);
	printf("\n");
	pNewRoot_TestCopyBinTree = CopyBinTree(pRoot);
	printf("ǰ�������TEST COPY BINTREE��:");
	PerOrder(pNewRoot_TestCopyBinTree);
	printf("\n");
	MirrorBinTree(pRoot);
	printf("ǰ���ӡ������pRoot�ݹ飩��");
	PerOrder(pRoot);
	printf("\n");
	MirrorBinTreeNor(pRoot);
	printf("ǰ���ӡ������pRoot�ǵݹ飩��");
	PerOrder(pRoot);
	printf("\n");	
	printf("�������Ľڵ������%d��.\n", BinTreeSize(pRoot));
	printf("������Ҷ�ӽڵ������%d��.\n", BinTreeLeaf(pRoot));
	printf("�������ĸ߶ȣ�%d.\n", BinTreeHight(pRoot));
	printf("��������%d��Ľڵ����Ϊ%d.\n", 2, BinTreeKLevelNode(pRoot, 2));
	pFindNode = FindNode(pRoot, 'F');
	if (IsNodeInBinTree(pRoot, FindNode(pRoot, 'F')))
		printf("yes\n");
	else
		printf("NO\n");
}