#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//测试主函数main是否可以被调用
int main()
{
	printf("1");
	main();
}