#include"Stack.h"
#define MAX_ROW 6
#define MAX_COL 6
typedef struct Maze
{
	int _map[MAX_ROW][MAX_COL];
}Maze;
//typedef struct Position
//{
//	int _x;
//	int _y;
//}Position;
void InitMap(Maze* m, int map[MAX_ROW][MAX_COL]);
void PrintMap(Maze* m);
int IsValidEnter(Maze* m, Position enter);
int IsMazeExit(Maze* m, Position cur, Position enter);
int IsPass(Maze* m, Position cur);
void PassMazeNor(Maze* m, Position enter, Stack* s);
void PrintPath(Stack* s);
void PassMaze(Maze* m, Position enter, Stack* s);
void _PassMaze(Maze* m, Position enter);
void TestMaze();

