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
	//����
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
		:_name("���"),
		_gender("��"),
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
	sizeof(A);//����A����ռ�ڴ�Ĵ�С
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
//class Base//����һ������
//{
//public:
//	~Base()//��ʽ������������������
//	{
//		cout << "Base::~Base()" << endl;//�ڻ�������������ڲ�������ӡ���Լ��ĺ�����
//	}
//	int _b;//��������ݳ�Ա
//};
//class Derive :public Base//����һ�������࣬���м̳��Ի���
//{
//public:
//	~Derive()//��ʾ�����������������������ڸ�����һ���ϵ�
//	{
//		cout << "Derive::~Derive()" << endl;//�����������ڲ�������ӡ�Լ��ĺ�����
//	}
//	int _d;//�������Լ������ݳ�Ա
//};
//int main()
//{
//	Derive d;//����һ��������
//	return 0;
//}

//
//#include<iostream>
//using namespace std;
//class Base//����һ������
//{
//public:
//	void Test()//�ڻ����ж���һ����ΪTest�ĺ���
//	{
//		cout << "Base::Test()" << endl;//�ں����ڲ���ӡ�ú���������������
//	}
//};
//class Derive :public Base//����һ�����м̳��Ի���Base��������Derive
//{
//public:
//	void Test()//����������Ҳͬ������һ����ΪTest�ĺ���
//	{
//		cout << "Derive::Test()" << endl;//�ں����ڲ���ӡ�ú���������������
//	}
//};
//int main()
//{
//	Derive d;//����������Ķ���
//	d.Test();//����Ĭ���������ͨ��������������ͬ������������ĸ��������еĺ���
//	d.Derive::Test();//������������������
//	d.Base::Test();//��ӻ������������
//	return 0;
//}


//
//#include<iostream>
//using namespace std;
//class Base//����һ������
//{
//public:
//	void BaseTest()//�ڻ����ж���һ����ͨ����
//	{
//		cout << "Base::BaseTest()" << endl;//�øú�����ӡ�����ڵ������򼰺�����
//	}
//	int _base;//����һ�����ڻ�������ݱ���
//};
//class Derive1 :public Base//����һ�����м̳��Ի���Base��������
//{
//public:
//	void Derive1Test()//����һ���������Լ�����ͨ����
//	{
//		cout << "Derive1::Derive1Test()" << endl;//�øú�����ӡ�����ڵ������򼰺�����
//	}
//	int _derive1;//����һ�������������Լ������ݱ���
//};
//class Derive2 :public Derive1//����һ�����м̳���������Derive1��������
//{
//public:
//	void Derive2Test()//����һ���������Լ�����ͨ����
//	{
//		cout << "Derive2::Derive2Test()" << endl;//�øú�����ӡ�����ڵ������򼰺�����
//	}
//	int _derive2;//����һ�������������Լ������ݱ���
//};
//int main()
//{
//	Derive1 d1;//����Derive1������Ķ���
//	cout << sizeof(d1) << endl;//�鿴Derive1���������Ĵ�С
//	d1._base = 1;
//	d1._derive1 = 2;
//	Derive2 d2;//����Derive2������Ķ���
//	cout << sizeof(d2) << endl;//�鿴Derive2���������Ĵ�С
//	d2._base = 3;
//	d2._derive1 = 4;
//	d2._derive2 = 5;
//	return 0;
//}


//#include<iostream>
//using namespace std;
////���ȶ�����������
//class Base1//��һ������
//{
//public:
//	void Base1Test()//�ڵ�һ�������ж���һ������
//	{
//		cout << "Base1::Base1Test()" << endl;//�����������ӡ�Լ���������ͺ�����
//	}
//	int _base1;//����һ�����ڵ�һ����������ݱ���
//};
//class Base2//�ڶ�������
//{
//public:
//	void Base2Test()//�ڵڶ��������ж���һ������
//	{
//		cout << "Base2::Base2Test()" << endl;//�����������ӡ�Լ���������ͺ�����
//	}
//	int _base2;//����һ�����ڵڶ�����������ݱ���
//};
//class Derive :public Base1, public Base2//�������๫�м̳��Ի���1�ͻ���2
//{
//public:
//	void DeriveTest()//����һ���������Լ��ĺ���
//	{
//		cout << "Derive::DeriveTest()" << endl; //�����������ӡ�Լ���������ͺ�����
//	}
//	int _derive;//����һ���������Լ������ݱ���
//};
//int main()
//{
//	Derive d;//�������������
//	cout << sizeof(d) << endl;//��ӡ����������ռ�ֽڴ�С
//	d._base1 = 1;//ͨ���������޸Ļ���1�����ݳ�Ա��ֵ
//	d._base2 = 2;//ͨ���������޸Ļ���2�����ݳ�Ա��ֵ
//	d._derive = 3;//ͨ���������޸�����������ݳ�Ա��ֵ
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class Base//����һ������
//{
//public:
//	void BaseTest()//����һ������
//	{
//		cout << "Base::BaseTest()" << endl;//�ú�����ӡ�Լ��������򼰺�����
//	}
//	int _base;//����һ����������ݳ�Ա
//};
//class C1 :public Base//����һ��������C1���м̳���Base��
//{
//public:
//	void C1Test()//����һ������
//	{
//		cout << "C1::C1Test()" << endl;//�ú�����ӡ�Լ��������򼰺�����
//	}
//	int _c1;//����һ������C1������ݳ�Ա
//};
//class C2 :public Base//����һ��������C2���м̳���Base��
//{
//public:
//	void C2Test()//����һ������
//	{
//		cout << "C2::C2Test()" << endl;//�ú�����ӡ�Լ��������򼰺�����
//	}
//	int _c2;//����һ������C2������ݳ�Ա
//};
//class Derive :public C1, public C2//����һ��������Derive���ж�̳���C1���C2��
//{
//public:
//	void DeriveTest()//����һ������
//	{
//		cout << "Derive::DeriveTest()" << endl;//�ú�����ӡ�Լ��������򼰺�����
//	}
//	int _derive;//����һ������������Derive�����ݳ�Ա
//};
//int main()
//{
//	Derive d;//����������d�Ķ���
//	cout << sizeof(d) << endl;//��ӡ���������d��ռ�ֽڴ�С
//	d.C1::_base = 1;//ͨ�����������ı�Base������ݳ�Ա
//	d._c1 = 2;//ͨ�����������ı�C1������ݳ�Ա
//	d._c2 = 3;//ͨ�����������ı�C2������ݳ�Ա
//	d._derive = 4;//ͨ�����������ı�Derive������ݳ�Ա
//	return 0;
//}



//
//#include<iostream>
//using namespace std;
//class Base//����һ������
//{
//public:
//	void BaseTest()//�ڻ����ж���һ������
//	{
//		cout << "Base::BaseTest()" << endl;//�����������ӡ�Լ��������򼰺�����
//	}
//	int _base;//�ڻ����ж���һ�����ݳ�Ա
//};
//class C1 :virtual public Base//����һ����������������̳���Base��
//{
//public:
//	void C1Test()//�����ж���һ������
//	{
//		cout << "C1::C1Test()" << endl;//�����������ӡ�Լ��������򼰺�����
//	}
//	int _c1;//�����ж���һ�����ݳ�Ա
//};
//class Derive :virtual public C1//����һ����Derive������������̳���C1��
//{
//public:
//	void DeriveTest()//�����ж���һ������
//	{
//		cout << "DeriveTest()" << endl;////�����������ӡ�Լ��������򼰺�����
//	}
//	int _derive;//�����ж���һ�����ݳ�Ա
//};
//
//
//int main()
//{
//	Derive d;//�������������
//	cout << sizeof(d) << endl;//��ӡ������Ĵ�С
//	d._base = 1;//ͨ�����������ı�̳���Base�����ݳ�Ա
//	d._c1 = 2;//ͨ�����������ñ�̳���C1������ݳ�Ա
//	d._derive = 3;//ͨ�����������ı����Լ������ݳ�Ա
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
//class Base1//����Base1��
//{
//public:
//	int _base1;//����һ�����ݳ�Ա
//};
//class Base2//����Base2��
//{
//public:
//	int _base2;//����һ�����ݳ�Ա
//};
////����Derive�ࣻ��Derive�๫������̳���Base1���Base2��
//class Derive :virtual public Base1, virtual public Base2
//{
//public:
//	int _derive;//����һ�����ݳ�Ա
//};
//int main()
//{
//	Derive d;//����Derive��Ķ���
//	cout << sizeof(d) << endl;//��ӡDerive�����Ĵ�С
//	d._base1 = 1;//ͨ�����������ı�̳���Base1�����ݳ�Ա��ֵ
//	d._base2 = 2;//ͨ�����������ı�̳���Base2�����ݳ�Ա��ֵ
//	d._derive = 3;//ͨ�����������ı����Լ������ݳ�Ա
//	return 0;
//}



//#include<iostream>
//using namespace std;
//class Base//����һ��base��
//{
//public:
//	int _base;//����һ�����ݳ�Ա
//};
//class C1:virtual public Base//����C1������̳���Base��
//{
//public:
//	int _c1;//����һ�����ݳ�Ա
//
//};
//class C2 : virtual public Base//����C2������̳���Base��
//{
//public:
//	int _c2;//����һ�����ݳ�Ա
//};
////����Derive�๫�������̳���C1���C2��
//class Derive : virtual public C1, virtual public C2
//{
//public:
//	int _derive;//����һ�����ݱ���
//};
//int main()
//{
//	Derive d;//����Derive�����
//	cout << sizeof(d) << endl;//��ӡDerive�����Ĵ�С
//	d._base = 1;//ͨ��Derive�����ı�Base������ݳ�Ա
//	d._c1 = 2;//ͨ��Derive�����ı�C1���������ݳ�Ա
//	d._c2 = 3;//ͨ��Derive�����ı�C2���������ݳ�Ա
//	d._derive = 4;//ͨ��Derive�����ı����Լ������ݳ�Ա
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
class WashRoom//����һ�����������ģ��
{
public:
	void GoToManWashRoom()//������ʿ������ĺ���
	{
		cout << "Turn Left" << endl;//��ӡ����
	}
	void GoToWomanWashRoom()//����Ůʿ������ĺ���
	{
		cout << "Turn Right" << endl;//��������
	}
};
class Person//����һ������
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



////����һ��������
//class Base
//{
//public:
//	virtual void BaseTest() = 0;//���麯��
//};
//int main()
//{
//	Base b;//�����ó�����ʵ��������
//	return 0;
//}



/*
#include<iostream>
using namespace std;

class YouSay//����ƺ�����ģ��
{
public:
	void IsAMan()//�������
	{
		cout << "hi ˧��" << endl;//��ӡhi ˧��
	}
	void IsAWoman()//�����Ů
	{
		cout << "hi ��Ů" << endl;//��ӡhi ��Ů
	}
	void IsAChild()//�����С����
	{
		cout << "hi С����" << endl;//��ӡhi С����
	}
};
class Person//��������ָ���˵ĳ�����
{
public:
	virtual void YouWillSay(YouSay& y) = 0;//����ƺ��ĺ���
};
class Man :public Person//������ʿ���������м̳���person��
{
public:
	virtual void YouWillSay(YouSay& y)//��д�̳���person��Ĵ��麯��
	{
		y.IsAMan();//����������ʿ�ĳƺ�����
	}
};
class Woman :public Person//����Ůʿ���������м̳���person��
{
public:
	virtual void YouWillSay(YouSay& y)//��д�̳���person��Ĵ��麯��
	{
		y.IsAWoman();//��������Ůʿ�ĳƺ�����
	}
};
class Child :public Person//����С�������������м̳���person��
{
public:
	virtual void YouWillSay(YouSay& y)//��д�̳���person��Ĵ��麯��
	{
		y.IsAChild();//��������С���ӵĳƺ�����
	}
};
int main()
{
	YouSay y;//�����ƺ���ʵ��������
	Person* p;//����һ������ָ���˵������͵�ָ��
	p = new Man;//��p��ָ��һ����ʿ
	p->YouWillSay(y);//ͨ����ʿ�Ķ������Ҫ�ƺ��ĺ���
	p = new Woman;//��pָ��һ��Ůʿ
	p->YouWillSay(y);//ͨ��Ůʿ�Ķ������Ҫ�ƺ��ĺ���
	p = new Child;//��pָ��һ��С����
	p->YouWillSay(y);//ͨ��С���ӵĶ������Ҫ�ƺ��ĺ���
	return 0;
}
*/


/*
#include<iostream>
using namespace std;
class Base//����һ��Base��
{
public:
	virtual void BaseTest1()//Base���ж����麯��BaseTest1()
	{
		cout << "Base::BaseTest1()" << endl;//������ӡ����������ͺ�����
	}
	virtual void BaseTest2()//Base���ж����麯��BaseTest2����
	{
		cout << "Base::BaseTest2()" << endl;//������ӡ����������ͺ�����
	}
	int _base;//Base���ڶ���һ�����ݳ�Ա
};
class Derive :virtual public Base//����Derive�๫����ͨ�̳���Base��
{
public:
	virtual void BaseTest1()//��Base���BaseTest1()����������д
	{
		cout << "Derive::BaseTest1()" << endl;
	}
	virtual void DeriveTest1()//Derive���ж��庯��DeriveTest1()
	{
		cout << "Derive::DeriveTest1()" << endl;//������ӡ����������ͺ�����
	}
	virtual void DeriveTest2()//Derive���ж��庯��DeriveTest2����
	{
		cout << "Derive::DervieTest2()" << endl;//������ӡ����������ͺ�����
	}
	int _derive;//Derive�ඨ��һ�����ݳ�Ա
};

typedef void(*PF)();//������ָ������ֽ���������
void FunTest(Derive& d)//����һ���������Ժ���
{
	PF* PFTV = NULL;//����һ��ָ����ָ���ָ��
	PFTV = (PF*)(*((int*)&d + 3));//��Derive������ǰ�ĸ��ֽڵ�ָ��ǿ������ת��Ϊһ��ָ����ָ���ָ��
	while (*PFTV)//����һ��ѭ����������ָ�뱣���ֵΪ0ʱ�˳�
	{
		(*PFTV)();//��ָ����ִ�к���ָ��ָ��ĺ���
		PFTV = (PF*)((int*)PFTV + 1);//ִ����һ������
	}
}
int main()
{
	Derive d;//����Derive�����
	cout << sizeof(d) << endl;//��ӡDerive�����Ĵ�С
	d._base = 1;//ͨ��Dervie�����ı�̳���Base���������ݳ�Ա
	d._derive = 2;//ͨ��Derive�����ı����Լ������ݳ�Ա
	FunTest(d);
	return 0;
}
*/


/*
#include<iostream>
using namespace std;
class Base1//����һ��Base1��
{
public:
	virtual void Base1Test1()//��Base1���ж����һ���麯��
	{
		cout << "Base1::Base1Test1()" << endl;//������ӡ���������򼰺�����
	}
	virtual void Base1Test2()//��Base2���ж���ڶ����麯��
	{
		cout << "Base1::Base1Test2()" << endl;//������ӡ���������򼰺�����
	}
	int _base1;//��Base1���ж���һ�����ݳ�Ա
};
class Base2//����Base2��
{
public:
	virtual void Base2Test1()//��Base2���ж����һ���麯��
	{
		cout << "Base2::Base2Test1()" << endl;//������ӡ�Լ��������򼰺�����
	}
	virtual void Base2Test2()//��Base2���ж���ڶ����麯��
	{
		cout << "Base2::Base2Test2()" << endl;//������ӡ�Լ���������ͺ�����
	}
	int _base2;//��Base2���ж���һ�����ݳ�Ա
};
class Derive :virtual public Base1,virtual public Base2//����Derive�๫����ͨ�̳���Base1��Base2��
{
public:
	virtual void Base1Test1()//��Derive���ж�Base1��ĵ�һ���麯��������д
	{
		cout << "Derive::Base1Test1()" << endl;//������ӡ����������ͺ�����
	}
	virtual void Base2Test1()//��Derive���ж�Base2��ĵ�һ���麯��������д
	{
		cout << "Derive::Base2Test1()" << endl;//������ӡ����������ͺ�����
	}
	virtual void DeriveTest1()//��Derive���ж��������еĵ�һ���麯��
	{
		cout << "Derive::DeriveTest1()" << endl;//������ӡ����������ͺ�����
	}
	virtual void DeriveTest2()//��Derive���ж��������еĵڶ����麯��
	{
		cout << "Derive::DervieTest2()" << endl;//������ӡ����������ͺ�����
	}
	int _derive;//��Derive���ж���һ�����ݳ�Ա
};
typedef void(*PF)();//������ָ������ֽ���������
void FunTest(Derive& d)//����һ���������Ժ���
{
	PF* PFTV = NULL;//����һ��ָ����ָ���ָ��
	PFTV = (PF*)(*((int*)&d + 5));//��Derive������ǰ�ĸ��ֽڵ�ָ��ǿ������ת��Ϊһ��ָ����ָ���ָ��
	while (*PFTV)//����һ��ѭ����������ָ�뱣���ֵΪ0ʱ�˳�
	{
		(*PFTV)();//��ָ����ִ�к���ָ��ָ��ĺ���
		PFTV = (PF*)((int*)PFTV + 1);//ִ����һ������
	}
}
int main()
{
	Derive d;//����Derive�����
	//cout << sizeof(d) << endl;//��ӡ������Derive��Ĵ�С
	d._base1 = 1;//ͨ��Derive�����ı�̳���Base1������ݳ�Ա
	d._base2 = 2;//ͨ��Derive�����ı�̳���Base2������ݳ�Ա
	d._derive = 3;//ͨ��Derive�����ı����Լ������ݳ�Ա
	FunTest(d);
	return 0;
}
*/


/*

#include<iostream>
using namespace std;
class Base//����Base��
{
public:
	virtual void BaseTest1()//��Base���ڶ����һ���麯��
	{
		cout << "Base::BaseTest1()" << endl;//������ӡ�Լ���������ͺ�����
	}
	virtual void BaseTest2()//��Base���ڴ�ӡ�ڶ����麯��
	{
		cout << "Base::BaseTest2()" << endl;//������ӡ�Լ���������ͺ�����
	}
	int _base;//����Base������ݳ�Ա
};
class C1 :virtual public Base//����C1�๫����ͨ�̳���Base��
{
public:
	virtual void C1Test1()//��C1���ڶ����һ���麯��
	{
		cout << "C1::C1Test1()" << endl;//������ӡ�Լ���������ͺ�����
	}
	virtual void C1Test2()//��C2���ڶ���ڶ����麯��
	{
		cout << "C1::C1Test2()" << endl;//������ӡ�Լ���������ͺ�����
	}
	int _c1;//����C1������ݳ�Ա
};
class C2 :virtual public Base//����C2�๫����ͨ�̳���Base��
{
public:
	virtual void C2Test1()//��C2���ڶ����һ���麯��
	{
		cout << "C2::C2Test1()" << endl;//������ӡ�Լ���������ͺ�����
	}
	virtual void C2Test2()//��C2���ڶ���ڶ����麯��
	{
		cout << "C2::C2Test2()" << endl;//������ӡ�Լ���������ͺ�����
	}
	int _c2;//����C2������ݳ�Ա
};
class Derive :virtual public C1,virtual public C2//����Deive�๫����ͨ�̳���C1��C2��
{
public:
	virtual void BaseTest1()//��Derive������дBase��ĵ�һ���麯��
	{
		cout << "Derive::BaseTest1()" << endl;//������ӡ����������ͺ�����
	}
	virtual void C1Test1()//��Derive������дC1��ĵ�һ���麯��
	{
		cout << "Derive::C1Test1()" << endl;//������ӡ����������ͺ�����
	}
	virtual void C2Test1()//��Derive������дC2��ĵ�һ���麯��
	{
		cout << "Derive::C2Test1()" << endl;//������ӡ����������ͺ�����
	}
	virtual void DeriveTest1()//��Derive���ж������ĵ�һ�����е��麯��
	{
		cout << "Derive::DeriveTest1()" << endl;//������ӡ����������ͺ�����
	}
	virtual void DeriveTest2()//��Derive���ж������ĵڶ������е��麯��
	{
		cout << "Derive::DeriveTest2()" << endl;//������ӡ����������ͺ�����
	}
	int _derive;//����Derive������ݳ�Ա
};
typedef void(*PF)();//������ָ������ֽ���������
void FunTest(Derive& d)//����һ���������Ժ���
{
	PF* PFTV = NULL;//����һ��ָ����ָ���ָ��
	PFTV = (PF*)(*((int*)&d + 8));//��Derive������ǰ�ĸ��ֽڵ�ָ��ǿ������ת��Ϊһ��ָ����ָ���ָ��
	while (*PFTV)//����һ��ѭ����������ָ�뱣���ֵΪ0ʱ�˳�
	{
		(*PFTV)();//��ָ����ִ�к���ָ��ָ��ĺ���
		PFTV = (PF*)((int*)PFTV + 1);//ִ����һ������
	}
}

int main()
{
	Derive d;//����Derive�����
	//cout << sizeof(d) << endl;//��ӡDerive�����Ĵ�С
	d._base = 1;//ͨ��Derive�����ı�̳���Base������ݳ�Ա��ֵ
	d._c1 = 3;//ͨ��Derive�����ı�̳���C1������ݳ�Ա��ֵ
	d._c2 = 4;//ͨ��Derive�����ı�̳���C2������ݳ�Ա��ֵ
	d._derive = 5;//ͨ��Derive�����ı�Derive�����е����ݳ�Ա��ֵ
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