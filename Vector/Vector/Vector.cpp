#include"Vector.h"//包含的头文件

//模板类和操作函数的声明
template<class T>
class Vector
{
public:
	explicit Vector(size_t capacity = 0);//构造函数
	Vector(Vector<T>& v);//拷贝构造函数
	void Push_Back(T data);//尾插
	void Pop_Back();//尾删
	void Insert(T data, size_t pos);//自定位置插入
	void Earse(size_t pos);//自定位置删除
	void Clear();//删除全部元素
	void Swap(size_t pos1, size_t pos2);//交换两个位置的值
	T& Front();//返回第一个位置的元素
	T& Back();//返回最后一个元素的引用
	T& At(size_t pos);//返回自定位置的元素
	T* Begin();//获取容器头位置地址
	T* End();//获取容器尾位置地址
	size_t Size();//获取存储元素个数
	size_t Capacity();//获取当前容量大小
	void ReCapacity();//更改容量大小
	bool Empty();//判断容器是否为空
	bool operator==(T& data);
	bool operator!=(T& data);
	Vector& operator=(Vector& v);
	T& operator[](Vector& v);
	~Vector();//析构函数
private:
	T* _ptr;
	size_t _capacity;
	size_t _size;
};

//模板类中操作函数的定义
//构造函数
template<class T>
Vector<T>::Vector(size_t capacity = 0)
:_capacity(capacity)
, _size(0)
{
	_ptr = new T[_capacity];
	assert(_ptr);
}

//拷贝构造函数
template<class T>
Vector<T>::Vector(Vector<T>& v)
:_capacity(v._capacity)
, _size(v._size)
{
	int i = 0;
	_ptr = new T[_capacity];
	assert(_ptr);

	//拷贝引用的容器中存放的内容
	for (i = 0; i < _size; i++)
		*(_ptr+i) = *(v._ptr+i);
}

//尾插
template<class T>
void Vector<T>::Push_Back(T data)
{
	if (_size >= _capacity)
		ReCapacity();
	*(_ptr + _size) = data;
	_size++;
}

//尾删
template<class T>
void Vector<T>::Pop_Back()
{
	_size--;
}

//自定位置插入
template<class T>
void Vector<T>::Insert(T data, size_t pos)
{
	int i = 0;
	if(_size >= _capacity)
		ReCapacity();
	for (i = _size; i > 0; i--)
	{
		*(_ptr + i) = *(_ptr + i - 1);
	}
	size++;
}

//自定位置删除
template<class T>
void Vector<T>::Earse(size_t pos)
{
	int i = 0;
	for (i = pos; i < _size; i++)
	{
		*(_ptr + i - 1) = *(_ptr + i);
	}
	_size--;
}

//删除所有元素    
template<class T>
void Vector<T>::Clear()
{
	_size = 0;
}

//交换两个位置的元素
template<class T>
void Vector<T>::Swap(size_t pos1, size_t pos2)
{
	int tmp = *(_ptr + pos1 - 1);
	*(_ptr + pos1 - 1) = *(_ptr + _pos2 - 1);
	*(_ptr + pos2 - 1) = tmp;
}

//获取容器头位置的元素
template<class T>
T* Vector<T>::Begin()
{
	return _ptr;
}

//获取容器最后一个元素
template<class T>
T& Vector<T>::Back()
{
	return *(_ptr + _size - 1);
}

//获取容器第一个元素
template<class T>
T& Vector<T>::Front()
{
	return *(_ptr);
}

//自定位置获取元素
template<class T>
T& Vector<T>::At(size_t pos)
{
	return *(_ptr + pos - 1);
}


//获取容器元素末尾地址
template<class T>
T* Vector<T>::End()
{
	return (_ptr + _size - 1);
}

//返回_size
template<class T>
size_t Vector<T>::Size()
{
	return _size;
}

//返回_capacity
template<class T>
size_t Vector<T>::Capacity()
{
	return _capacity;
}

//增容
template<class T>
void Vector<T>::ReCapacity()
{
	int i = 0;
	T* New_ptr = new T[_capacity + 3];
	for (i = 0; i < _size; i++)
	{
		*(New_ptr + i) = *(_ptr + i);
	}
	delete[] _ptr;
	_ptr = New_ptr;
	_capacity += 3;
}

//判空
template<class T>
bool Vector<T>::Empty()
{
	return _size == 0;
}


//析构函数
template<class T>
Vector<T>::~Vector()
{
	delete[] _ptr;
	_capacity = 0;
	_size = 0;
}
//主函数
int main()
{
	Vector<int> v1(3);
	v1.Push_Back(1);
	v1.Push_Back(2);
	v1.Push_Back(3);
	v1.Push_Back(4);
	return 0;
}