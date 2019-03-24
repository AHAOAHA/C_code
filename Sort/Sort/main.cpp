#include <iostream>
#include "HeapSortSelfOpt.hpp"	//∂—≈≈–Ú
#include "DirInsertSort.hpp"	//÷±Ω”≤Â»Î≈≈–Ú
#include "HalfInsertSort.hpp"	//’€∞Î≤Â»Î≈≈–Ú
#include "ShellSort.hpp"	//œ£∂˚≈≈–Ú
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