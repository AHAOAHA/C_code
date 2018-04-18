#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void Print(char mine_map[ROWS][COLS])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			printf("%c ", mine_map[i][j]);
		}
		printf("\n");
	}
}
void Init(char mine_map[ROWS][COLS],char mine_map_show[ROWS][COLS])
{
	int num = (ROWS)*(COLS);
	int i = 0;
	int j = 0;
	memset(mine_map, '0',num);
	memset(mine_map_show, '*', num);
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			if (0 == i)
			{
				mine_map[i][j] = 47 + j;
				mine_map_show[i][j] = 47 + j;
			}
			else if (0 == j)
			{
				mine_map[i][j] = 47 + i;
				mine_map_show[i][j] = 47 + i;
			}
		}
	}

}
void Mine(char mine_map[ROWS][COLS])
{
	int row = 0;
	int col = 0;
	int i = 0;
	int row_s = 0;
	int col_s = 0;
	row_s = ROWS;
	col_s = COLS;
	srand((unsigned int)time(NULL));
	for (i = 0; i < MINE_NUM; i++)
	{
		
		do
		{
			row = 0;
			col = 0;
			while (row < 1 || col < 1)
			{
				row = rand() % row_s;			
				col = rand() % col_s;
	
			}		
		} while (mine_map[row][col] != '0');
		mine_map[row][col] = 36;
	}
}
void Clear_Mine(char mine_map[ROWS][COLS], char mine_map_show[ROWS][COLS])
{
	int row = 0;
	int col = 0;
	int i = 0;
	int j = 0;
	int mine_num = 0;
	int open = 0;
	printf("请输入要查看的坐标：");
	flag:
	scanf("%d %d", &row, &col);
	if (row >= 10 || col >= 10)
	{
		printf("非法输入，请重新输入：");
		goto flag;
	}
	mine_num = Mine_num(mine_map, row, col);
	if (36 == mine_map[row + 1][col + 1])
	{
		printf("你踩到地雷了，游戏结束\n");
		for (i = 0; i < ROWS; i++)
		{
			for (j = 0; j < COLS; j++)
			{
				if (mine_map[i][j] == 36)
				{
					mine_map_show[i][j] = 36;
				}
			}
		}
		Print(mine_map_show);
		return;
	}
	else if ('0' == mine_map[row + 1][col + 1])
	{
		for (open = 0; open < rand() % 9; open++)
		{
			for (i = row; i < row + 2; i++)
			{
				for (j = col; j < col + 2; j++)
				{
					if ('0' == mine_map[i][j])
					{
						mine_map_show[i][j] = '0';
					}
				}
			}
		}
		mine_map_show[row + 1][col + 1] = '0'+mine_num;
	}
	
}
int Go_on(char mine_map_show[ROWS][COLS])
{
	int i = 0;
	int j = 0;
	int count = Is_win(mine_map_show);
	for (i = 1; i < ROWS; i++)
	{
		for (j = 1; j < COLS; j++)
		{
			if (mine_map_show[i][j] ==36)
			{
				return 0;
			}
			else if (MINE_NUM==count)
			{
				return 0;
			}
		}
	}
	return 1;
}
int Mine_num(char mine_map[ROWS][COLS],int row,int col)
{
	int i = 0;
	int j = 0;
	int mine_num = 0;
	for (i = row; i <= row + 2; i++)
	{
		for (j = col ; j <= col + 2; j++)
		{
			if (mine_map[i][j] == 36)
			{
				mine_num++;
			}
		}
	}
	return mine_num;
}
int Is_win(char mine_map_show[ROWS][COLS])
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 1; i < ROWS; i++)
	{
		for (j = 1; j < COLS; j++)
		{
			if (mine_map_show[i][j] == '*')
			{
				count++;
			}
		}
	}

	return count;
}
void Game()
{
	int ret = 0;
	char mine_map[ROWS][COLS] = { 0 };
	char mine_map_show[ROWS][COLS] = { 0 };
	Init(mine_map,mine_map_show);
	Mine(mine_map);
	Print(mine_map);
	printf("\n");
	while (Go_on(mine_map_show))
	{
		Print(mine_map_show);
		Clear_Mine(mine_map, mine_map_show);
		if (Is_win(mine_map_show) == MINE_NUM)
		{
			printf("恭喜你排出了所有雷\n");
		}
	}
}