#include<string>
#include<iostream>
using namespace std;
#if 0
int main()
{
	string s;
	char buf[1024] = { 0 };
	fgets(buf, sizeof(buf) - 1, stdin);
	buf[strlen(buf) - 1] = '\0';
	cout << buf << endl;
	s = buf;
	cout << s << endl;
	return 0;
}
#endif