#include"StackOnly.h"
#include"HeapOnly.h"
int main()
{
	HeapOnly* p = HeapOnly::GetObj();
	StackOnly obj;
	return 0;
}