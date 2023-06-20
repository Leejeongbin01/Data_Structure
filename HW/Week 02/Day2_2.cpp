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
//	void at(int idx) {
//		if (arr[idx] == 0) {
//			cout << 0 << endl;
//		}
//		else {
//			cout << arr[idx] << endl;
//		}
//	}
//	void set(int idx, int x) {
//		if (arr[idx] == 0) {
//			cout << 0 << endl;
//		}
//		else {
//			arr[idx] = x;
//		}
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
//	int T,x,tmp;
//	string s;
//	Array a(10000);
//
//	cin >> T;
//	for (int i = 0; i < T; i++) {
//		cin >> s;
//		if (s == "at") {
//			cin >> x;
//			a.at(x);
//		}
//		else if (s == "add") {
//			cin >> x >> tmp;
//			a.add(x, tmp);
//		}
//		else if (s == "set") {
//			cin >> x >> tmp;
//			a.set(x, tmp);
//		}
//		else if (s == "remove") {
//			cin >> x;
//			a.remove(x);
//		}
//		else if (s == "printArray") {
//			a.printArray();
//		}
//	}
//
//
//	return 0;
//}