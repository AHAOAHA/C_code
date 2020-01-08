#include "MiddleOrder.h"
#include <iostream>
#include <stack>

static void _MiddleOrder(Node* root) {
	if(root == nullptr) {
		return;
	}
	_MiddleOrder(root->_left);
	std::cout << root->_data << " ";
	_MiddleOrder(root->_right);
}

void AHAOAHA::MiddleOrder(Node* root) {
	_MiddleOrder(root);
	std::cout << std::endl;
}

void AHAOAHA::NRMiddleOrder(Node* root) {
	std::stack<Node*> st;
	Node* cur = root;
	while(cur != nullptr || !st.empty()) {
		while(cur != nullptr) {
			st.push(cur);
			cur = cur->_left;
		}
		if(cur == nullptr) {
			cur = st.top();
			st.pop();
			std::cout << cur->_data << " ";
			cur = cur->_right;
		}


	}
}