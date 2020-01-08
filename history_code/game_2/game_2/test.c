#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void Menu()
{
	printf("***********************************************\n");
	printf("********      1.play      0. exit     *********\n");
	printf("***********************************************\n");
}
int main()
{
	int i = 1;
	while (i)
	{
		Menu();
		printf("请选择：");
		scanf("%d", &i);
		switch (i)
		{
		case 0:printf("退出游戏\n");
			break;
		case 1:Proc();
			printf("开始游戏\n");
			Game();
			break;
		default:printf("选择错误，请重新开始\n");
			break;

		}
	}
	system("pause");
	return 0;
}