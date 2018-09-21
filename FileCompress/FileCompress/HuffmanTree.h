#pragma once

#include<queue>
#include<vector>
template<class W>
struct HuffmanTreeNode//Huffman树结点
{
	HuffmanTreeNode<W>* _left;//左子树
	HuffmanTreeNode<W>* _right;//右子树
	W _w;//权值
};

template<class W>
class HuffmanTree//Huffman树
{
	typedef HuffmanTreeNode<W> Node;//防止定义节点时出错
public:
	HuffmanTree()//构造函数
		：_root(NULL)
	{}
	HuffmanTree(W* w, size_t n)
	{
		//构建Huffman树
		std::priority_queue<Node*, vector<Node*>, NodeCompare> minheap;
		for (size_t i = 0; i < n; ++i)
		{
			minheap.push();
		}
	}
protected:
	Node* _root;//根节点
};