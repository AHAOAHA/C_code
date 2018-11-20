#pragma once

namespace AHAOAHA
{
	template<class T>
	class Vector
	{
		typedef T* iterator;
		typedef const T* const_iterator;
		typedef T* reverse_iterator;
		typedef const T* const_reverse_iterator;

	public:

		explicit Vector()
			:_start(nullptr)
			,_finish(nullptr)
			,_endOfSpatial(nullptr)
		{}

		explicit Vector(iterator start, iterator end)
			:_start(nullptr)
			,_finish(nullptr)
			,_endOfSpatial(nullptr)
		{
			size_t capacity = end - start;
			_start = new T[capacity];
			_endOfSpatial = _start + capacity;
			for (size_t i = 0; (start+i) != end; ++i)
			{
				_start[i] = start[i];
			}
		}

		explicit Vector(size_t count, T data = 0)
			:_start(nullptr)
			,_finish(nullptr)
			,_endOfSpatial(nullptr)
		{
			_start = new T[count];
			_endOfSpatial = _start + count;
			_finish = _start + count;
			for (size_t i = 0; (_start + i) != _endOfSpatial; ++i)
			{
				_start[i] = data;
			}
		}

		~Vector()
		{
			delete[] _start;
			_start = nullptr;
			_finish = nullptr;
			_endOfSpatial = nullptr;
		}

		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator cbegin()const
		{
			return _start;
		}
		const_iterator cend()const
		{
			return _finish;
		}

		reverse_iterator rbegin()
		{
			return _finish - 1;
		}
		reverse_iterator rend()
		{
			return _start - 1;
		}
		const_reverse_iterator crbegin()const
		{
			return _finish - 1;
		}
		const_reverse_iterator crend()const
		{
			return _start - 1;
		}
		const size_t capacity()const
		{
			if (_start == nullptr)
				return 0;
			return (_endOfSpatial - _start);
		}

		const size_t size()const
		{
			if (_start == nullptr)
				return 0;
			return (_finish - _start);
		}

		void resize(size_t count);
		void reserve(size_t count);
		void pushback(T data);
		void popback();
		void insert(iterator pos, T data);
		void earse(size_t pos, size_t len);
		T& operator[](size_t pos)
		{
			assert(pos < this->size());
			return _start[pos];
		}
	private:
		T* _start;
		T* _finish;
		T* _endOfSpatial;
	};
}


template<class T>
void AHAOAHA::Vector<T>::resize(size_t count)
{
	if (this->capacity() < count)
	{
		size_t size = this->size();
		reserve(count);
		for (size; size < this->capacity(); ++size)
		{
			_start[size] = 0;
		}

		_finish = _start + count;
	}
	else
	{
		_finish = _start + count;
	}
}

template<class T>
void AHAOAHA::Vector<T>::reserve(size_t count)
{
	size_t tmpsize = this->size();
	if (this->capacity() < count)
	{
		T* newstart = new T[count];

		for (size_t i = 0; (_start + i) != _finish; ++i)
		{
			newstart[i] = _start[i];
		}

		delete[] _start;

		_start = newstart;
		_finish = _start + tmpsize;
		_endOfSpatial = newstart + count;
	}
}

template<class T>
void AHAOAHA::Vector<T>::insert(iterator pos, T data)
{
	size_t tmppos = pos - _start;
	if (this->capacity() == this->size())
	{
		reserve(capacity() * 2);
	}
	
	//此处需要注意vector增容之后的迭代器失效问题
	pos = _start + tmppos;

	for (auto it = _finish; it != pos; --it)
	{
		*it = *(it - 1);
	}
	*pos = data;
	_finish++;
}

template<class T>
void AHAOAHA::Vector<T>::pushback(T data)
{
	insert(this->begin()+size(), data);
}