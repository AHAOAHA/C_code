#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
using namespace std;
class Date
{
public:
	Date(int year = 2018, int month = 06, int day = 11)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
	Date(const Date& d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
	{}
	//��������
	Date& AdjustDate(Date& d);
	//��������(����)
	Date& AdjustDateSub(Date& d);
	//��������(�ӷ�)
	Date& AdjustDateAdd(Date& d);
	//��ǰ����x��֮����ʲô����
	Date operator+(int days);
	//��ǰ����x��ǰ��ʲô����
	Date operator-(int days);
	//��ӡ����
	void PrintDate();
	
private:
	int _year;
	int _month;
	int _day;
};
void TestDate();
