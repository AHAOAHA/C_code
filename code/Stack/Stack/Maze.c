#include"Maze.h"
//简单迷宫
//初始化迷宫地图数据
void InitMap(Maze* m, int map[MAX_ROW][MAX_COL])
{
	int i = 0;
	int j = 0;
	assert(m);
	for (i = 0; i < MAX_ROW; i++)
	{
		for (j = 0; j < MAX_COL; j++)
		{
			m->_map[i][j] = map[i][j];
		}
	}
}
//打印迷宫
void PrintMap(Maze* m)
{
	int i = 0;
	int j = 0;
	assert(m);
	for (i = 0; i < MAX_ROW; i++)
	{
		for (j = 0; j < MAX_COL; j++)
		{
			printf("%d ", m->_map[i][j]);
		}
		printf("\n");
	}
}
//检测迷宫的入口是否有效
int IsValidEnter(Maze* m, Position enter)
{
	assert(m);
	if (0 == enter._x || 0 == enter._y || 5 == enter._x || 5 == enter._y)
	{
		return 0 == m->_map[enter._x][enter._y];
	}
	return 0;
}
//检测cur位置是否为迷宫的出口
int IsMazeExit(Maze* m, Position cur, Position enter)
{
	assert(m);
	if (cur._x == enter._x && cur._y == enter._y)
	{
		return 0;
	}
	else if (0 == cur._x || 5 == cur._x || 0 == cur._y || 5 == cur._y)
	{
		return 1;
	}
	return 0;
}
/////////////////////////////////////
void TestMaze()
{
	Maze m;
	Position enter;
	Position exit;
	enter._x = 2;
	enter._y = 5;
	exit._x = 4;
	exit._y = 3;
	int map[MAX_ROW][MAX_COL] = { { 0, 0, 0, 0, 0, 0 },
							   { 0, 0, 1, 0, 0, 0 },
							   { 0, 0, 1, 0, 0, 0 },
						       { 0, 0, 1, 1, 1, 0 },
							   { 0, 0, 1, 0, 1, 1 },
							   { 0, 0, 1, 0, 0, 0 } };
	InitMap(&m, map);
	PrintMap(&m);

}