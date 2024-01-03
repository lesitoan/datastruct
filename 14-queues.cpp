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

Queue::Queue(int size) {
	this->size = size;
	front = rear = -1;
	arr = new int[size];
}

void Queue::enQueue(int x) {
	if(rear == size - 1) {
		cout << "full" << endl;
	} else {
		rear++;
		arr[rear] = x;
	}
}

int Queue::deQueue() {
	if(front == rear) {
		cout << "Empty" << endl;
		return -1;
	} else {
		front++;
		return arr[front];
	}
}

void Queue::display() {
	for(int i = front + 1; i <= rear; i++) {
		cout << arr[i] << "\t";
	}
	cout <<endl;
	
}

Queue::~Queue() {
	delete[] arr;
}



int main() {
	Queue* queue = new Queue(5);
	queue->enQueue(1);
	queue->enQueue(1);
	queue->enQueue(3);
	queue->enQueue(4);
	queue->enQueue(5);
	queue->enQueue(6);
	queue->display();
	queue->deQueue();
	queue->deQueue();
	queue->deQueue();
	queue->display();
	
	
	delete queue;
	getchar();
	return 0;
}
