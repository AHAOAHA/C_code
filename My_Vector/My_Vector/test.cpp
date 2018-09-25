#include"Vector.hpp"
using namespace std;
int main()
{
	Vector<int> v1(3,1);
	Vector<int> v2(3, 3);
	printf("%d  %d\n", v1[1], v2[2]);
	v1.swap(v2);
	printf("%d  %d\n", v1[1],v2[2]);
	return 0;
}