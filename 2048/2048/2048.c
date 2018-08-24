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

struct POS
{
	int row;
	int col;
};


void MovePointW(int array[ROW][COL])
{
	struct POS pos;
	struct POS start;

	//�б�����ά���� ��������
	for (start.col = 0; start.col < COL; ++start.col)
	{
		pos.col = start.col;
		pos.row = 0;
		for (start.row = 0; start.row < ROW; ++start.row)
		{
			//�ҳ������0��λ��
			while (0 != array[pos.row][pos.col] && pos.row < ROW)
			{
				++pos.row;
			}
			if (pos.row == ROW)
				continue;

			//��pos���� �����λ�ò���0 �Ͱ�������pos��λ��
			if (0 != array[start.row][start.col] && start.row>pos.row)
			{
				array[pos.row][pos.col] = array[start.row][start.col];
				array[start.row][start.col] = 0;
			}
		}
	}
}
void MovePointS(int array[ROW][COL])
{
	struct POS pos;
	struct POS start;

	//�б�����ά���� ��������
	for (start.col = COL - 1; start.col >= 0; --start.col)
	{
		pos.col = start.col;
		pos.row = ROW - 1;
		for (start.row = ROW - 1; start.row >= 0; --start.row)
		{
			while (0 != array[pos.row][pos.col] && pos.row >= 0)
			{
				--pos.row;
			}
			if (pos.row == -1)
				continue;
			if (0 != array[start.row][start.col] && start.row<pos.row)
			{
				array[pos.row][pos.col] = array[start.row][start.col];
				array[start.row][start.col] = 0;
			}
		}
	}
}
void MovePointA(int array[ROW][COL])
{
	struct POS pos;
	struct POS start;

	//�б�����ά���� ��������
	for (start.row = 0; start.row < ROW; ++start.row)
	{
		pos.row = start.row;
		pos.col = 0;
		for (start.col = 0; start.col < COL; ++start.col)
		{
			//�ҳ������0��λ��
			while (0 != array[pos.row][pos.col] && pos.row < COL)
			{
				++pos.col;
			}
			if (pos.row == COL)
				continue;

			//��pos���� �����λ�ò���0 �Ͱ�������pos��λ��
			if (0 != array[start.row][start.col] && start.col>pos.col)
			{
				array[pos.row][pos.col] = array[start.row][start.col];
				array[start.row][start.col] = 0;
			}
		}
	}
}
void MovePointD(int array[ROW][COL])
{
	struct POS pos;
	struct POS start;

	//�б�����ά���� ��������
	for (start.row = ROW - 1; start.row >= 0; --start.row)
	{
		pos.row = start.row;
		pos.col = COL - 1;
		for (start.col = COL - 1; start.col >= 0; --start.col)
		{
			while (0 != array[pos.row][pos.col] && pos.col >= 0)
			{
				--pos.col;
			}
			if (pos.col == -1)
				continue;
			if (0 != array[start.row][start.col] && start.col<pos.col)
			{
				array[pos.row][pos.col] = array[start.row][start.col];
				array[start.row][start.col] = 0;
			}
		}
	}
}
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