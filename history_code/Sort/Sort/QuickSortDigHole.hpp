#pragma once
#include "Common.h"

template<class T, class Com = Greater<T>>
class QuickSortDigHole
{
public:
	void Sort(std::vector<T>& v)
	{
		DigHole(v, 0, v.size() - 1);		//ÍÚ¿Ó·¨
	}
private:
	/****************ÍÚ¿Ó·¨---begin********************/
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
			while (comper(obj, v[right]) && left < right)
				right--;
			v[left] = v[right];
			while (comper(v[left], obj) && left < right)
				left++;
			v[right] = v[left];
		}
		v[right] = obj;
		return right;
	}
	/****************ÍÚ¿Ó·¨---end********************/
};