#include"list.hpp"
int main()
{
	MyList<int> s;
	s.push_back(1);
	s.push_back(2);
	s.pop_front();
	s.push_front(0);
	s.pop_back();
	return 0;
}