#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//int count_one_bits(int num)
//{
//	int i = 0;
//	int count = 0;
//	if (1 <= num)
//	{
//		while (32 > i)
//		{
//			if (num % 2 == 1)
//			{
//				count++;
//			}
//			num = num >> 1;
//			i++;
//			}
//		return count;
//	}
//	else
//	{
//		num = -num;
//		while (32 > i)
//		{
//			if (num % 2 == 1)
//			{
//				count++;
//			}
//			num = num >> 1;
//			i++;
//		}
//		return count + 1;
//	}
//
//}
//int main()
//{
//	int num = 0;
//	int count = 0;
//	printf("请输入一个数字：");
//	scanf("%d", &num);
//	count = count_one_bits(num);
//	printf("这个数字的二进制序列中有%d个1\n", count);
//	system("pause");
//	return 0;
//}
//void Separated(num)
//{
//	int i = 0;
//
//	if (1 <= num)
//	{
//		printf("奇数序列：");
//		int num_1 = num;
//		while (32 > i)
//		{
//			printf("%d ", num_1 % 2);
//			num_1 = num_1 >> 2;
//			i += 2;
//		}
//		printf("\n");
//		i = 0;
//		printf("偶数序列：");
//		while (32 > i)
//		{
//			num = num >> 1;
//			printf(" %d", num % 2);
//			i += 2;
//		}
//	}
//	else
//	{
//		num = -num;
//		int num_1 = num;
//		printf("奇数序列：");
//		while (32 > i)
//		{
//			printf("%d ", num_1 % 2);
//			num_1 = num_1 >> 2;
//			i += 2;
//		}
//		printf("\n");
//		i = 0;
//		printf("偶数序列：");
//		while (30 > i)
//		{
//			num = num >> 1;
//			printf(" %d", num % 2);
//			i += 2;
//		}
//		printf(" 1");
//	}
//	printf("\n");
//}
//int main()
//{
//	int num = 0;
//	printf("请输入一个数：");
//	scanf("%d", &num);
//	Separated(num);
//	system("pause");
//	return 0;
//}
//int main()
//{
//	int num = 0;
//	printf("请输入一个整数：");
//	scanf("%d", &num);
//	printf("从个位开始输出：");
//	while (num != 0)
//	{
//		printf("%d  ", num % 10);
//		num = num / 10;
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}
int main()
{
	int num_1 = 0;
	int num_2 = 0;
	int count = 0;
	int i = 0;
	printf("请输入两个数字");
	scanf("%d%d", &num_1, &num_2);
	if (((0 <= num_1) && (0 < num_1)) || ((0 >= num_1) && (0 >= num_2)))
	{
		while (i < 32)
		{
			if ((num_1 % 2) != (num_2 % 2))
			{
				count++;
			}
			num_1 = num_1 >> 1;
			num_2 = num_2 >> 1;
			i++;
		}
	}
	else
	{
		if (0 > num_1)
		{
			num_1 = -num_1;
		}
		if (0 > num_2)
		{
			num_2 = -num_2;
		}
		while (i < 31)
		{
			if ((num_1 % 2) != (num_2 % 2))
			{
				count++;
			}
			num_1 = num_1 >> 1;
			num_2 = num_2 >> 1;
			i++;
		}
		count++;
	}
	printf("这两个数的比特位中有%d个不同\n", count);
	system("pause");
	return 0;
}