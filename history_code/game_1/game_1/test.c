#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void Menu()
{
	printf("*****************************************************\n");
	printf("********         1.play      0. exit         ********\n");
	printf("*****************************************************\n");
	printf("��ѡ��");
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
		case 0:printf("�˳���Ϸ\n");
			system("pause");
			return 0;
			break;
		case 1:Proc();
			printf("��ʼ��Ϸ\n");
			Game();
			break;
		default:printf("�Ƿ�ѡ�������¿�ʼ\n");
			break;
		}

	}

}