#include"2048.h"
//��ӡ����
void PrintMap(int array[ROW][COL])
{
	int i = 0;
	int j = 0;
	printf("\n");
	for (i = 0; i < ROW; ++i)
	{
		printf("---------------------\n");
		for (j = 0; j < COL; ++j)
		{
			if (0 != array[i][j])
			{
				if (10 > array[i][j])
					printf("|   %d", array[i][j]);
				else if (10 <= array[i][j] && 100>array[i][j])
					printf("|  %d", array[i][j]);
				else if (100 <= array[i][j] && 1000 > array[i][j])
					printf("| %d", array[i][j]);
				else
					printf("|%d", array[i][j]);
			}
			else
				printf("|    ");
		}
		printf("|\n");
	}
	printf("---------------------\n");
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
	case 'w':IsSeedW(array);
		MovePointW(array);
		break;
	case 's':IsSeedS(array);
		MovePointS(array);
		break;
	case 'a':IsSeedA(array);
		MovePointA(array);
		break;
	case 'd':IsSeedD(array);
		MovePointD(array);
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

/*
ʹ������λ�÷ֱ����в���0�ĵ�һλ�͵ڶ�λ
����һλ�͵ڶ�λ��� ����������� ���������һλ��λ�� ���ѱ����� �������Ѱ��
������� �ðѵڶ�λ��λ�ø�����һλ ���Ѱ�ҵڶ�λ�ı�� �������Ѱ�ҵڶ�λ
*/
//�������㺯��W
void CountFuncW(int array[ROW][COL])
{
	int flag_1 = 0;
	int flag = 0;
	struct POS pos;
	struct POS first;
	struct POS second;
	//�б�����λ���� ��������
	for (pos.col = 0; pos.col < COL; ++pos.col)
	{
		flag = 0;
		for (pos.row = 0; pos.row < ROW; ++pos.row)
		{
			if (0 != array[pos.row][pos.col] && 0 == flag)
			{
				first.col = pos.col;
				first.row = pos.row;
				flag = 1;
			}
			else if (0 != array[pos.row][pos.col] && 1 == flag)
			{
				second.row = pos.row;
				second.col = pos.col;
				flag_1 = 1;
			}
			if (1 == flag_1)
			{
				if (array[first.row][first.col] == array[second.row][second.col])
				{
					array[first.row][first.col] *= 2;
					array[second.row][second.col] = 0;
					flag = 0;
					Flag_Seed = 1;
				}

				else
				{
					first.col = second.col;
					first.row = second.row;
				}

				flag_1 = 0;
			}
		}
	}
}
void MovePointW(int array[ROW][COL])
{
	struct POS pos;
	struct POS start;
	//���㺯��
	CountFuncW(array);

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

void CountFuncS(int array[ROW][COL])
{
	int flag_1 = 0;
	int flag = 0;
	struct POS pos;
	struct POS first;
	struct POS second;
	//�б�����λ���� ��������
	for (pos.col = COL - 1; pos.col >= 0; --pos.col)
	{
		flag = 0;
		for (pos.row = ROW - 1; pos.row >= 0; --pos.row)
		{
			if (0 != array[pos.row][pos.col] && 0 == flag)
			{
				first.col = pos.col;
				first.row = pos.row;
				flag = 1;
			}
			else if (0 != array[pos.row][pos.col] && 1 == flag)
			{
				second.row = pos.row;
				second.col = pos.col;
				flag_1 = 1;
			}
			if (1 == flag_1)
			{
				if (array[first.row][first.col] == array[second.row][second.col])
				{
					array[first.row][first.col] *= 2;
					array[second.row][second.col] = 0;
					flag = 0;
					Flag_Seed = 1;
				}

				else
				{
					first.col = second.col;
					first.row = second.row;
				}

				flag_1 = 0;
			}
		}
	}
}
void MovePointS(int array[ROW][COL])
{
	struct POS pos;
	struct POS start;

	CountFuncS(array);
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

void CountFuncA(int array[ROW][COL])
{
	int flag_1 = 0;
	int flag = 0;
	struct POS pos;
	struct POS first;
	struct POS second;
	//�б�����λ���� ��������
	for (pos.row = 0; pos.row < ROW; ++pos.row)
	{
		flag = 0;
		for (pos.col = 0; pos.col < COL; ++pos.col)
		{
			if (0 != array[pos.row][pos.col] && 0 == flag)
			{
				first.col = pos.col;
				first.row = pos.row;
				flag = 1;
			}
			else if (0 != array[pos.row][pos.col] && 1 == flag)
			{
				second.row = pos.row;
				second.col = pos.col;
				flag_1 = 1;
			}
			if (1 == flag_1)
			{
				if (array[first.row][first.col] == array[second.row][second.col])
				{
					array[first.row][first.col] *= 2;
					array[second.row][second.col] = 0;
					flag = 0;
					Flag_Seed = 1;
				}

				else
				{
					first.col = second.col;
					first.row = second.row;
				}

				flag_1 = 0;
			}
		}
	}
}
void MovePointA(int array[ROW][COL])
{
	struct POS pos;
	struct POS start;

	CountFuncA(array);
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

void CountFuncD(int array[ROW][COL])
{
	int flag_1 = 0;
	int flag = 0;
	struct POS pos;
	struct POS first;
	struct POS second;
	//�б�����λ���� ��������
	for (pos.row = ROW - 1; pos.row >= 0; --pos.row)
	{
		flag = 0;
		for (pos.col = COL - 1; pos.col >= 0; --pos.col)
		{
			if (0 != array[pos.row][pos.col] && 0 == flag)
			{
				first.col = pos.col;
				first.row = pos.row;
				flag = 1;
			}
			else if (0 != array[pos.row][pos.col] && 1 == flag)
			{
				second.row = pos.row;
				second.col = pos.col;
				flag_1 = 1;
			}
			if (1 == flag_1)
			{
				if (array[first.row][first.col] == array[second.row][second.col])
				{
					array[first.row][first.col] *= 2;
					array[second.row][second.col] = 0;
					flag = 0;
					Flag_Seed = 1;
				}

				else
				{
					first.col = second.col;
					first.row = second.row;
				}

				flag_1 = 0;
			}
		}
	}
}
void MovePointD(int array[ROW][COL])
{
	struct POS pos;
	struct POS start;

	CountFuncD(array);
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

//�ж��Ƿ���Ҫ��������
int Flag_Seed = 1;//����ȫ�ֱ�����Ϊ�Ƿ��������ӵı��
void IsSeedW(int array[ROW][COL])
{
	int flag_first_0 = 0;//����Ƿ��ҵ���һ��0
	struct POS start;

	//�б�����ά���� ��������
	for (start.col = 0; start.col < COL; ++start.col)
	{
		flag_first_0 = 0;//�����һ�еĶԱ�ʱ ��flag_first_0��Ϊ0
		for (start.row = 0; start.row < ROW; ++start.row)
		{
			if (0 == array[start.row][start.col] && 0 == flag_first_0)
			{
				flag_first_0 = 1;//��ʾ�ҵ���һ��0
			}
			else if (0 != array[start.row][start.col] && 1 == flag_first_0)
			{
				Flag_Seed = 1;
				return;
			}
		}
	}
}
void IsSeedS(int array[ROW][COL])
{
	int flag_first_0 = 0;//����Ƿ��ҵ���һ��0
	struct POS start;

	//�б�����ά���� ��������
	for (start.col = COL - 1; start.col >= 0; --start.col)
	{
		flag_first_0 = 0;//�����һ�еĶԱ�ʱ ��flag_first_0��Ϊ0
		for (start.row = ROW - 1; start.row >= 0; --start.row)
		{
			if (0 == array[start.row][start.col] && 0 == flag_first_0)
			{
				flag_first_0 = 1;//��ʾ�ҵ���һ��0
			}
			else if (0 != array[start.row][start.col] && 1 == flag_first_0)
			{
				Flag_Seed = 1;
				return;
			}
		}
	}
}
void IsSeedA(int array[ROW][COL])
{
	int flag_first_0 = 0;//����Ƿ��ҵ���һ��0
	struct POS start;

	//�б�����ά���� ��������
	for (start.row = 0; start.row < ROW; ++start.row)
	{
		flag_first_0 = 0;//�����һ�еĶԱ�ʱ ��flag_first_0��Ϊ0
		for (start.col = 0; start.col < COL; ++start.col)
		{
			if (0 == array[start.row][start.col] && 0 == flag_first_0)
			{
				flag_first_0 = 1;//��ʾ�ҵ���һ��0
			}
			else if (0 != array[start.row][start.col] && 1 == flag_first_0)
			{
				Flag_Seed = 1;
				return;
			}
		}
	}
}
void IsSeedD(int array[ROW][COL])
{
	int flag_first_0 = 0;//����Ƿ��ҵ���һ��0
	struct POS start;

	//�б�����ά���� ��������
	for (start.row = ROW - 1; start.row >= 0; --start.row)
	{
		flag_first_0 = 0;//�����һ�еĶԱ�ʱ ��flag_first_0��Ϊ0
		for (start.col = COL - 1; start.col >= 0; --start.col)
		{
			if (0 == array[start.row][start.col] && 0 == flag_first_0)
			{
				flag_first_0 = 1;//��ʾ�ҵ���һ��0
			}
			else if (0 != array[start.row][start.col] && 1 == flag_first_0)
			{
				Flag_Seed = 1;
				return;
			}
		}
	}
}
//////////////////////////��Ϸ���庯��
int Game(int array[ROW][COL])
{
	printf("��Ϸ��ʼ��");
	while (!IsDown(array))
	{
		if (1 == Flag_Seed)
		{
			Seed(array);
			Flag_Seed = 0;
		}
		PrintMap(array);
		MoveMap(array);
	}
	return 0;
}