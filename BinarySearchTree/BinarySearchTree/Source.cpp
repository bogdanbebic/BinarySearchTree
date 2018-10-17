#include <iostream>

class TreeNode {
public:
	TreeNode(int key = 0, TreeNode *left_node_ptr = nullptr, TreeNode *right_node_ptr = nullptr);
	int get_key();
	void set_key(int key);
	TreeNode *left, *right;
private:
	int key_;
};

TreeNode::TreeNode(int key, TreeNode* left_node_ptr, TreeNode* right_node_ptr) {
	key_ = key;
	left = left_node_ptr;
	right = right_node_ptr;
}

int TreeNode::get_key() {
	return key_;
}

void TreeNode::set_key(int key) {
	key_ = key;
}


class BinarySearchTree {
public:
	BinarySearchTree();
	// TODO: implementation
private:
	TreeNode *root_;
	// TODO: maybe more implementation
};

BinarySearchTree::BinarySearchTree() {
	root_ = nullptr;
	// TODO: maybe more implementation
}


int main() {
	std::cout << "Hello, World!" << std::endl;

	system("pause");

	return 0;
}
