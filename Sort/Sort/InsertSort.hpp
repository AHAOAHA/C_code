#pragma once
#include <vector>

class InsertSort
{
public:
	void Sort(std::vector<int>& v)
	{
		for (int i = 0; i < static_cast<int>(v.size()); ++i)
		{
			int obj = v[i];	//先将要插入的数据保存起来
			int pos = 0;
			while (pos < i && v[pos] < v[i])
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