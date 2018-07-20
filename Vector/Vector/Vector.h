#include<stdlib.h>
template<class T>
class Vector
{
public:
	Vector(size_t capacity = 10)
		:_capacity(capacity)
		, _ptr(new T[_capacity])
		, _size(0)
	{}
	~Vector()
	{
		if (_ptr)
		{
			delete[] _ptr;
			_ptr = NULL;
		}
		_capacity = 0;
		_size = 0;
	}
private:
	T* _ptr;
	size_t _capacity;
	size_t _size;
};
