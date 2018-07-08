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
	//引用
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
		:_name("张昊"),
		_gender("男"),
		_age(age)
	{}

private:
	char _name[20];
		char _gender[3];
		int _age;

};
*/
/*
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
		cout << _hour << ":" << _minute << " :" << _second << endl;
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
*/

#if 0


class Date
{
	//friend ostream operator<<(ostream cout,const Date d);
public:
	Date(int year = 2018, int month = 6, int day = 11)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
//private:
	int _year;
	int _month;
	int _day;
};
//ostream operator<<(ostream cout, const Date& d)
//{
//	//cout << d._year << '/' << d._month << '/' << d._day;
//	//return cout;
//}
/*
#include<iostream>
using namespace std;


int main()
{ 
	Date d;
	//cout << d << endl;
	return 0;
}
*/
#endif


//class A
//{
//	void Swap();
//};
//void A::Swap()
//{
//
//}
//int main()
//{
//	return 0;
//}
//
//class Date
//{
//public:
//	void Test()
//	{
//		_year = 2018;
//		_month = 7;
//		_day = 21;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	int size = sizeof(Date);
//	return 0;
//}
/*
class Date
{
public:
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1;
	Date d2;
	Date d3;
	d1.SetDate(2018, 7, 21);
	d2.SetDate(2018, 8, 21);
	d3.SetDate(2018, 9, 21);
	return 0;
}
*/


/*
class Student
{

public:
	Student(int age = 0)
		:_age(age)
	{
		_count++;
	}
	static int _count;
	int _age;
};
int Student::_count = 0;
int main()
{
	Student s1;
	Student s2;
	Student s3;
	return 0;
}
*/
/*
class A
{
public:
	static int _count;
};
int main()
{
	//A a1;
	sizeof(A);//计算A类所占内存的大小
	A::_count;
	A a1;
	a1._count;
	return 0;
}
*/



//#include<iostream>
//using namespace std;
//class Base
//{
//public:
//	void TestFunc1()
//	{
//		cout << "Base::TestFunc1()" << endl;
//	}
//	int _b;
//};
//class Derive1 :public Base
//{
//public:
//	void TestFunc2()
//	{
//		cout << "Derive::TestFunc2()" << endl;
//	}
//	int _d1;
//};
//int main()
//{
//	Derive1 d;
//	cout << sizeof(d) << endl;
//	d._b = 1;
//	d._d1 = 2;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class Base//定义一个基类
//{
//public:
//	~Base()//显式定义出基类的析构函数
//	{
//		cout << "Base::~Base()" << endl;//在基类的析构函数内部让它打印出自己的函数名
//	}
//	int _b;//基类的数据成员
//};
//class Derive :public Base//定义一个派生类，公有继承自基类
//{
//public:
//	~Derive()//显示定义出派生类的析构函数，在该行下一个断点
//	{
//		cout << "Derive::~Derive()" << endl;//在析构函数内部让它打印自己的函数名
//	}
//	int _d;//派生类自己的数据成员
//};
//int main()
//{
//	Derive d;//创建一个派生类
//	return 0;
//}

//
//#include<iostream>
//using namespace std;
//class Base//定义一个基类
//{
//public:
//	void Test()//在基类中定义一个名为Test的函数
//	{
//		cout << "Base::Test()" << endl;//在函数内部打印该函数的作用域及名称
//	}
//};
//class Derive :public Base//定义一个公有继承自基类Base的派生类Derive
//{
//public:
//	void Test()//在派生类里也同样定义一个名为Test的函数
//	{
//		cout << "Derive::Test()" << endl;//在函数内部打印该函数的作用域及名称
//	}
//};
//int main()
//{
//	Derive d;//创建派生类的对象
//	d.Test();//测试默认请情况下通过派生类对象访问同名函数会访问哪个作用域中的函数
//	d.Derive::Test();//添加派生类作用域访问
//	d.Base::Test();//添加基类作用域访问
//	return 0;
//}


//
//#include<iostream>
//using namespace std;
//class Base//定义一个基类
//{
//public:
//	void BaseTest()//在基类中定义一个普通函数
//	{
//		cout << "Base::BaseTest()" << endl;//让该函数打印它所在的作用域及函数名
//	}
//	int _base;//定义一个属于基类的数据变量
//};
//class Derive1 :public Base//定义一个公有继承自基类Base的派生类
//{
//public:
//	void Derive1Test()//定义一个派生类自己的普通函数
//	{
//		cout << "Derive1::Derive1Test()" << endl;//让该函数打印它所在的作用域及函数名
//	}
//	int _derive1;//定义一个属于派生类自己的数据变量
//};
//class Derive2 :public Derive1//定义一个公有继承自派生类Derive1的派生类
//{
//public:
//	void Derive2Test()//定义一个派生类自己的普通函数
//	{
//		cout << "Derive2::Derive2Test()" << endl;//让该函数打印它所在的作用域及函数名
//	}
//	int _derive2;//定义一个属于派生类自己的数据变量
//};
//int main()
//{
//	Derive1 d1;//创建Derive1派生类的对象
//	cout << sizeof(d1) << endl;//查看Derive1派生类对象的大小
//	d1._base = 1;
//	d1._derive1 = 2;
//	Derive2 d2;//创建Derive2派生类的对象
//	cout << sizeof(d2) << endl;//查看Derive2派生类对象的大小
//	d2._base = 3;
//	d2._derive1 = 4;
//	d2._derive2 = 5;
//	return 0;
//}


//#include<iostream>
//using namespace std;
////首先定义两个基类
//class Base1//第一个基类
//{
//public:
//	void Base1Test()//在第一个基类中定义一个函数
//	{
//		cout << "Base1::Base1Test()" << endl;//让这个函数打印自己的作用域和函数名
//	}
//	int _base1;//定义一个属于第一个基类的数据变量
//};
//class Base2//第二个基类
//{
//public:
//	void Base2Test()//在第二个基类中定义一个函数
//	{
//		cout << "Base2::Base2Test()" << endl;//让这个函数打印自己的作用域和函数名
//	}
//	int _base2;//定义一个属于第二个基类的数据变量
//};
//class Derive :public Base1, public Base2//让派生类公有继承自基类1和基类2
//{
//public:
//	void DeriveTest()//定义一个派生类自己的函数
//	{
//		cout << "Derive::DeriveTest()" << endl; //让这个函数打印自己的作用域和函数名
//	}
//	int _derive;//定义一个派生类自己的数据变量
//};
//int main()
//{
//	Derive d;//创建派生类对象
//	cout << sizeof(d) << endl;//打印出派生类所占字节大小
//	d._base1 = 1;//通过派生类修改基类1的数据成员的值
//	d._base2 = 2;//通过派生类修改基类2的数据成员的值
//	d._derive = 3;//通过派生类修改派生类的数据成员的值
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class Base//定义一个基类
//{
//public:
//	void BaseTest()//定义一个函数
//	{
//		cout << "Base::BaseTest()" << endl;//让函数打印自己的作用域及函数名
//	}
//	int _base;//定义一个基类的数据成员
//};
//class C1 :public Base//定义一个派生类C1公有继承自Base类
//{
//public:
//	void C1Test()//定义一个函数
//	{
//		cout << "C1::C1Test()" << endl;//让函数打印自己的作用域及函数名
//	}
//	int _c1;//定义一个属于C1类的数据成员
//};
//class C2 :public Base//定义一个派生类C2公有继承自Base类
//{
//public:
//	void C2Test()//定义一个函数
//	{
//		cout << "C2::C2Test()" << endl;//让函数打印自己的作用域及函数名
//	}
//	int _c2;//定义一个属于C2类的数据成员
//};
//class Derive :public C1, public C2//定义一个派生类Derive公有多继承自C1类和C2类
//{
//public:
//	void DeriveTest()//定义一个函数
//	{
//		cout << "Derive::DeriveTest()" << endl;//让函数打印自己的作用域及函数名
//	}
//	int _derive;//定义一个属于派生类Derive的数据成员
//};
//int main()
//{
//	Derive d;//创建派生类d的对象
//	cout << sizeof(d) << endl;//打印派生类对象d所占字节大小
//	d.C1::_base = 1;//通过派生类对象改变Base类的数据成员
//	d._c1 = 2;//通过派生类对象改变C1类的数据成员
//	d._c2 = 3;//通过派生类对象改变C2类的数据成员
//	d._derive = 4;//通过派生类对象改变Derive类的数据成员
//	return 0;
//}




#include<iostream>
using namespace std;
class Base//定义一个基类
{
public:
	void BaseTest()//在基类中定义一个函数
	{
		cout << "Base::BaseTest()" << endl;//让这个函数打印自己的作用域及函数名
	}
	int _base;//在基类中定义一个数据成员
};
class C1 :virtual public Base//定义一个类让他公有虚拟继承自Base类
{
public:
	void C1Test()//在类中定义一个函数
	{
		cout << "C1::C1Test()" << endl;//让这个函数打印自己的作用域及函数名
	}
	int _c1;//在类中定义一个数据成员
};
class Derive :virtual public C1//定义一个类Derive让它公有虚拟继承自C1类
{
public:
	void DeriveTest()//在类中定义一个函数
	{
		cout << "DeriveTest()" << endl;////让这个函数打印自己的作用域及函数名
	}
	int _derive;//在类中定义一个数据成员
};


int main()
{
	Derive d;//创建派生类对象
	cout << sizeof(d) << endl;//打印派生类的大小
	d._base = 1;//通过派生类对象改变继承自Base的数据成员
	d._c1 = 2;//通过派生类对象该变继承自C1类的数据成员
	d._derive = 3;//通过派生类对象改编它自己的数据成员
	return 0;
}






//class C1 :virtual public Base
//{
//public:
//	void C1::C1Test()
//	{
//		cout << "C1::C1Test()" << endl;
//	}
//	int _c1;
//};
//class C2 :virtual public Base
//{
//public:
//	void C2::C2Test()
//	{
//		cout << "C2::C2Test()" << endl;
//	}
//	int _c2;
//};