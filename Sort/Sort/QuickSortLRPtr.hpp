#pragma once
#include "Common.h"
/********************快速排序---begin************************/

template<class T, class Com = Greater<T>>
class QuickSortLRPtr
{
public:
	void Sort(std::vector<T>& v)
	{
		LRPoint(v, 0, v.size() - 1);		//左右指针法
	}

private:
	/***************左右指针法---begin******************/
	void LRPoint(std::vector<T>& v, int left, int right)
	{
		if (left >= right)
			return;
		int div = Partition(v, left, right);
		LRPoint(v, left, div - 1);
		LRPoint(v, div + 1, right);
	}

	int Partition(std::vector<T>& v, int left, int right)
	{
		int prvot = left;
		Com comper;

		while (left < right)
		{
			while (comper(v[right] , v[prvot]) && left < right)
				right--;
			while (comper(v[prvot] , v[left]) && left < right)
				left++;
			
			std::swap(v[right], v[left]);
		}
		std::swap(v[right], v[prvot]);
		return right;
	}
	/***************左右指针法---end******************/

	
};

/********************快速排序---end**************************/


