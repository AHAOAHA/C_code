#include "AfterOrder.h"
#include <iostream>
#include <stack>

static void _MiddleOrder(Node* root) {
	if(root == nullptr) {
		return;
	}
	_MiddleOrder(root->_left);
	_MiddleOrder(root->_right);
	std::cout << root->_data << " ";
}

void AHAOAHA::AfterOrder(Node* root) {
	_MiddleOrder(root);
	std::cout << std::endl;
}

void AHAOAHA::NRAfterOrder(Node* root) {
	std::stack<Node*> st;
	std::stack<Node*> output;
	Node* cur = root;
	while (cur != nullptr || !st.empty()) {
		while (cur != nullptr) {
			st.push(cur);
			output.push(cur);
			cur = cur->_right;
		}
		if (cur == nullptr) {
			cur = st.top();
			st.pop();
			cur = cur->_left;
		}
	}

	while(!output.empty()) {
		cur = output.top();
		output.pop();
		std::cout << cur->_data << " ";
	}

	std::cout << std::endl;
}