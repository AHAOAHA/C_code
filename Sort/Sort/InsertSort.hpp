#pragma once
#include <vector>

class InsertSort
{
public:
	void Sort(std::vector<int>& v)
	{
		for (int i = 0; i < static_cast<int>(v.size()); ++i)
		{
			int obj = v[i];	//�Ƚ�Ҫ��������ݱ�������
			int pos = 0;
			while (pos < i && v[pos] < v[i])
				pos++;
			if(pos == i)
				continue;	//�ҵ��ĺ���λ�ü����ǵ�ǰλ��

			for (int j = i; i > pos; --i)
			{
				std::swap(v[i], v[i - 1]);
			}

			v[pos] = obj;
		}
	}
};