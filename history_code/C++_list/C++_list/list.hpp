#ifndef __LIST_HPP__
#define __LIST_HPP__
/*
 * C++实现链表list(无头结点)
 */

template<class T>
class MyList
{
public:
	MyList()
		:_ptrLast(nullptr)
		,_phead(nullptr)
	{}

	void push_back(T data)
	{
		if (_phead == nullptr)
		{
			_phead = new ListNode;
			_ptrLast = _phead;
			_phead->_data = data;
			_phead->_pnext = nullptr;
			return;
		}

		_ptrLast->_pnext = new ListNode;
		_ptrLast = _ptrLast->_pnext;
		_ptrLast->_data = data;
		_ptrLast->_pnext = nullptr;

	}

	void pop_back()
	{
		if (_phead)
		{
			ListNode* temp_ptr = _phead;
			while (temp_ptr->_pnext != _ptrLast)
			{
				temp_ptr = temp_ptr->_pnext;
			}

			delete _ptrLast;
			_ptrLast = temp_ptr;
			_ptrLast->_pnext = nullptr;
		}
	}

	void push_front(T data)
	{
		ListNode* temp_ptr = new ListNode;
		temp_ptr->_pnext = _phead;
		temp_ptr->_data = data;
		_phead = temp_ptr;
	}

	void pop_front()
	{
		if (_phead)
		{
			ListNode* temp_ptr = _phead;
			_phead = _phead->_pnext;
			delete temp_ptr;
		}
	}

	~MyList()
	{
		ListNode* temp_ptr = _phead;
		while (temp_ptr)
		{
			ListNode* del_ptr = temp_ptr;
			temp_ptr = temp_ptr->_pnext;
			delete del_ptr;
		}
	}
	
private:
	typedef struct ListNode//链表节点结构
	{
		T _data;
		ListNode* _pnext;
	}ListNode;
	ListNode* _phead;
	ListNode* _ptrLast;
	size_t _size;
};

#endif