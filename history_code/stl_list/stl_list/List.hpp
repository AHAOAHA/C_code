#pragma once
#include<iostream>


namespace AHAOAHA
{
	template<class T>
	struct ListNode
	{
		ListNode(T data = T())
			:_data(data)
			,_pNext(nullptr)
			,_pPre(nullptr)
		{}

		T _data;
		ListNode<T>* _pNext;
		ListNode<T>* _pPre;
	};

	template<class T, class Ref, class Saf>
	struct _ListIterator
	{
		typedef ListNode<T>* PNode;

		//Self定义了迭代器的类型，如果传进来时是iterator则Self就是iterator,如果传进来是const_iterator,则Self就是const_iterator
		typedef _ListIterator<T, Ref, Saf> Self;


		typedef _ListIterator<T, T&, T*> iterator;
		typedef _ListIterator<T, const T&, const T*> const_iterator;

		_ListIterator(PNode pNode = nullptr)
			:_pNode(pNode)
		{}

		Ref operator*()const
		{
			return _pNode->_data;
		}

		Saf operator->()const
		{
			return &(operator*());
		}

		Self& operator++()
		{
			this->_pNode = this->_pNode->_pNext;
			return *this;
		}

		Self operator++(int)
		{
			Self tmp(*this);
			_pNode = _pNode->_pNext;
			return tmp;
		}

		bool operator!=(Self it)
		{
			return this->_pNode != it._pNode;
		}

		bool operator==(Self it)
		{
			return this->_pNode == it._pNode;
		}

		PNode _pNode;
	};


	template<class T>
	class List
	{
		typedef ListNode<T> Node;
		typedef ListNode<T>* PNode;
	public:
		typedef _ListIterator<T, T&, T*> iterator;
		typedef _ListIterator<T, const T&, const T*> const_iterator;
		
 	public:
		List()
			:_pHead(new Node)
		{
			_pHead->_pNext = _pHead;
			_pHead->_pPre = _pHead;
		}

		List(const List& l)
			:_pHead(new Node)
		{
			//需要const的迭代器
		}

		List& operator=(List l)
		{
			swap(_pHead, l._pHead);
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				PNode tmp = it._pNode;
				it++;
				delete tmp;
			}
		}

		~List()
		{
			clear();
			delete _pHead;
			_pHead = nullptr;
		}

		void pushback(T data)
		{
			insert(_pHead, data);
		}
		void popback(T data)
		{
			earse(_pHead->_pPre);
		}

		void insert(iterator pos, T data)
		{
			PNode newNode = new Node(data);
			PNode pPur = pos._pNode;
			PNode pPre = pPur->_pPre;

			newNode->_pNext = pPur;
			pPur->_pPre = newNode;

			pPre->_pNext = newNode;
			newNode->_pPre = pPre;
		}

		void earse(iterator pos)
		{
			PNode pPre = pos._pNode;
			PNode pNext = pos._pNode->_pNext;
			pPre->_pNext = pNext;
			pNext->_pPre = pPre;

			delete pos._pNode;
		}

		void print()
		{
			const_iterator it = cbegin();
			while (it != this->cend())
			{
				//*it = 1;
				std::cout << *it << " ";
				++it;
			}
			std::cout << std::endl;
		}


		iterator begin()
		{
			return iterator(_pHead->_pNext);
		}

		const_iterator cbegin()const
		{
			return const_iterator(_pHead->_pNext);
		}

		iterator end()
		{
			return iterator(_pHead);
		}

		const_iterator cend()const
		{
			return const_iterator(_pHead);
		}
		
	private:	
		PNode _pHead;
	};
}