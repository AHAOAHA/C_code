#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//void menu()
//{
//	printf("*****************************************************************\n");
//	printf("**********************1.play game  0.exit************************\n");
//	printf("*****************************************************************\n");
//}
//int game(int j)
//{
//	int i = 0;
//
//	scanf("%d", &i);
//	if (i < j)
//	{
//		return 1;
//	}
//	else if (i > j)
//	{
//		return 2;
//	}
//	else if (i == j)
//	{
//		return 3;
//	}
//	else
//	{
//		return 0;
//	}
//
//}
//int main()
//{
//
//	int i = 0;
//	int j = 0;
//	int ret = 0;
//	menu();
//	srand((unsigned)time(NULL));
//	j = rand() % 100;
//	scanf("%d", &i);
//	if (1 == i)
//	{
//		printf("游戏开始\n");
//		while(ret != 3)
//		{
//			ret = game(j);
//			if (1 == ret)
//			{
//				printf("太小了\n");
//			}
//			else if (2 == ret)
//			{
//				printf("太大了\n");
//			}
//		}
//		if (3 == ret)
//		{
//			printf("恭喜你，答对了！\n");
//		}
//	}
//	else if (0 == i)
//	{
//		printf("Game Over\n");
//
//		return 0;
//	}
//	system("pause");
//	return 0;
//}
int main()
{
	char arr[10] = { 0 };
	int i = 0;
	for (i = 0; i <= 2; i++)
	{
		printf("请输入密码：");
		scanf("%s", arr);
		if (0 == strcmp(arr, "123456"))
		{
			printf("密码正确\n");
			break;
		}
		else
		{
			printf("密码错误，请重新新输入\n");
		}
	}
	if (3 == i)
	{
		printf("三次输入错误\n");
	}
	system("pause");
	return 0;
}
int main()
{
	char i = 0;
	while (i!=-1)
	{
		scanf("%c", &i);
		if (97 <= i && 122 >= i)
		{
			printf("%c\n", i - 32);
		}
		else if (65 <= i && 90 >= i)
		{
			printf("%c\n", i + 32);
		}
	}

	system("pause");
	return 0;
}
//int Seach(int arr[],int key,int sz)
//{
//	int mid = 0;
//	int left = 0;
//	int right = sz - 1;
//	printf("请输入要查找的数字：");
//	scanf("%d", &key);
//	while (left <= right)
//	{
//		mid = left + (right - left) / 2;
//		if (arr[mid] == key)
//		{
//			return mid;
//		}
//		else if (arr[mid] < key)
//		{
//			left = left + 1;
//		}
//		else if (arr[mid] > key)
//		{
//			right = right - 1;
//		}
//	}
//	return -1;
//}
//
//	int main()
//{
//	int arr[] = {  1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int key = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = Seach(arr, key, sz);
//	if (-1 == ret)
//	{
//		printf("没有这个数字\n");
//	}
//	else
//	{
//		printf("%d\n", ret);
//	}
//	system("pause");
//	return 0;
//}