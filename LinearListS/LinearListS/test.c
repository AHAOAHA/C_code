#define _CRT_SECURE_NO_WARNINGS 1
#include"LinearListS.h"
int main()
{
	LinearList ListS;
	InitList(&ListS);
	InputList(&ListS);
	//LinearListPushBack(&ListS, 9);
	//LinearListPopBack(&ListS);
	//LinearListPushFront(&ListS, DataType data);
	//LinearListPushFront(&ListS, 8);
	//LinearListPopBack(&ListS);
	//LinearListPopFront(&ListS);
	//LinearListRemove(&ListS, 4);
	//LinearListErase(&ListS, 3);
	//LinearListInsert(&ListS, 2, 4);
	//LinearListRemoveAll(&ListS, 4);
	//BubbleSort(&ListS);
	SelectSort(&ListS);
	PrintList(&ListS);
	system("pause");
	return 0;
}	