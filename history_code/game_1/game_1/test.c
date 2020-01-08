#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void Menu()
{
	printf("*****************************************************\n");
	printf("********         1.play      0. exit         ********\n");
	printf("*****************************************************\n");
	printf("请选择：");
}
int main()
{
	while (1)
	{
		Menu();
		int i = 0;
		scanf("%d", &i);
		switch (i)
		{
		case 0:printf("退出游戏\n");
			system("pause");
			return 0;
			break;
		case 1:Proc();
			printf("开始游戏\n");
			Game();
			break;
		default:printf("非法选择，请重新开始\n");
			break;
		}

	}

}