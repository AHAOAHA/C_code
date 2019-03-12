//#include "HeapSortAdjustDown.hpp"
#include "HeapSortAdjustUp.hpp"
//void HeapSortDown(std::vector<int>& v)
//{
//	//�������µ�����
//	for (int i = v.size() - 1; i >= 0; --i)
//	{
//		AdjustDown(v, i);  //ÿ����һ�Σ���v��ǰn������Ԫ�ػ����Ѷ�
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