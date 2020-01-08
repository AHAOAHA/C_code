#pragma once
#include<malloc.h>
template<class T,size_t N>
class Array
{
	typedef T value_type;
	typedef size_t size_type;
	typedef value_type* iterator;
public:
	Array()//构造函数
	{
		char* ptr = (char*)malloc(N*sizeof(value_type));
		_start = (iterator)(ptr + 2 * sizeof(size_type));
		_end = _start + N;
		_finish = _start;
	}
	void fill(value_type value)//用一个数字充满所有空间
	{
		iterator ptr = _start;
		size_type* _size = (size_type*)((char*)_start - sizeof(size_type));
		*_size = N;
		while (ptr != _end)
		{
			*ptr = value;
			ptr += 1;
		}
	}
	value_type& operator[](size_type num)const
	{
		return *(_start + num);
	}
	value_type& front()const
	{
		return *_start;
	}
	value_type& back()const
	{
		return *(_finish-1);
	}
	iterator begin()const
	{
		return _start;
	}
	const iterator cbegin()const
	{
		return _start;
	}
	iterator end()const
	{
		return _end;
	}
	const iterator cend()const
	{
		return _end;
	}
	iterator rbegin()const
	{
		return (_end-1);
	}
	const iterator crbegin()const
	{
		return (_end - 1);
	}
	iterator rend()const
	{
		return _start;
	}
	const iterator crend()const
	{
		return _start;
	}

	size_type size()const
	{
		return *(((size_type*)_start) - 1);
	}
	size_type max_size()const
	{
		return *(((size_type*)_start) - 2);
	}

	bool empty()const
	{
		return size() == 0;
	}

	void swap(Array<value_type, N>& arr)
	{
		iterator ptr = _start;
		size_type i = 0;
		size_type* p_ls = ((size_type*)_start) - 1;
		size_type* p_rl = ((size_type*)arr.begin() - 1);
		while ((ptr+i) != _end)
		{
			Swap(ptr + i, arr.begin() + i);
			i += 1;
		}
		i = *p_ls;
		*p_ls = *p_rl;
		*p_rl = i;
	}



	~Array()//析构函数
	{
		free(((char*)_start) - 2 * sizeof(size_type));
		_start = nullptr;
		_end = nullptr;
		_finish = nullptr;
	}
private:
	void Swap(iterator l, iterator r)
	{
		value_type temp = *l;
		*l = *r;
		*r = temp;
	}
	iterator _start;
	iterator _finish;
	iterator _end;
};