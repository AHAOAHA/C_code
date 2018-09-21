#include"Array.hpp"
#include<array>
#include<stdio.h>
using namespace std;
int main()
{
	Array<int, 3> arr1;
	Array<int, 3> arr2;
	arr1.fill(3);
	arr2.fill(1);
	printf("%d %d %d\n", arr1[0], arr1[1], arr1[2]);
	printf("%d %d %d\n", arr2[0], arr2[1], arr2[2]);
	arr1.swap(arr2);
	printf("%d %d %d\n", arr1[0], arr1[1], arr1[2]);
	printf("%d %d %d\n", arr2[0], arr2[1], arr2[2]);
	return 0;
}