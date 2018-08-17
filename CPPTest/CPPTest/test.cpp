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



//
//#include<iostream>
//using namespace std;
//class Base//定义一个基类
//{
//public:
//	void BaseTest()//在基类中定义一个函数
//	{
//		cout << "Base::BaseTest()" << endl;//让这个函数打印自己的作用域及函数名
//	}
//	int _base;//在基类中定义一个数据成员
//};
//class C1 :virtual public Base//定义一个类让他公有虚拟继承自Base类
//{
//public:
//	void C1Test()//在类中定义一个函数
//	{
//		cout << "C1::C1Test()" << endl;//让这个函数打印自己的作用域及函数名
//	}
//	int _c1;//在类中定义一个数据成员
//};
//class Derive :virtual public C1//定义一个类Derive让它公有虚拟继承自C1类
//{
//public:
//	void DeriveTest()//在类中定义一个函数
//	{
//		cout << "DeriveTest()" << endl;////让这个函数打印自己的作用域及函数名
//	}
//	int _derive;//在类中定义一个数据成员
//};
//
//
//int main()
//{
//	Derive d;//创建派生类对象
//	cout << sizeof(d) << endl;//打印派生类的大小
//	d._base = 1;//通过派生类对象改变继承自Base的数据成员
//	d._c1 = 2;//通过派生类对象该变继承自C1类的数据成员
//	d._derive = 3;//通过派生类对象改编它自己的数据成员
//	return 0;
//}






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



//
//#include<iostream>
//using namespace std;
//class Base1//定义Base1类
//{
//public:
//	int _base1;//定义一个数据成员
//};
//class Base2//定义Base2类
//{
//public:
//	int _base2;//定义一个数据成员
//};
////定义Derive类；让Derive类公有虚拟继承自Base1类和Base2类
//class Derive :virtual public Base1, virtual public Base2
//{
//public:
//	int _derive;//定义一个数据成员
//};
//int main()
//{
//	Derive d;//创建Derive类的对象
//	cout << sizeof(d) << endl;//打印Derive类对象的大小
//	d._base1 = 1;//通过派生类对象改变继承自Base1类数据成员的值
//	d._base2 = 2;//通过派生类对象改变继承自Base2类数据成员的值
//	d._derive = 3;//通过派生类对象改变他自己的数据成员
//	return 0;
//}



//#include<iostream>
//using namespace std;
//class Base//定义一个base类
//{
//public:
//	int _base;//定义一个数据成员
//};
//class C1:virtual public Base//定义C1类虚拟继承自Base类
//{
//public:
//	int _c1;//定义一个数据成员
//
//};
//class C2 : virtual public Base//定义C2类虚拟继承自Base类
//{
//public:
//	int _c2;//定义一个数据成员
//};
////定义Derive类公有虚拟多继承自C1类和C2类
//class Derive : virtual public C1, virtual public C2
//{
//public:
//	int _derive;//定义一个数据变量
//};
//int main()
//{
//	Derive d;//创建Derive类对象
//	cout << sizeof(d) << endl;//打印Derive类对象的大小
//	d._base = 1;//通过Derive类对象改变Base类的数据成员
//	d._c1 = 2;//通过Derive类对象改变C1类对象的数据成员
//	d._c2 = 3;//通过Derive类对象改变C2类对象的数据成员
//	d._derive = 4;//通过Derive类对象改变它自己的数据成员
//	return 0;
//}



//#include<iostream>
//using namespace std;
//template<typename T,typename T2>
//T2 Add(T first, T2 second)
//{
//	return (T2)first + second;
//}
//int main()
//{
//	cout << Add(2, 3.1) << endl;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class Base
//{
//public:
//	virtual void BaseTest()
//	{
//		cout << "BaseTest()" << endl;
//	}
//};
//class Derive :public Base
//{
//public:
//	virtual void BaseTest()
//	{
//		cout << "DeriveTest()" << endl;
//	}
//};
//int main()
//{
//	Derive d;
//	Base b;
//	b.BaseTest();
//	d.BaseTest();
//	b.BaseTest();
//	return 0;
//}

/*
#include<iostream>
using namespace std;
class WashRoom//定义一个卫生间的类模型
{
public:
	void GoToManWashRoom()//代表男士卫生间的函数
	{
		cout << "Turn Left" << endl;//打印向左
	}
	void GoToWomanWashRoom()//代表女士卫生间的函数
	{
		cout << "Turn Right" << endl;//代表向右
	}
};
class Person//定义一个基类
{
public:
	virtual void GoToWashRoom(WashRoom& wc) = 0;
};
class Man :public Person
{
public:
	virtual void GoToWashRoom(WashRoom& wc)
	{
		wc.GoToManWashRoom();
	}
};
class Woman :public Person
{
public:
	virtual void GoToWashRoom(WashRoom& wc)
	{
		wc.GoToWomanWashRoom();
	}
};
int main()
{
	WashRoom wc;
	Person* p;
	p = new Man;
	p->GoToWashRoom(wc);
	return 0;
}
*/

/*
#include<iostream>
using namespace std;
class Base
{
public:
	virtual void BaseTest1()
	{
		cout << "BaseTest1()" << endl;
	}
	virtual void BaseTest2()
	{
		cout << "BaseTest2()" << endl;
	}
	int _base;
};
class 
int main()
{
	return 0;
}
*/



////创建一个抽象类
//class Base
//{
//public:
//	virtual void BaseTest() = 0;//纯虚函数
//};
//int main()
//{
//	Base b;//尝试用抽象类实例化对象
//	return 0;
//}



/*
#include<iostream>
using namespace std;

class YouSay//定义称呼的类模型
{
public:
	void IsAMan()//如果是男
	{
		cout << "hi 帅哥" << endl;//打印hi 帅哥
	}
	void IsAWoman()//如果是女
	{
		cout << "hi 美女" << endl;//打印hi 美女
	}
	void IsAChild()//如果是小朋友
	{
		cout << "hi 小朋友" << endl;//打印hi 小朋友
	}
};
class Person//定义用来指向人的抽象类
{
public:
	virtual void YouWillSay(YouSay& y) = 0;//定义称呼的函数
};
class Man :public Person//定义男士类让它公有继承自person类
{
public:
	virtual void YouWillSay(YouSay& y)//重写继承自person类的纯虚函数
	{
		y.IsAMan();//调用遇到男士的称呼函数
	}
};
class Woman :public Person//定义女士类让它公有继承自person类
{
public:
	virtual void YouWillSay(YouSay& y)//重写继承自person类的纯虚函数
	{
		y.IsAWoman();//调用遇到女士的称呼函数
	}
};
class Child :public Person//定义小孩子类让它公有继承自person类
{
public:
	virtual void YouWillSay(YouSay& y)//重写继承自person类的纯虚函数
	{
		y.IsAChild();//调用遇到小孩子的称呼函数
	}
};
int main()
{
	YouSay y;//创建称呼的实例化对象
	Person* p;//创建一个可以指向人的类类型的指针
	p = new Man;//让p先指向一个男士
	p->YouWillSay(y);//通过男士的对象调用要称呼的函数
	p = new Woman;//让p指向一个女士
	p->YouWillSay(y);//通过女士的对象调用要称呼的函数
	p = new Child;//让p指向一个小孩子
	p->YouWillSay(y);//通过小孩子的对象调用要称呼的函数
	return 0;
}
*/


/*
#include<iostream>
using namespace std;
class Base//定义一个Base类
{
public:
	virtual void BaseTest1()//Base类中定义虚函数BaseTest1()
	{
		cout << "Base::BaseTest1()" << endl;//函数打印它的作用域和函数名
	}
	virtual void BaseTest2()//Base类中定义虚函数BaseTest2（）
	{
		cout << "Base::BaseTest2()" << endl;//函数打印它的作用域和函数名
	}
	int _base;//Base类内定义一个数据成员
};
class Derive :virtual public Base//定义Derive类公有普通继承自Base类
{
public:
	virtual void BaseTest1()//对Base类的BaseTest1()函数进行重写
	{
		cout << "Derive::BaseTest1()" << endl;
	}
	virtual void DeriveTest1()//Derive类中定义函数DeriveTest1()
	{
		cout << "Derive::DeriveTest1()" << endl;//函数打印它的作用域和函数名
	}
	virtual void DeriveTest2()//Derive类中定义函数DeriveTest2（）
	{
		cout << "Derive::DervieTest2()" << endl;//函数打印它的作用域和函数名
	}
	int _derive;//Derive类定义一个数据成员
};

typedef void(*PF)();//将函数指针的名字进行重命名
void FunTest(Derive& d)//定义一个函数测试函数
{
	PF* PFTV = NULL;//定义一个指向函数指针的指针
	PFTV = (PF*)(*((int*)&d + 3));//将Derive类对象的前四个字节的指针强制类型转换为一个指向函数指针的指针
	while (*PFTV)//设置一个循环，当函数指针保存的值为0时退出
	{
		(*PFTV)();//用指针来执行函数指针指向的函数
		PFTV = (PF*)((int*)PFTV + 1);//执行下一个函数
	}
}
int main()
{
	Derive d;//创建Derive类对象
	cout << sizeof(d) << endl;//打印Derive类对象的大小
	d._base = 1;//通过Dervie类对象改变继承自Base类对象的数据成员
	d._derive = 2;//通过Derive类对象改变它自己的数据成员
	FunTest(d);
	return 0;
}
*/


/*
#include<iostream>
using namespace std;
class Base1//定义一个Base1类
{
public:
	virtual void Base1Test1()//在Base1类中定义第一个虚函数
	{
		cout << "Base1::Base1Test1()" << endl;//函数打印它的作用域及函数名
	}
	virtual void Base1Test2()//在Base2类中定义第二个虚函数
	{
		cout << "Base1::Base1Test2()" << endl;//函数打印它的作用域及函数名
	}
	int _base1;//在Base1类中定义一个数据成员
};
class Base2//定义Base2类
{
public:
	virtual void Base2Test1()//在Base2类中定义第一个虚函数
	{
		cout << "Base2::Base2Test1()" << endl;//函数打印自己的作用域及函数名
	}
	virtual void Base2Test2()//在Base2类中定义第二个虚函数
	{
		cout << "Base2::Base2Test2()" << endl;//函数打印自己的作用域和函数名
	}
	int _base2;//在Base2类中定义一个数据成员
};
class Derive :virtual public Base1,virtual public Base2//定义Derive类公有普通继承自Base1和Base2类
{
public:
	virtual void Base1Test1()//在Derive类中对Base1类的第一个虚函数进行重写
	{
		cout << "Derive::Base1Test1()" << endl;//函数打印它的作用域和函数名
	}
	virtual void Base2Test1()//在Derive类中对Base2类的第一个虚函数进行重写
	{
		cout << "Derive::Base2Test1()" << endl;//函数打印它的作用域和函数名
	}
	virtual void DeriveTest1()//在Derive类中定义它特有的第一个虚函数
	{
		cout << "Derive::DeriveTest1()" << endl;//函数打印它的作用域和函数名
	}
	virtual void DeriveTest2()//在Derive类中定义它特有的第二个虚函数
	{
		cout << "Derive::DervieTest2()" << endl;//函数打印它的作用域和函数名
	}
	int _derive;//在Derive类中定义一个数据成员
};
typedef void(*PF)();//将函数指针的名字进行重命名
void FunTest(Derive& d)//定义一个函数测试函数
{
	PF* PFTV = NULL;//定义一个指向函数指针的指针
	PFTV = (PF*)(*((int*)&d + 5));//将Derive类对象的前四个字节的指针强制类型转换为一个指向函数指针的指针
	while (*PFTV)//设置一个循环，当函数指针保存的值为0时退出
	{
		(*PFTV)();//用指针来执行函数指针指向的函数
		PFTV = (PF*)((int*)PFTV + 1);//执行下一个函数
	}
}
int main()
{
	Derive d;//创建Derive类对象
	//cout << sizeof(d) << endl;//打印派生类Derive类的大小
	d._base1 = 1;//通过Derive类对象改变继承自Base1类的数据成员
	d._base2 = 2;//通过Derive类对象改变继承自Base2类的数据成员
	d._derive = 3;//通过Derive类对象改变它自己的数据成员
	FunTest(d);
	return 0;
}
*/


/*

#include<iostream>
using namespace std;
class Base//定义Base类
{
public:
	virtual void BaseTest1()//在Base类内定义第一个虚函数
	{
		cout << "Base::BaseTest1()" << endl;//函数打印自己的作用域和函数名
	}
	virtual void BaseTest2()//在Base类内打印第二个虚函数
	{
		cout << "Base::BaseTest2()" << endl;//函数打印自己的作用域和函数名
	}
	int _base;//定义Base类的数据成员
};
class C1 :virtual public Base//定义C1类公有普通继承自Base类
{
public:
	virtual void C1Test1()//在C1类内定义第一个虚函数
	{
		cout << "C1::C1Test1()" << endl;//函数打印自己的作用域和函数名
	}
	virtual void C1Test2()//在C2类内定义第二个虚函数
	{
		cout << "C1::C1Test2()" << endl;//函数打印自己的作用域和函数名
	}
	int _c1;//定义C1类的数据成员
};
class C2 :virtual public Base//定义C2类公有普通继承自Base类
{
public:
	virtual void C2Test1()//在C2类内定义第一个虚函数
	{
		cout << "C2::C2Test1()" << endl;//函数打印自己的作用域和函数名
	}
	virtual void C2Test2()//在C2类内定义第二个虚函数
	{
		cout << "C2::C2Test2()" << endl;//函数打印自己的作用域和函数名
	}
	int _c2;//定义C2类的数据成员
};
class Derive :virtual public C1,virtual public C2//定义Deive类公有普通继承自C1和C2类
{
public:
	virtual void BaseTest1()//在Derive类中重写Base类的第一个虚函数
	{
		cout << "Derive::BaseTest1()" << endl;//函数打印它的作用域和函数名
	}
	virtual void C1Test1()//在Derive类中重写C1类的第一个虚函数
	{
		cout << "Derive::C1Test1()" << endl;//函数打印它的作用域和函数名
	}
	virtual void C2Test1()//在Derive类中重写C2类的第一个虚函数
	{
		cout << "Derive::C2Test1()" << endl;//函数打印它的作用域和函数名
	}
	virtual void DeriveTest1()//在Derive类中定义它的第一个特有的虚函数
	{
		cout << "Derive::DeriveTest1()" << endl;//函数打印它的作用域和函数名
	}
	virtual void DeriveTest2()//在Derive类中定义它的第二个特有的虚函数
	{
		cout << "Derive::DeriveTest2()" << endl;//函数打印它的作用域和函数名
	}
	int _derive;//定义Derive类的数据成员
};
typedef void(*PF)();//将函数指针的名字进行重命名
void FunTest(Derive& d)//定义一个函数测试函数
{
	PF* PFTV = NULL;//定义一个指向函数指针的指针
	PFTV = (PF*)(*((int*)&d + 8));//将Derive类对象的前四个字节的指针强制类型转换为一个指向函数指针的指针
	while (*PFTV)//设置一个循环，当函数指针保存的值为0时退出
	{
		(*PFTV)();//用指针来执行函数指针指向的函数
		PFTV = (PF*)((int*)PFTV + 1);//执行下一个函数
	}
}

int main()
{
	Derive d;//创建Derive类对象
	//cout << sizeof(d) << endl;//打印Derive类对象的大小
	d._base = 1;//通过Derive类对象改变继承自Base类的数据成员的值
	d._c1 = 3;//通过Derive类对象改变继承自C1类的数据成员的值
	d._c2 = 4;//通过Derive类对象改变继承自C2类的数据成员的值
	d._derive = 5;//通过Derive类对象改变Derive类特有的数据成员的值
	FunTest(d);
	return 0;
}
*/


/*
void TestFunc1()
{
	throw 1;
}
void TestFunc2()
{
	try
	{
		TestFunc1();
	}
	catch (...)
	{

	}
}       
int main()
{
	TestFunc2();
	return 0;
}
*/

/*
typedef void(*PF)();
template<class T>
class Test
{
public:

};

int main()
{
	return 0;
}
*/
/*
#include<iostream>
using namespace std;
template<class T>
class A
{
public:
	A();
private:
	T* ptr;
};
template<class T>
A<T>::A()
{
	cout << "hahah" << endl;
}


int main()
{
	A<int> a;
	return 0;
}
*/

/*
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> v1;
	vector<int> v2(10, 5);

	int array[] = { 1, 2, 3, 4, 5, 6, 7 };
	vector<int> v3(array, array + sizeof(array) / sizeof(array[0]));

	vector<int> v4(v3);
	vector<int>::iterator it = v4.begin();
	while (it != v4.end())
	{
		cout << *it++ << " ";
	}
	return 0;
}
*/

/*
#include<vector>
#include<iostream>
using namespace std;

void VectorTest()
{
	vector<int> v1(10);
	vector<int> v2(v1);
	vector<int> v3(2);
	cout << &v1 << endl;
	cout << &v2 << endl;
	v1 = v2;
	cout << &v1 << endl;
	cout << &v2 << endl;
	v1 = v3;
	cout << &v1 << endl;
	cout << &v3 << endl;
	cout << v1.front() << endl;
}
int main()
{
	VectorTest();
}
*/

/*
#include<string.h>
#include<string>
#include<iostream>
using namespace std;
class A
{
	A(string name= "NONE", string sex= "SECERT", int age = 0)
	:_age(age)
	, _name(name)
	, _sex(sex)
	{}
private:
	string _name;
	string _sex;
	int _age;
};
int main()
{
	string s1 = "hello world!";
	string s2;
	cout << s1 << s2 << endl;
	cout << s1.data() <<endl;
	return 0;
}
*/

/*
void TestMemory()
{
	int* p1 = (int*)malloc(sizeof(int));
	int* p2 = (int*)malloc(sizeof(int));
	int* p3 = new int;
	int* p4 = new int;
	int* p5 = new int[10];
	int* p6 = new int[10];
	delete p1;
	delete[] p2;
	free(p3);
	delete[] p4;
	free(p5);
	delete p6;
}
#include<iostream>
using namespace std;
int main()
{
	TestMemory();
	return 0;
}
*/
#if 0
#include<iostream>
using namespace std;
int main()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	for (auto e : array)
		cout << e << " ";
	cout << endl;
	return 0;
}
#endif
#if 0
class Base
{
public:
	void virtual Test()
	{}
	int _a;

};
class Derive :public Base
{
public:
	void Test()
	{}
	int _w;
};
int main()
{
	return 0;
}
#endif
#include<iostream>
using namespace std;
template<class T>
T Add(T x, T y)
{
	return x + y;
}
int main()
{
	cout << Add(3, 5) << endl;
	return 0;
}