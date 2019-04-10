#include <iostream>
#include "HeapSortSelfOpt.hpp"	//������
#include "DirInsertSort.hpp"	//ֱ�Ӳ�������
#include "HalfInsertSort.hpp"	//�۰��������
#include "ShellSort.hpp"	//ϣ������
#include "QuickSort.h"
#include "MergeSort.hpp"

int main()
{
	std::vector<int> v = { 7,9,2,5,4,8,4,7,2,3,33,44 };
	//DirInsertSort<int, Lesser<int>>().Sort(v);
	//HeapSortSelfOpt<int, Lesser<int>>().Sort(v);
	//ShellSort<int, Lesser<int>>().Sort(v);
	//QuickSort<int, Lesser<int>>().Sort(v);
	MergeSort<int>()._MergeSort(v, 0, v.size() - 1);
	return 0;
}