#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i = 0;
	int r = 0;
	int j = 0;
	int arr[3][4] = { 0 };
	for (i = 0; i <3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			arr[i][j] = r++;
			printf("%d\n", arr[i][j]);
		}
	}
	system("pause");
	return 0;
}