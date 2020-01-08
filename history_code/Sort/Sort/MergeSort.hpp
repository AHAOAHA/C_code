#pragma once
#include "Common.h"

template<class T, class Com = Greater<T>>
class MergeSort
{
public:
	//合并两个有序数组
	void Merge(std::vector<T>& v, int L, int M, int R)
	{
		Com comper;
		int left_size = M - L + 1;	//	确定左边的数组的大小
		int right_size = R - M;	//确定右边的数组的大小
		int left_index = 0, right_index = 0;
		std::vector<T> v_lhs;
		std::vector<T> v_rhs;

		//将原数组拆分为两个已经排好序的数组
		for(left_index = L; left_index < M + 1; ++left_index)
		{
			//搬移左边的元素
			v_lhs.push_back(v[left_index]);
		}

		for(right_index = M  + 1; right_index < R + 1; ++right_index)
		{
			//搬移右边的数组
			v_rhs.push_back(v[right_index]);
		}

		left_index = 0;
		right_index = 0;
		int k = L;

		while(left_index < left_size && right_index < right_size)
		{
			//将分开的两个有序数组进行合并并写入原数组
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

		//搬移剩余元素
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

	//进行分治
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