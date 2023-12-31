#include <iostream>
using namespace std;

struct Stack {
	int size;
	int top;
	int* arr;
};

class StackDs {
	public:
		StackDs(int size = 0) {
			stack = new Stack;
			if(size > 0) stack->arr = new int[size];
			stack->top = -1;
		}
		void push(int val) {
			stack->top ++;
			stack->arr[stack->top] = val;
		}
		int pop() {
			int val = -1;
			if(stack->top == -1) return val;
			val = stack->arr[stack->top];
			stack->top--;
			return val;
		}
		int peak(int pos) {
			int val = -1;
			if((stack->top - pos + 1) < 0) return val;
			val = stack->arr[stack->top - pos + 1];
			return val;
		}
		
		~StackDs() {
			delete[] stack->arr;
			delete stack;
		}
	
	private:
		Stack* stack;
	
};


int main() {
	StackDs* stackDs = new StackDs(5);
	stackDs->push(10);
	stackDs->push(20);
	stackDs->push(40);
	cout << stackDs->peak(2);
	stackDs->pop();
	cout << stackDs->peak(2);
	getchar();
	return 0;
}
