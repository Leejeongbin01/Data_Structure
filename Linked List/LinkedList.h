#include <iostream>
using namespace std;

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class Node {
public:
	int data;
	Node* next;

	Node(int e) {
		this->data = e;
		this->next = NULL;
	}
};

class SLinkedList {
public:
	Node* head; //리스트의 head
	Node* tail; //리스트의 tail
public:
	SLinkedList() {
		head = NULL;
		tail = NULL;
	}
	void addFront(int x) { // 리스트의 가장 앞에 노드 삽입
		Node* n = new Node(x);
		if (head == NULL) {
			head = n;
			tail = n;
		}
		else {
			n->next = head;
			head = n;
		}
	}
	int removeFront() { // 리스트의 가장 앞 노드 삭제 후 원소 반환
		if (head == NULL) {
			cout << "리스트가 비어있음\n";
			return 0;
		}
		else {
			Node* delNode = head;
			int d = delNode->data;
			head = head->next;
			delete delNode;
			return d;
		}
	}
	int front() {
		if (head == NULL) {
			cout << "head가 비어있으므로 front 사용 x\n";
			return 0;
		}
		else {
			return head->data;
		}
	}
	int empty() {
		if (head == NULL) {
			return 1;
		}
		else{
			return 0;
		}
	}
	void showList() {
		if (empty()) {
			cout << "head가 비어잇으므로 showlist 사용x\n";
			return;
		}
		else {
			Node* curNode = head;
			while (curNode!=NULL) {
				cout << curNode->data << " ";
				curNode = curNode->next;
			}
			cout << endl;
		}
	}
	void addBack(int x) {
		Node* newNode = new Node(x);
		if (empty()) {
			cout << "head가 비어있으므로 \n";
			head = newNode;
			return;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
	}
};

#endif // !LINKEDLIST_H
