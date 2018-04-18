#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define EXCHANGE(X) (((X)%10)*10)+((X)/10)
//#define MAX(X, Y) (X)>(Y)?(X):(Y)
//int main()
//{
//	int a = 3;
//	int b = 5;
//	int max = MAX(a, b);
//	printf("max = %d\n", max);
//	system("pause");
//	return 0;
//}
int main()
{
	int a = 0;
	int ret = 0;
	printf("请输入一个两位数：");
	scanf("%d", &a);
	ret = EXCHANGE(a);
	printf("ret = %d\n", ret);
	system("pause");
	return 0;
}