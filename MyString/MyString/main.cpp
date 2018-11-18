#include "String.h"
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#if 1
int main()
{
	AHAOAHA::String s1;
	AHAOAHA::String s2("world");
	s1 = "hello";
	s1.append(" world");
	size_t pos = s1.find("or");
	s1.erase(pos, 2);
	s1.erase(3);
	std::cout << s1 << std::endl;
		
	return 0;
}
#endif