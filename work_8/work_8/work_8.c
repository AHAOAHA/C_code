#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define LINE 5
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//	int e = 0;
//	for (a = 1; a <= 5; a++)
//	{
//		for (b = 1; b <= 5; b++)
//		{
//			if (b != a)
//			{
//				for (c = 1; c <= 5; c++)
//				{
//					if ((c != b) && (c != a))
//					{
//						for (d = 1; d <= 5; d++)
//						{
//							if ((d != c) && (d != b) && (d != a))
//							{
//								for (e = 1; e <= 5; e++)
//								{
//									if ((e != d) && (e != d) && (e != c) && (e != b) && (e != a))
//									{
//										if (((b == 2) + (a == 3)) == 1 && ((b == 2) + (e == 4)) == 1 && ((c == 1) + (d == 2)) == 1 && ((c == 5) + (d == 3)) == 1 && ((e == 4) + (a == 1)) == 1)
//										{
//											
//											printf("a=%d,b=%d,c=%d,d=%d,e=%d\n", a, b, c, d, e);
//										}
//									}
//								}
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//	system("pause");
//	return 0;
//
//}
//int main()
//{
//	char killer = 0;
//	for (killer = 'A'; killer <= 'D'; killer++)
//	{
//		if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3)
//		{
//			printf("%c\n", killer);
//		}
//	}
//	system("pause");
//	return 0;
//}
void Print(int arr[LINE][LINE])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < LINE; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%d",arr[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int arr[LINE][LINE] = { 0 };
	int i = 0;
	int j = 0;
	for (i = 0; i <= LINE; i++)
	{
		arr[i][0] = 1;
		arr[i][i] = 1;
	}
	for (i = 2; i <= LINE; i++)
	{
		for (j = 1; j <= i - 1; j++)
		{
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}
	Print(arr);
	system("pause");
	return 0;
}