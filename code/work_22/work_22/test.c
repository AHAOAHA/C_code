//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<assert.h>
//char *My_strncpy(char *target, const char* source, int size)
//{
//	char *p = target;
//	assert(target);
//	assert(source);
//	while (size--)
//	{
//		*target = *source;
//		target++;
//		source++;
//	}
//	return p;
//	
//}
//int main()
//{
//	char str1[20] = "abcdef";
//	char str2[20] = "ghijk";
//	puts(str1);
//	My_strncpy(str1, str2, 2);
//	//strncpy(str1,str2,2);
//	puts(str1);
//	system("pause");
//	return 0;
//}
//
//
//
//
//char *My_strncat(char *target, const char *source, int size)
//{
//	char *p = target;
//	assert(target);
//	assert(source);
//	while (*target)
//	{
//		target++;
//	}
//	while (size--)
//	{
//		*target = *source;
//		target++;
//		source++;
//	}
//	return p;
//}
//int main()
//{
//	char str1[20] = "abcdef";
//	char str2[20] = "ghijk";
//	puts(str1);
//	My_strncat(str1, str2, 3);
//	//strncat(str1, str2, 3);
//	puts(str1);
//	system("pause");
//	return 0;
//}
//
//
//int My_strncmp(const char*str1, const char * str2, int size)
//{
//	assert(str1);
//	assert(str2);
//	while (size--)
//	{
//		if (*str1 == *str2)
//		{
//			str1++;
//			str2++;
//		}
//		else
//			break;
//	}
//	if (size == -1)
//		return 0;
//	return -1;
//}
//int main()
//{
//	char str1[20] = "abdcef";
//	char str2[20] = "abcdcef";
//	int ret = 0;
//	puts(str1);
//	ret = My_strncmp(str1, str2, 6);
//	//ret=strncmp(str1, str2, 6);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}