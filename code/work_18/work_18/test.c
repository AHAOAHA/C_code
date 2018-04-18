#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Rid(int x, int y)
//{
//	return x*y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//int main(int argc, char *argv[], char *envp[])
//{ 
//	int num = 0;
//	if (argc > 4)
//	{
//		printf("≤Œ ˝¥ÌŒÛ\n");
//		exit(1);
//	}
//	switch (*(argv[1] + 1))
//	{
//	case 'a':num = Add(atoi(argv[2]), atoi(argv[3]));
//		break;
//	case 'b':num = Sub(atoi(argv[2]), atoi(argv[3]));
//		break;
//	case 'c':num = Rid(atoi(argv[2]), atoi(argv[3]));
//		break;
//	case 'd':num = Div(atoi(argv[2]), atoi(argv[3]));
//		break;
//	default:printf(" ‰»Î¥ÌŒÛ\n");
//		break;
//	}
//	printf("%d\n", num);
//	system("pause");
//	return 0;
//}



#include<string.h>
Sort_str(char *str[], int sz)
{
	int i = 0;
	int j = 0;
	char *tmp = NULL;
	for (j = 0; j < sz; j++)
	{
		for (i = j; i < sz-j-1; i++)
		{
			if (0 == strcmp(str[i], str[i + 1]))
				;
			else if (1 == strcmp(str[i], str[i + 1]))
			{
				tmp = str[i];
				str[i] = str[i + 1];
				str[i + 1] = tmp;
			}
			else
				;
		}
	}
}
int main()
{
	int sz = 0;
	char *str[] = { "cdcjvsdv", "aasvdsdv", "efwef", "dscs" };
	sz = sizeof(str) / sizeof(str[0]);
	Sort_str(str, sz);
	puts(str[0]);
	puts(str[1]);
	puts(str[2]);
	puts(str[3]);
	system("pause");
	return 0;
}