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
#include<vector>
#include<string>
int main()
{
	std::vector<std::string> v;
	v.push_back("ahah");
	v.push_back("w");
	std::vector<std::string> v2(v.begin(), v.end());
	return 0;
}