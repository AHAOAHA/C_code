#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
//int main()
//{
//	int arr[] = { 1, 1, 2, 3, 3, 4, 5, 5, 6, 6, 7, 7, 8, 8 };
//	int i = 0;
//	int j = 0;
//	int sz = 0;
//	int num = 0;
//	int count = 0;
//	sz = sizeof(arr) / sizeof(arr[0]);
//	for (j = 0; j < sz; j++)
//	{
//		num = arr[j];
//		count = 0;
//		for (i = 0; i < sz; i++)
//		{
//			if (arr[i] == num)
//			{
//				count++;
//			}
//		}
//		if (1 == count)
//		{
//			printf("%d\n", num);
//		}
//	}
//	system("pause");
//	return 0;
//}
//
//
//
//
//int Bottle(int money)
//{
//	if (money != 0 && money >= 2)
//	{
//		if (0 == (money % 2))
//		{
//			return money + Bottle(money / 2);
//		}
//		else 
//		{
//			return money + Bottle(money / 2) + 1;
//		}
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//	int money = 0;
//	printf("money=");
//	scanf("%d", &money);
//	printf("you can drink %d botttle\n", Bottle(money));
//	system("pause");
//	return 0;
//}
//
//
//void My_strcpy(char *dest, char *src)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	while (*dest++ = *src++)
//	{
//		;
//	}
//
//}
//int main()
//{
//	char arr[10] = "abcdef";
//	char arr1[10] = "hahahah";
//	printf("*p=%s\n", arr1);
//	My_strcpy(arr1, arr);
//	printf("*p=%s\n", arr1);
//	system("pause");
//	return 0;
//}
//
//
//#include<string.h>
//char *My_strcat(char *str_front,const char *str_later)
//{
//	assert(str_front != NULL);
//	assert(str_later != NULL);
//	char *p = str_front;
//	while (*str_front != '\0')
//	{
//		str_front++;
//	}
//	while (*str_front++ = *str_later++)
//	{
//		;
//	}
//	return p;
//}
//int main()
//{
//	char str[10] = "abcdef";
//	char str1[10] = "scjsic";
//	char *p = NULL;
//	p = My_strcat(str, str1);
//	printf("strcat = %s\n", p);
//	system("pause");
//	return 0;
//}