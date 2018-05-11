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
//拷贝二叉树   根+左子树+右子树
PNode CopyBinTree(PNode pRoot)
{
	PNode pNewRoot = NULL;
	if (pRoot)
	{
		pNewRoot = BuyBinTreeNode(pRoot->_data);
		//拷贝左子树
		pNewRoot->_pLeft = CopyBinTree(pRoot->_pLeft);
		//拷贝右子树
		pNewRoot->_pRight = CopyBinTree(pRoot->_pRight);
	}
	return pNewRoot;
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
//找当前树最左边的节点，并保存所经过路径中的所有节点
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
	PNode pTop = NULL;
	PNode pPrev = NULL;//标记最近访问过的节点
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
		if (NULL == pTop->_pRight || pTop->_pRight == pPrev)//如果发现栈顶节点的右孩子已经被访问过时，直接遍历栈顶节点
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
//二叉树的销毁
//后序遍历的应用
void DetoryBinTree(PNode* pRoot)
{
	PNode pCur = NULL;
	assert(pRoot);
	if (*pRoot)
	{
		DetoryBinTree(&(*pRoot)->_pLeft);
		DetoryBinTree(&(*pRoot)->_pRight);
		free(*pRoot);
		*pRoot = NULL;
	}
}
//二叉树的镜像---递归
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
//二叉树的镜像---非递归
//后序遍历 从后向前镜像
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
//求二叉树中节点的个数
int BinTreeSize(PNode pRoot)
{
	static int count = 0;
	if (NULL == pRoot)
		return 0;
	if (pRoot)
	{
		count++;
		BinTreeSize(pRoot->_pLeft);
		BinTreeSize(pRoot->_pRight);
	}
	return count;
}
//求二叉树中叶子节点的个数
int BinTreeKLevelNode(PNode pRoot, int K)
{

}
///////////////////////////////////////////////////////测试函数
void TestBinTree()
{
	PNode pRoot;
	PNode pNewRoot_TestCopyBinTree;
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
	pNewRoot_TestCopyBinTree = CopyBinTree(pRoot);
	printf("前序遍历（TEST COPY BINTREE）:");
	PerOrder(pNewRoot_TestCopyBinTree);
	printf("\n");
	MirrorBinTree(pRoot);
	printf("前序打印（镜像pRoot递归）：");
	PerOrder(pRoot);
	printf("\n");
	MirrorBinTreeNor(pRoot);
	printf("前序打印（镜像pRoot非递归）：");
	PerOrder(pRoot);
	printf("\n");	
	printf("二叉树的节点个数：%d个.\n", BinTreeSize(pRoot));
}