#include<malloc.h>
#include<assert.h>
#include<stdio.h>
template<class T>
class Vector
{
	typedef int ptrdiff_t;
	//Vector的嵌套型别定义（参考vector源码）
	typedef T value_type;//存储的数据类型
	typedef value_type* pointer;//可以指向存储的数据的指针
	typedef value_type* iterator;//迭代器（与指针相同）
	typedef size_t size_type;//数据size的类型
	typedef value_type& reference;//数据的引用类型
	typedef ptrdiff_t difference_type;//表示两个迭代器之间的距离，C++内置定义typedef int ptrdiff_t;
public:
	Vector()//默认构造函数
		:_start(nullptr)
		, _finish(nullptr)
		, _end(nullptr)
		, _size(0)
		, _capacity(0)
	{}
	Vector(size_type n, value_type value)//第一个参数代表要存放数据数量，第二个参数表示要存放的值
	{
		//申请空间并安装好迭代器
		_size = n;
		_capacity = n;
		_start = new value_type[_capacity];
		assert(_start);
		_end = _start + _capacity;
		_finish = _start + _size;

		//放入数据
		iterator ptr = _start;
		while (n--)
		{
			*ptr++ = value;
		}
	}
	Vector(iterator start, iterator end)//数组的头和尾，前闭后开
	{
		//申请空间并安装好迭代器
		_capacity = end - start;
		_size = _capacity;
		_start = new value_type[_capacity];
		assert(_start);
		_end = _start + _capacity;
		_finish = _start + _size;

		//放入数据
		iterator ptr = _start;
		size_t i = 0;
		for (ptr = _start; (ptr + i) != _finish; ++i)
		{
			ptr[i] = start[i];
		}
	}
	Vector(Vector<T>& v)//拷贝构造函数
	{
		//申请空间并安装迭代器
		_capacity = v.capacity();
		_size = v.size();
		_start = new value_type[_capacity];
		assert(_start);
		_end = _start + _capacity;
		_finish = _start + _size;

		//放入数据
		iterator ptr = v.begin();
		iterator ptr_me = _start;
		size_type i = 0;
		while ((ptr + i) != v.end())
		{
			ptr_me[i] = ptr[i];
			i += 1;
		}
	}
	const size_type capacity()const
	{
		return this->_capacity;
	}
	const size_type size()const
	{
		return this->_size;
	}
	iterator begin()const
	{
		return this->_start;
	}
	const iterator cbegin()const
	{
		return this->_start;
	}
	iterator end()const
	{
		return this->_end;
	}
	const iterator cend()const
	{
		return this->_end;
	}
	iterator rbegin()const
	{
		return (_end - 1);
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
	const size_type max_size()const
	{
		return _capacity;
	}
	const bool empty()const
	{
		return _size == 0;
	}
	void resize(size_type size,value_type value = 0)
	{
		if (size <= _size)
			_size = size;
		else
		{
			while (((_start + _size) != (_start + size)) && ((_start + _size) != _end))
			{
				_start[_size] = value;
				_size += 1;
			}
			_size = size;
		}
	}
	void reserve(size_type capacity)
	{
		//判断新容量是否大于旧容量
		if (capacity <= _capacity)
			return;
		//保存旧空间信息
		size_type old_capacity = _capacity;
		size_type old_size = _size;
		iterator old_start = _start;
		iterator old_end = _end;
		iterator old_finish = _finish;

		//开辟新空间并安装迭代器
		_capacity = capacity;
		_start = new value_type[_capacity];
		_end = _start + _capacity;
		_finish = _start + _size;

		//复制旧空间的数据
		size_type i = 0;
		while (_start + i != _start + _size)
		{
			_start[i] = old_start[i];
			i += 1;
		}

		//释放旧空间
		delete[] old_start;
		old_start = nullptr;
		old_end = nullptr;
	}
	void InsertPop(value_type value);//尾插
	//~Vector();//析构函数
	const size_t at(value_type value)const
	{
		iterator = _start;
		size_t count = 0;
		while ((*(_start + count) != value) && (_start + count != end))
		{
			count += 1;
		}
		if ((_start + count) == _end)
			return -1;
		return count;
	}
	value_type front()const
	{
		return *_start;
	}
	value_type back()const
	{
		return *(_end - 1);
	}
	value_type operator[](size_type i)const
	{
		return *(_start + i);
	}
	void push_back(value_type value)
	{
		if (!has_space())
			reserve(_capacity * 2+1);
		*(_start + _size) = value;
		_size += 1;
	}
	void pop_back()
	{
		_size -= 1;
	}
	void insert(size_type pos, const value_type value)//固定位置插入单个数据
	{
		if (!has_space())
			reserve(_capacity * 2 + 1);
		if (pos >= _size)
		{
			printf("所插入位置之前还有空位置，将为您尾插入可使用的第一个位置!\n");
			push_back(value);
		}
		else
		{
			iterator ptr = _start + _size - 1;
			size_type num = _size - pos;
			while (num--)
			{
				move(ptr, ptr + 1);
			}
			*(_start + pos) = value;
		}
	}
	void insert(size_type pos, const size_type n, value_type value)//从固定位置向后插入固定数目的固定数据
	{
		//准备空间
		while ((_size + n) >= _capacity)
		{
			reserve(_capacity * 2 + 1);
		}

		//先将pos位置之后的所有数据存在另外的一块空间内
		size_type temp_size = _size - pos;
		iterator temp_start = new value_type[temp_size];
		iterator temp_end = temp_start + temp_size;
		size_t i = 0;
		while ((temp_start + i) != (temp_end))
		{
			temp_start[i] = _start[pos + i];
			i += 1;
		}

		//从真实空间的pos位置开始向后插入需要的数据
		size_t temp_n = n;
		while (temp_n--)
		{
			_start[pos] = value;
			_size += 1;
			pos += 1;
		}

		//将临时空间内的数据补齐
		i = 0;
		while ((temp_start + i) != temp_end)
		{
			_start[_size - n + i] = temp_start[i];
			i += 1;
		}

		//释放临时空间
		delete temp_start;
		temp_start = nullptr;
		temp_end = nullptr;
	}
	void insert(size_type pos, value_type* start, value_type* end)
	{
		//准备空间
		size_t size = end - start;
		while (_size + size >= _capacity)
		{
			reserve(_capacity * 2 + 1);
		}

		//用临时空间保存pos位置向后的数据
		size_type temp_size = _size - pos;
		iterator temp_start = new value_type[temp_size];
		iterator temp_end = temp_start + temp_size;
		size_t i = 0;
		while ((temp_start + i) != (temp_end))
		{
			temp_start[i] = _start[pos + i];
			i += 1;
		}

		//将要插入的数据进行插入
		size_t temp_pos = pos;
		while (start + temp_pos != end)
		{
			_start[temp_pos] = start[temp_pos];
			_size += 1;
			temp_pos += 1;
		}

		//将临时空间内的数据补齐
		i = 0;
		while ((temp_start + i) != temp_end)
		{
			_start[_size - size +i] = temp_start[i];
			i += 1;
		}

		//释放临时空间
		delete temp_start;
		temp_start = nullptr;
		temp_end = nullptr;

	}
	void swap(Vector<value_type>& v);//暂未实现
	void earse(size_t pos)//删除某一个数据
	{
		if (_size <= pos)
		{
			printf("%d位置没有数据！\n", pos);
			return;
		}
		while ((pos + 1) != _size)
		{
			move(_start + pos + 1, _start + pos);
			pos += 1;
		}
		_size -= 1;
	}
	void earse(size_t pos_start, size_t pos_end)//删除某一段数据(前闭后开)
	{
		if (pos_start > pos_end)
			assert(0);
		else if (pos_start == pos_end)
		{
			earse(pos_start);
			return;
		}

		if (pos_start >= _size)
		{
			printf("所选区域不存在数据！\n");
			return;
		}

		if (pos_end >= _size - 1)
		{
			_size = _size - (pos_end - pos_start);
		}
		else
		{
			size_t pos_temp_end = pos_end;
			while ((_start + pos_temp_end ) != (_start + _size))
			{
				move(_start + pos_temp_end , _start + pos_temp_end - (pos_end - pos_start));
				pos_temp_end += 1;
			}
			_size = _size - (pos_end - pos_start);
		}
	}
protected:
	const bool has_space()const
	{
		return _size != _capacity;
	}
	void move(const iterator pos1, iterator pos2)
	{
		*pos2 = *pos1;
	}

private:
	iterator _start;//表示目前使用空间的头
	iterator _finish;//表示目前使用空间的尾
	iterator _end;//表示目前可用空间的尾
	size_type _capacity;//表示所维护的空间总的容量
	size_type _size;//表示已经使用容量的大小
};