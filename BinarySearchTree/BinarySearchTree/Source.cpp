#include <iostream>


struct BinarySearchTree {
	struct TreeNode {
		int key;
		TreeNode *left, *right;
		TreeNode(int node_key = 0, TreeNode *left_node_ptr = nullptr, TreeNode *right_node_ptr = nullptr);
	};
	TreeNode *root;
	BinarySearchTree(TreeNode *root_node = nullptr);
	TreeNode * search(int key);
	void insert(TreeNode *new_node);

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

BinarySearchTree::TreeNode* BinarySearchTree::search(int key) {
	TreeNode *current = root;
	while (current != nullptr && key != current->key) {
		if (key < current->key) {
			current = current->left;
		}
		else {
			current = current->right;
		}
	}
	return current;
}

void BinarySearchTree::insert(TreeNode *new_node) {
	TreeNode *current = nullptr, *next = root;
	if (root == nullptr) {
		root = new_node;
		return;
	}
	while (next != nullptr) {
		current = next;
		if (new_node->key == current->key) {
			// THIS WHILE STATEMENT ENSURES FIFO
			while (current->left != nullptr && current->left->key == new_node->key) {
				current = current->left;
			}
			break;
		}
		if (new_node->key < current->key) {
			next = current->left;
		}
		else {
			next = current->right;
		}
	}
	if (new_node->key <= current->key) {
		new_node->left = current->left;
		current->left = new_node;
	}
	else {
		new_node->right = current->right;
		current->right = new_node;
	}
}


int main() {
	std::cout << "Hello, World!" << std::endl;

	system("pause");

	return 0;
}
