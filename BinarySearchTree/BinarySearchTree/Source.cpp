#include <iostream>

struct TreeNode {
	TreeNode(int node_key = 0, TreeNode *left_node_ptr = nullptr, TreeNode *right_node_ptr = nullptr);
	int key;
	TreeNode *left, *right;
};

TreeNode::TreeNode(int node_key, TreeNode* left_node_ptr, TreeNode* right_node_ptr) {
	key = node_key;
	left = left_node_ptr;
	right = right_node_ptr;
}


struct BinarySearchTree {
	BinarySearchTree();
	// TODO: implementation
	TreeNode *root;
	// TODO: maybe more implementation
};

BinarySearchTree::BinarySearchTree() {
	root = nullptr;
	// TODO: maybe more implementation
}


int main() {
	std::cout << "Hello, World!" << std::endl;

	system("pause");

	return 0;
}
