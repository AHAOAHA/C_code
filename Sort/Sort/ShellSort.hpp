#pragma once
#include "Common.h"

/******************希尔排序---begin*********************/
template<class T, class Com = Greater<T> >
class ShellSort
{
public:
	void Sort(std::vector<T>& v)
	{
		int gap = v.size();
		while (1)
		{
			gap = gap / 3 + 1;
			//gap = gap / 2;
			DirInsertSort(v, v.size(), gap);
			//对每一组进行直接插入排序
			if (gap == 1)
				break;
		}
	}
private:
	void DirInsertSort(std::vector<T>& v, const int& size, const int& gap)
	{
		//对每个gap进行直接插入排序
		Com comper;
		for (int i = gap; i < size; ++i)	//从gap的位置开始，一直到最后一个元为止
		{
			T obj = v[i];
			int j = 0;
			for (j = i - gap; j >= 0; j -= gap)
			{
				if (comper(obj, v[j]) || v[j] == obj)
					break;
				else
					v[j + gap] = v[j];
			}
			v[j + gap] = obj;
		}
	}
};
/******************希尔排序---end***********************/