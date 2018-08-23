#include"2048.h"
//��ӡ����
void PrintMap(int array[ROW][COL])
{
	int i = 0;
	int j = 0;
	printf("\n");
	for (i = 0; i < ROW; ++i)
	{
		printf("-----------------\n");
		for (j = 0; j < COL; ++j)
		{
			if (0 != array[i][j])
				printf("| %d ", array[i][j]);
			else
				printf("|   ");
		}
		printf("|\n");
	}
	printf("-----------------\n");
}

//�ж��Ƿ�ʧ�� ����0��ʾδʧ�� ����1��ʾʧ��
int IsDown(int array[ROW][COL])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; ++i)
	{
		for (j = 0; j < COL; ++j)
		{
			if (0 == array[i][j])
			{
				return 0;
			}
		}
	}
	return 1;
}

//����
void Seed(int array[ROW][COL])
{
	int row = 0;
	int col = 0;
	int flag = 0;
	if (IsDown(array))
	{
		printf("�����ˣ�\n");
		return;
	}
	srand((unsigned)time(NULL));//�ó�������ʱ����Ϊ�������������
	do
	{
		flag = 0;
		row = rand() % ROW;
		col = rand() % COL;
		if (0 == array[row][col])
		{
			array[row][col] = 2;
		}
		else if (2 == array[row][col])
		{
			flag = 1;
		}
	} while (!(2 == array[row][col] && 0 == flag));
}

//�ƶ���ͼ
void MoveMap(int array[ROW][COL])
{
	char point = '0';
	if (IsDown(array))
	{
		printf("�����ˣ�\n");
		return;
	}
	printf("������Ҫ�ƶ��ķ���");
	point = _getch();
	switch(point)
	{
	case 'w':MovePointW(array);
		break;
	case 's':MovePointS(array);
		break;
	case 'a':MovePointA(array);
		break;
	case 'd':MovePointD(array);
		break;
	default:printf("�Ƿ����룡\n");
		break;
	}
}

void MovePointW(int array[ROW][COL])
{}
void MovePointS(int array[ROW][COL])
{}
void MovePointA(int array[ROW][COL])
{}
void MovePointD(int array[ROW][COL])
{}
//////////////////////////��Ϸ���庯��
int Game(int array[ROW][COL])
{
	while (!IsDown(array))
	{
		Seed(array);
		PrintMap(array);
		MoveMap(array);
	}
	return 0;
}