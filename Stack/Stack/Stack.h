#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define MAXSIZE 50
typedef struct BinTreeNode* StackDataType;
typedef struct Stack
{
	StackDataType * _array;
	int _top;//��ʾ��ЧԪ�ظ��� ��ʾջ��λ��
	int _capacity;//�ײ�ռ��ܴ�С
}Stack;
void StackInit(Stack* s);
void StackPush(Stack* s, StackDataType data);
void StackPop(Stack* s);
StackDataType StackTop(Stack* s);
int StackSize(Stack* s);
int StackEmpty(Stack* s);
void StackDestroy(Stack* s);
int MatchBrackets(Stack* s, char* str);
int RPN(Stack* s, char* str);
void TestStack();