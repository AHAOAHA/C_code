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

	//查找值为data的节点
	pDel = FindBSTree(pRoot, data);

	//当要删除的节点是根节点
	if (pDel == *pRoot)
	{
		//根节点的左孩子即就是左子树中最大的节点
		if (NULL == (*pRoot)->_pLeft)
		{
			//即说明根节点的左孩子节点没有右孩子
			//让根节点的左孩子连接根节点的右孩子
			(*pRoot)->_pLeft->_pRight = (*pRoot)->_pRight;
			//释放根节点
			free(*pRoot);
			//让MAXINLEFT成为新的根节点
			pRoot = &(*pRoot)->_pLeft;
		}
		else
		{
			//找到pRoot左子树里最右边（最大）的节点
			MaxInLeft = (*pRoot)->_pLeft;
			while (MaxInLeft->_pRight)
			{
				pParent = MaxInLeft;
				MaxInLeft = MaxInLeft->_pRight;
			}
			//将找到的节点的双亲节点的右孩子置空
			pParent->_pRight = NULL;
			//交换找到的节点与根节点的数据
			Swap(&MaxInLeft->_data, &(*pRoot)->_data);
			//释放找到的节点
			free(MaxInLeft);
			MaxInLeft = NULL;
		}
	}

	//当要删除的节点在根节点的左右子树中
	else
	{
		pCur = (*pRoot);

		//要删除的节点是孩子节点||要删除的节点只有一颗子树
		if (NULL == pDel->_pLeft || NULL==pDel->_pRight)
		{
			while (pCur == pDel && pCur)
			{
				pParent = pCur;
				if (pDel->_data < pCur->_data)
				{
					pCur = pCur->_pLeft;
				}
				else if (pDel->_data>pCur->_data)
				{
					pCur = pCur->_pRight;
				}
			}
			//PdeL是双亲的左孩子
			if (pDel = pParent->_pLeft)
			{
				if (NULL != pDel->_pLeft)
					pParent->_pLeft = pDel->_pLeft;
				else if (NULL != pDel->_pRight)
					pParent->_pLeft = pDel->_pRight;
				else
					pParent->_pLeft = pDel->_pLeft;
			}
			//PdeL是双亲的右孩子
			else if (pDel = pParent->_pRight)
			{
				if (NULL != pDel->_pRight)
					pParent->_pRight = pDel->_pRight;
				else if (NULL != pDel->_pLeft)
					pParent->_pRight = pDel->_pLeft;
				else
					pParent->_pRight = pDel->_pLeft;
			}
			free(pDel);
			pDel = NULL;
			return;
		}

		//要删除的节点有两颗子树
		else if (NULL != pDel->_pLeft&&NULL != pDel->_pRight)
		{
			//要删除的节点在根节点的左子树
			if (pDel->_data < (*pRoot)->_data)
			{
				pCur = (*pRoot);
				while (pCur == pDel && pCur)
				{
					pParent = pCur;
					if (pDel->_data < pCur->_data)
					{
						pCur = pCur->_pLeft;
					}
					else if (pDel->_data>pCur->_data)
					{
						pCur = pCur->_pRight;
					}
				}
				pParent->_pLeft = pDel->_pRight;

			}
		}
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
}