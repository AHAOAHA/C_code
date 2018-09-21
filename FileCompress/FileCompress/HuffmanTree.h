#pragma once

#include<queue>
#include<vector>
template<class W>
struct HuffmanTreeNode//Huffman�����
{
	HuffmanTreeNode<W>* _left;//������
	HuffmanTreeNode<W>* _right;//������
	W _w;//Ȩֵ
};

template<class W>
class HuffmanTree//Huffman��
{
	typedef HuffmanTreeNode<W> Node;//��ֹ����ڵ�ʱ����
public:
	HuffmanTree()//���캯��
		��_root(NULL)
	{}
	HuffmanTree(W* w, size_t n)
	{
		//����Huffman��
		std::priority_queue<Node*, vector<Node*>, NodeCompare> minheap;
		for (size_t i = 0; i < n; ++i)
		{
			minheap.push();
		}
	}
protected:
	Node* _root;//���ڵ�
};