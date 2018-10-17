#include <iostream>


struct BinarySearchTree {
	struct TreeNode {
		int key;
		TreeNode *left, *right;
		TreeNode(int node_key = 0, TreeNode *left_node_ptr = nullptr, TreeNode *right_node_ptr = nullptr);
	};

	TreeNode *root;

	BinarySearchTree(TreeNode *root_node = nullptr);
	
	// TODO: implementation
	
};

BinarySearchTree::TreeNode::TreeNode(int node_key, TreeNode* left_node_ptr, TreeNode* right_node_ptr) {
	key = node_key;
	left = left_node_ptr;
	right = right_node_ptr;
}

BinarySearchTree::BinarySearchTree(TreeNode *root_node) {
	root = root_node;
}


int main() {
	std::cout << "Hello, World!" << std::endl;

	system("pause");

	return 0;
}
