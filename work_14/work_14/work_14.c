#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void Left_Rotate(char arr[], int k, int sz)
{
	int i = 0;
	char *p = NULL;
	p = arr + sz - k;
	printf("%s", p);
}
int main()
{
	char arr[] = "abcdef";
	int k = 0;
	int sz = 0;
	printf("%s\n", arr);
	printf("请输入要旋转的字符数：");
	scanf("%d", &k);
	sz = strlen(arr);
	Left_Rotate(arr, k, sz);
	arr[sz - k] = arr[sz];
	printf("%s\n", arr);
	system("pause");
	return 0;
}
//void Copy(char arr[20], int sz)
//{
//	char *p = NULL;
//	char *p1 = NULL;
//	int count = 0;
//	p = arr;
//	p1 = arr + sz;
//	while (count < sz)
//	{
//		*p1 = *p;
//		p1++;
//		p++;
//		count++;
//	}
//	p1 = '\0';
//}
//int Check(char arr[20], char arr_s[20], int sz)
//{
//	char *p = NULL;
//	char *p_s = NULL;
//	int i = 0;
//	p = arr;
//	p_s = arr_s;
//	while (*p_s != *p)
//	{
//		p++;
//	}
//	for (i = 0; i < sz; i++)
//	{
//		if (*p_s == *p)
//		{
//			p_s++;
//			p++;
//		}
//		else
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//int main()
//{
//	char arr[20] = "abcdef";
//	char arr_s[20] = "efabed";
//	int sz = 0;
//	int ret = 0;
//	sz = strlen(arr);
//	Copy(arr, sz);
//	ret = Check(arr, arr_s, sz);
//	if (ret == 0)
//	{
//		printf("no\n");
//	}
//	else if (ret == 1)
//	{
//		printf("yes\n");
//	}
//	system("pause");
//	return 0;
//}