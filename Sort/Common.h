#pragma once
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <vector>
#include <algorithm>
inline void PrintArr(const std::vector<int>& v)
{
	for (auto& e : v)
	{
		cout << e << "  ";
	}
	cout << endl;
}