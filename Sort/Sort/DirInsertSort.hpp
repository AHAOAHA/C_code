#pragma once
#include "Common.h"

/*****************直接插入排序---begin************************/
template<class T, class Com = Greater<T> >
class DirInsertSort	
{
public:
	void Sort(std::vector<T>& v)
	{
		for (int i = 1; i < static_cast<int>(v.size()); ++i)
		{
			T obj = v[i];	//先将要插入的数据保存起来
			int pos = 0;
			Com comper;
			/*		这种寻找位置的方式是十分挫的！！
			while (pos < i && comper(v[i], v[pos]))
				pos++;
			if(pos == i)
				continue;	//找到的合适位置即就是当前位置

			for (int j = i; i > pos; --i)
			{
				std::swap(v[i], v[i - 1]);
			}
			*/

			for (pos = i - 1; pos >= 0; --pos)
			{	//从后面开始找，若不满足条件则之间将元素移动
				if (comper(v[pos], obj) || v[pos] == obj)
					break;
				else
					v[pos + 1] = v[pos];
			}

			v[pos + 1] = obj;
		}
	}
};
/*******************直接插入排序---end************************/