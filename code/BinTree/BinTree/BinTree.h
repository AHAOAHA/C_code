#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>
#include<stdio.h>
#include<string.h>
typedef char DataType;
typedef struct BinTreeNode
{
	struct BinTreeNode* _pLeft;
	struct BinTreeNode* _pRight;
	DataType _data;
}Node, *PNode;
//////////////////////////////////////
void TestBinTree();
void CreateBinTree(PNode* pRoot, DataType array[], int* index, int size, DataType unindex);
PNode BuyBinTreeNode(DataType data);
void PerOrder(PNode pRoot);
void PostOrder(PNode pRoot);
void InFixOrder(PNode pRoot);
void TestBinTree();
//////////////////////////////////////
