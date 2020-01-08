#define _CRT_SECURE_NO_WARNINGS 1
typedef int BSTDataType;
typedef struct BSTreeNode
{
	struct BSTreeNode* _pLeft;
	struct BSTreeNode* _pRight;
	BSTDataType _data;
}BSTNode;
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//��ʼ������������
void InitBSTree(BSTNode** pRoot);
void InsertBSTree(BSTNode** pRoot, BSTDataType data);
BSTNode* BuyBSTNode(BSTDataType data);
BSTNode* FindBSTree(BSTNode** pRoot, BSTDataType data);
void Swap(BSTDataType* Left, BSTDataType* Right);
void DeleteBSTree(BSTNode** pRoot, BSTDataType data);
void PreOrder(BSTNode* pRoot);
void DestroyBSTree(BSTNode** pRoot);
BSTNode* FindBSTreeR(BSTNode** pRoot, BSTDataType data);
int DeleteBSTreeR(BSTNode** pRoot, BSTDataType data);
void TestBSTree();