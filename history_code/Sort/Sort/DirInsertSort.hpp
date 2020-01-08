#pragma once
#include "Common.h"

/*****************ֱ�Ӳ�������---begin************************/
template<class T, class Com = Greater<T> >
class DirInsertSort	
{
public:
	void Sort(std::vector<T>& v)
	{
		for (int i = 1; i < static_cast<int>(v.size()); ++i)
		{
			T obj = v[i];	//�Ƚ�Ҫ��������ݱ�������
			int pos = 0;
			Com comper;
			/*		����Ѱ��λ�õķ�ʽ��ʮ�ִ�ģ���
			while (pos < i && comper(v[i], v[pos]))
				pos++;
			if(pos == i)
				continue;	//�ҵ��ĺ���λ�ü����ǵ�ǰλ��

			for (int j = i; i > pos; --i)
			{
				std::swap(v[i], v[i - 1]);
			}
			*/

			for (pos = i - 1; pos >= 0; --pos)
			{	//�Ӻ��濪ʼ�ң���������������֮�佫Ԫ���ƶ�
				if (comper(v[pos], obj) || v[pos] == obj)
					break;
				else
					v[pos + 1] = v[pos];
			}

			v[pos + 1] = obj;
		}
	}
};
/*******************ֱ�Ӳ�������---end************************/