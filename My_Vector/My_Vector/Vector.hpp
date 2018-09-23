#include<malloc.h>
#include<assert.h>
#include<stdio.h>
template<class T>
class Vector
{
	typedef int ptrdiff_t;
	//Vector��Ƕ���ͱ��壨�ο�vectorԴ�룩
	typedef T value_type;//�洢����������
	typedef value_type* pointer;//����ָ��洢�����ݵ�ָ��
	typedef value_type* iterator;//����������ָ����ͬ��
	typedef size_t size_type;//����size������
	typedef value_type& reference;//���ݵ���������
	typedef ptrdiff_t difference_type;//��ʾ����������֮��ľ��룬C++���ö���typedef int ptrdiff_t;
public:
	Vector()//Ĭ�Ϲ��캯��
		:_start(nullptr)
		, _finish(nullptr)
		, _end(nullptr)
		, _size(0)
		, _capacity(0)
	{}
	Vector(size_type n, value_type value)//��һ����������Ҫ��������������ڶ���������ʾҪ��ŵ�ֵ
	{
		//����ռ䲢��װ�õ�����
		_size = n;
		_capacity = n;
		_start = new value_type[_capacity];
		assert(_start);
		_end = _start + _capacity;
		_finish = _start + _size;

		//��������
		iterator ptr = _start;
		while (n--)
		{
			*ptr++ = value;
		}
	}
	Vector(iterator start, iterator end)//�����ͷ��β��ǰ�պ�
	{
		//����ռ䲢��װ�õ�����
		_capacity = end - start;
		_size = _capacity;
		_start = new value_type[_capacity];
		assert(_start);
		_end = _start + _capacity;
		_finish = _start + _size;

		//��������
		iterator ptr = _start;
		size_t i = 0;
		for (ptr = _start; (ptr + i) != _finish; ++i)
		{
			ptr[i] = start[i];
		}
	}
	Vector(Vector<T>& v)//�������캯��
	{
		//����ռ䲢��װ������
		_capacity = v.capacity();
		_size = v.size();
		_start = new value_type[_capacity];
		assert(_start);
		_end = _start + _capacity;
		_finish = _start + _size;

		//��������
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
		//�ж��������Ƿ���ھ�����
		if (capacity <= _capacity)
			return;
		//����ɿռ���Ϣ
		size_type old_capacity = _capacity;
		size_type old_size = _size;
		iterator old_start = _start;
		iterator old_end = _end;
		iterator old_finish = _finish;

		//�����¿ռ䲢��װ������
		_capacity = capacity;
		_start = new value_type[_capacity];
		_end = _start + _capacity;
		_finish = _start + _size;

		//���ƾɿռ������
		size_type i = 0;
		while (_start + i != _start + _size)
		{
			_start[i] = old_start[i];
			i += 1;
		}

		//�ͷžɿռ�
		delete[] old_start;
		old_start = nullptr;
		old_end = nullptr;
	}
	void InsertPop(value_type value);//β��
	//~Vector();//��������
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
	void insert(size_type pos, const value_type value)//�̶�λ�ò��뵥������
	{
		if (!has_space())
			reserve(_capacity * 2 + 1);
		if (pos >= _size)
		{
			printf("������λ��֮ǰ���п�λ�ã���Ϊ��β�����ʹ�õĵ�һ��λ��!\n");
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
	void insert(size_type pos, const size_type n, value_type value)//�ӹ̶�λ��������̶���Ŀ�Ĺ̶�����
	{
		//׼���ռ�
		while ((_size + n) >= _capacity)
		{
			reserve(_capacity * 2 + 1);
		}

		//�Ƚ�posλ��֮����������ݴ��������һ��ռ���
		size_type temp_size = _size - pos;
		iterator temp_start = new value_type[temp_size];
		iterator temp_end = temp_start + temp_size;
		size_t i = 0;
		while ((temp_start + i) != (temp_end))
		{
			temp_start[i] = _start[pos + i];
			i += 1;
		}

		//����ʵ�ռ��posλ�ÿ�ʼ��������Ҫ������
		size_t temp_n = n;
		while (temp_n--)
		{
			_start[pos] = value;
			_size += 1;
			pos += 1;
		}

		//����ʱ�ռ��ڵ����ݲ���
		i = 0;
		while ((temp_start + i) != temp_end)
		{
			_start[_size - n + i] = temp_start[i];
			i += 1;
		}

		//�ͷ���ʱ�ռ�
		delete temp_start;
		temp_start = nullptr;
		temp_end = nullptr;
	}
	void insert(size_type pos, value_type* start, value_type* end)
	{
		//׼���ռ�
		size_t size = end - start;
		while (_size + size >= _capacity)
		{
			reserve(_capacity * 2 + 1);
		}

		//����ʱ�ռ䱣��posλ����������
		size_type temp_size = _size - pos;
		iterator temp_start = new value_type[temp_size];
		iterator temp_end = temp_start + temp_size;
		size_t i = 0;
		while ((temp_start + i) != (temp_end))
		{
			temp_start[i] = _start[pos + i];
			i += 1;
		}

		//��Ҫ��������ݽ��в���
		size_t temp_pos = pos;
		while (start + temp_pos != end)
		{
			_start[temp_pos] = start[temp_pos];
			_size += 1;
			temp_pos += 1;
		}

		//����ʱ�ռ��ڵ����ݲ���
		i = 0;
		while ((temp_start + i) != temp_end)
		{
			_start[_size - size +i] = temp_start[i];
			i += 1;
		}

		//�ͷ���ʱ�ռ�
		delete temp_start;
		temp_start = nullptr;
		temp_end = nullptr;

	}
	void swap(Vector<value_type>& v);//��δʵ��
	void earse(size_t pos)//ɾ��ĳһ������
	{
		if (_size <= pos)
		{
			printf("%dλ��û�����ݣ�\n", pos);
			return;
		}
		while ((pos + 1) != _size)
		{
			move(_start + pos + 1, _start + pos);
			pos += 1;
		}
		_size -= 1;
	}
	void earse(size_t pos_start, size_t pos_end)//ɾ��ĳһ������(ǰ�պ�)
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
			printf("��ѡ���򲻴������ݣ�\n");
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
	iterator _start;//��ʾĿǰʹ�ÿռ��ͷ
	iterator _finish;//��ʾĿǰʹ�ÿռ��β
	iterator _end;//��ʾĿǰ���ÿռ��β
	size_type _capacity;//��ʾ��ά���Ŀռ��ܵ�����
	size_type _size;//��ʾ�Ѿ�ʹ�������Ĵ�С
};