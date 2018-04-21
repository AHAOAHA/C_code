#include"Maze.h"
//���Թ�
//��ʼ���Թ���ͼ����
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
//��ӡ�Թ�
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
//����Թ�������Ƿ���Ч
int IsValidEnter(Maze* m, Position enter)
{
	assert(m);
	if (0 == enter._x || 0 == enter._y || 5 == enter._x || 5 == enter._y)
	{
		return 1 == m->_map[enter._x][enter._y];
	}
	return 0;
}
//���curλ���Ƿ�Ϊ�Թ��ĳ���
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
//��⵱ǰλ���Ƿ�Ϊͨ·
int IsPass(Maze* m, Position cur)
{
	assert(m);
	return 1 == m->_map[cur._x][cur._y];
}
//���Թ�---ѭ���ŷ�
void PassMazeNor(Maze* m, Position enter, Stack* s)
{
	Position next;
	Position cur;
	cur = enter;
	next = enter;
	assert(m);
	if (0 == IsValidEnter(m, enter))
	{
		return 0;
	}
	m->_map[enter._x][enter._y] = 2;
	StackPush(s, enter);
	
	while (0 == IsMazeExit(m, cur, enter))
	{
		//��
		next._x = cur._x - 1;
		next._y = cur._y;
		if (IsPass(m, next))
		{
			cur = next;
			m->_map[cur._x][cur._y] = 2;
			StackPush(s, cur);
			continue;
		}
		//��
		next._y = cur._y - 1;
		next._x = cur._x;
		if (IsPass(m, next))
		{
			cur = next;
			m->_map[cur._x][cur._y] = 2;
			StackPush(s, cur);
			continue;
		}
		//��
		next._y = cur._y + 1;
		next._x = cur._x;
		if (IsPass(m, next))
		{
			cur = next;
			m->_map[cur._x][cur._y] = 2;
			StackPush(s, cur);
			continue;
		}
		//��
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
//��ӡ·��
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
//���Թ�---�ݹ鷽��
void _PassMaze(Maze* m, Position enter)
{
	assert(m);
}
void PassMaze(Maze* m, Position enter, Stack* s)
{
	Position next;
	Position cur;
	assert(m);
	cur = enter;
	if (0 == IsValidEnter(m, enter))
		return 0;

}
/////////////////////////////////////
void TestMaze()
{
	Maze m;
	Stack s;
	Position enter;
	Position exit;
	enter._x = 5;
	enter._y = 2;
	exit._x = 4;
	exit._y = 3;
	int map[MAX_ROW][MAX_COL] = { { 0, 0, 0, 0, 0, 0 },
							   { 0, 0, 1, 0, 0, 0 },
							   { 0, 0, 1, 0, 0, 0 },
						       { 0, 0, 1, 1, 1, 0 },
							   { 0, 0, 1, 0, 1, 1 },
							   { 0, 0, 1, 0, 0, 0 } };
	InitMap(&m, map);
	StackInit(&s);
	PassMazeNor(&m, enter, &s);
	PrintMap(&m);
	PrintPath(&s);
}