#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void Init(char chess[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			chess[i][j] = ' ';
		}
	}
}
void Print(char chess[ROW][COL])
{
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			printf(" %c ",chess[i][j]);
			if (j != COL-1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i != ROW - 1)
		{
			for (k = 0; k < COL; k++)
			{
				printf("---");
				if (k != COL - 1)
				{
					printf("|");
				}
			}
		}
		printf("\n");
	}
}
int Go_on(char chess[ROW][COL])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (chess[i][j]==' ')
			{
				return 1;
			}
		}
	}
		return 0;

}
int Win(char chess[ROW][COL])
{
	int i = 0;
	int ret = 0;
	for (i = 0; i < ROW; i++)
	{
		if (chess[i][0] == chess[i][1]
			&& chess[i][1] == chess[i][2]
			&& chess[i][0] != ' ')
		{
			return chess[i][0];
		}
	}
	for (i = 0; i < COL; i++)
	{
		if (chess[0][i] == chess[1][i]
			&& chess[1][i] == chess[2][i]
			&& chess[0][i] != ' ')
		{
			return chess[0][i];
		}
	}
	if (chess[0][0] == chess[1][1]
		&& chess[1][1] == chess[2][2]
		&& chess[0][0] != ' ')
	{
		return chess[0][0];
	}
	if (chess[0][2] == chess[1][1]
		&& chess[1][1] == chess[2][0]
		&& chess[0][2] != ' ')
	{
		return chess[0][2];
	}
	ret=Go_on(chess);
	if (1 == ret)
	{
		;
	}
	else
	{
		return 'q';
	}
}
void Game()
{
	int i = 0;
	int row = 0;
	int col = 0;
	int row_cmp = 0;
	int col_cmp = 0;
	char winer = 0;
	srand((unsigned int)time(NULL));
	char chess[ROW][COL] = { 0 };
	Init(chess, ROW, COL);
	Print(chess);
	while (Go_on(chess))
	{
		printf("玩家走：");
		scanf("%d %d", &row, &col);
		while (chess[row][col] != ' ')
		{
			printf("位置已经被占用，请重新选择：");
			scanf("%d %d", &row, &col);
		}
		chess[row][col] = '0';
		Print(chess);
		winer = Win(chess);
		if (winer == 'X')
		{
			printf("电脑赢\n");
			break;
		}
		else if (winer == '0')
		{
			printf("玩家赢\n");
			break;
		}
		else if (winer == 'q')
		{
			printf("平局\n");
			break;
		}
		printf("电脑走：");
		do
		{
			row_cmp = rand() % ROW;
			col_cmp = rand() % COL;
		} while (chess[row_cmp][col_cmp]!=' ');
		chess[row_cmp][col_cmp] = 'X';
		printf("\n");
		Print(chess);
		winer=Win(chess);
		if (winer == 'X')
		{
			printf("电脑赢\n");
			break;
		}
		else if (winer == '0')
		{
			printf("玩家赢\n");
			break;
		}
		else if (winer == 'q')
		{
			printf("平局\n");
			break;
		}
	}

}