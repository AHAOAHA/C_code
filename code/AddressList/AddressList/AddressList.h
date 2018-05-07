#ifndef __ADDRESS_LIST__
#define __ADDRESS_LIST__
#define _CRT_SECURE_NO_WARNINGS 1
#define MAXSIZE 1000
//int Size = 1000;
typedef struct LinkMan
{
	char _name[20];
	int _age;
	enum Sex
	{
		MAN,
		WOMAN,
		SECERT
	}Sex;
	long long int _Tel;
	char _address[50];
	int _order;
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
void Menu();
void TestAddressList();
#endif//__ADDRESS_LIST__