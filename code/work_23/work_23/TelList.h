#define _CRT_SECURE_NO_WARNINGS 1
#ifndef __TELLIST__
#define __TELLIST__
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct TelList
{
	char name[20];
	enum SEX
	{
		MAN,
		WOMAN,
		SECRET
	}sex;
	int age;
	long long int tel;
	char address[50];
	int size;
	int num;
}TelList,*PTelList;
void InitTelList(PTelList * ps);
void AddTelList(PTelList plist);
void DelTelList(PTelList plist);
void PrintTelList(PTelList plist);
#endif//__TELLIST__
