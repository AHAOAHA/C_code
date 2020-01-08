#ifndef __COMMENT_CONVERT__
#define __COMMENT_CONVERT__
#include<stdio.h>
#include<stdlib.h>
enum STATE
{
	NO_STATE,
	C_STATE,
	CPP_STATE,
	END_STATE
};
void CommentConvert(FILE* pfIn, FILE* pfOut);
void CComment(FILE *pfIn, FILE *pfout, enum STATE *ps);
void CppComment(FILE *pfIn, FILE *pfout, enum STATE *ps);
void NoComment(FILE *pfIn, FILE *pfout, enum STATE *ps);
#endif//__COMMENT_CONVERT__
