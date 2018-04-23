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
//ºÚµ•√‘π¨
void InitMap(Maze* m, int map[MAX_ROW][MAX_COL]);
void PrintMap(Maze* m);
int IsValidEnter(Maze* m, Position enter);
int IsMazeExit(Maze* m, Position cur, Position enter);
int IsPass(Maze* m, Position cur);
void PassMazeNor(Maze* m, Position enter, Stack* s);
void PrintPath(Stack* s);
//ºÚµ•√‘π¨µ›πÈ∑®
int _PassMaze(Maze* m, Position enter, Position cur);
void PassMaze(Maze* m, Position cur);
//∏¥‘”√‘π¨
void PassComplexMaze(Maze* m, Position enter, Stack* ShortPath);
void _PassComplexMaze(Maze* m, Position enter, Position cur, Stack* ShortPath);
int IsPassComplex(Maze* m, Position cur, Position next, Position enter);
//≤‚ ‘∫Ø ˝
void TestMaze();

