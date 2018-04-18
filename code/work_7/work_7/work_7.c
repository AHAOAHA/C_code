#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//void Mul(int i)
//{
//	int r = 0;
//	int j = 0;
//	for (r = 1; r <= i; r++)
//	{
//		for (j = 1; j <= r; j++)
//		{
//			printf("%3d*%2d=%4d", r, j, r*j);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int i = 0;
//	printf("请输入行数：");
//	scanf("%d", &i);
//	Mul(i);
//	system("pause");
//	return 0;
//}
//void Swap(int* pa, int* pb)
//{
//	int tmp = *pa;
//	*pa = *pb;
//	*pb = tmp;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	printf("请输入要交换的两个数：");
//	scanf("%d%d", &a, &b);
//	printf("a=%d,b=%d\n", a, b);
//	Swap(&a,&b);
//	printf("a=%d,b=%d\n", a, b);
//	system("pause");
//	return 0;
//}
//void Leap_year(int year)
//{
//	if ((0 == year % 400) || ((0 != year % 100) && (0 == year % 4)))
//	{
//		printf("是闰年\n");
//	}
//	else
//	{
//		printf("不是闰年\n");
//	}
//}
//int main()
//{
//	int year = 0;
//	printf("请输入要判断的年份：");
//	scanf("%d", &year);
//	Leap_year(year);
//	system("pause");
//	return 0;
//}
//void Prime_number(int num)
//{
//	int i = 0;
//	for (i = 2; i < num; i++)
//	{
//		if (0 == num%i)
//		{
//			printf("不是素数\n");
//			return;
//		}
//	}
//	printf("是素数\n");
//}
//int main()
//{
//	int num = 0;
//	printf("请输入要判断的数字：");
//	scanf("%d", &num);
//	Prime_number(num);
//	system("pause");
//	return 0;
//}
void init(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		scanf("%d", &arr[i]);
	}
}
void print(int arr[],int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d", arr[i]);
	}
	printf("\n");
}
reverse(int arr[], int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left<right)
	{
		int tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
}
empty(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		arr[i] = 0;
	}
}
int main()
{
	int arr[10] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	printf("请输入数字：");
	init(arr, sz);
	print(arr, sz);
	reverse(arr, sz);
	print(arr, sz);
	system("pause");
	empty(arr, sz);
	print(arr, sz);
	return 0;
}
