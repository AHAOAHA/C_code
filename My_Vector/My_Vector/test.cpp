#include"Vector.hpp"
using namespace std;
int main()
{
	int arr[3] = { 12, 13, 14 };
	Vector<int> v1(3,1);
	v1.insert(0, arr, arr + 3);
	v1.earse(0,3);
	return 0;
}