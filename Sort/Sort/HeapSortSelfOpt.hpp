#pragma once
#include "Common.h"

template<class T, class Com = Greater<T> >
class HeapSortSelfOpt
{
public:
	void Sort(std::vector<T>& v)
	{
		for (int len = v.size(); len > 0; --len)
		{
			//AdjustDown(v, len);	//向下调整
			AdjustUp(v, len);	//向上调整
			std::swap(v[0], v[len- 1]);
		}
	}
private:
	/*************堆排序向下调整法---begin************/

	void AdjustDown(std::vector<T>& v, const int& len)
	{
		int parent = len / 2 - 1;
		for (parent; parent >= 0; --parent)
		{
			_AdjustDown(v, parent, len);
		}
	}

	void _AdjustDown(std::vector<T>& v, int parent, const int& len)
	{
		Com comper;
		int lchr = parent * 2 + 1;
		int biger_chr = lchr;
		int rchr = lchr + 1;
		if (rchr < len)
		{
			biger_chr = v[rchr] > v[lchr] ? rchr : lchr;
		}

		if (comper(v[biger_chr], v[parent]))
		{
			std::swap(v[biger_chr], v[parent]);
		}
		parent = biger_chr;
		lchr = parent * 2 + 1;
	}
	/*************堆排序向下调整法---end*******************/

	/*************堆排序向上调整法---begin*****************/

	void AdjustUp(std::vector<T>& v, const int& len)
	{
		int child = len - 1;
		for (child; child > 0; --child)
		{
			_AdjustUp(v, child, len);
		}
	}


	void _AdjustUp(std::vector<T>& v, int child, const int& len)
	{
		Com comper;
		int parent = (child - 1) >> 1;
		if (comper(v[child], v[parent]))
		{
			std::swap(v[parent], v[child]);
		}
	}
	/*************堆排序向上调整法---end*******************/
};