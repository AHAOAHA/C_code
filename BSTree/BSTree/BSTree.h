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
//³õÊ¼»¯¶þ²æËÑË÷Ê÷
void InitBSTree(BSTNode** pRoot);
void InsertBSTree(BSTNode** pRoot, BSTDataType data);
BSTNode* BuyBSTNode(BSTDataType data);

void TestBSTree();