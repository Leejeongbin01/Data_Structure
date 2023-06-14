#include <iostream>
using namespace std;

#ifndef STACK_H
#define STACK_H

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
	Node* head;
	Node* tail;
	
	SLinkedList() {
		head = NULL;
		tail = NULL;
	}
	int front() {
		return head->data;
	}
	void addFront(int e) {
		Node* newNode = new Node(e);
		if (head == NULL) {
			head = tail = newNode;
		}
		else {
			newNode->next = head;
			head = newNode;
		}
	}
	int removeFront() {
		Node* tmp = head;
		head = head->next;
		return tmp->data;
	}
};

class LinkedStack {
public:
	int n; // 스택 원소의 개수
	SLinkedList* S; // 링크드 리스트

	LinkedStack() {
		this->S = new SLinkedList();
		this->n = 0;
	}
	int size() {
		return n;
	}
	bool empty() {
		return n == 0;
	}
	int top() {
		if (n == 0) {
			cout << "스택에 아무것도 없음\n";
			return 0;
		}
		else {
			return S->head->data;
		}
	}
	void push(int e) {
		Node* newNode = new Node(e);
		newNode->next = S->head;
		S->head = newNode;
		n++;
	}
	int pop() {
		if (n == 0) {
			cout << "스택에 아무것도 없으므로 pop 사용 x\n";
			return 0;
		}
		else {
			Node* curNode = S->head;
			S->head = S->head->next;
			n--;
			return curNode->data;
		}
	}
	
	int calPostfix(string exp) {

	}
};

#endif // !STACK_H
