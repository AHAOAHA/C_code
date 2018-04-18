#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Stu
{
	char name[20];
	int age;
	char sex;
};
int main()
{
	struct Stu s1;
	s1.age = 19;
	/*strcpy(s1.name, "haoge");
	printf("%s\n", s1.name);
	printf("%d\n", s1.age);*/
	scanf("%c", &s1.sex);
	printf("%c", s1.sex);
	system("pause");
	return 0;
}
