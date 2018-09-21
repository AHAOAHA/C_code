#include<malloc.h>
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
	{}
	Vector(size_type n, value_type value)//第一个参数代表要存放数据数量，第二个参数表示要存放的值
	{
		//申请空间并安装好迭代器
		ApplySpace(sizeof(value_type)*n);

		//放入数据
		iterator ptr = _start;
		while (n--)
		{
			*ptr++ = value;
		}
	}
	Vector(iterator start, iterator end)//数组的头和尾，前闭后开
	{
		//申请空间
		ApplySpace((end - start)*sizeof(value_type));

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
		//申请空间
		ApplySpace(sizeof(v)-sizeof(size_type));

		//放入数据

	}
	const iterator begin()const
	{
		return this->_start;
	}
	const iterator end()const
	{
		return this->end;
	}
	const iterator finish()const
	{
		return this->_finish;
	}

	void ApplySpace(size_t size)//申请空间
	{
		//申请空间
		iterator ptr = (iterator)malloc(size + sizeof(size_type));
		size_type* ptr_size = (size_type*)ptr;
		//安装迭代器
		_start = (iterator)((char*)ptr + sizeof(size_type));
		_end = (iterator)((char*)_start + size);
		_finish = _end;

		//修改内存最开始的记录字节
		*(size_type*)ptr_size = size / sizeof(value_type);
	}

	void InsertPop(value_type value);//尾插
	//~Vector();//析构函数
private:
	iterator _start;//表示目前使用空间的头
	iterator _finish;//表示目前使用空间的尾
	iterator _end;//表示目前可用空间的尾

};