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
	//调整日期
	Date& AdjustDate(Date& d);
	//调整日期(减法)
	Date& AdjustDateSub(Date& d);
	//调整日期(加法)
	Date& AdjustDateAdd(Date& d);
	//当前日期x天之后是什么日期
	Date operator+(int days);
	//当前日期x天前是什么日期
	Date operator-(int days);
	//两个日期之间相差多少天
	Date operator-(const Date& d);
	//比较两个日期大小
	bool operator>(const Date& d);
	bool operator<(const Date& d);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);
	//重载赋值
	Date& operator=(const Date& d);
	//重载取地址符号
	Date* operator&();
	//前置++/--
	Date& operator++();
	Date& operator--();
	//后置++/--
	Date operator++(int);
	Date operator--(int);
	//打印日期
	void PrintDate();
	
private:
	int _year;
	int _month;
	int _day;
};
void TestDate();
