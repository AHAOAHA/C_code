#define _CRT_SECURE_NO_WARNINGS 1
#include"CommentConvert.h"
void CommentConvert(FILE* pfIn, FILE* pfOut)
{
	enum STATE state = NO_STATE;//默认为正常模式
	while (state != EOF)
	{
		switch (state)
		{
		case NO_STATE:NoComment(pfIn, pfOut, &state);
			break;
		case CPP_STATE:CppComment(pfIn, pfOut, &state);
			break;
		case C_STATE:CComment(pfIn, pfOut, &state);
			break;
		default:NoComment(pfIn, pfOut, &state);
			break;
		}
	}
}
void NoComment(FILE *pfIn, FILE *pfOut, enum STATE *ps)
{
	int first = fgetc(pfIn);
	if (first != EOF)
	{
		while (first != '/' && first != EOF)
		{
			fputc(first, pfOut);
			first = fgetc(pfIn);
		}
		if (first != EOF)
		{
			int second = fgetc(pfIn);
			if (second != EOF)
			{
				switch (second)
				{
				case '/':fputc(first, pfOut);
					fputc(second, pfOut);
					*ps = CPP_STATE;
					break;
				case '*':fputc(first, pfOut);
					fputc(first, pfOut);
					*ps = C_STATE;
					break;
				default:fputc(first, pfOut);
					fputc('/', pfOut);
					*ps = NO_STATE;
					break;
				}
			}
		}
		else
		{
			*ps = EOF;
		}
	}
	else
	{
		*ps = EOF;
	}
}
void CComment(FILE *pfIn, FILE *pfOut, enum STATE *ps)
{
	int second = 0;
	int first = 0;
flag:
	if (second != '*')
	{
		first = fgetc(pfIn);
	}
	else
	{
		first = second;
	}
	if (first != EOF)
	{
		while (first != '*')
		{
			if (first != '\n')
			{
				fputc(first, pfOut);
			}
			else
			{
				fputc(first, pfOut);
				fputc('/', pfOut);
				fputc('/', pfOut);
			}
			first = fgetc(pfIn);
			
		}
		second = fgetc(pfIn);
		if (second != EOF)
		{
			switch (second)
			{
			case '/':
				*ps = NO_STATE;
				break;
			default:
				fputc(second, pfOut);
				goto flag;
				break;
			}
		}
		else
		{
			*ps = EOF;
		}
	}
	else
	{
		*ps = EOF;
	}
}
void CppComment(FILE *pfIn, FILE *pfOut, enum STATE *ps)
{
	int first = 0;
	first = fgetc(pfIn);
	if (first != EOF)
	{
		while (first != '\n' && first != EOF)
		{
			fputc(first, pfOut);
			first = fgetc(pfIn);
		}
		if (first == '\n')
		{
			fputc(first, pfOut);
			*ps = NO_STATE;
		}
		else if (first == EOF)
		{
			*ps = EOF;
		}
	}
}