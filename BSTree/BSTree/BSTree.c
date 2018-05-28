#include"BSTree.h"
//��ʼ��
void InitBSTree(BSTNode** pRoot)
{
	assert(pRoot);
	*pRoot = NULL;
}

BSTNode* BuyBSTNode(BSTDataType data)
{
	BSTNode* pNewNode = NULL;
	//Ϊ�½ڵ�����ռ�
	pNewNode = (BSTNode*)malloc(sizeof(BSTNode));
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}

	//���½ڵ㸳ֵ
	pNewNode->_data = data;
	pNewNode->_pLeft = NULL;
	pNewNode->_pRight = NULL;

	return pNewNode;
}
//����ֵΪdata��Ԫ��
void InsertBSTree(BSTNode** pRoot, BSTDataType data)
{
	BSTNode* pCur = NULL;
	BSTNode* pParent = NULL;
	assert(pRoot);
	//������������Ϊ��ʱ
	if (NULL == *pRoot)
	{
		*pRoot = BuyBSTNode(data);
		return;
	}
	//����������������ʱ
	//���Ҵ�����ڵ��λ��
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

	//�����½ڵ�
	if (data < pParent->_data)
	{
		pParent->_pLeft = BuyBSTNode(data);
	}
	else
	{
		pParent->_pRight = BuyBSTNode(data);
	}
}

//�ڶ����������в���ֵΪdata�Ľڵ�
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
//������ֵ
void Swap(BSTDataType* Left, BSTDataType* Right)
{
	BSTDataType tmp = *Left;
	*Left = *Right;
	*Right = tmp;
}
//ɾ��ֵΪdata�Ľڵ�
void DeleteBSTree(BSTNode** pRoot, BSTDataType data)
{
	BSTNode* pCur = NULL;
	BSTNode* pParent = NULL;
	BSTNode* MaxInLeft = NULL;
	BSTNode* pDel = NULL;
	assert(pRoot);

	//����ֵΪdata�Ľڵ�
	pDel = FindBSTree(pRoot, data);

	//��Ҫɾ���Ľڵ��Ǹ��ڵ�
	if (pDel == *pRoot)
	{
		//���ڵ�����Ӽ����������������Ľڵ�
		if (NULL == (*pRoot)->_pLeft)
		{
			//��˵�����ڵ�����ӽڵ�û���Һ���
			//�ø��ڵ���������Ӹ��ڵ���Һ���
			(*pRoot)->_pLeft->_pRight = (*pRoot)->_pRight;
			//�ͷŸ��ڵ�
			free(*pRoot);
			//��MAXINLEFT��Ϊ�µĸ��ڵ�
			pRoot = &(*pRoot)->_pLeft;
		}
		else
		{
			//�ҵ�pRoot�����������ұߣ���󣩵Ľڵ�
			MaxInLeft = (*pRoot)->_pLeft;
			while (MaxInLeft->_pRight)
			{
				pParent = MaxInLeft;
				MaxInLeft = MaxInLeft->_pRight;
			}
			//���ҵ��Ľڵ��˫�׽ڵ���Һ����ÿ�
			pParent->_pRight = NULL;
			//�����ҵ��Ľڵ�����ڵ������
			Swap(&MaxInLeft->_data, &(*pRoot)->_data);
			//�ͷ��ҵ��Ľڵ�
			free(MaxInLeft);
			MaxInLeft = NULL;
		}
	}

	//��Ҫɾ���Ľڵ��ڸ��ڵ������������
	else
	{
		pCur = (*pRoot);

		//Ҫɾ���Ľڵ��Ǻ��ӽڵ�||Ҫɾ���Ľڵ�ֻ��һ������
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
			//PdeL��˫�׵�����
			if (pDel = pParent->_pLeft)
			{
				if (NULL != pDel->_pLeft)
					pParent->_pLeft = pDel->_pLeft;
				else if (NULL != pDel->_pRight)
					pParent->_pLeft = pDel->_pRight;
				else
					pParent->_pLeft = pDel->_pLeft;
			}
			//PdeL��˫�׵��Һ���
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

		//Ҫɾ���Ľڵ�����������
		else if (NULL != pDel->_pLeft&&NULL != pDel->_pRight)
		{
			//Ҫɾ���Ľڵ��ڸ��ڵ��������
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

//�����������������
void PreOrder(BSTNode* pRoot)
{
	if (NULL == pRoot)
		return;
	PreOrder(pRoot->_pLeft);
	printf("%d   ", pRoot->_data);
	PreOrder(pRoot->_pRight);
}
//���ٶ���������
void DestroyBSTree(BSTNode** pRoot)
{
	assert(*pRoot);
	DestroyBSTree(&(*pRoot)->_pLeft);
	DestroyBSTree(&(*pRoot)->_pRight);
	free(*pRoot);
	*pRoot = NULL;
}

/////////////////////////////////////���Ժ���
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