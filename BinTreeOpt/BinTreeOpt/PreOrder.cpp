#include "PreOrder.h"
#include <stack>
#include <iostream>

static void _PreOrder(Node* root) {
	if(root == nullptr) {
		return;
	}

	std::cout << root->_data << " ";
	_PreOrder(root->_left);
	_PreOrder(root->_right);
}

void AHAOAHA::PreOrder(Node* root) {
	_PreOrder(root);
	std::cout << std::endl;
}

void AHAOAHA::NRPreOrder(Node* root) {
	std::stack<Node*> st;
	Node* cur = root;
	while (cur != nullptr || !st.empty()) {
		while (cur != nullptr) {
			std::cout << cur->_data << " ";
			st.push(cur);
			cur = cur->_left;
		}

		if (cur == nullptr) {
			cur = st.top();
			st.pop();
			cur = cur->_right;
		}
	}
	std::cout << std::endl;
}