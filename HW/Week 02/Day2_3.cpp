//#include <iostream>
//using namespace std;
//
//class Array {
//private:
//	int n;
//	int* arr;
//public:
//	Array(int size) {
//		this->n = 0;
//		this->arr = new int[size];
//		for (int i = 0; i < size; i++) {
//			arr[i] = 0;
//		}
//	}
//	~Array() {
//		delete arr;
//	}
//	int at(int idx) {
//		return arr[idx];
//	}
//	void set(int idx, int x) {
//			arr[idx] = x;
//	}
//	void add(int idx, int x) {
//		if (arr[idx] == 0) {
//			while (arr[idx] == 0) {
//				if (idx == 0) {
//					arr[idx] = x;
//				}
//				idx--;
//			}
//			arr[idx + 1] = x;
//			n++;
//		}
//		else {
//			int cnt = 0;
//			for (int i = 0; i < 10000; i++) {
//				if (arr[i] != 0) {
//					cnt++;
//				}
//			}
//			int len = cnt - idx;
//			for (int i = 0; i <= len; i++) {
//				arr[cnt] = arr[cnt - 1];
//				cnt--;
//			}
//			arr[idx] = x;
//			n++;
//		}
//	}
//	void remove(int idx) {
//		if (arr[idx] == 0) {
//			cout << 0 << endl;
//		}
//		else {
//			int cnt = 0;
//			int len = n - idx-1;
//			cout << arr[idx] << endl;
//			for (int i = 0; i < len; i++) {
//				arr[idx] = arr[idx + 1];
//				idx++;
//			}
//			arr[n-1] = 0;
//			n--;
//		}
//	}
//	void printArray() {
//		if (n == 0) {
//			cout << 0 << endl;
//		}
//		else {
//			for (int i = 0; i < n; i++) {
//				cout << arr[i] << " ";
//			}
//			cout << endl;
//		}
//	}
//};
//
//int main() {
//	int T;
//	cin >> T;
//	for (int i = 0; i < T; i++) {
//		Array a(10000);
//		int num;
//		cin >> num;
//		for (int j = 0; j < num; j++) {
//			int x;
//			cin >> x;
//			a.set(j, x);
//		}
//		int K = 0, J = 0, C = 0;
//		for (int j = 0; j < num; j++) {
//			if (j % 3 == 0) {
//				K += a.at(j);
//			}
//			else if (j % 3 == 1) {
//				J += a.at(j);
//			}
//			else if (j % 3 == 2) {
//				C += a.at(j);
//			}
//		}
//		cout << K << " " << J << " " << C << endl;
//	}
//	return 0;
//}