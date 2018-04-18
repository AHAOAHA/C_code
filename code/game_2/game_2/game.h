#ifndef __GAME_H__
#define __GAME_H_
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define MINE_NUM 20
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
void Menu();
void Game();
void Mine(char mine_map[ROWS][COLS]);
void Print(char mine_map[ROWS][COLS]);
void Init(char mine_map[ROWS][COLS],char mine_map_show[ROWS][COLS]);
void Clear_Mine(char mine_map[ROWS][COLS], char mine_map_show[ROWS][COLS]);
int Go_on(char mine_map_show[ROWS][COLS]);
int Mine_num(char mine_map[ROWS][COLS], int row, int col);
int Is_win(char mine_map_show[ROWS][COLS]);
#endif//game.h
