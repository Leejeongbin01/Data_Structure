#include <iostream>
#include <vector>
using namespace std;

#define NOITEM 0
#define ISITEM 1
#define	AVAILABLE 2

struct entry {
	int key;
	string value;
	int valid;

	entry() {
		key = 0;
		value = "";
		valid = NOITEM;
	}
	
	entry(int key, string value) {
		this->key = key;
		this->value = value;
		valid = ISITEM;
	}
	void erase() {
		valid = AVAILABLE;
	}
};

// 선형 조사법

class hashTable {
private:
	entry* table;
	int cap;
	int hashFnc(int key) {
		return key % cap;
	}
public:
	hashTable(int n) {
		cap = n;
		table = new entry[cap];
	}
	void put(int key, string value) {
		int idx = hashFnc(key);
		int probe = 1;
		while (table[idx].valid == ISITEM && probe <= cap) {
			idx = hashFnc(idx + 1);
			probe++;
		}
		if (probe > cap) {
			return;
		}
		table[idx] = entry(key, value);
	}
	void erase(int key) {
		int idx = hashFnc(key);
		int probe = 1;
		while (table[idx].valid != NOITEM && probe <= cap) {
			if (table[idx].valid == ISITEM && table[idx].key == key) {
				table[idx].erase();
				return;
			}
			idx = hashFnc(idx + 1);
			probe++;
		}
		return;
	}
	string find(int key) {
		int idx = hashFnc(key);
		int probe = 1;
		while (table[idx].valid != NOITEM && probe <= cap) {
			if (table[idx].valid == ISITEM && table[idx].key == key) {
				return table[idx].value;
			}
			idx = hashFnc(idx + 1);
			probe++;
		}
		return "";
	}
};

// 이중해싱
class HashTable {
private:
	entry* table;
	int cap;
	int div;
	int hashFnc(int key) {
		return key % cap;
	}
	int hashFnc2(int key) {
		return div - (key % div);
	}
public:
	HashTable(int n, int m) {
		cap = n;
		div = m;
		table = new entry[cap];
	}
	void put(int key, string value) {
		int idx = hashFnc(key);
		int probe = 1;
		while (table[idx].valid == ISITEM && probe <= cap) {
			idx = hashFnc(idx + hashFnc2(key));
			probe++;
		}
		if (probe > cap) {
			return;
		}
		table[idx] = entry(key, value);
		return;
	}
	void erase(int key) {
		int idx = hashFnc(key);
		int probe = 1;

		while (table[idx].valid != NOITEM && probe <= cap) {
			if (table[idx].valid == ISITEM && table[idx].key == key) {
				table[idx].erase();
				return;
			}
			idx = hashFnc(idx + hashFnc2(key));
			probe++;
		}

		return;
	}
	string find(int key) {
		int idx = hashFnc(key);
		int probe = 1;

		while (table[idx].valid != NOITEM && probe <= cap) {
			if (table[idx].valid == ISITEM && table[idx].key == key) {
				return table[idx].value;
			}
			idx = hashFnc(idx + hashFnc2(key));
			probe++;
		}

		return;
	}
};
