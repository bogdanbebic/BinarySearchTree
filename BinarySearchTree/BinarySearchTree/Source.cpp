#include <iostream>
#include <queue>


struct BinarySearchTree {
	struct TreeNode {
		int key;
		TreeNode *left, *right;
		explicit TreeNode(int node_key = 0, TreeNode *left_node_ptr = nullptr, TreeNode *right_node_ptr = nullptr);
	};
	TreeNode *root;
	
	explicit BinarySearchTree(TreeNode *root_node = nullptr);

	BinarySearchTree(const BinarySearchTree &) = delete;
	void operator=(const BinarySearchTree &) = delete;

	~BinarySearchTree();	// TODO: implement
	
	TreeNode * search(int key);	// TODO: reimplement
	void insert(int key);	// TODO: reimplement using find or findParent function

	void levelOrderToCout();

	// TODO: implement output

	// TODO: implement key deletion

	// TODO: imlement max key reps searching

};

BinarySearchTree::TreeNode::TreeNode(int node_key, TreeNode* left_node_ptr, TreeNode* right_node_ptr) {
	key = node_key;
	left = left_node_ptr;
	right = right_node_ptr;
}

BinarySearchTree::BinarySearchTree(TreeNode *root_node) {
	root = root_node;
}

BinarySearchTree::~BinarySearchTree() {
	// TODO: deallocate all nodes
	root = nullptr;
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

void BinarySearchTree::insert(int key) {
	TreeNode *new_node = new TreeNode(key);
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

void BinarySearchTree::levelOrderToCout() {
	std::queue<TreeNode *> q;
	TreeNode *elem;
	q.push(root);
	while (!q.empty()) {
		elem = q.front();
		q.pop();
		if (elem != nullptr) {
			std::cout << elem->key << " ";
			q.push(elem->left);
			q.push(elem->right);
		}
	}
	std::cout << std::endl;
}


int main() {
	std::cout << "Hello, World!" << std::endl;

	int menu_option;
	bool is_running = true;
	BinarySearchTree bst;
	BinarySearchTree::TreeNode *elem;
	int key;

	while (is_running) {
		std::cout << "1. Make BST" << std::endl;
		std::cout << "2. Add node to BST" << std::endl;
		std::cout << "3. Search BST for key" << std::endl;
		std::cout << "4. Output BST" << std::endl;
		std::cout << "5. Delete key from BST" << std::endl;
		std::cout << "6. Delete BST" << std::endl;
		std::cout << "7. Output max number of key reps" << std::endl;
		std::cout << "0. Exit program" << std::endl;
		std::cout << "Seect menu option: ";

		std::cin >> menu_option;

		switch (menu_option) {
		case 1:	// N KEYS INSERT
			int n;
			std::cout << "Input number of keys to insert: ";
			std::cin >> n;
			for (int i = 0; i < n; i++) {
				std::cout << "Input key to insert: ";
				std::cin >> key;
				bst.insert(key);
			}
			break;
		case 2:	// KEY INSERT
			std::cout << "Input key to insert: ";
			std::cin >> key;
			bst.insert(key);
			break;
		case 3:	// KEY SEARCHING
			std::cout << "Input key to search for: ";
			std::cin >> key;
			elem = bst.search(key);
			if (elem != nullptr) {
				std::cout << "Succesful search: " << elem->key << std::endl;
			}
			else {
				std::cout << "Unsuccesful search :(" << std::endl;
			}
			break;
		case 4:
			std::cout << "Level order:" << std::endl;
			bst.levelOrderToCout();
			break;
		case 5:
			// TODO: delete key from BST
			break;
		case 6:
			// TODO: delete BST
			break;
		case 0:
			// TODO: delete BST
			is_running = false;
			break;
		}
		std::cout << std::endl;
	}

	system("pause");
	return 0;
}
