#include"BSTree.h"
//初始化
void InitBSTree(BSTNode** pRoot)
{
	assert(pRoot);
	*pRoot = NULL;
}

BSTNode* BuyBSTNode(BSTDataType data)
{
	BSTNode* pNewNode = NULL;
	//为新节点申请空间
	pNewNode = (BSTNode*)malloc(sizeof(BSTNode));
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}

	//给新节点赋值
	pNewNode->_data = data;
	pNewNode->_pLeft = NULL;
	pNewNode->_pRight = NULL;

	return pNewNode;
}
//插入值为data的元素
void InsertBSTree(BSTNode** pRoot, BSTDataType data)
{
	BSTNode* pCur = NULL;
	BSTNode* pParent = NULL;
	assert(pRoot);
	//当二叉搜索树为空时
	if (NULL == *pRoot)
	{
		*pRoot = BuyBSTNode(data);
		return;
	}
	//当二叉搜索树不空时
	//查找带插入节点的位置
	pCur = *pRoot;
	pParent = pCur;
	while (pCur)
	{
		pParent = pCur;
		if (data < pCur->_data)
		{
			pCur = pCur->_pLeft;
		}
		else if (data>pCur->_data)
		{
			pCur = pCur->_pRight;
		}
		else
			return;
	}

	//插入新节点
	if (data < pParent->_data)
	{
		pParent->_pLeft = BuyBSTNode(data);
	}
	else
	{
		pParent->_pRight = BuyBSTNode(data);
	}
}

//在二叉搜索树中查找值为data的节点
BSTNode* FindBSTree(BSTNode** pRoot, BSTDataType data)
{
	BSTNode* pFind = NULL;
	assert(pRoot);
	pFind = *pRoot;
	while (pFind)
	{
		if (data == pFind->_data)
			return pFind;
		else if (data < pFind->_data)
		{
			pFind = pFind->_pLeft;
		}
		else
		{
			pFind = pFind->_pRight;
		}
	}
	return NULL;
}
//交换数值
void Swap(BSTDataType* Left, BSTDataType* Right)
{
	BSTDataType tmp = *Left;
	*Left = *Right;
	*Right = tmp;
}
//删除值为data的节点
void DeleteBSTree(BSTNode** pRoot, BSTDataType data)
{
	BSTNode* pCur = NULL;
	BSTNode* pParent = NULL;
	BSTNode* MaxInLeft = NULL;
	BSTNode* pDel = NULL;
	assert(pRoot);
	
	pCur = *pRoot;

	//寻找要删除的节点
	while (pCur &&  data != pCur->_data)
	{
		if (data < pCur->_data)
			pCur = pCur->_pLeft;
		else
			pCur = pCur->_pRight;
	}
	//如果要删除的数字不在二叉树中就退出
	if (NULL == pCur)
		return;

	//用pDel标记要删除的节点
	pDel = pCur;
		//a.要删除的结点无孩子结点  
		//b.要删除的结点只有左孩子结点 
	if ((pDel->_pLeft && NULL == pDel->_pRight)||(NULL == pDel->_pLeft&&NULL ==pDel->_pRight))
	{
		//让要删除节点的双亲节点指向要删除节点的左孩子
		pCur = *pRoot;
		pParent = *pRoot;

		//找要删除节点的双亲节点
		while (pCur != pDel)
		{
			pParent = pCur;
			if (data < pCur->_data)
			{
				pCur = pCur->_pLeft;
			}
			else
			{
				pCur = pCur->_pRight;
			}
		}

		if (pParent == pDel)//要删除的节点是根节点
		{
			pRoot = &(*pRoot)->_pLeft;
			free(pDel);
			pDel = NULL;
			return;
		}

		//判断要删除的节点是双亲结点的左孩子还是右孩子
		if (pParent->_pLeft == pDel)
		{
			//要删除的节点不是根节点
			pParent->_pLeft = pDel->_pLeft;
			free(pDel);
			pDel = NULL;
			return;
		}
		else
		{
			pParent->_pRight = pDel->_pLeft;
			free(pDel);
			pDel = NULL;
			return;
		}
	}
		//c.要删除的结点只有右孩子结点  
	else if (pDel->_pRight && NULL == pDel->_pLeft)
	{
		pCur = *pRoot;
		pParent = pCur;

		//找要删除节点的双亲结点
		while (pCur != pDel)
		{
			pParent = pCur;
			if (data < pCur->_data)
			{
				pCur = pCur->_pLeft;
			}
			else
			{
				pCur = pCur->_pRight;
			}
		}

		if (pParent == pDel)//要删除的节点是根节点
		{
			pRoot = &(*pRoot)->_pRight;
			free(pDel);
			pDel = NULL;
			return;
		}

		//要删除的节点不是根节点

		//判断要删除的节点是双亲节点的左孩子还是右孩子
		if (pParent->_pRight == pDel)
		{
			pParent->_pRight = pDel->_pRight;
			free(pDel);
			pDel = NULL;
			return;
		}
		else
		{
			pParent->_pLeft = pDel->_pRight;
			free(pDel);
			pDel = NULL;
			return;
		}
	}
		//d.要删除的结点有左、右孩子结点 
	if (pDel->_pLeft&&pDel->_pRight)
	{
		pCur = *pRoot;
		pParent = pCur;

		//找要删除节点的双亲结点
		while (pCur != pDel)
		{
			pParent = pCur;
			if (data < pCur->_data)
			{
				pCur = pCur->_pLeft;
			}
			else
			{
				pCur = pCur->_pRight;
			}
		}
		
		if (pParent == pDel)//要删除节点是根节点
		{
			//找到根节点左子树中最右边的节点与他的双亲节点
			pCur = (*pRoot)->_pLeft;
			pParent = *pRoot;
			while (pCur->_pRight)
			{
				pParent = pCur;
				pCur = pCur->_pRight;
			}
			//交换节点的数值
			Swap(&pCur->_data, &pDel->_data);
			//根节点的左子树就是最大的节点
			if (pParent == *pRoot)
			{
				pParent->_pLeft = pCur->_pLeft;
				free(pCur);
				pCur = NULL;
				return;
			}
			pParent->_pRight = pCur->_pRight;
			return;
		}

		//要删除的节点不是根节点
		//将要要删除的节点作为根节点
		DeleteBSTree(&pDel, data);
	}
}

//中序遍历二叉搜索树
void PreOrder(BSTNode* pRoot)
{
	if (NULL == pRoot)
		return;
	PreOrder(pRoot->_pLeft);
	printf("%d   ", pRoot->_data);
	PreOrder(pRoot->_pRight);
}
//销毁二叉搜索树
void DestroyBSTree(BSTNode** pRoot)
{
	assert(*pRoot);
	DestroyBSTree(&(*pRoot)->_pLeft);
	DestroyBSTree(&(*pRoot)->_pRight);
	free(*pRoot);
	*pRoot = NULL;
}

//递归实现搜索二叉树查找
BSTNode* FindBSTreeR(BSTNode** pRoot, BSTDataType data)
{
	assert(pRoot);
	if (NULL == *pRoot)
		return NULL;
	if (data == (*pRoot)->_data)
		return *pRoot;
	else if (data < (*pRoot)->_data)
		return FindBSTreeR(&(*pRoot)->_pLeft, data);
	else if (data > (*pRoot)->_data)
		return FindBSTreeR(&(*pRoot)->_pRight, data);
	return NULL;
}

//递归实现搜索二叉树插入
int InsertBSTreeR(BSTNode** pRoot, BSTDataType data)
{
	assert(pRoot);
	if (NULL == *pRoot)
	{
		*pRoot = BuyBSTNode(data);
		return 1;
	}
	else if (data < (*pRoot)->_data)
		InsertBSTreeR(&(*pRoot)->_pLeft, data);
	else if (data > (*pRoot)->_data)
		InsertBSTreeR(&(*pRoot)->_pRight, data);
	return 0;
}

//递归实现二叉树删除
int DeleteBSTreeR(BSTNode** pRoot, BSTDataType data)
{
	BSTNode* pCur = NULL;
	BSTNode* pParent = NULL;
	assert(pRoot);
	if (NULL == *pRoot)
		return 0;
	if (data < (*pRoot)->_data)
		return DeleteBSTreeR(&(*pRoot)->_pLeft, data);
	else if (data>(*pRoot)->_data)
		return DeleteBSTreeR(&(*pRoot)->_pRight, data);
	else
	{
		BSTNode* pDel = (*pRoot);

		//如果要删除的节点只有右子树或没有子树
		if (NULL == pDel->_pLeft)
		{
			*pRoot = pDel->_pRight;
			free(pDel);
		}
		//要删除的节点只有右子树
		else if (NULL == pDel->_pRight)
		{
			*pRoot = pDel->_pLeft;
			free(pDel);
		}
		//要删除的节点既有左子树也有右子树
		else
		{
			//在左子树中找最右边的子树
			BSTNode* pSwap = pDel->_pLeft;
			BSTNode* pParent = pSwap;
			while (pSwap && pSwap->_pRight)
			{
				pParent = pSwap;
				pSwap = pSwap->_pRight;
			}

			//交换找到的节点与要删除节点的数值
			Swap(&pDel->_data, &pSwap->_data);

			//找到的节点是根节点的左子树，pSwap和pparent指向同一个节点，删除交换的节点pSwap
			if (pParent == pSwap)
			{
				*pRoot = pSwap->_pLeft;
				free(pSwap);
				pSwap = NULL;
			}
			//pSwap是pParent的右孩子
			else
			{
				pParent->_pRight = pSwap->_pRight;
				free(pSwap);
				pSwap = NULL;
			}
		}
	}
	return 1;
}

/////////////////////////////////////测试函数
void TestBSTree()
{
	BSTNode* pRoot;
	int i = 0;
	BSTDataType array[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	InitBSTree(&pRoot);
	for (; i < sizeof(array) / sizeof(array[0]); ++i)
	{
		InsertBSTree(&pRoot, array[i]);
	}
	PreOrder(pRoot);
	printf("\n");
	printf("%x\n", FindBSTreeR(&pRoot, 5));
	InsertBSTreeR(&pRoot, 10);
	InsertBSTreeR(&pRoot, 12);
	InsertBSTreeR(&pRoot, 11);
	printf("\n");
	PreOrder(pRoot);
	DeleteBSTreeR(&pRoot, 0);
	printf("\n");
	PreOrder(pRoot);
	printf("\n");
}