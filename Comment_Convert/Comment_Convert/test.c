#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include"CommentConvert.h"
int main()
{
	FILE* pfIn = fopen("CodeIn.txt", "r");
	if (NULL == pfIn)
	{
		perror("open CodeIn.txt for read");
		exit(EXIT_FAILURE);
	}
	FILE* pfOut = fopen("CodeOut.txt", "w");
	{
		if (NULL == pfOut)
		{
			perror("open CodeOut.txt for write");
			pfIn = NULL;
			exit(EXIT_FAILURE);
			
		}
	}
	CommentConvert(pfIn, pfOut);
	printf("文件已经转换完成\n");
	fclose(pfIn);
	fclose(pfOut);
	//exit(EXIT_SUCCESS);
	system("pause");
	return 0;
}
