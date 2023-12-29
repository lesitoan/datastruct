#include  <iostream>
#include <cmath>
using namespace std;

struct Node {
	int data;
	Node* next;
}* first = NULL;

void createLinkedList(Node* &p, int* arr, int n);
void displayLinkedlist (Node* p);
int count(Node* p);
int total(Node* p);
int maxOfLinkedList(Node* p);
Node* search(Node* p, int x);
Node* searchRecursion(Node* p, int x);
void insertNode(Node* &p, int pos, int x);
void insertLinkedListSorted(Node* &p, int x);
void deleteElement(Node* &p, int pos);
bool checkSorted (Node* p);
void deleteDuplicateSorted (Node* p);
void reverse(Node* p);
void reverseSliding(Node* &p);
void reverseRecursion(Node* p, Node* q);
Node* merge2LinkedList (Node* p, Node* q);
bool checkLoopLinkedList(Node* p);

void createCircularLinkedList(Node* p);
void displayCircular(Node* head);
void displayCircularRecursion(Node* head);

int main() {
	int arr[] = {3,7,9,9,9,11,15};
	int n = sizeof(arr) / sizeof(int);
	createLinkedList(first, arr, n);
	
	/*-----------linear linked list----------------
	displayLinkedlist(first);
	cout << "\n" << count(first);
	cout << "\n" << total(first) << endl;
	cout << maxOfLinkedList(first) << endl;
	cout << search(first, 7) << endl;
	cout << searchRecursion(first, 7) << endl;
	insertNode(first, 0, 99);
	insertLinkedListSorted(first,1);
	deleteElement(first,1);
	deleteDuplicateSorted(first);
	reverseRecursion(NULL, first);
	Node* second = NULL;
	int arr1[] = {1,3,5,6,7};
	createLinkedList(second, arr1 , 5);
	Node* merge = merge2LinkedList(first, second);
	displayLinkedlist(first);
	*/


	/*----------cricular linked list-------------*/
	createCircularLinkedList(first);
	displayCircularRecursion(first);
	
	
	getchar();
	return 0;
}


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

void reverse(Node* p) { // it khi dung
	Node* t = p;
	int length = 0;
	while(t) {
		length++;
		t = t->next;
	}
	t = p;
	int* arr = new int[length];
	for(int i = 0; i < length; i++) {
		arr[i] = t->data;
		t = t->next;
	}
	t = p;
	while(t) {
		length--;
		t->data = arr[length];
		t = t->next;
	};
	delete[] arr;
}

void reverseSliding(Node* &p) {
	Node* pre = NULL;
	Node* cur = NULL;
	Node* after = p;
	while(after) {
		pre = cur;
		cur = after;
		after = after->next;
		cur->next = pre;
	}
	first = cur;
}

void reverseRecursion(Node* p, Node* q) {
	if(q) {
		reverseRecursion(q, q->next);
		q->next = p;
	} else {
		first = p;
	}
}

Node* merge2LinkedList (Node* p, Node* q) {
	Node* last = NULL;
	Node* r = NULL;
	if(p->data < q->data) {
		r = last = p;
		p = p->next;
	} else {
		r = last = q;
		q= q->next;
	}
	r->next = NULL;
	while(p && q) {
		if(p->data < q->data) {
			last->next = p;
			last = p;
			p = p->next;
		} else {
			last->next = q;
			last = q;
			q = q->next;
		}
		last->next=NULL;
	}
	if(p) last->next = p;
	if(q) last->next = q;
	return r;
}
oid createCircularLinkedList(Node* p) {
	Node* q = p;
	Node* last = p;
	while(last) {
		q = last;
		last = last->next;
	}
	q->next = p;
};

void displayCircular(Node* head) {
	Node* last = head;
	do {
		cout << last->data << "\t";
		last = last->next;
	} while (last != head);
}

void displayCircularRecursion(Node* head) {
	static int check = 0;
	if(head != first || check == 0) {
		cout << head->data << "\t";
		check = 1;
		displayCircularRecursion(head->next);
	}
}
