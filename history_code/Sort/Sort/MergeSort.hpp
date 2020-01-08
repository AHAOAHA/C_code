#pragma once
#include "Common.h"

template<class T, class Com = Greater<T>>
class MergeSort
{
public:
	//�ϲ�������������
	void Merge(std::vector<T>& v, int L, int M, int R)
	{
		Com comper;
		int left_size = M - L + 1;	//	ȷ����ߵ�����Ĵ�С
		int right_size = R - M;	//ȷ���ұߵ�����Ĵ�С
		int left_index = 0, right_index = 0;
		std::vector<T> v_lhs;
		std::vector<T> v_rhs;

		//��ԭ������Ϊ�����Ѿ��ź��������
		for(left_index = L; left_index < M + 1; ++left_index)
		{
			//������ߵ�Ԫ��
			v_lhs.push_back(v[left_index]);
		}

		for(right_index = M  + 1; right_index < R + 1; ++right_index)
		{
			//�����ұߵ�����
			v_rhs.push_back(v[right_index]);
		}

		left_index = 0;
		right_index = 0;
		int k = L;

		while(left_index < left_size && right_index < right_size)
		{
			//���ֿ�����������������кϲ���д��ԭ����
			if(comper(v_rhs[right_index], v_lhs[left_index]))
			{
				v[k] = v_lhs[left_index];
				left_index++;
				k++;
			}
			else
			{
				v[k] = v_rhs[right_index];
				right_index++;
				k++;
			}
		}

		//����ʣ��Ԫ��
		while(left_index < left_size)
		{
			v[k] = v_lhs[left_index];
			left_index++;
			k++;
		}

		while(right_index < right_size)
		{
			v[k] = v_rhs[right_index];
			right_index++;
			k++;
		}
	}

	//���з���
	void _MergeSort(std::vector<T>& v, int L, int R)
	{
		if (L == R)
			return;
		int M = (L + R) / 2;
		_MergeSort(v, L, M);
		_MergeSort(v, M + 1, R);
		Merge(v, L, M, R);
	}
};