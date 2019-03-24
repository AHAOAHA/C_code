#if 0
#include <iostream>

class Base
{
public:
	void Func()
	{
		std::cout << "Test::Base" << std::endl;
	}
};

class Derive :public Base
{
public:
	void Func()
	{
		std::cout << "Test::Derive" << std::endl;
	}
};

int main()
{
	int a = 0;
	a++;
	return 0;
}
#endif

#if 0
#include "Test.h"
//#include "test.cpp"

int main()
{
	Test<int>(3);
	return 0;
}
#endif

#if 0
#include <string>
#include <stack>
#include <iostream>
class Parenthesis {
public:
	bool chkParenthesis(std::string A, int n) {
		// write code here
		std::stack<char> st;
		for (size_t i = 0; i < A.size(); ++i)
		{
			if (A[i] != '(' && A[i] != ')')
				return false;

			if (A[i] == '(')
			{
				st.push(A[i]);
			}
			if (A[i] == ')' && st.empty())
			{
				return false;
			}

			if (A[i] == ')' && !st.empty())
			{
				st.pop();
			}
		}

		if (st.empty())
			return true;
		return false;
	}
};

int main()
{
	Parenthesis test;
	std::string str("(()())");
	bool ret = test.chkParenthesis(str, 6);
	LONGLONG_MIN;
	return 0;
}
#endif

#if 0
#include <iostream>

void BegerAndSamllerFib(const long long int& num, long long int& biger, long long int& smaller)
{
	long long int first = 1;
	long long int second = 1;
	long long int third = num - 1;
	while (third < num)
	{
		third = first + second;
		first = second;
		second = third;
	}

	biger = third;
	smaller = first;
}

int main()
{
	long long int biger = 0;
	long long int smaller = 0;
	long long int num = 0;
	while (std::cin >> num)
	{
		BegerAndSamllerFib(num, biger, smaller);
		long long int minstep = 0;
		minstep = (biger - num) > (num - smaller) ? (num - smaller) : (biger - num);
		std::cout << minstep << std::endl;
	}

	return 0;
}
#endif
#if 0

#include <vector>
#include <string>
#include <string.h>
#include <iostream>

bool IsOfDir(const std::vector<std::string>& str_v)
{
	//ÅÐ¶ÏÊÇ·ñ¸ù¾Ý×ÖµäÅÅÐò
	for (size_t i = 0; i < str_v.size() - 1; ++i)
	{
		for (size_t j = i + 1; j < str_v.size(); ++j)
		{
			if (strcmp(str_v[i].c_str(), str_v[j].c_str()) > 0)
				return false;
		}
	}
	return true;
}

bool IsOfLen(const std::vector<std::string>& str_v)
{
	//ÅÐ¶ÏÊÇ·ñ¸ù¾Ý³¤¶ÈÅÅÐò
	for (size_t i = 0; i < str_v.size() - 1; ++i)
	{
		for (size_t j = i + 1; j < str_v.size(); ++j)
		{
			if (str_v[j].length() < str_v[i].length())
				return false;
		}
	}
	return true;
}

int main()
{
	size_t str_num = 0;    //×Ö·û´®¸öÊý
	while (std::cin >> str_num)
	{
		if (str_num == 0)
			return -1;
		std::vector<std::string> str_v;    //´æ´¢×Ö·û´®µÄvector
		for (size_t i = 0; i < str_num; ++i)
		{
			std::string tmp;
			std::cin >> tmp;
			str_v.push_back(tmp);
		}
		bool is_of_dir = IsOfDir(str_v);
		bool is_of_len = IsOfLen(str_v);
		if (is_of_dir == true && is_of_len == false)
		{
			std::cout << "lexicographically" << std::endl;
			continue;
		}
		else if (is_of_dir == false && is_of_len == true)
		{
			std::cout << "lengths" << std::endl;
			continue;
		}
		else if (is_of_dir == true && is_of_len == true)
		{
			std::cout << "both" << std::endl;
			continue;
		}
		else if (is_of_dir == false && is_of_len == false)
		{
			std::cout << "none" << std::endl;
			continue;
		}
	}
	return 0;
}
#endif
#if 0
#include <iostream>
class Test1
{
public:
	int _t;
};
class Test2
{
public:
	int _t;
};

int main()
{
	const int a = 3;
	int* p = const_cast<int*>(&a);
	int& ra = const_cast<int&>(a);
	ra = 5;
	
	return 0;
}
#endif
#if 0
#include "Test.h"
#include <iostream>

class Test
{
public:
	static void func()
	{
		std::cout << "func" << std::endl;
	}
};

class Derive : public Test
{
public:

};

int main()
{
	//std::vector<int> v;
	//func(v);
	Derive::func();
	return 0;
}
#endif

#include <iostream>
using std::endl;
using std::cout;
class Test
{
public:
	inline void func()
	{
	


	}
};

inline void func1()
{}

int main()
{
	Test t;
	cout << func1 << endl;
	//char a2[1048567];
	//char a3[1048567];
	//char a4[1048567];
	//char a5[1048567];
	//char a6[1048567];
	//char a7[1048567];
	//char a8[1048567];
	return 0;
}