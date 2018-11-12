#include<string>

using namespace std;
#if 1
int main()
{
	const char* str = "hello";
	string s1(str);
	s1.reserve(100);
	system("pause");
	return 0;
}
#endif