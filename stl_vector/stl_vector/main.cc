#include"Vector.hpp"
#include<vector>
#include<iostream>

#if 1
int main()
{
	int array[5] = { 0 };
	AHAOAHA::Vector<int> v0(6,1);
	//AHAOAHA::Vector<int> v1(array, array + 5);
	//AHAOAHA::Vector<int> v2(6, 1);
	//AHAOAHA::Vector<int> v3(6);
	//v0.resize(100);
	//v0.reserve(100);
	v0.insert(v0.begin(), 4);
	v0.pushback(5);
	size_t count = 0;
	for (const auto& e : v0)
	{
		count++;
		std::cout << e << " ";
	}
	std::cout << count << std::endl;
	return 0;
}

#endif

#if 0
int main()
{
	int array[1] = { 0 };
	std::vector<int> v1(array, array+1);
	std::vector<int> v2(6, 1);
	std::vector<int> v3(8);
	std::cout << v1.capacity() << std::endl;
	std::cout << v2.capacity() << " " << v2.size() << std::endl;
	std::cout << v3.capacity() << " " << v3.size() << std::endl;
	return 0;
}
#endif