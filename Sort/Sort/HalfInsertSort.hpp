#include "Common.h"

/********************�۰��������---begin*********************/

/*����˼����ֱ�Ӳ������˼�����ƣ�������Ѱ��Ҫ����λ��ʱ�����ö��ֲ���*/
template<class T, class Com = Greater<T>>
class HalfInsertSort
{
public:
	void Sort(std::vector<T>& v)
	{
		for (int i = 0; i < v.size(); ++i)
		{
			T obj = v[i];
			int pos = 0;
			pos = GetInsertPos(v, i);
			if (pos == i)
				continue;

			for (int j = i; i > pos; --j)
			{
				std::swap(v[i], v[i - 1]);
			}

			v[pos] = obj;
		}
	}
private:
	//�۰����Ѱ��λ��
	size_t GetInsertPos(const std::vector<T>& v, const T& obj, int pos)
	{
		int left = 0;
		int right = pos;
		Com comper;
		int middle = 0;
		while (left < right)
		{
			middle = (left + right) >> 1;
			if (comper(v[middle], obj))
			{
				if (v[middle] > obj)
					right = middle - 1;
				else
					left = middle + 1;

			}
			else
			{
				if (v[middle] > obj)
					left = middle + 1;
				else
					right = middle - 1;
			}
		}

		return middle;
	}
};

/********************�۰��������---end***********************/