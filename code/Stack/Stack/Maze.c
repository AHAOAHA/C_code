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
		return 1 == m->_map[enter._x][enter._y];
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
//检测当前位置是否为通路
int IsPass(Maze* m, Position cur)
{
	assert(m);
	return 1 == m->_map[cur._x][cur._y];
}
//走迷宫---循环放法
void PassMazeNor(Maze* m, Position enter, Stack* s)
{
	Position next;
	Position cur;
	cur = enter;
	next = enter;
	assert(m);
	if (0 == IsValidEnter(m, enter))
	{
		return;
	}
	//m->_map[enter._x][enter._y] = 2;
	StackPush(s, enter);
	
	while (0 == IsMazeExit(m, cur, enter))
	{
		//上
		next._x = cur._x - 1;
		next._y = cur._y;
		if (IsPass(m, next))
		{
			cur = next;
			m->_map[cur._x][cur._y] = 2;
			StackPush(s, cur);
			continue;
		}
		//左
		next._y = cur._y - 1;
		next._x = cur._x;
		if (IsPass(m, next))
		{
			cur = next;
			m->_map[cur._x][cur._y] = 2;
			StackPush(s, cur);
			continue;
		}
		//右
		next._y = cur._y + 1;
		next._x = cur._x;
		if (IsPass(m, next))
		{
			cur = next;
			m->_map[cur._x][cur._y] = 2;
			StackPush(s, cur);
			continue;
		}
		//下
		next._x = cur._x + 1;
		next._y = cur._y;
		if (IsPass(m, next))
		{
			cur = next;
			m->_map[cur._x][cur._y] = 2;
			StackPush(s, cur);
			continue;
		}
		m->_map[cur._x][cur._y] = 3;
		StackPop(s);
		cur = StackTop(s);
	}
}
//打印路径
void PrintPath(Stack* s)
{
	assert(s);
	printf("x = %d ,y = %d", StackTop(s)._x,StackTop(s)._y);
	StackPop(s);
	while (s->_top)
	{
		printf("<---x = %d ,y = %d", StackTop(s)._x, StackTop(s)._y);
		StackPop(s);
	}
	printf("\n");
}
//走迷宫---递归方法
void PassMaze(Maze* m, Position enter)
{
	assert(m);
	_PassMaze(m, enter, enter);
}
int _PassMaze(Maze* m, Position enter/*入口不变*/,Position cur)
{
	Position next;
	assert(m);
	if (IsPass(m, cur))//判断当前位置是不是能走通
	{
		m->_map[cur._x][cur._y] = 2;//能走通，把当前位置标记为2
		if (IsMazeExit(m, cur, enter))//判断当前位置是不是出口
			return 1;

		//上
		next._x = cur._x - 1;
		next._y = cur._y;
		if (_PassMaze(m, enter, next))
			return 1;//如果向上的位置可以走通，就返回1
		//左
		next._x = cur._x;
		next._y = cur._y - 1;
		if (_PassMaze(m, enter, next))
			return 1;//如果向上的位置可以走通，就返回1
		//右
		next._x = cur._x;
		next._y = cur._y + 1;
		if (_PassMaze(m, enter, next))
			return 1;//如果向上的位置可以走通，就返回1
		//下
		next._x = cur._x + 1;
		next._y = cur._y;
		if (_PassMaze(m, enter, next))
			return 1;//如果向上的位置可以走通，就返回1

		m->_map[cur._x][cur._y] = 3;//如果向四个方向都不能走通，就说明当前位置是一个死路，就将当前位置标记为3，也返回0
	}
		return 0;//如果当前位置不能走通，返回0
}
//复杂迷宫
int IsPassComplex(Maze* m, Position cur, Position next, Position enter)//检测当前位置的下一步是否能走通
{
	assert(m);
	if (1 == m->_map[next._x][next._y]||m->_map[next._x][next._y] >= m->_map[cur._x][cur._y])//next位置不超过cur位置的数字就是可以走通
		return 1;
	return 0;

}
void PassComplexMaze(Maze* m, Position enter, Stack* ShortPath)
{
	assert(m);
	if (!IsValidEnter(m, enter))
	{
		printf("迷宫入口错误\n");
		return;
	}
	m->_map[enter._x][enter._y] = 2;
	StackPush(ShortPath, enter);
	_PassComplexMaze(m,enter,enter,ShortPath);
}
void _PassComplexMaze(Maze* m, Position enter, Position cur, Stack* ShortPath)//真正走迷宫的函数
{//遗留问题--------栈空间的保存
	Position next;
	assert(m);
	if (IsMazeExit(m, cur, enter))//判断当前位置是不是出口
		return;
	//上
	next._x = cur._x - 1;
	next._y = cur._y;
	if (IsPassComplex(m, cur, next, enter))
	{
		m->_map[next._x][next._y] = m->_map[cur._x][cur._y] + 1;
		StackPush(ShortPath, next);
		_PassComplexMaze(m, enter,next, ShortPath);
	}
	//左
	next._x = cur._x;
	next._y = cur._y - 1;
	if (IsPassComplex(m, cur, next, enter))
	{
		m->_map[next._x][next._y] = m->_map[cur._x][cur._y] + 1;
		StackPush(ShortPath, next);
		_PassComplexMaze(m, enter, next, ShortPath);
	}
	//右
	next._x = cur._x;
	next._y = cur._y + 1;
	if (IsPassComplex(m, cur, next, enter))
	{
		m->_map[next._x][next._y] = m->_map[cur._x][cur._y] + 1;
		StackPush(ShortPath, next);
		_PassComplexMaze(m, enter, next, ShortPath);
	}
	//下
	next._x = cur._x + 1;
	next._y = cur._y;
	if (IsPassComplex(m, cur, next, enter))
	{
		m->_map[next._x][next._y] = m->_map[cur._x][cur._y] + 1;
		StackPush(ShortPath, next);
		_PassComplexMaze(m, enter, next, ShortPath);
	}
	StackPop(ShortPath);
}
/////////////////////////////////////
void TestMaze()
{
	Maze m;
	Stack ShortPath;
	Position enter;
	//Position exit;
	enter._x = 5;
	enter._y = 1;
	int map_complex[MAX_ROW][MAX_COL] = { { 0, 0, 0, 0, 0, 0 },
									  { 0, 1, 1, 1, 0, 0 },
									  { 0, 1, 0, 1, 0, 0 },
									  { 0, 1, 0, 1, 0, 0 },
									  { 0, 1, 1, 1, 1, 1 },
									  { 0, 1, 0, 0, 0, 0 } };
	InitMap(&m, map_complex);
	StackInit(&ShortPath);
	PassComplexMaze(map_complex, enter, &ShortPath);
	//PrintMap(&m);
	//PassMaze(&m, enter);
	//PassMazeNor(&m, enter, &s);
	//PrintMap(&m);
	//PrintPath(&s);
}