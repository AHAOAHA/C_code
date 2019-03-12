#ifndef __OBJECT_POOL_H__
#define __OBJECT_POOL_H__

//�����ڴ��

template<class T>
class ObjectPool
{
protected:
		struct Block
		{
			char* _start = nullptr;
			size_t _bytesize = 0;
			size_t _byteleft = 0;
			Block* _next = nullptr;

			Block(size_t bytesize)
			{
				_start = (char*)malloc(bytesize);
				_bytesize = bytesize;
				_byteleft = bytesize;
				Block* _next = nullptr;
			}
		};

		T*& OBJNEXT(T* ptr)
		{
			return *(T**)ptr;
		}
public:
	ObjectPool(size_t initnum = 32)
	{
		_head = _tail = new Block(initnum * sizeof(T));
	}

	T* New()
	{
		T* obj = nullptr;
		if (_freelist != nullptr)
		{
			obj = _freelist;
			_freelist = OBJNEXT(_freelist);
		}
		else
		{
			Block* tail = _tail;
			if (tail->_byteleft == 0)
			{
				Block newblock = new Block(_tail->_bytesize * 2);
				_tail->_next = newblock;
				_tail = newblock;
			}

			obj = (char*)(_tail->_bytesize - _tail->_byteleft);
			_tail->_byteleft -= sizeof(T);

			return obj;
		}
	}

	void Delete(T* ptr)
	{
		//�������ĵ�һ��
		if (_freelist == nullptr)
		{
			_freelist = ptr;

			//���������ڴ����ʼ��4/8�ֽڴ�ź���ָ��ĵ�ַ
			//(*(T**)ptr) = nullptr;
			OBJNEXT(ptr) = nullptr;
		}

		else
		{
			//(*(T**)ptr) = _freelist;
			OBJNEXT(ptr) = _freelist;
			_freelist = ptr;
		}
	}
protected:

	//��������
	T* _freelist;

	//�����
	Block* _head;
	Block* _tail;
};


#endif