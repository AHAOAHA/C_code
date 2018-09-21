#include<malloc.h>
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
	{}
	Vector(size_type n, value_type value)//��һ����������Ҫ��������������ڶ���������ʾҪ��ŵ�ֵ
	{
		//����ռ䲢��װ�õ�����
		ApplySpace(sizeof(value_type)*n);

		//��������
		iterator ptr = _start;
		while (n--)
		{
			*ptr++ = value;
		}
	}
	Vector(iterator start, iterator end)//�����ͷ��β��ǰ�պ�
	{
		//����ռ�
		ApplySpace((end - start)*sizeof(value_type));

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
		//����ռ�
		ApplySpace(sizeof(v)-sizeof(size_type));

		//��������

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

	void ApplySpace(size_t size)//����ռ�
	{
		//����ռ�
		iterator ptr = (iterator)malloc(size + sizeof(size_type));
		size_type* ptr_size = (size_type*)ptr;
		//��װ������
		_start = (iterator)((char*)ptr + sizeof(size_type));
		_end = (iterator)((char*)_start + size);
		_finish = _end;

		//�޸��ڴ��ʼ�ļ�¼�ֽ�
		*(size_type*)ptr_size = size / sizeof(value_type);
	}

	void InsertPop(value_type value);//β��
	//~Vector();//��������
private:
	iterator _start;//��ʾĿǰʹ�ÿռ��ͷ
	iterator _finish;//��ʾĿǰʹ�ÿռ��β
	iterator _end;//��ʾĿǰ���ÿռ��β

};