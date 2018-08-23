#include"2048.h"
//打印函数
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

//判断是否失败 返回0表示未失败 返回1表示失败
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

//播种
void Seed(int array[ROW][COL])
{
	int row = 0;
	int col = 0;
	int flag = 0;
	if (IsDown(array))
	{
		printf("你输了！\n");
		return;
	}
	srand((unsigned)time(NULL));//用程序运行时间作为生成随机数种子
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

//移动地图
void MoveMap(int array[ROW][COL])
{
	char point = '0';
	if (IsDown(array))
	{
		printf("你输了！\n");
		return;
	}
	printf("请输入要移动的方向：");
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
	default:printf("非法输入！\n");
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
//////////////////////////游戏主体函数
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