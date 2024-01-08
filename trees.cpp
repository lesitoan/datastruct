#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

struct Node {
	Node* lChild;
	int data; 
	Node* rChild;
};


class Tree {
private:
	Node* root;
	queue<Node*> queue;
public:
	Tree();
	~Tree();
	void create();
	void preOrder(Node* t);
    void preOrder() { preOrder(root); }
    void iterativePreOrder();
    void iterativePostOrder();
    void levelOrder();
};

void generatingTree(int* p, int m, int* q, int n) {
	if(m != n) cout << "invalid data input" << endl;
	for(int i = 0; i < m; i++) {
		int check = m;
		vector<int> right;
		vector<int> left;
		for( int j = 0; j < n; j++) {
			if(check == m) {
				right.push_back(q[j]);
			}else if(p[i] == q[j]) {
				
			}
		}
	}
}


int main() {
	Tree* tree = new Tree;
	tree->create();
//	tree->iterativePreOrder();
	tree->iterativePostOrder();
	cout << endl;
	tree->levelOrder();
	delete tree;
	int k; cin >> k;
	getchar();
	return 0;
}

Tree::Tree() {
		root = new Node;
		root->lChild = nullptr;
		root->rChild = nullptr;
		queue.push(root);
}

Tree::~Tree() {
	while(!queue.empty()) {
		queue.pop();
	}
}

void Tree::create() {
	cout << "Enter Root Data:" << flush;
	cin >> root->data;
	int x;
	Node* p;
	while(!queue.empty()) {
		p = queue.front();
		cout << "Enter left child data of " << p->data << ": " << flush;
		cin >> x;
		if(x != -1) {
			Node* t = new Node;
			t->lChild = nullptr;
			t->rChild = nullptr;
			t->data = x;
			p->lChild = t;
			queue.push(t);
		}
		cout << "Enter right child data of " << p->data << ": " << flush;
		cin >> x;
		if(x != -1) {
			Node* t = new Node;
			t->lChild = nullptr;
			t->rChild = nullptr;
			t->data = x;
			p->rChild = t;
			queue.push(t);
		}
		queue.pop();
	}
}

void Tree::preOrder(Node* t) {
	if(t) {
		cout << t->data << "\t";
		preOrder(t->lChild);
		preOrder(t->rChild);
	}
}

void Tree::iterativePreOrder() {
    	stack<Node*> st;
    	Node* t = root;
    	while(t || !st.empty()) {
    		if(t) {
    			cout << t->data << "\t";
    			st.push(t);
    			t = t->lChild;
			} else {
				t = st.top()->rChild;
				st.pop();
			}
		}
    	
	}
	
void Tree::iterativePostOrder() {
    	stack<Node*> st1;
    	stack<int> st2;
    	Node* t = root;
    	st1.push(t);
    	while(!st1.empty()) {
    		t = st1.top();
    		st1.pop();
    		st2.push(t->data);
    		if(t->lChild) st1.push(t->lChild);
    		if(t->rChild) st1.push(t->rChild);
		};
		while(!st2.empty()) {
			cout << st2.top() << "\t";
			st2.pop();
		}
	}
	
void Tree::levelOrder() {
    	Node* t = root;
    	std::queue<Node*> q;
    	q.push(t);
    	while(!q.empty()) {
    		t = q.front();
    		q.pop();
    		cout << t->data << "\t";
    		if(t->lChild) q.push(t->lChild);
    		if(t->rChild) q.push(t->rChild);
		}
		cout << endl;
	}
