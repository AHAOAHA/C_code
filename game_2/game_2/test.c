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
		printf("��ѡ��");
		scanf("%d", &i);
		switch (i)
		{
		case 0:printf("�˳���Ϸ\n");
			break;
		case 1:Proc();
			printf("��ʼ��Ϸ\n");
			Game();
			break;
		default:printf("ѡ����������¿�ʼ\n");
			break;

		}
	}
	system("pause");
	return 0;
}