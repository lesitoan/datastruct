#include  <iostream>
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

int main() {
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int n = 9;
	createLinkedList(arr, n);
	displayLinkedlist(first);
	cout << "\n" << count(first);
	cout << "\n" << total(first);
	getchar();
	return 0;
}

