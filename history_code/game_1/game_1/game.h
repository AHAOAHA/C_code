#ifndef __GAME_H__
#define __GAME_H__
#define ROW 3
#define COL 3
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<time.h>
void Menu();
void Game();
int Win(char chess[ROW][COL]);
int Go_on(char chess[ROW][COL]);
void Print(char chess[ROW][COL]);
void Proc();
void Init(char chess[ROW][COL], int row, int col);
#endif//game.h