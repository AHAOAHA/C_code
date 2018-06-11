#define _CRT_SECURE_NO_WARNINGS 1
/*
#include<stdlib.h>
#include<stdio.h>
#define _cplusplus 1
#ifndef _cplusplus
extern "C" {
#endif
	void Test(int a)
	{}
	void Test(char b)
	{}
#ifndef _cplusplus
}
#endif
void Swap(int&ra, int& rb)
{
	int tmp = ra;
	ra = rb;
	rb = tmp;
}
int main()
{
	//ÒýÓÃ
	int a = 1;
	int b = 2;
	int& ra = a;
	int& rb = b;
	printf("%d %d\n",a,b);
	Swap(ra, rb);
	printf("%d %d\n", a, b);

	system("pause");
	return 0;
}
*/

/*
#include<stdlib.h>
#include<stdio.h>
namespace N1{
	int a = 1;
	int b = 2;
	void Swap(int& a,int & b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}
};
namespace N2{
	int a = 5;
	int b = 6;
	void Swap(int& a, int& b)
	{
		int tmp = a;
		a = b; 
		b = tmp;
	}
};
#include<windows.h>
int main()
{
	int timestart = GetTickCount();
	int timeend = 0;
	int Count = 10000000000;
	printf("%d %d\n", N1::a, N2::a);
	while (Count--)
	{
		N1::Swap(N1::a, N2::a);
	}
	printf("%d %d\n",N1::a,N2::a);
	timeend = GetTickCount();
	printf("time=%d \n", timeend - timestart);
	system("pause");
	return 0;
}
*/
#if 0
#include<iostream>
#include<stdlib.h>
#include<iomanip>
using namespace std;
int main()
{
	/*
	int a = 0,b,c,d;
	cin >> a >> b >> c;
	cout << "a=" << a << "b=" << b << '\n' << endl;
	//cout << a; 
	system("pause");
	return 0;
	*/
	double a = 123.012345678912345678;
	cout << a << endl;
	cout << setprecision(9) << a << endl;
	system("pause");
	return 0;
}
#endif
#pragma pack(16)
#include<stdlib.h>
/*
class Student
{
public:
	Student(char* name, char* gender, int age)
		:_name("ÕÅê»"),
		_gender("ÄÐ"),
		_age(age)
	{}

private:
	char _name[20];
		char _gender[3];
		int _age;

};
*/
#include<iostream>
using namespace std;


class Date
{
public:
	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
	void PrintDate()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
	char _size;
};


class Time
{
public:
	Time(int hour=17, int minute=30, int second=80)
		:_hour(hour)
		, _minute(minute)
		, _second(second)
		, _ra(_hour)
		, _d1(2018,6,10)
		, _id(_hour/10)
	{}
	void PrintTime()
	{
		_d1.PrintDate();
		cout << _hour << ":" << _minute << ":" << _second << endl;
	}
private:
	const int _id;
	Date _d1;
	int& _ra;
	int _hour;
	int _minute;
	int _second;
};


int main()
{
	Time t1;
	size_t DateSize = 0;
	DateSize = sizeof(Date);
	cout << "DateSize = " << DateSize << endl;
	t1.PrintTime();
	system("pause");
	return 0;
}