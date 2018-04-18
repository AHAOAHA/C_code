#include"LinearListD.h"
int main()
{
	LinearListD ListD;
	LinearListDInit(&ListD);
	LinearListPushBack(&ListD, 1);
	LinearListPushBack(&ListD, 2);
	LinearListPushBack(&ListD, 3);
	LinearListPushBack(&ListD, 4);
	LinearListDPopBack(&ListD);
	LinearListDDestroy(&ListD);
	system("pause");
	return 0;
}
