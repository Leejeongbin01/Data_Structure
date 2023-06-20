#include <iostream>
#include <cmath>
using namespace std;

class Array {
private:
	int n;
	int* arr;
public:
	Array(int size) {
		this->n = 0;
		this->arr = new int[size];
		for (int i = 0; i < size; i++) {
			arr[i] = 0;
		}
	}
	~Array() {
		delete arr;
	}
	int at(int idx) {
		return arr[idx];
	}
	void set(int idx, int x) {
			arr[idx] = x;
	}
};

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		Array a(10000);
		int num;
		cin >> num;
		for (int j = 0; j < num; j++) {
			int x;
			cin >> x;
			a.set(j, x);
		}
		int K = 0, J = 0, C = 0;
		int c1 = 0, c2 = 0, c3 = 0;
		int avr1, avr2, avr3;
		for (int j = 0; j < num; j++) {
			if (j % 3 == 0) {
				if (a.at(j) != 0) {
					c1++;
				}
				K += a.at(j);
			}
			else if (j % 3 == 1) {
				if (a.at(j) != 0) {
					c2++;
				}
				J += a.at(j);
			}
			else if (j % 3 == 2) {
				if (a.at(j) != 0) {
					c3++;
				}
				C += a.at(j);
			}
		}
		if (c1 != 0) {
			avr1 = floor(K / c1);
		}
		else {
			avr1 = 0;
		}
		if (c2 != 0) {
			avr2 = floor(J / c2);
		}
		else {
			avr2 = 0;
		}
		if (c3 != 0) {
			avr3 = floor(C / c3);
		}
		else {
			avr3 = 0;
		}
		cout << K << " " << J << " " << C << endl;
		cout << avr1 << " " << avr2 << " " << avr3 << endl;
	}
	return 0;
}