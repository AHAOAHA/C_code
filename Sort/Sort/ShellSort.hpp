#pragma once
#include "Common.h"

/******************希尔排序---begin*********************/
template<class T, class Com = Greater<T> >
class ShellSort
{
public:
	void Sort(std::vector<T>& v)
	{
		int gap = v.size() / 2;
		while (gap > 0)
		{
			int group_num =  gap;

			DirInsertSort(v, gap, group_num);
			//对每一组进行直接插入排序
			gap = gap / 2;
		}
	}
private:
	void DirInsertSort(std::vector<T>& v, int gap, int group_num)
	{
		Com comper;
		for (int i = 0; i < group_num; ++i)
		{
			for (int j = i; j < static_cast<int>(v.size()); j += gap)
			{
				int pos = i;
				T obj = v[j];
				while (comper(v[j], v[pos]) && pos < j)
					pos += gap;

				if(pos == j)
					continue;

				for (int move_pos = j; move_pos > pos; move_pos -= gap)
				{
					std::swap(v[move_pos], v[move_pos - gap]);
				}
				v[pos] = obj;
			}
		}
	}
};
/******************希尔排序---end***********************/