#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//void swap(int *pa, int *pb)
//{
//	int tmp = 0;
//	tmp = *pa;
//	*pa = *pb;
//	*pb = tmp;
//}
//int main()
//{
//	int arr_a[4] = { 1, 2, 3, 4 };
//	int arr_b[4] = { 6, 7, 8, 9 };
//	int i = 0;
//	printf("arr_a={ %d,%d,%d,%d }\narr_b={ %d,%d,%d,%d }\n",arr_a[0], arr_a[1], arr_a[2], arr_a[3], arr_b[0], arr_b[1], arr_b[2], arr_b[3]);
//	for (i = 0; i <= 3; i++)
//	{
//		swap(&arr_a[i], &arr_b[i]);
//	}
//	printf("arr_a={ %d,%d,%d,%d }\narr_b={ %d,%d,%d,%d }\n", arr_a[0], arr_a[1], arr_a[2], arr_a[3], arr_b[0], arr_b[1], arr_b[2], arr_b[3]);
//	system("pause");
//	return 0;
//}
//int main()
//{
//	float i = 0.0;
//	float add = 0;
//	float num = 0;
//	for (i = 1; i <= 100;i+=2)
//	{
//		num =num + (1 / i - 1 / (1 + i));
//	}
//	printf("%f\n", num);
//	system("pause");
//	return 0;
//}
//int main()
//{
//	int num = 0;
//	int i = 0;
//	int a = 0;
//	for (num = 1; num <= 100; num++)
//	{
//		if (num < 10 && num == 9)
//		{
//			++i;
//		}
//		else if (num >= 10)
//		{
//			a = num / 10;
//			if (a == 9)
//			{
//				++i;
//			}
//			if ((num - 10 * (a)) == 9)
//			{
//				++i;
//			}
//        }
//	}
//	printf("9出现的次数=%d\n", i);
//	system("pause");
//	return 0;
//}