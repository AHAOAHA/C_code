#include"Vector.h"
int main()
{
	int array[3] = { 1, 2, 3 };
	Vector<int> v(array, array+3);
	return 0;
}