#pragma once
# define _CRT_SECURE_NO_WARNINGS 1
#include<string.h>
#include<assert.h>
#include<iostream>
namespace AHAOAHA
{

	class String
	{
		typedef char* iterator;
		typedef char* reverse_iterator;
		typedef const char* const_iterator;
		typedef const char* reverse_const_iterator;
	public:
		friend std::ostream& operator<<(std::ostream& out, const String& s);
		friend std::istream& operator>>(std::istream& in, const String& s);
		//为什么不能string s()这样构造字符串？
		String(const char* str = "")
		{
			assert(str);
			_size = strlen(str);
			if(_size <= 15)
			{
				_capacity = 15;
				_str = new char[_capacity + 1];
				strcpy(_str, str);
			}
			else
			{
				_capacity = _size;
				_str = new char[_capacity + 1];
				strcpy(_str, str);
			}
		}
		String(const String& s)
			:_str(nullptr)
		{
			String tmp(s._str);
			Swap(tmp);
		}
		String(const char ch)
		{
			char str[2] = { '\0' };
			str[0] = ch;
			String tmp(str);
			this->Swap(tmp);
		}
		String& operator=(const String& s);
		String& operator=(const char* pstr);
		String& operator=(const char ch);
		~String()
		{
			delete[] _str;
			_capacity = 0;
			_size = 0;
		}
		String& append(const String& s);
		String& append(const char* pstr);
		void push_back(const char ch);
		String& insert(size_t pos, const String& s);
		String& erase(size_t pos = 0, size_t len = npos);
		void reserve(const size_t n);
		void resize(const size_t n);
		const char* c_str()const
		{
			return _str;
		}
		const size_t size()const
		{
			return _size;
		}
		const size_t capacity()const
		{
			return _capacity;
		}
		const bool empty()const;
		size_t find(const String& s, size_t pos = 0)const;
		size_t find(const char ch, size_t pos = 0)const;
		size_t find(const char *s, size_t pos = 0)const;
		size_t rfind(const String& s, size_t pos = 0)const;
		char& operator[](size_t pos);
		const char& operator[](size_t pos)const;
		String& operator+=(const String& s);
		String& operator+=(const char* pstr);
		String& operator+=(const char ch);
		String Substr(size_t pos = 0, size_t len = npos);
		void Swap(String& s);

		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		const_iterator cbegin()const
		{
			return _str;
		}
		const_iterator cend()const
		{
			return _str + _size;
		}
		reverse_iterator rbegin()
		{
			return _str + _size - 1;
		}
		reverse_iterator rend()
		{
			return _str - 1;
		}
		reverse_const_iterator crbegin()const
		{
			return _str + _size - 1;
		}
		reverse_const_iterator crend()const
		{
			return _str - 1;
		}
		static const size_t npos;

	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
}

