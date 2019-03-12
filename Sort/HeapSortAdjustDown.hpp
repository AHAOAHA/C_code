/*************************************************************************
*File Name: HeapSort.cpp
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: Mon 04 Mar 2019 07:10:50 PM CST
 ************************************************************************/
#pragma once
#include "Common.h"


void _AdjustDown(std::vector<int>& v, size_t parent, size_t len)
{
	size_t l_chr = parent * 2 + 1;  //计算出左孩子的长度
	while (l_chr <= len)
	{
		size_t r_chr = l_chr + 1; //右孩子下标
		size_t biger_chr = l_chr;
		if (r_chr <= len)
		{
			biger_chr = v[l_chr] > v[r_chr] ? l_chr : r_chr;
		}
		if (v[parent] < v[biger_chr])
		{
			std::swap(v[parent], v[biger_chr]);
			parent = biger_chr;
			l_chr = l_chr * 2 + 1;
		}
		else
			break;
	}
}

void AdjustDown(std::vector<int>& v, int len)
{
	int parent = (len - 1) / 2;
	for (parent; parent >= 0; --parent)
	{
		_AdjustDown(v, parent, len);
	}
}



