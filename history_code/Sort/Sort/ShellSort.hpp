#pragma once
#include "Common.h"

/******************ϣ������---begin*********************/
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
			//��ÿһ�����ֱ�Ӳ�������
			if (gap == 1)
				break;
		}
	}
private:
	void DirInsertSort(std::vector<T>& v, const int& size, const int& gap)
	{
		//��ÿ��gap����ֱ�Ӳ�������
		Com comper;
		for (int i = gap; i < size; ++i)	//��gap��λ�ÿ�ʼ��һֱ�����һ��ԪΪֹ
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
/******************ϣ������---end***********************/