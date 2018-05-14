#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
struct Student
{
	float score[5];
	float avescore, maxscore, minscore;
};
void main()
{
	int i;
	struct Student m;
	printf("input the score of five course:\n");
	for (i = 0; i < 5; i++)    //输入5门课的成绩
		scanf("%f", &m.score[i]);
	m.avescore = 0;
	m.maxscore = m.score[0];
	m.minscore = m.score[0];
	for (i = 0; i < 5; i++)
	{
		m.avescore += m.score[i];
		if (m.score[i] > m.maxscore)
			m.maxscore = m.score[i];
		if (m.score[i] < m.minscore)
			m.minscore = m.score[i];
	}
	m.avescore /= 5;
	printf("avescore = %4.1f, maxscore = %4.1f, minscore = %5.1f\n",m.avescore, m.maxscore, m.minscore);
	system("pause");
	return 0;
}