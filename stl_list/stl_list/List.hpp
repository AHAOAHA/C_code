#pragma once



namespace AHAOAHA
{
	template<class T>
	struct ListNode
	{
		ListNode()
			:_data()
			,_pNext(nullptr)
			,_pPre(nullptr)

		{}
		T _data;
		ListNode<T>* _pNext;
		ListNode<T>* _pPre;
	};

	template<class T>
	class List
	{
		typedef ListNode<T> Node;
 	public:
		List()
			:_pHead(new Node)
		{}
	private:	
		Node* _pHead;
	};
}