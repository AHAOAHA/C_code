#pragma once
#include "Common.h"

/*****************ֱ�Ӳ�������---begin************************/
template<class T, class Com = Greater<T> >
class DirInsertSort	
{
public:
	void Sort(std::vector<T>& v)
	{
		for (int i = 0; i < static_cast<int>(v.size()); ++i)
		{
			T obj = v[i];	//�Ƚ�Ҫ��������ݱ�������
			int pos = 0;
			Com comper;
			while (pos < i && comper(v[i], v[pos]))
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
/*******************ֱ�Ӳ�������---end************************/