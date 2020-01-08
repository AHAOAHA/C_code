#if 0
class Base
{
public:
	int _b;
};
class C1 :public Base
{
public:
	int _c1;
};

class C2 :public Base
{
public:
	int _c2;
};

class Derive :virtual public C1, virtual public C2
{
public:
	int _d;
};
int main()
{
	Derive d;
	return 0;
}
#endif
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

class Test
{
public:
	Test(int n)
	{
		cout << "构造函数" << endl;
	}

	Test(const Test& t)
	{
		cout << "拷贝构造函数" << endl;
	}

	Test & operator=(const Test& t)
	{
		cout << "赋值运算符重载" << endl;
		return *this;
	}
};

int main()
{
	Test t(10);
	//Test t2 = t;
	t = 10;
	return 0;
}