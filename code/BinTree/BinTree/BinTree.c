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
	if (NULL != pRoot)
	{
		printf("%c   ", pRoot->_data);
		PerOrder(pRoot->_pLeft);
		PerOrder(pRoot->_pRight);
	}
}
//�����ӡ�������ڵ�
void InFixOrder(PNode pRoot)
{
	if (NULL != pRoot)
	{
		InFixOrder(pRoot->_pLeft);
		printf("%c   ", pRoot->_data);
		InFixOrder(pRoot->_pRight);
	}
}
//�����ӡ�������ڵ�
void PostOrder(PNode pRoot)
{
	if (NULL != pRoot)
	{
		PostOrder(pRoot->_pLeft);
		PostOrder(pRoot->_pRight);
		printf("%c   ", pRoot->_data);
	}
}
///////////////////////////////////////////////////////���Ժ���
void TestBinTree()
{
	PNode pRoot;
	int index = 0;
	DataType unindex = '#';
	DataType array[] = "ABD###CE##F";
	CreateBinTree(&pRoot, array, &index, strlen(array), unindex);
	PerOrder(pRoot);
	printf("\n");
	InFixOrder(pRoot);
	printf("\n");
	PostOrder(pRoot);
	printf("\n");
}