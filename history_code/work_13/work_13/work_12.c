#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int i = 0;
//	int j = 0;
//	int tmp = 0;
//	for (i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
//	{
//		if (arr[i] % 2 == 0)
//		{
//			for (j = i; j < sizeof(arr)/sizeof(arr[0])-i; j++)
//			{
//				tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//	for (i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
//	{
//		printf("%d  ", arr[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}
int main()
{
	int arr[3][3] = { { 1, 2, 3 }, { 2, 3, 4 }, { 3, 4, 5 } };
	int i = 0;
	int j = 0;
	int num = 0;
	int z = 0;
	int m = 0;
	printf("请输入要查找的数：");
	scanf("%d", &num);
	for (i = 0; i < 3; i++)
	{
		if (num >= arr[i][0] && num <= arr[i][2])
		{
			z = 1;
			m = i;
			break;
		}
		else
		{
			printf("没找到\n");
		}
	}
	switch (z)
	{
	case 0:break;
	case 1:
		for (j = 0; j < 3; j++)
		{
			if (arr[m][j] == num)
			{
				printf("找到了\n");
			}
		}
	}
	system("pause");
	return 0;
}


