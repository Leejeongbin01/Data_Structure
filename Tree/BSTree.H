#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int key;
	Node* parent;
	Node* left;
	Node* right;
	Node(int key) {
		this->key = key;
		parent = left = right = NULL;
	}
};

class BST {
private:
	Node* root;
public:
	BST() {
		root = NULL;
	}
	Node* search(Node* cur, int key) {
		if (cur == NULL) {
			return NULL;
		}
		if (cur->key == key) {
			return cur;
		}
		else if (cur->key < key) {
			return search(cur->right, key);
		}
		else {
			return search(cur->left, key);
		}
	}
	void insert(int key) {
		if (search(root, key)!=NULL) {
			return;
		}
		Node* n = new Node(key);
		if (root == NULL) {
			root = n;
			return;
		}
		Node* cur = root;
		Node* par = NULL;
		while (cur != NULL) {
			par = cur;
			if (cur->key < key) {
				cur = cur->right;
			}
			else {
				cur = cur->left;
			}
		}
		n->parent = par;
		if (par->key < key) {
			par->right = n;
		}
		else {
			par->left = n;
		}
	}
	void remove(int key) {
		Node* del = search(root, key);
		if (del == NULL) {
			return;
		}
		Node* par = del->parent;
		Node* child;
		if (del->left == NULL && del->right == NULL) {
			child = NULL;
		}
		else if (del->left == NULL && del->right != NULL) {
			child = del->right;
		}
		else if (del->left != NULL && del->right == NULL) {
			child = del->left;
		}
		else {
			child = del->right;
			while (child->left != NULL) {
				child = child->left;
			}
			del->key = child->key;
			del = child;
			par = del->parent;
			child = del->right;
		}
		if (par == NULL) {
			root = child;
			root->parent = NULL;
		}
		else if (del == par->left) {
			par->left = child;
			if (child != NULL) {
				child->parent = par;
			}
		}
		else {
			par->right = child;
			if (child != NULL) {
				child->parent = par;
			}
		}
		delete del;
	}
};
