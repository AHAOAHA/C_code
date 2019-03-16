#include <iostream>
#include "HeapSortSelfOpt.hpp"
#include "InsertSort.hpp"
int main()
{
	std::vector<int> v = { 10,1,11,2,4 };
	//HeapSortSelfOpt<int>().Sort(v);
	InsertSort().Sort(v);
	//Test();
	return 0;
}