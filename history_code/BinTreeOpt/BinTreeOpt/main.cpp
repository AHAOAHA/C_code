#include "Common.h"
#include "PreOrder.h"
#include "MiddleOrder.h"
#include "AfterOrder.h"
#include "LevelOrder.h"

int main()
{
	Node* root = new Node(3);
	root->_left = new Node(5);
	root->_right = new Node(6);
	root->_left->_left = new Node(1);
	root->_left->_right = new Node(2);
	root->_right->_left = new Node(9);
	root->_right->_right = new Node(10);

	//AHAOAHA::NRPreOrder(root);
	//AHAOAHA::PreOrder(root);
	//_PreOrder(root);	static修饰的函数只在当前.c文件中有效
	//AHAOAHA::MiddleOrder(root);
	//AHAOAHA::NRMiddleOrder(root);
	//AHAOAHA::AfterOrder(root);
	//AHAOAHA::NRAfterOrder(root);
	//AHAOAHA::LevelOrder(root);
	return 0;
}