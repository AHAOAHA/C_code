#pragma once
#include <vector>
#include <iostream>

template<class T>
struct Greater
{
	bool operator()(const T& child, const T& parent)
	{
		return child > parent;
	}
};

template<class T>
struct Lesser
{
	bool operator()(const T& child, const T& parent)
	{
		return child < parent;
	}
};