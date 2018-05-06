#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>
#include<stdio.h>
#include<string.h>
#include"Queue.h"
#include"Stack.h"
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
void PerOrderNor(PNode pRoot);
void PostOrder(PNode pRoot);
void InFixOrder(PNode pRoot);
void LevelOrder(PNode pRoot);
void InFixOrderNor_1(PNode pRoot);
void InFixOrderNor_2(PNode pRoot);
void PostOrderNor(PNode pRoot);
void TestBinTree();
//////////////////////////////////////
