#include <iostream>
#include "HeapSortSelfOpt.hpp"	//∂—≈≈–Ú
#include "DirInsertSort.hpp"	//÷±Ω”≤Â»Î≈≈–Ú
#include "HalfInsertSort.hpp"	//’€∞Î≤Â»Î≈≈–Ú
#include "ShellSort.hpp"	//œ£∂˚≈≈–Ú
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