#include  <iostream>
#include <cmath>
using namespace std;

struct Node {
	int data;
	Node* next;
}* first = NULL;

void createLinkedList(int* arr, int n) {
	first= new Node;
	first->data = arr[0];
	first->next = NULL;
	Node* t, * last;
	last = first;
	for(int i = 1; i < n; i++) {
		t = new Node;
		t->data = arr[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
}

void displayLinkedlist (Node* p) {
	if (p != NULL) {
		cout << p->data << "\t";
		displayLinkedlist(p->next);
	}
}

int count(Node* p) {
	if(!p) return 0;
	return count(p->next) + 1;
}

int total(Node* p) {
	if(!p) return 0;
	return p->data + total(p->next);
}

int maxOfLinkedList(Node* p) {
	int x;
	int maxValue = -pow(2,31);
	if(!p) return maxValue;
	maxValue = p->data;
	x = maxOfLinkedList(p->next);
	if(x > maxValue) {
		return x;
	} else {
		return maxValue;
	}
}

Node* search(Node* p, int x) {
	Node* tmp = p;
	while (tmp) {
		if(x == tmp->data) return tmp;
		tmp = tmp->next;
	}
	return NULL;
}

Node* searchRecursion(Node* p, int x) {
	if(!p) return NULL;
	if(x == p->data) return p;
	return searchRecursion(p->next, x);
}

int main() {
	int arr[] = {9,8,7,6,5,4,3,2,1};
	int n = 9;
	createLinkedList(arr, n);
	displayLinkedlist(first);
	cout << "\n" << count(first);
	cout << "\n" << total(first) << endl;
	cout << maxOfLinkedList(first) << endl;
	cout << search(first, 7) << endl;
	cout << searchRecursion(first, 7) << endl;
	getchar();
	return 0;
}

