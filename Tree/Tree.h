#include <iostream>
#include <vector>
using namespace std;

class Node {
	int data;
	Node* parent;
	vector<Node*> childList;
	Node(int data,Node* p) {
		this->data = data;
		parent = p;
	}
	friend class Tree;
};

class Tree {
private:
	Node* root;
	vector<Node*> nodeList;
	int find(int data, vector<Node*>& list) {
		for (int i = 0; i < list.size(); i++) {
			if (list[i]->data == data) {
				return i;
			}
		}
		return -1;
	}
public:
	Tree(int data) {
		root = new Node(data,NULL);
		nodeList.push_back(root);
	}
	void insertNode(int parData, int data) {
		if (find(data, nodeList) != -1) {
			return;
		}
		int idx = find(parData, nodeList);
		if (idx == -1) {
			return;
		}

		Node* parNode = nodeList[idx];
		Node* newNode = new Node(data, parNode);
		parNode->childList.push_back(newNode);
		nodeList.push_back(newNode);
		return;
	}
	void deleteNode(int data) {
		int idx = find(data, nodeList);
		if (idx == -1) {
			return;
		}
		Node* delNode = nodeList[idx];
		if (delNode == root) {
			return;
		}
		Node* parNode = delNode->parent;
		for (int i = 0; i < delNode->childList.size(); i++) {
			parNode->childList.push_back(delNode->childList[i]);
			delNode->childList[i]->parent = parNode;
		}
		vector<Node*>& child = parNode->childList;
		child.erase(child.begin() + find(data, child));
		nodeList.erase(nodeList.begin() + idx);
		delete delNode;
		return;
	}
	void printPar(int data) {
		int idx = find(data, nodeList);
		if (idx == -1) {
			return;
		}
		Node* curNode = nodeList[idx];
		cout << curNode->parent->data << endl;
	}
	void printChild(int data) {
		int idx = find(data, nodeList);
		if (idx == -1) {
			return;
		}
		vector<Node*>& child = nodeList[idx]->childList;
		for (int i = 0; i < child.size(); i++) {
			cout << child[i]->data << " ";
		}
		cout << endl;
	}
};
