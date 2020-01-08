#include "LevelOrder.h"
#include <queue>
#include <iostream>

void AHAOAHA::LevelOrder(Node* root) {
	if(root == nullptr) {
		return;
	}
	std::queue<Node*> qe;
	Node* cur = root;
	//首先将头节点入队列
	qe.push(cur);
	while(!qe.empty()) {
		cur = qe.front();
		qe.pop();
		if (cur->_left)
			qe.push(cur->_left);
		if (cur->_right)
			qe.push(cur->_right);

		std::cout << cur->_data << " ";
	}
	std::cout << std::endl;
	
}