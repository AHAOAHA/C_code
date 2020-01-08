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
		return;
	}
	//m->_map[enter._x][enter._y] = 2;
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
void PassMaze(Maze* m, Position enter)
{
	assert(m);
	_PassMaze(m, enter, enter);
}
int _PassMaze(Maze* m, Position enter/*��ڲ���*/,Position cur)
{
	Position next;
	assert(m);
	if (IsPass(m, cur))//�жϵ�ǰλ���ǲ�������ͨ
	{
		m->_map[cur._x][cur._y] = 2;//����ͨ���ѵ�ǰλ�ñ��Ϊ2
		if (IsMazeExit(m, cur, enter))//�жϵ�ǰλ���ǲ��ǳ���
			return 1;

		//��
		next._x = cur._x - 1;
		next._y = cur._y;
		if (_PassMaze(m, enter, next))
			return 1;//������ϵ�λ�ÿ�����ͨ���ͷ���1
		//��
		next._x = cur._x;
		next._y = cur._y - 1;
		if (_PassMaze(m, enter, next))
			return 1;//������ϵ�λ�ÿ�����ͨ���ͷ���1
		//��
		next._x = cur._x;
		next._y = cur._y + 1;
		if (_PassMaze(m, enter, next))
			return 1;//������ϵ�λ�ÿ�����ͨ���ͷ���1
		//��
		next._x = cur._x + 1;
		next._y = cur._y;
		if (_PassMaze(m, enter, next))
			return 1;//������ϵ�λ�ÿ�����ͨ���ͷ���1

		m->_map[cur._x][cur._y] = 3;//������ĸ����򶼲�����ͨ����˵����ǰλ����һ����·���ͽ���ǰλ�ñ��Ϊ3��Ҳ����0
	}
		return 0;//�����ǰλ�ò�����ͨ������0
}
//�����Թ�
int IsPassComplex(Maze* m, Position cur, Position next, Position enter)//��⵱ǰλ�õ���һ���Ƿ�����ͨ
{
	assert(m);
	if (1 == m->_map[next._x][next._y]||m->_map[next._x][next._y] >= m->_map[cur._x][cur._y])//nextλ�ò�����curλ�õ����־��ǿ�����ͨ
		return 1;
	return 0;

}
void PassComplexMaze(Maze* m, Position enter, Stack* ShortPath)
{
	assert(m);
	if (!IsValidEnter(m, enter))
	{
		printf("�Թ���ڴ���\n");
		return;
	}
	m->_map[enter._x][enter._y] = 2;
	StackPush(ShortPath, enter);
	_PassComplexMaze(m,enter,enter,ShortPath);
}
void _PassComplexMaze(Maze* m, Position enter, Position cur, Stack* ShortPath)//�������Թ��ĺ���
{//��������--------ջ�ռ�ı���
	Position next;
	assert(m);
	if (IsMazeExit(m, cur, enter))//�жϵ�ǰλ���ǲ��ǳ���
		return;
	//��
	next._x = cur._x - 1;
	next._y = cur._y;
	if (IsPassComplex(m, cur, next, enter))
	{
		m->_map[next._x][next._y] = m->_map[cur._x][cur._y] + 1;
		StackPush(ShortPath, next);
		_PassComplexMaze(m, enter,next, ShortPath);
	}
	//��
	next._x = cur._x;
	next._y = cur._y - 1;
	if (IsPassComplex(m, cur, next, enter))
	{
		m->_map[next._x][next._y] = m->_map[cur._x][cur._y] + 1;
		StackPush(ShortPath, next);
		_PassComplexMaze(m, enter, next, ShortPath);
	}
	//��
	next._x = cur._x;
	next._y = cur._y + 1;
	if (IsPassComplex(m, cur, next, enter))
	{
		m->_map[next._x][next._y] = m->_map[cur._x][cur._y] + 1;
		StackPush(ShortPath, next);
		_PassComplexMaze(m, enter, next, ShortPath);
	}
	//��
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