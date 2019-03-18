#pragma once
#include "Common.h"

/*****************直接插入排序---begin************************/
template<class T, class Com = Greater<T> >
class DirInsertSort	
{
public:
	void Sort(std::vector<T>& v)
	{
		for (int i = 0; i < static_cast<int>(v.size()); ++i)
		{
			T obj = v[i];	//先将要插入的数据保存起来
			int pos = 0;
			Com comper;
			while (pos < i && comper(v[i], v[pos]))
				pos++;
			if(pos == i)
				continue;	//找到的合适位置即就是当前位置

			for (int j = i; i > pos; --i)
			{
				std::swap(v[i], v[i - 1]);
			}

			v[pos] = obj;
		}
	}
};
/*******************直接插入排序---end************************/