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
	//判断是否根据字典排序
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
	//判断是否根据长度排序
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
	size_t str_num = 0;    //字符串个数
	while (std::cin >> str_num)
	{
		if (str_num == 0)
			return -1;
		std::vector<std::string> str_v;    //存储字符串的vector
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
#if 0
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
#endif

#if 0

#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<assert.h>
#include<string.h>


class String
{
public:
	//增容
	void Reserve(size_t newcapacity)
	{
		if (newcapacity > _capacity) {
			char* str = new char[newcapacity + 1];
			strcpy(str, _str);
			delete[] _str;
			_str = str;
			_capacity = newcapacity;
		}
	}
	typedef char* Iterator;
	typedef char* const_Iterator;
	//全缺省，缺省值为" "
	String(const char* str = " ")  //构造
		:_size(strlen(str))
		, _capacity(_size)
		, _str(new char[_size + 1])
	{
		strcpy(_str, str);
	}
	//拷贝构造，现代写法

	String(const String &s)
		:_str(nullptr)
		, _size(0)
		, _capacity(0)
	{
		String tmp(s._str);
		Swap(tmp);
	}
	//赋值运算符重载
	//现代写法
	String& operator=(String s) {
		Swap(s);
		return *this;
	}

	char& operator[](size_t n) {
		assert(n < _size);
		return _str[n];
	}
	const char& operator[](size_t n)const
	{
		assert(n < _size);
		return _str[n];
	}
	void Swap(String & tmp)
	{
		swap(_str, tmp._str);
		swap(_size, tmp._size);
		swap(_capacity, tmp._capacity);
	}


	~String()
	{
		if (_str) {
			delete[] _str;
			_str = nullptr;
		}
	}



	//后插
	void PushBack(char c)
	{

		if (_size == _capacity) {

			size_t newc = (_capacity == 0 ? 15 : _capacity * 2);
			Reserve(newc);
		}
		_str[_size++] = c;
		_str[_size] = '\0';
	}

	//Iterator
	Iterator begin()
	{
		return _str;
	}
	Iterator end()
	{
		return _str + _size;
	}
	const Iterator begin()const
	{
		return _str;
	}
	const Iterator end()const
	{
		return _str + _size;
	}
	void Popback()
	{
		assert(_size > 0);

	}
	size_t Size()
	{
		return _size;
	}
	size_t Capacity()
	{
		return _capacity;
	}


	//尾插
	void Append(const char* str) {
		size_t sz = _capacity < strlen(str);
		if (sz + _size)
		{
			Reserve(sz + _size);
		}
		strcpy(_str + _size, str);
		_size += sz;
	}
	void Resize(size_t n, char c = '\0')
	{

		//n>_capacity 需要增容 给增容的空间赋值为c
		//n>_size 给增容的空间赋值为c
		if (n > _capacity)
		{
			Reserve(n);
		}
		if (n > _size) {
			memset(_str + _size, c, n - _size);
		}
		_size = n;
		_str[_size] = '\0';


		//_size=n _[_size]='\0'
	}
	//在pos位置插入字符c
	void Insert(size_t pos, const char c)
	{
		assert(_size > pos);
		if (_size == _capacity)
		{
			//增容
			size_t newc = (_capacity == 0 ? 15 : _capacity * 2);
			this->Reserve(newc);
		}
		size_t end = ++_size;
		while (end > pos)
		{
			//从后向前挪动
			_str[end] = _str[end - 1];
			--end;
		}
		_str[pos] = c;
		_str[_size] = '\0';


	}
	//插入字符串
	void Insert(size_t pos, const char* str)
	{
		assert(pos < _size);
		size_t len = strlen(str);
		if (_capacity < _size + len) {
			//size_t newc = (_capacity == 0 ? len + 1 : len + _size);
			Reserve(len + _size);
		}
		//从后向前挪动数据
		size_t end = _size + len;
		while (end > pos + len - 1) {
			//第一个挪动的为'\0'
			_str[end] = _str[end - len];
			--end;
		}
		//从pos位置拷贝str
		for (int i = 0; i < len; i++) {
			_str[i + pos] = str[i];
		}
		_size += len;
	}

	void Erase(size_t pos, size_t len)
	{
		assert(pos < _size);
		//从pos开始的字符全都被删除
		if (pos + len > _size) {
			_size = pos;
			_str[_size] = '\0';
		}
		else
		{
			size_t start = pos + len;
			//以pos+len位置开始一个一个向前挪动len个位置
			while (start < _size) {
				_str[pos++] = _str[start++];
			}
			_size -= len;
			_str[_size] = '\0';
		}
	}
	friend ostream& operator<<(ostream& _cout, const String &s);
private:
	size_t _size;  //有效字符长度，不含‘\0’
	size_t _capacity; //实际能存放的最大字符数 不含‘\0’,实际申请的空间少一个字节
	char * _str;
};
ostream& operator<<(ostream& _cout, const String &s)
{
	for (auto&e : s)
	{
		_cout << e << " ";
	}
	return _cout;
}

int main()
{
	String s;
	s.PushBack('a');
	s.PushBack('b');
	s.PushBack('c');
	s.PushBack('d');
	cout << s << endl;  //a b c d
	s.Insert(2, 'a');
	s.Insert(5, 'e');
	s.Insert(2, 't');
	s.Insert(3, 'p');   //a b  t  t a c d e
	cout << s << endl;
	system("pause");
	return 0;
}
#endif
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
#if 0

void DeBugTest(std::vector<std::vector<int>> &v)
{
	for (auto & e : v)
	{
		for (auto & c : e)
		{
			cout << c << " ";
		}
		cout << endl;
	}
}

int main()
{
	std::vector<std::vector<int> > map;
	int row = 0;
	int col = 0;
	while (cin >> row)
	{
		cin >> col;
		for (size_t i = 0; i < col; ++i)
		{
			std::vector<int> v;
			map.push_back(v);
			for (size_t j = 0; j < row; ++j)
			{
				int tmp;
				cin >> tmp;
				map[i].push_back(tmp);
			}
		}    //地图接收完毕

		DeBugTest(map);

	}
	return 0;
}
#endif

#if 0

#define  test "hello"##"world"
#define min(a, b) ((a)>(b)?b:a)
#undef test


void func(int arr[3][5])
{}

int main()
{

	int arr[5][3];
	func(arr);
	int a = 3;
	int b = 5;
	min(a, b);
	return 0;
}
#endif

#if 0

#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

int MaxGrpNum(std::vector<int> grp)
{
	int max = 0;
	for (int i = grp.size() - 1; i >= 0; --i)
	{
		if (i == 3)
		{
			max += grp[i];
			grp[i] = 0;
		}
		else if (i == 2)
		{
			//计算3和1可以组成几个4
			//int num = 0;
			if (grp[0] > grp[i])
			{
				//3较少
				max += grp[i];
				grp[i] = 0;
				grp[0] -= grp[i];
			}
			else
			{
				//3和1一样多；3较多
				max += grp[0];
				grp[0] = 0;
				grp[i] -= grp[0];
			}
		}
		else if (i == 1)
		{
			//2
			if(grp[i] > 2)
			{
				//大于2
				if(grp[i]%2 == 0)
				{
					max += grp[i] / 2;
					grp[i] = 0;
				}
				else
				{
					max += grp[i] / 2;
					grp[i] = 1;
					if (grp[0] >= 2)
					{
						max += 1;
						grp[0] -= 2;
					}
				}
			}
			else
			{
				//小于2
			}
		}
		else
		{
			//1
			if (grp[i] > 4)
			{
				max += (grp[i] / 4);
				grp[i] = grp[i] % 4;
			}
			else
			{
				//NOTHING TODO
			}
		}
	}
	return max;
}

int main()
{
	//v[0]单人 v[1]双人 v[2]三人 v[3]四人
	int grp_num = 0;
	while (cin >> grp_num)
	{
		std::vector<int> grp;
		for (size_t j = 0; j < static_cast<size_t>(grp_num); ++j)
		{
			for (size_t i = 0; i < 4; ++i)
			{
				int tmp;
				cin >> tmp;
				grp.push_back(tmp);
			}	//组数接收完毕

			int max_num = MaxGrpNum(grp);
			grp.resize(0);
			cout << max_num << endl;
		}
	}
	return 0;
}
#endif

#if 0

int main()
{
	int a = 3, b = 5;
	auto lamber_swap = [&a, &b]()mutable{int tmp = a; a = b; b = tmp; };
	lamber_swap();
	return 0;
	move
}

#endif

#if 0

#include <iostream>
#include <unordered_set>
#include <vector>
using std::cout;
using std::endl;
using std::cin;


int main()
{
	std::unordered_set<char> uos;
	char ch;
	bool is_o = false;
	while ()
	{
		if (ch == ',')
			continue;
		if (is_o == false)
		{
			if (ch == '\n')
			{
				//一次测试用例完成
				uos.clear();
				cout << "false" << endl;
			}
			auto it = uos.find(ch);
			if (it == uos.end())
			{
				//目前无重合数据，插入
				uos.insert(ch);
			}
			else
			{
				//有重合数据则带环 结束一次测试用例
				is_o = true;
				cout << "true" << endl;
				uos.clear();
			}
		}
		else
		{
			if (ch == '\n')
			{
				is_o = false;
				uos.clear();
			}
		}
	}
	return 0;
}
#endif
#if 0
#include <string>

std::string Test()
{
	std::string s = "hello";
	return s;
}

int main()
{
	std::string&& rs = Test();
	rs.clear();
	return 0;
}
#endif

#if 0
#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	std::vector<int> v = { 3,2,1 };
	do{
		for (auto &e : v)
		{
			std::cout << e << " ";
		}
		std::cout << std::endl;
	} while (prev_permutation(v.begin(), v.end()));
	return 0;
}
#endif
#include "Test.h"
int main()
{
	AHAOAHA::test();
	return 0;
}