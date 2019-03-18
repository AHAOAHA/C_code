#pragma once
#include "Common.h"
/********************��������---begin************************/

template<class T, class Com = Greater<T>>
class QuickSort
{
public:
	void Sort(std::vector<T>& v)
	{
		//LRPoint(v, 0, v.size() - 1);		//����ָ�뷨
		DigHole(v, 0, v.size() - 1);		//�ڿӷ�
	}

private:
	/***************����ָ�뷨---begin******************/
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
	/***************����ָ�뷨---end******************/

	/****************�ڿӷ�---begin********************/
	void DigHole(std::vector<T>& v, int left, int right)
	{
		if (left >= right)
			return;
		int div = DigHoleHandler(v, left, right);
		DigHole(v, left, div - 1);
		DigHole(v, div + 1, right);
	}

	int DigHoleHandler(std::vector<T>& v, int left, int right)
	{
		T obj = v[left];
		Com comper;
		while (left < right)
		{
			while (comper(obj , v[right]) && left < right)
				right--;
			v[left] = v[right];
			while (comper(v[left], obj) && left < right)
				left++;
			v[right] = v[left];
		}
		v[right] = obj;
		return right;
	}
	/****************�ڿӷ�---end********************/
};

/********************��������---end**************************/


