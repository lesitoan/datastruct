#include <iostream>
using namespace std;

class Queue {
	public:
		Queue(int size);
		void enQueue(int x);
		int deQueue();
		void display();
		~Queue();
	
	private:
		int size;
    	int front;
    	int rear;
    	int* arr;
};

//dung linked list
struct Node {
	int data;
	Node* next;
};

class QueueLinkedList {
	public:
		QueueLinkedList();
		~QueueLinkedList();
		void enQueue(int x);
		void display();
		int deQueue();
		
	private:
		Node* front;
		Node* rear;
};


int main() {
//	Queue* queue = new Queue(5);
//	queue->enQueue(1);
//	queue->display();
//	delete queue;

	QueueLinkedList* queue = new QueueLinkedList();
	queue->enQueue(5);
	queue->enQueue(6);
	queue->enQueue(7);
	queue->deQueue();
	queue->display();
		
	getchar();
	return 0;
}

Queue::Queue(int size) {
	this->size = size;
	front = rear = 0;
	arr = new int[size];
}

void Queue::enQueue(int x) {
	if((rear+1)%size == front) {
		cout << "full" << endl;
	} else {
		rear = (rear+1)%size;
		arr[rear] = x;
	}
}

int Queue::deQueue() {
	if(front == rear) {
		cout << "Empty" << endl;
		return -1;
	} else {
		front = (front + 1) % size;
		return arr[front];
	}
}

void Queue::display() {
    int i = (front + 1) % size;
    while (i != (rear + 1) % size) {
    	cout << arr[i] << "\t";
    	i = (i + 1) % size;
	}
    cout << endl;
}

Queue::~Queue() {
	delete[] arr;
}

QueueLinkedList::QueueLinkedList() {
	front = NULL;
	rear = NULL;
}

void QueueLinkedList::enQueue(int x) {
	Node* t = new Node;
	if(!t) cout << "heap full" << endl;
	t->data = x;
	t->next = NULL;
	if(!front) {
		front = rear = t;
	} else {
		rear->next = t;
		rear = t;
	}
}

int QueueLinkedList::deQueue() {
	if(!front) {
		cout << "empty" << endl;
		return -1;
	} else {
		Node* t = front;
		front = front->next;
		delete t;
	}
}
QueueLinkedList::~QueueLinkedList() {
	while(front) {
		Node* t = front;
		front = front->next;
		delete t;
	}
}

void QueueLinkedList::display() {
	if(!front) return;
	Node* p = front;
	while(p) {
		cout << p->data << "\t";
		p = p->next;
	}
	cout << endl;
}



