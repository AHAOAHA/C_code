#include"Stack.h"
void StackInit(Stack* s)
{
	assert(s);
	s->_array = (StackDataType*)malloc(MAXSIZE * sizeof(StackDataType));
	s->_capacity = MAXSIZE;
	s->_top = 0;
}
//入栈
void StackPush(Stack* s, StackDataType data)
{
	assert(s);
	*((s->_array) + (s->_top)) = data;
	s->_top++;
}
//出栈
void StackPop(Stack* s)
{
	assert(s);
	s->_top--;
}
//获取栈顶元素
StackDataType StackTop(Stack* s)
{
	assert(s);
	if (StackEmpty(s))
		return *((s->_array) + ((s->_top) - 1));
	else
	{
		printf("栈中没有元素\n");
		exit(1);
	}

}
//有效元素个数
int StackSize(Stack* s)
{
	assert(s);
	return s->_top;
}
//检测栈是否为空
int StackEmpty(Stack* s)
{
	assert(s);
	if (s->_top == 0)
		return 0;
	return 1;
}
//销毁栈
void StackDestroy(Stack* s)
{
	assert(s);
	free(s->_array);
	s->_capacity = 0;
	s->_top = 0;
}

//用栈解决括号匹配问题
//int MatchBrackets(Stack* s, char* str)
//{
//	int i = 0;
//	assert(s);
//	while (*str != '\0')
//	{
//		if (*str == '{' || *str == '[' || *str == '(' || *str == ')' || *str == ']' || *str == '}')
//		{
//			if (*str == '{' || *str == '(' || *str == '[')
//			{
//				StackPush(s, *str);
//				str++;
//			}
//			else
//			{
//				if (0 == StackEmpty(s))
//					return 0;
//				else
//				{
//					if ((*str == 41 && 40 == StackTop(s)) || (*str == 93 && 91 == StackTop(s)) || (*str == 125 && StackTop(s) == 123))
//					{
//						StackPop(s);
//						str++;
//					}
//					else
//						return 0;
//				}
//			}
//		}
//		else
//			str++;
//	}
//	if (0 == StackEmpty(s))
//		return 1;
//	return 0;
//}
////逆波兰表达式（后缀表达式）
//int RPN(Stack* s, char* str)
//{
//	int left = 0;
//	int right = 0;
//	int ret = 0;
//	int num = 0;
//	assert(s);
//	while (*str != '\0')
//	{
//		if (*str == '+' || *str == '-' || *str == '*' || *str == '/')
//		{
//			right = StackTop(s);
//			StackPop(s);
//			left = StackTop(s);
//			StackPop(s);
//			switch (*str)
//			{
//			case '+':
//				ret = left + right;
//				StackPush(s, ret);
//				break;
//			case '-':
//				ret = left - right;
//				StackPush(s, ret);
//				break;
//			case '*':
//				ret = left*right;
//				StackPush(s, ret);
//				break;
//			case '/':
//				ret = left / right;
//				StackPush(s, ret);
//				break;
//			}
//			str++;
//		}
//		else if (*str == ' ')
//			str++;
//		else
//		{
//			StackPush(s, atoi(str));
//			str++;
//		}
//	}
//	return StackTop(s);
//}
///////////////////////////////////////////////////////
//void TestStack()
//{
//	Stack stack;
//	StackInit(&stack);
//	int ret = 0;
//	char arr[23] = "2 3 4 + * 6 - 8 2 / +";
//	printf("%d\n", RPN(&stack, arr));
//}