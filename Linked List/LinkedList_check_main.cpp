#include "LinkedList.h"

int main() {
	SLinkedList sList;

	sList.showList();

	sList.addFront(5);
	sList.addFront(10);
	sList.addBack(50);
	sList.showList();

	cout << sList.removeFront() << endl;
	sList.showList();
	
	cout << sList.head->data;

	return 0;
}
