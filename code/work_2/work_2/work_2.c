#include<stdio.h>
#include<stdlib.h>
//void swap(int *x, int *y)
//{
//	int tmp = 0;
//	tmp = *x;
//	*x = *y;
//	*y = tmp;
//
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf_s("%d%d", &a, &b);
//	printf("a=%d,b=%d\n",a,b);
//	swap(&a, &b);
//	printf("a=%d,b=%d\n",a,b);
//	system("pause");
//	return 0;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int tmp = 0;
//	scanf_s("%d%d", &a, &b);
//	printf("a=%d,b=%d\n", a, b);
//	tmp = a;
//	a = b;
//	b = tmp;
//	printf("a=%d,b=%d\n", a, b);
//	system("pause");
//	return 0;
//}
//int main()
//{
//	int num[10] = { 0 };
//	int i = 0;
//	int j = 0;
//	int tmp = 0;
//	for (i = 0; i < 10; i++)
//	{
//		scanf_s("%d", &num[i]);
//	}
//	for (j = 0; j <= 8; j++)
//	{
//		if (num[j] >= num[j + 1])
//		{
//			tmp = num[j + 1];
//			num[j + 1] = num[j];
//			num[j] = tmp;
//		}
//	}
//	printf("MAX=%d\n", num[9]);
//	system("pause");
//	return 0;
//}
//int main()
//{
//	int num[3] = { 0 };
//	int i = 0;
//	int tmp = 0;
//	for (i = 0; i <= 2; i++)
//	{
//		scanf_s("%d", &num[i]);
//	}
//	for (i = 0; i <= 1; i++)
//	{
//		if (num[i] >= num[i + 1])
//		{
//			tmp = num[i];
//			num[i] = num[i + 1];
//			num[i + 1] = tmp;
//		}
//	}
//	printf("%d>%d>%d\n", num[2], num[1], num[0]);
//	system("pause");
//	return 0;
//}
int main()
{
	int a = 0;
	int b = 0;
	int num_a[] = { 0 };
	int num_b[] = { 0 };
	int num[] = { 0 };
	int i = 0;
	int x = 0;
	int y = 0;
	int z = 0;
	int j = 0;
	int q = 0;
	int w = 0;
	int tmp = 0;
	scanf_s("%d%d", &a, &b);
	for (i = 1; i <= a; i++)
	{
		if (a%i == 0)
		{
			num_a[x++] = i;
		}
	}
	for (i = 1; i <= b; i++)
	{
		if (b%i == 0)
		{
			num_b[y++] = i;
		}
	}
	printf("a有%d个约数\nb有%d个约数\n",x,y);
	if (a <= b)
	{
		for (z = 0; z <= x - 1; z++)
		{
			for (j = 0; j <= y- 1; j++)
			{
				if (num_a[z] == num_b[j])
				{
					num[q++] = num_a[z];
				}
			
			}

		}
	}
	else
	{
		for (z = 0; z <= x - 1; z++)
		{
			for (j = 0; j <= y - 1; j++)
			{
				if (num_b[z] == num_a[j])
				{
					num[q++] = num_b[z];
				}
			}

		}
	}
	printf("a,b的公约数有%d个\n", q);
	for (w = 0; w <= q - 3; w++)
	{
		if (num[w] >= num[w + 1])
		{
			tmp = num[w + 1];
			num[w + 1] = num[w];
			num[w] = tmp;
		}
	}
	printf("最大公约数=%d\n", num[q - 1]);
	system("pause");
	return 0;
}