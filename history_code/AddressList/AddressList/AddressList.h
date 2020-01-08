#ifndef __ADDRESS_LIST__
#define __ADDRESS_LIST__
#define _CRT_SECURE_NO_WARNINGS 1
#define MAXSIZE 1000//定义通讯录最大存储人数为1000
typedef struct LinkMan//定义存储的结构体
{
	char _name[20];//姓名
	int _age;//年龄
	enum Sex//性别
	{
		MAN,
		WOMAN,
		SECERT
	}Sex;
	long long int _Tel;//电话
	char _address[50];//地址
	int _order;//序号
}LinkManNode,*PLinkManNode;
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
/////////////////////////////////////////
void AddressListInit(PLinkManNode* AddressList);
void InputLinkMan(PLinkManNode AddressList);
void CoverLinkMan(PLinkManNode AddressList, int order);
void DeleteLinkMan(PLinkManNode* PAddressList, int order);
void FindLinkManByName(PLinkManNode PAddressList, char name[20]);
void PrintLinkManByOrder(PLinkManNode PAddressList, int order);
void FindLinkManByOrder(PLinkManNode PAddressList, int order);
void AmendLinkManByName(PLinkManNode PAddressList, char name[20]);
void AmendLinkManByOrder(PLinkManNode PAddressList, int order);
void SwapLinkMan(PLinkManNode pLinkMan_1, PLinkManNode pLinkMan_2);
void SortByName(PLinkManNode *PAddressList);
void Menu();
void TestAddressList();
#endif//__ADDRESS_LIST__