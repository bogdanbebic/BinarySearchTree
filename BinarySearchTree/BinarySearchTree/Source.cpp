#include <iostream>
#include <queue>


class BinarySearchTree {
public:
	struct TreeNode {
		int key;
		TreeNode *left, *right;
		explicit TreeNode(int node_key = 0, TreeNode *left_node_ptr = nullptr, TreeNode *right_node_ptr = nullptr);
	};
	
	explicit BinarySearchTree(TreeNode *root_node = nullptr);
	BinarySearchTree(const BinarySearchTree &) = delete;
	void operator=(const BinarySearchTree &) = delete;
	~BinarySearchTree();
	void deallocate_nodes();
	TreeNode *find_parent(int key) const;
	void insert(int key);
	void level_order_to_cout() const;
	TreeNode *search(int key) const;	// NOT USED
	// TODO: implement key deletion
	// TODO: imlement max key reps searching
private:
	TreeNode *inorder_pred(TreeNode *start_node) const;
	void insert_below_parent(int key, TreeNode *parent);
	TreeNode *root_;
};

BinarySearchTree::TreeNode::TreeNode(int node_key, TreeNode* left_node_ptr, TreeNode* right_node_ptr) {
	key = node_key;
	left = left_node_ptr;
	right = right_node_ptr;
}

BinarySearchTree::BinarySearchTree(TreeNode *root_node) {
	root_ = root_node;
}

BinarySearchTree::~BinarySearchTree() {
	deallocate_nodes();
	root_ = nullptr;
}

BinarySearchTree::TreeNode* BinarySearchTree::find_parent(int key) const {
	TreeNode *parent = nullptr, *next = root_;
	while (next != nullptr && key != next->key) {
		parent = next;
		if (key < next->key) {
			next = next->left;
		}
		else {
			next = next->right;
		}
	}
	return parent;
}

/**
 * NOT USED
 */
BinarySearchTree::TreeNode* BinarySearchTree::search(int key) const {
	TreeNode *current = root_;
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

void BinarySearchTree::deallocate_nodes() {
	std::queue<TreeNode *> q;
	q.push(root_);
	while (!q.empty()) {
		TreeNode *elem = q.front();
		q.pop();
		if (elem != nullptr) {
			q.push(elem->left);
			q.push(elem->right);
			delete elem;
		}
	}
}

/**	!!!!! WARNING !!!!!
 *	ONLY FINDS INORDER PRED BELOW CURRENT NODE
 */
BinarySearchTree::TreeNode* BinarySearchTree::inorder_pred(TreeNode* start_node) const {
	TreeNode *pred = start_node;
	if (start_node->left != nullptr) {
		pred = start_node->left;
		while (pred->right != nullptr) {
			pred = pred->right;
		}
	}
	return pred;
}

/**	!!!!! WARNING !!!!!
 *	DOES NOT CHECK EDGE CASE parent == nullptr
 */
void BinarySearchTree::insert_below_parent(int key, TreeNode* parent) {
	auto new_node = new TreeNode(key);
	if (key <= parent->key) {
		new_node->left = parent->left;
		parent->left = new_node;
	}
	else {
		new_node->right = parent->right;
		parent->right = new_node;
	}
}

void BinarySearchTree::insert(int key) {
	TreeNode *parent = find_parent(key);
	if (parent == nullptr) {
		if (root_ == nullptr) {
			root_ = new TreeNode(key);
		}
		else {
			parent = inorder_pred(root_);
			insert_below_parent(key, parent);
		}
		return;
	}
	if (parent->left != nullptr && parent->left->key == key) {
		parent = inorder_pred(parent->left);
	}
	else if (parent->right != nullptr && parent->right->key == key) {
		parent = inorder_pred(parent->right);
	}
	insert_below_parent(key, parent);
}

void BinarySearchTree::level_order_to_cout() const {
	std::queue<TreeNode *> q;
	q.push(root_);
	while (!q.empty()) {
		TreeNode *elem = q.front();
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
		std::cout << "1. Add nodes to BST" << std::endl;
		std::cout << "2. Add node to BST" << std::endl;
		std::cout << "3. Search BST for key" << std::endl;
		std::cout << "4. Output BST" << std::endl;
		std::cout << "5. Delete key from BST" << std::endl;
		std::cout << "6. Delete BST" << std::endl;
		std::cout << "7. Output max number of key reps" << std::endl;
		std::cout << "0. Exit program" << std::endl;
		std::cout << "Select menu option: ";

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
			bst.level_order_to_cout();
			break;
		case 5:
			// TODO: delete key from BST
			break;
		case 6:
			bst.deallocate_nodes();
			break;
		case 0:
			bst.deallocate_nodes();
			is_running = false;
			break;
		default: 
			break;
		}
		std::cout << std::endl;
	}

	system("pause");
	return 0;
}
