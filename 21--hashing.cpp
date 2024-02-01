#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Chaining {
private:
	list<int> hashTable[10];
public:
	int hashFunc(int x) {
		return x % 10;
	}
	void insert(int x) {
		int index = hashFunc(x);
		hashTable[index].push_front(x);
	}
	bool search(int x) {
		int index = hashFunc(x);
		stack<int> st;
		bool check = false;
		while(!hashTable[index].empty()) {
			if(hashTable[index].front() == x) {
				check = true;
				break;
			} else {
				st.push(hashTable[index].front());
				hashTable[index].pop_front();	
			}
		}
		while(!st.empty()) {
			hashTable[index].push_front(st.top());
			st.pop();
		}
		return check;
	}
};

class LinearProbing {
private:
	int size;
	list<int> hashTable[10];
public:
	LinearProbing(int n = 10) {
		size = n * 2;
	}
	int hashFunc(int x, int i = 0) {
		return (x + i) % 10 ;
	}
	void insert(int x) {
		int i = 0;
		int index = hashFunc(x, i);
		while(!hashTable[index].empty()) {
			i++;
			index = hashFunc(x, i);
		}
		hashTable[index].push_front(x);
	}
	bool search(int x) {
		int index = hashFunc(x);
		bool check = false;
		int i = 0;
		while(!hashTable[index].empty()) {
			if(hashTable[index].front() == x) return true;
			i++;
			index = hashFunc(x, i);
		}
		return false;
	}
};

int main() {
	
//	Chaining* Ch = new Chaining;
//	Ch->insert(10);
//	Ch->insert(11);
//	Ch->insert(12);
//	Ch->insert(13);
//	Ch->insert(14);
//	Ch->insert(15);
//	Ch->insert(25);
//	Ch->insert(35);
//	if(Ch->search(45)) {
//		cout << "true";
//	} else {
//		cout << "false";
//	}
//	delete Ch;

	LinearProbing* LP = new LinearProbing(3);
	LP->insert(10);
	LP->insert(20);
	LP->insert(30);
	if(LP->search(30)) {
		cout << "true";
	} else {
		cout << "false";
	}if(LP->search(24)) {
		cout << "true";
	} else {
		cout << "false";
	}
	getchar();
	return 0;
}
