#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#define ROW 4//������Ϊ4
#define COL 4//������Ϊ4
void PrintMap(int array[ROW][COL]);//��ӡ����
int Game(int array[ROW][COL]);//��Ϸ���庯��
int IsDown(int array[ROW][COL]);//�ж���Ϸ�Ƿ�ʧ��
void Seed(int array[ROW][COL]);//��������
void MoveMap(int array[ROW][COL]);//�ƶ���ϷԪ��
void MovePointW(int array[ROW][COL]);
void MovePointS(int array[ROW][COL]);
void MovePointA(int array[ROW][COL]);
void MovePointD(int array[ROW][COL]);