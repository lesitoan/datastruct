#include <iostream>
#include <queue>
#include <stack>

using namespace std;
struct Node {
	Node* lChild;
	int data; 
	Node* rChild;
};


class BST {
private:
	Node* root;
public:
	BST();
	~BST();
	void preOrder(Node* t);
    void preOrder() { preOrder(root); };
    
	Node* search(Node* t, int key);   
    Node* search(int key) { return search(root, key); };
    
    Node* insert(Node* t, int key);
    Node* insert(int key) { return insert(root, key); };
    
    Node* inPre(Node* t);
	Node* inSucc(Node* t);
    
    void deleteNode(Node* &t, int key);
	void deleteNode(int key) { deleteNode(root, key); };
	
	void createBSTFromPreOder(int* pre, int length);
};


int main() {
	BST* bst = new BST;
	int arr[] = {30, 20, 10, 15, 25, 40, 50, 45};
	bst->createBSTFromPreOder(arr, 8);
	
	
	bst->insert(9);
//	bst->insert(15);
//	bst->insert(5);
//	bst->insert(20);
//	bst->insert(16);
//	bst->insert(8);
//	bst->insert(12);
//	bst->insert(3);
//	bst->insert(6);
//	Node* r = bst->search(60);
//	if(r) {
//		cout << "found" << endl;
//	} else {
//		cout << "not found" << endl;
//	}
//	bst->preOrder();
//	cout << endl;
//	bst->deleteNode(9);
	bst->preOrder();

	
	int k; cin >> k;
	getchar();
	return 0;
}

BST::BST() {
	root = nullptr;
}

BST::~BST() {
	delete root;
}

void BST::preOrder(Node* t) {
	if(t != nullptr) {
		if(t->data != -1)cout << t->data << "\t";
		preOrder(t->lChild);
		preOrder(t->rChild);
	}
}

Node* BST::search(Node* t, int key) {
		if(!t) {
			return nullptr;
		} else if (t->data == key) {
			return t;
		} else if (t->data > key) {
			return search(t->lChild, key);
		} else {
			return search(t->rChild, key);
		}
	}   
	
Node* BST::insert(Node* t, int key) {
    	if(!t) {
    		Node* p = nullptr;
    		p = new Node;
    		p->lChild = p->rChild = nullptr;
    		p->data = key;
    		if(!root) root = p;
    		return p;
    		
		} else if (t->data > key) {
			t->lChild = insert(t->lChild, key);
		} else if (t->data < key) {
			t->rChild = insert(t->rChild, key);
		}	
	}
	
Node* BST::inPre(Node* t) {
    	Node* p = t;
    	while(t) {
    		p = t;
    		t = t->rChild;
		}
		return p;
	} 
	
Node* BST::inSucc(Node* t) {
    	Node* p = t;
    	while(t) {
    		p = t;
    		t = t->lChild;
		}
		return p;
	}
	
void BST::deleteNode(Node* &t, int key) {
		//tree empty
    	if(!t) return;
    	//tree only root node || key = leaf node
    	if(t->lChild == nullptr && t->rChild == nullptr && t->data == key) {
			t->data = -1; return;
		}
		//key != leaf node
		if(t->data > key) {
			deleteNode(t->lChild, key);
		} else if(t->data < key) {
			deleteNode(t->rChild, key);
		} else {
			Node* inSuccNode = inSucc(t->rChild);
			if(inSuccNode) {
				t->data = inSuccNode->data;
				deleteNode(inSuccNode, inSuccNode->data);
			} else {
				Node* inPreNode = inPre(t->lChild);
				t->data = inPreNode->data;
				deleteNode(inPreNode, inPreNode->data);
			}
		}
    	
	}

void BST::createBSTFromPreOder(int* pre, int length) {
		if(root) return;
		root = new Node;
		root->data = pre[0];
		root->lChild = root->rChild = nullptr;
		Node* p = root;
		std::stack<Node*> st;
		for(int i=1; i<length; i++) {
			//insert left
			if(pre[i] < p->data) {
				st.push(p);
				Node* t = new Node;
				t->data = pre[i];
				t->lChild = t->rChild = nullptr;
				p->lChild = t;
				p = t;
			//insert right
			} else if(pre[i] > p->data) {
				if(st.empty() || pre[i] < st.top()->data) {
					Node* t = new Node;
					t->data = pre[i];
					t->lChild = t->rChild = nullptr;
					p->rChild = t;
					p = t;
				} else if(pre[i] > st.top()->data) {
					p = st.top();
					st.pop();
					Node* t = new Node;
					t->data = pre[i];
					t->lChild = t->rChild = nullptr;
					p->rChild = t;
					p = t;
				}
			}
		}
	}
