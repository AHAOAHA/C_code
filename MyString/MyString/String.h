#pragma once
# define _CRT_SECURE_NO_WARNINGS 1
#include<string.h>
namespace AHAOAHA
{
	template<class T>
	void swap(T& ptr1, T& ptr2)
	{
		T tmp = ptr1;
		ptr1 = ptr2;
		ptr2 = tmp;
	}
	
	class String
	{
	public:
		String(const char* str = "")
		{
			if (str == nullptr)
			{
				_str = new char[1];
				*_str = '\0';
				_capacity = 0;
				_size = 0;
			}
			else
			{
				_str = new char[strlen(str) + 1];
				strcpy(_str, str);
				_capacity = strlen(str);
				_size = strlen(str);
			}
		}
		String(const String& s)
		{
			_capacity = s._capacity;
			_size = s._size;
			_str = new char[_capacity + 1];
			strcpy(_str, s._str);
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
		char operator[](size_t pos);
		const char operator[](size_t pos)const;
		String& operator+=(const String& s);
		String& operator+=(const char* pstr);
		String& operator+=(const char ch);

		
		static const size_t npos;
	private:


		char* _str;
		size_t _size;
		size_t _capacity;
	};
}

