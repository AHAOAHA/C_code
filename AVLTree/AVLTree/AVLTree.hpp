#pragma once

//节点信息
template<class K, class V>
struct Node
{
	Node(K key, V val) :_left(nullptr), _right(nullptr), _parent(nullptr), _bf(0), _key(key), _data(val)
	{}

	Node<K, V>* _left;
	Node<K, V>* _right;
	Node<K, V>* _parent;
	
	int _bf;
	K _key;
	V _data;
};

template<class K, class V>
class AVLTree
{
	typedef Node<K, V> Node;
public:
	AVLTree() :_root(nullptr)
	{}

	bool Insert(Node* newnode)
	{
		
	}

	~AVLTree()
	{}
private:
	Node* _root;		//根节点
};


