#include"Stack.h"
int main()
{
	Stack stack;
	StackInit(&stack);
	int ret = 0;
	char arr[23] = "2 3 4 + * 6 - 8 2 / +";
	printf("%d\n",RPN(&stack, arr));
	system("pause");
	return 0;
}