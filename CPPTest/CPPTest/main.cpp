#include <iostream>

class Base
{
public:
	void Func()
	{
		std::cout << "Test::Base" << std::endl;
	}
};

class Derive :public Base
{
public:
	void Func()
	{
		std::cout << "Test::Derive" << std::endl;
	}
};

int main()
{
	int a = 0;
	a++;
	return 0;
}