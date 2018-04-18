#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//int main()
//{
//	char a = '*';
//	int i = 0;
//	int j = 0;
//	for (i = 0; i <= 6; i++)
//	{
//		for (j = 0; j < 2 * i + 1; j++)
//		{
//			printf("%c", a);
//		}
//		printf("\n\n");
//	}
//	for (i = 5; i >= 0; i--)
//	{
//		for (j = 0; j < 2 * i + 1; j++)
//		{
//			printf("%c", a);
//		}
//		printf("\n\n");
//	}
//
//	system("pause");
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	int num_g = 0;
//	int num_s = 0;
//	int num_b = 0;
//	printf("0-999的水仙花数：");
//	for (i = 0; i < 1000; i++)
//	{
//		if (10 > i)
//		{
//			if (i*i*i == i)
//			{
//				printf("%d ", i);
//			}
//		}
//		else if (10 <= i && 100 > i)
//		{
//			num_g = i % 10;
//			num_s = i / 10;
//			if (num_g*num_g*num_g + num_s*num_s*num_s == i)
//			{
//				printf("%d ", i);
//			}
//		}
//		else if (100 <= i && 1000 > i)
//		{
//			num_g = i % 10;
//			num_b = i / 100;
//			num_s = i / 10 - num_b * 10;
//			if (num_g*num_g*num_g + num_b*num_b*num_b + num_s*num_s*num_s == i)
//			{
//				printf("%d ", i);
//			}
//		}
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}
//int main()
//
//{
//	int an[] = { 0 };
//	int sn[] = { 0 };
//
//	int i = 0;
//	int num = 2;
//
//
//	for ( i = 0; i <= 5; i++)
//	{
//		an[i+1] = 10 * an[i] + num;
//		printf("%d\n", an[i]);
//		sn[i+1] = sn[i+1] + an[i+1];
//	}
//	printf("sn5=%d", sn[5]);
//	system("pause");
//	return 0;
//}
