#pragma once

struct Node {
	explicit Node(int data):_data(data), _left(nullptr), _right(nullptr)
	{}

	int _data;
	Node* _left;
	Node* _right;
};