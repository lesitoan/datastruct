#include  <iostream>
#include <cmath>
using namespace std;

struct Node {
	int data;
	Node* next;
}* first = NULL;

void createLinkedList(Node* &p, int* arr, int n) {
	p= new Node;
	p->data = arr[0];
	p->next = NULL;
	Node* t, * last;
	last = p;
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

void insertNode(Node* &p, int pos, int x) {
		Node* t = new Node;
		t->data = x;
	if(pos <= 0) { // before first Node
		t->next = first;
		p = t;
	} else { //after pos
		Node* q = p;
		for(int i = 0; i < pos - 1 && q; i++) {
			q = q->next;
		}
		if(!q) return; // pos > length
		t->next = q->next;
		q->next = t;
	}
}

void insertLinkedListSorted(Node* &p, int x) {
	Node* newNode = new Node;
	newNode->data = x;
	if(first->data > x) { // before first Node
		newNode->next = p;
		p = newNode;
	} else {
		Node* after = p, * before = NULL;
		while(after && after->data < x) {
			before = after;
			after = after->next;
		}
		newNode->next = after;
		before->next = newNode;
	}
}

void deleteElement(Node* &p, int pos) {
	Node* t = p;
	if(pos == 1) {
		p = p->next;
	} else {
		Node* q = NULL;
		for(int i = 0; i < pos - 1 && t; i++) {
			q = t;
			t = t->next;
		}
		q->next = t->next;
	}
	delete t;
} 

bool checkSorted (Node* p) {
	int preData = p->data;
	Node* t = p->next;
	while(t) {
		if(preData > t->data) return false;
		preData = t->data;
		t = t->next;
	}
	return true;
}

void deleteDuplicateSorted (Node* p) {
	Node* preNode = p;
	Node* curNode = p->next;
	while(curNode != NULL) {
		if(preNode->data == curNode->data) {
			preNode->next = curNode->next;
			Node* t = curNode;
			curNode = curNode->next;
			delete t;
			
		} else {
			preNode = curNode;
	}
			curNode = curNode->next;	
		}
}

void reverse(Node* p) {
	Node* pre = p;
	Node* cur = p->next;
	if(!cur->next) {
		first = cur;
		cur->next = pre;
	} else {
		reverse(cur);
		cur->next = pre;	
	}
	
}


int main() {
	int arr[] = {3,7,9,9,9,11,15};
	int n = sizeof(arr) / sizeof(int);
	createLinkedList(first, arr, n);
//	displayLinkedlist(first);
//	cout << "\n" << count(first);
//	cout << "\n" << total(first) << endl;
//	cout << maxOfLinkedList(first) << endl;
//	cout << search(first, 7) << endl;
//	cout << searchRecursion(first, 7) << endl;
//	insertNode(first, 0, 99);
//	insertLinkedListSorted(first,1);
//	deleteElement(first,1);
	deleteDuplicateSorted(first);
	reverse(first);
	displayLinkedlist(first);
	getchar();
	return 0;
}







