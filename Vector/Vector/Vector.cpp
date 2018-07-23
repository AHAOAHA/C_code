#include"Vector.h"//������ͷ�ļ�

//ģ����Ͳ�������������
template<class T>
class Vector
{
public:
	explicit Vector(size_t capacity = 0);//���캯��
	Vector(Vector<T>& v);//�������캯��
	void Push_Back(T data);//β��
	void Pop_Back();//βɾ
	void Insert(T data, size_t pos);//�Զ�λ�ò���
	void Earse(size_t pos);//�Զ�λ��ɾ��
	void Clear();//ɾ��ȫ��Ԫ��
	void Swap(size_t pos1, size_t pos2);//��������λ�õ�ֵ
	T& Front();//���ص�һ��λ�õ�Ԫ��
	T& Back();//�������һ��Ԫ�ص�����
	T& At(size_t pos);//�����Զ�λ�õ�Ԫ��
	T* Begin();//��ȡ����ͷλ�õ�ַ
	T* End();//��ȡ����βλ�õ�ַ
	size_t Size();//��ȡ�洢Ԫ�ظ���
	size_t Capacity();//��ȡ��ǰ������С
	void ReCapacity();//����������С
	bool Empty();//�ж������Ƿ�Ϊ��
	bool operator==(T& data);
	bool operator!=(T& data);
	Vector& operator=(Vector& v);
	T& operator[](Vector& v);
	~Vector();//��������
private:
	T* _ptr;
	size_t _capacity;
	size_t _size;
};

//ģ�����в��������Ķ���
//���캯��
template<class T>
Vector<T>::Vector(size_t capacity = 0)
:_capacity(capacity)
, _size(0)
{
	_ptr = new T[_capacity];
	assert(_ptr);
}

//�������캯��
template<class T>
Vector<T>::Vector(Vector<T>& v)
:_capacity(v._capacity)
, _size(v._size)
{
	int i = 0;
	_ptr = new T[_capacity];
	assert(_ptr);

	//�������õ������д�ŵ�����
	for (i = 0; i < _size; i++)
		*(_ptr+i) = *(v._ptr+i);
}

//β��
template<class T>
void Vector<T>::Push_Back(T data)
{
	if (_size >= _capacity)
		ReCapacity();
	*(_ptr + _size) = data;
	_size++;
}

//βɾ
template<class T>
void Vector<T>::Pop_Back()
{
	_size--;
}

//�Զ�λ�ò���
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

//�Զ�λ��ɾ��
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

//ɾ������Ԫ��    
template<class T>
void Vector<T>::Clear()
{
	_size = 0;
}

//��������λ�õ�Ԫ��
template<class T>
void Vector<T>::Swap(size_t pos1, size_t pos2)
{
	int tmp = *(_ptr + pos1 - 1);
	*(_ptr + pos1 - 1) = *(_ptr + _pos2 - 1);
	*(_ptr + pos2 - 1) = tmp;
}

//��ȡ����ͷλ�õ�Ԫ��
template<class T>
T* Vector<T>::Begin()
{
	return _ptr;
}

//��ȡ�������һ��Ԫ��
template<class T>
T& Vector<T>::Back()
{
	return *(_ptr + _size - 1);
}

//��ȡ������һ��Ԫ��
template<class T>
T& Vector<T>::Front()
{
	return *(_ptr);
}

//�Զ�λ�û�ȡԪ��
template<class T>
T& Vector<T>::At(size_t pos)
{
	return *(_ptr + pos - 1);
}


//��ȡ����Ԫ��ĩβ��ַ
template<class T>
T* Vector<T>::End()
{
	return (_ptr + _size - 1);
}

//����_size
template<class T>
size_t Vector<T>::Size()
{
	return _size;
}

//����_capacity
template<class T>
size_t Vector<T>::Capacity()
{
	return _capacity;
}

//����
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

//�п�
template<class T>
bool Vector<T>::Empty()
{
	return _size == 0;
}


//��������
template<class T>
Vector<T>::~Vector()
{
	delete[] _ptr;
	_capacity = 0;
	_size = 0;
}
//������
int main()
{
	Vector<int> v1(3);
	v1.Push_Back(1);
	v1.Push_Back(2);
	v1.Push_Back(3);
	v1.Push_Back(4);
	return 0;
}