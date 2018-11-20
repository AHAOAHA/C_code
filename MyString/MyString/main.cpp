#include "String.h"
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#if 1
int main()
{
	AHAOAHA::String s("hello world");
	for (auto& c : s)
	{
		std::cout << c;
	}
	std::cout << std::endl;
		
	for (auto it = s.rbegin(); it != s.rend(); --it)//标准逆向迭代器为++
	{
		std::cout << *it;
	}
	std::cout << std::endl;
	return 0;
}
#endif

#if 0
int main()
{
	std::string s("hello world");
	for (auto it = s.rbegin(); it != s.rend(); ++it)
	{
		std::cout << *it;
	}
	std::cout << std::endl;
	return 0;
}
#endif