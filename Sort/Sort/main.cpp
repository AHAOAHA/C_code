#include <iostream>
#include "HeapSortSelfOpt.hpp"	//������
#include "DirInsertSort.hpp"	//ֱ�Ӳ�������
#include "HalfInsertSort.hpp"	//�۰��������
#include "ShellSort.hpp"	//ϣ������
#include "QuickSort.hpp"
int main()
{
	std::vector<int> v = { 1,5,2,6,8 };
	//DirInsertSort<int, Lesser<int>>().Sort(v);
	//HeapSortSelfOpt<int, Lesser<int>>().Sort(v);
	//ShellSort<int, Lesser<int>>().Sort(v);
	//QuickSort<int, Lesser<int>>().Sort(v);
	return 0;
}