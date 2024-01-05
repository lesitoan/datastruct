#include <iostream>
using namespace std;

struct NodeOfTree {
	NodeOfTree* lChild;
	int data; 
	NodeOfTree* rChild;
};

struct NodeOfQueue {
	NodeOfTree* data;
	NodeOfQueue* next;
};

class Queue {
private:
	NodeOfQueue* front;
	NodeOfQueue* rear;
public:
	Queue() {
		front = rear = nullptr;
	}
	void enQueue(NodeOfTree* p) {
		NodeOfQueue* t = new NodeOfQueue;
		t->data = p;
		t->next = nullptr;
		if(!front) {
			front = rear = t;
		} else {
			rear->next = t;
			rear = t;
		}
	}
	void deQueue() {
		if(!front) {
			cout << "enpty" << endl;
		} else {
			NodeOfQueue* t = front;
			front = front->next;
			delete t;
		}
	}
	NodeOfTree* pop() {
		if(!front) {
			cout << "enpty" << endl;
		} else {
			return front->data;
		}
	}
	
	bool isEmpty() {
		if(!front) return true;
		return false;
	}
	~Queue(){
		while(front) {
			NodeOfQueue* t = front;
			front = front->next;
			delete t;
		}
	}
};

class Tree {
private:
	NodeOfTree* root;
	Queue* queue = new Queue;
public:
	Tree() {
		root = new NodeOfTree;
		root->lChild = nullptr;
		root->rChild = nullptr;
		queue->enQueue(root);
	}
	void create() {
		int x = -1;
		int y = -1;
		NodeOfTree* p;
		while(!queue->isEmpty()) {
			cout << "Ezzzzzzzzzz " << endl;
			p = queue->pop();
			cout << "Enter data of left child: ";
			cin >> x;
			if(x != -1) {
				cout << "x" << endl;
				NodeOfTree* t = new NodeOfTree;
				t->lChild = nullptr;
				t->rChild = nullptr;
				t->data = x;
				p->lChild = t;
				queue->enQueue(t);
				x = -1;
			}
			cout << "Enter data of right child: ";
			cin >> y;
			if(y != -1) {
				cout << "y" << endl;
				NodeOfTree* t = new NodeOfTree;
				t->lChild = nullptr;
				t->rChild = nullptr;
				t->data = y;
				p->rChild = t;
				queue->enQueue(t);
				y = -1;
			}
			queue->deQueue();
		}

	}
};



int main() {
	Tree* tree = new Tree;
	tree->create();
	
	delete tree;
	getchar();
	return 0;
}
