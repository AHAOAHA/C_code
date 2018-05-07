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
//前序打印二叉树节点
void PerOrder(PNode pRoot)
{
	if (NULL == pRoot)
		return;
	printf("%c   ", pRoot->_data);
	PerOrder(pRoot->_pLeft);
	PerOrder(pRoot->_pRight);
}
//前序打印二叉树节点---非递归
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
//中序打印二叉树节点
void InFixOrder(PNode pRoot)
{
	if (NULL == pRoot)
		return;
	InFixOrder(pRoot->_pLeft);
	printf("%c   ", pRoot->_data);
	InFixOrder(pRoot->_pRight);
}
//方法一---中序打印二叉树节点---非递归
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
//方法二---中序打印二叉树节点---非递归
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
			StackPop(&s);//删除栈顶的空节点
		pCur = StackTop(&s);
		printf("%c   ", pCur->_data);
		StackPop(&s);
		pCur = pCur->_pRight;
		if (pCur)//当右孩子存在时让它入栈
			StackPush(&s, pCur);
	}

}
//后序打印二叉树节点
void PostOrder(PNode pRoot)
{
	if (NULL == pRoot)
		return;
	PostOrder(pRoot->_pLeft);
	PostOrder(pRoot->_pRight);
	printf("%c   ", pRoot->_data);
}
//后序打印二叉树节点---非递归
void PostOrderNor(PNode pRoot)
{
	PNode pCur = NULL;
	Stack s1;
	Stack s2;
	if (NULL == pRoot)
		return;
	StackInit(&s1);
	StackInit(&s2);
	pCur = pRoot;
	StackPush(&s1, pCur);
	while (StackEmpty(&s1))
	{
		pCur = StackTop(&s1);
		StackPop(&s1);
		StackPush(&s2, pCur);
		if (pCur->_pLeft)
			StackPush(&s1, pCur->_pLeft);
		if (pCur->_pRight)
			StackPush(&s1, pCur->_pRight);
		pCur = StackTop(&s1);
	}
	while (StackEmpty(&s2))
	{
		printf("%c   ", StackTop(&s2)->_data);
		StackPop(&s2);
	}
}
//层序遍历打印二叉树节点---需要使用队列
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
///////////////////////////////////////////////////////测试函数
void TestBinTree()
{
	PNode pRoot;
	int index = 0;
	DataType unindex = '#';
	DataType array[] = "ABD###CE##F";
	CreateBinTree(&pRoot, array, &index, strlen(array), unindex);
	printf("前序打印：");
	PerOrder(pRoot);
	printf("\n");
	printf("前序打印（非递归）：");
	PerOrderNor(pRoot);
	printf("\n");
	printf("中序打印：");
	InFixOrder(pRoot);
	printf("\n");
	printf("中序打印（方法一非递归）：");
	InFixOrderNor_1(pRoot);
	printf("\n");
	printf("中序打印（方法二非递归）：");
	InFixOrderNor_2(pRoot);
	printf("\n");
	printf("后序打印：");
	PostOrder(pRoot);
	printf("\n");
	printf("后序打印（非递归）：");
	PostOrderNor(pRoot);
	printf("\n");
	printf("层序打印：");
	LevelOrder(pRoot);
	printf("\n");
}