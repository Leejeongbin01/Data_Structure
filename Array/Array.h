#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;

class Array {
private:
	int size; // 사이즈
	int* arr; // 배열
public:
	Array(int s) :size(s) {
		this->arr = new int[size];
		for (int i = 0; i < size; i++) {
			arr[i] = 0;
		}
	}
	// 생성자, 받은 사이즈만큼 크기 결정, 모든 값 0으로 초기화

	int at(int idx) {
		return arr[idx];
	}
	// 해당 위치에 저장된 값 반환
	// 원소가 없는 index값 주어졌을 때 0 리턴
	
	void set(int idx, int x) {
		arr[idx] = x;
	}
	// 해당 index에 저장된 값 덮어씌우기

	void add(int idx, int num) {
		if (idx > size-1) { // 배열의 사이즈를 벗어나므로..
			cout << "add시, 지정한 idx 값은 배열의 사이즈를 벗어남\n";
			return;
		}
		
		for (int i = size - 2; i >= idx; i--) {
			arr[i + 1] = arr[i];
		}
		arr[idx] = num;
	}
	// 해당 index에 값 삽입
	
	int remove(int idx) {
		int value = arr[idx];

		for (int i = idx; i < size+1; i++) {
			arr[i] = arr[i + 1];
		}
		arr[size - 1] = 0;
		return value;
	}
	// 해당 index에 값 삭제하고 그 값 반환
	// 원소가 없을 경우와 중간 값 삭제일 경우 한 칸씩 당기기

	void printArray() {
		cout << "\n배열에 저장되어 있는 값을 차례대로 출력하겠습니다.\n";
		for (int i = 0; i < size; i++) {
			cout << arr[i] << " ";
		}
			cout << endl;
	}
	// 배열에 저장되어 있는 값 차레로 출력
	// 배열이 비어있으면 정지
};

#endif // !ARRAY_H

