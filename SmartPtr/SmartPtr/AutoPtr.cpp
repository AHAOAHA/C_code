#include <iostream>
#include <memory>

class Test
{
public:
	int _t = 1;
};
int main()
{
	std::auto_ptr<Test> p1(new Test);
	std::auto_ptr<Test> p2(p1);
	return 0;
}