#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define MAXSIZE 50
typedef int DataType;
typedef struct Stack
{
	DataType * _array;
	int _top;//表示有效元素个数 表示栈顶位置
	int _capacity;//底层空间总大小
}Stack;
void StackInit(Stack* s);
void StackPush(Stack* s, DataType data);
void StackPop(Stack* s);
DataType StackTop(Stack* s);
int StackSize(Stack* s);
int StackEmpty(Stack* s);
void StackDestroy(Stack* s);
int MatchBrackets(Stack* s, char* str);
int RPN(Stack* s, char* str);
