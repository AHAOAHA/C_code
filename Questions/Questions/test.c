#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int* a = NULL;
	a = (int*)malloc(sizeof(int));
	free(a);
	printf("%x\n", &a);
	printf("%x\n", a);
	system("pause");
	return 0;
}