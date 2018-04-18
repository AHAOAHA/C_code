#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//int Feibonacci(int k)
//{
//	if (k > 2)
//		return Feibonacci(k-1)+Feibonacci(k-2);
//	else
//		return 1;
//}
//int main()
//{
//	int k = 0;
//	scanf("%d", &k);
//	printf("%d\n", Feibonacci(k));
//	system("pause");
//	return 0;
//}


//int Feibonacci(int k)
//{
//	int i = 0;
//	int first = 1;
//	int second = 1;
//	int third = 0;
//	if (k < 2)
//		return 1;
//	else
//	{
//		for (i = 0; i < k-2; i++)
//		{
//			third = first + second;
//			first = second;
//			second = third;
//		}
//		return third;
//	}
//}
//int main()
//{
//	int k = 0;
//	scanf("%d", &k);
//	printf("%d\n", Feibonacci(k));
//	system("pause");
//	return 0;
//}

//int Index(int n, int k)
//{
//	if (k > 1)
//	{
//		return n*Index(n, k - 1);
//	}
//	else if (k < 1)
//	{
//		return n*Index(n ,k + 1);
//	}
//	else
//	{
//		return n;
//	}
//}
//int main()
//{
//	int n = 0;
//	int k = 0;
//	printf("n=");
//	scanf("%d", &n);
//	printf("k=");
//	scanf("%d", &k);
//	printf("n^k=%d\n", Index(n, k));
//	system("pause");
//	return 0;
//}


//int Digitsum(int num)
//{
//	if (num > 10)
//	{
//		return num % 10 + Digitsum(num / 10);
//	}
//	else
//		return num;
//}
//int main()
//{
//	int num = 0;
//	int ret = 0;
//	printf("num=");
//	scanf("%d", &num);
//	ret = Digitsum(num);
//	printf("ret=%d\n", ret);
//	system("pause");
//	return 0;
//}


//void reverse_string(char arr[])
//{
//	char *p = NULL;
//	p = arr;
//	if (*p == '\0')
//		printf("·´Ïò£º");
//	else
//	{
//		reverse_string(++p);
//		printf("%c", *(--p));
//	}
//}
//int main()
//{
//	int sz = 0;
//	char arr[] = "abcdef";
//	reverse_string(arr);
//	system("pause");
//	return 0;
//}


//int My_strlen(char *p)
//{
//	char *pa = NULL;
//	pa = p;
//	if (*pa != '\0')
//		return My_strlen(pa + 1) + 1;
//	else
//		return 0;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	int ret = 0;
//	ret = My_strlen(arr);
//	printf("%s\n", arr);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}

//int My_strlen(char *p)
//{
//	int count = 0;
//	while (*(p++) != '\0')
//	{
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	int ret = 0;
//	ret = My_strlen(arr);
//	printf("%s\n", arr);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}

//int Factorial(int n)
//{
//	if (n > 1)
//		return Factorial(n - 1)*n;
//	else
//		return 1;
//}
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	printf("n=");
//	scanf("%d", &n);
//	ret = Factorial(n);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}


//int Factorial(int n)
//{
//	int sum = 1;
//	while (n != 1)
//	{
//		sum = sum*(n--);
//	}
//	return sum;
//}
//int main()
//{
//	int ret = 0;
//	int n = 0;
//	printf("n=");
//	scanf("%d", &n);
//	ret = Factorial(n);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}

//void Print(int n)
//{
//	if (n > 10)
//	{
//		printf("%d\n", n % 10);
//		Print(n / 10);
//	}
//	else
//		printf("%d\n", n);
//}
//
//int main()
//{
//	int n = 1234;
//	int ret = 0;
//	Print(n);
//	system("pause");
//	return 0;
//}