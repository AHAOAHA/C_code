#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//char *My_strcpy(char* target, const char *source)
//{
//	assert(traget != NULL);
//	assert(source != NULL);
//	while (*target++ = *source++)
//	{
//		;
//	}
//	return target;
//}
//int main()
//{
//	char str1[20] = "abcdef";
//	char str2[20] = "ghif";
//	printf("%s\n", str1);
//	//strcpy(str1, str2);
//	My_strcpy(str1, str2);
//	printf("%s\n", str1);
//	system("pause");
//	return 0;
//}
//
//
//char * My_strcat(char *traget, const char* source)
//{
//	assert(traget != NULL);
//	assert(source != NULL);
//	while (*traget)
//	{
//		traget++;
//	}
//	while (*traget++ = *source++)
//	{
//		;
//	}
//	return traget;
//}
//int main()
//{
//	char str1[20] = "abcdef";
//	char str2[20] = "higk";
//	printf("%s\n", str1);
//	My_strcat(str1, str2);
//	printf("%s\n", str1);
//	system("pause");
//	return 0;
//}
//
//
//char *My_strstr(const char *traget, const char * source)
//{
//	assert(traget != NULL);
//	assert(source != NULL);
//	char *start=traget;
//	char *p1 = traget;
//	char *p = NULL;
//	while (*source != *traget && *traget != '\0')
//	{
//		traget++;
//		p = traget;
//	}
//	
//	while (*source == *traget && *source!='\0')
//	{
//		source++;
//		traget++;
//	}
//	if (*source == '\0')
//	{
//		return p;
//	}
//	return (NULL);
//	
//}
//int main()
//{
//	char str1[20] = "abcdef";
//	char str2[20] = "cOd";
//	printf("%s\n", str1);
//	char *p=My_strstr(str1, str2);
//	printf("%s\n", p);
//	system("pause");
//	return 0;
//}
//
//
//
//
//char*My_strchr(const char *str, const int ch)
//{
//	assert(str != NULL);
//	while (*str != (char)ch && *str != '\0')
//	{
//		str++;
//	}
//	if (*str == '\0')
//		return (NULL);
//	return str;
//}
//int main()
//{
//	char str[20] = "abcdefgh";
//	char str1[20] = "igklmn";
//	char ch = 'R';
//	char *ret = NULL;
//	ret = My_strchr(str, ch);
//	//ret = strchr(str, ch);
//	printf("%s\n", ret);
//	system("pause");
//	return 0;
//}
//
//
//
//int My_strcmp(const char*str1, const char *str2)
//{
//	assert(str1 != NULL);
//	assert(str2 != NULL);
//	while (*str1 == *str2 && (*str1 != '\0' || *str2 != '\0'))
//	{
//		str1++;
//		str2++;
//	}
//	if (*str1 == '\0'&&*str2 == '\0')
//		return 0;
//	else if (*str1 > *str2)
//		return 1;
//	else
//		return -1;
//}
//int main()
//{
//	char str1[20] = "abcdef";
//	char str2[20] = "abcde";
//	int ret = 0;
////	ret = strcmp(str1, str2);
//	ret = My_strcmp(str1, str2);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}
//
//
//
//
//void* My_memcpy(char *traget, const char *source, int sz)
//{
//	assert(traget != NULL);
//	assert(source != NULL);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		*traget = *source;
//		traget++;
//		source++;
//	}
//}
//int main()
//{
//	char str1[20] = "abcdef";
//	char str2[20] = "ghij";
//	printf("%s\n", str1);
//	//memcpy(str1, str2, 25);
//	My_memcpy(str1, str2, 5);
//	printf("%s\n", str1);
//	system("pause");
//	return 0;
//}
//
//
//
//
//
//void* My_memmove(char *traget, const char *source, int sz)
//{
//	assert(traget != NULL);
//	assert(source != NULL);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		*traget = *source;
//		traget++;
//		source++;
//	}
//}
//int main()
//{
//	char str1[20] = "abcdef";
//	char str2[20] = "ghijk";
//	printf("%s\n", str1);
//	//memmove(str1,str2,4);
//	My_memmove(str1, str2, 4);
//	puts(str1);
//	system("pause");
//	return 0;
//}