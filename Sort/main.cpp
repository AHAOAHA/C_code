//#include "HeapSortAdjustDown.hpp"
#include "HeapSortAdjustUp.hpp"
//void HeapSortDown(std::vector<int>& v)
//{
//	//采用向下调整法
//	for (int i = v.size() - 1; i >= 0; --i)
//	{
//		AdjustDown(v, i);  //每进行一次，将v中前n个最大的元素换到堆顶
//		std::swap(v[0], v[i]);
//	}
//}

void HeapSortUp(std::vector<int>& v)
{
	for (int i = v.size() - 1; i >= 0; --i)
	{
		AdjustUp(v, i);
		std::swap(v[0], v[i]);
	}
}
int main()
{
	int arr[5] = { 3,5,2,7,1 };
	std::vector<int> v(arr, arr + 5);
	//HeapSortDown(v);
	HeapSortUp(v);
	PrintArr(v);
	return 0;
}