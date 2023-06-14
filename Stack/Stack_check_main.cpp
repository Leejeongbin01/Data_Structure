#include "Stack.h"

int main() {
	LinkedStack s;
	
	cout << s.size() << endl << s.empty() << endl << s.top() << endl;

	s.push(5);
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	cout << "--------------------" << endl;


	cout << s.top() << endl;

	s.pop();
	cout << s.top() << endl;

	s.pop();
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;

	cout << s.size() << endl << s.empty() << endl << s.top() << endl;

	return 0;
}
