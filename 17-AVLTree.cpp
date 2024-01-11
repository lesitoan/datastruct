#include <iostream>
using namespace std;

struct Node {
	Node* lChild;
	Node* rChild;
	int data;
	int height;
};

class AVL{
private:
	Node* root;
public:
	AVL() { root = nullptr; };
	~AVL() { delete root; };
	void preOrder(Node* t);
    void preOrder() { preOrder(root); };
    
    int updateHeight(Node* t);
	int balanceFactor(Node *p);
	
	Node* LLRotation(Node* t);
	Node* RRRotation(Node* t);
	Node* LRRotation(Node* t);
	Node* RLRotation(Node* t);
    
    Node* insert(Node* t, int key);
	Node* insert(int key) { insert(root, key); };
};

int main() {
	AVL* avl = new AVL;
	avl->insert(10);
	avl->insert(30);
	avl->insert(20);
	avl->insert(3);
	avl->insert(15);
	avl->insert(1);
	avl->preOrder();
	getchar();
	return 0;
}

void AVL::preOrder(Node* t) {
	if(t != nullptr) {
		cout << t->data << "\t";
		preOrder(t->lChild);
		preOrder(t->rChild);
	}
}

int AVL::updateHeight(Node* t) {
    	int l = (t && t->lChild) ? t->lChild->height : 0;
    	int r = (t && t->rChild) ? t->rChild->height : 0;
    	int height = l>r ? l+1 : r+1;
    	return height;
	}
int AVL::balanceFactor(Node *p) {
	    int hl;
	    int hr;
	    hl = (p && p->lChild) ? p->lChild->height : 0;
	    hr = (p && p->rChild) ? p->rChild->height : 0;
	    return hl - hr;
	}
Node* AVL::LLRotation(Node* t) {
		Node* tl = t->lChild;
		Node* tlr = tl->rChild;
		tl->rChild = t;
		t->lChild = tlr;
		t->height = updateHeight(t);
		tl->height = updateHeight(tl);
		if(root == t) root = tl;
		return tl;
	}
Node* AVL::RRRotation(Node* t) {
		Node* tr = t->rChild;
		Node* trl = tr->lChild;
		tr->lChild = t;
		t->rChild = trl;
		t->height = updateHeight(t);
		tr->height = updateHeight(tr);
		if(root == t) root = tr;
		return tr;
	}
Node* AVL::LRRotation(Node* t) {
		Node* tl = t->lChild;
		Node* tlr = tl->rChild;
		tl->rChild = tlr->lChild;
		t->lChild = tlr->rChild;
		tlr->rChild = t;
		tlr->lChild = tl;
		t->height = updateHeight(t);
		tl->height = updateHeight(tl);
		tlr->height = updateHeight(tlr);
		if(root == t) root = tlr;
		return tlr;
	}
Node* AVL::RLRotation(Node* t) {
		Node* tr = t->rChild;
		Node* trl = tr->lChild;
		tr->lChild = trl->rChild;
		t->rChild = trl->lChild;
		trl->lChild = t;
		trl->rChild = tr;
		t->height = updateHeight(t);
		tr->height = updateHeight(tr);
		trl->height = updateHeight(trl);
		if(root == t) root = trl;
		return trl;
	}
Node* AVL::insert(Node* t, int key) {
    	if(!t) {
    		Node* p = new Node;
    		p->lChild = p->rChild = nullptr;
    		p->data = key;
    		p->height = 1;
    		if(!root) root = p;
    		return p;
		} else if(t->data < key) {
			t->rChild = insert(t->rChild, key);
		} else if(t->data > key) {
			t->lChild = insert(t->lChild, key);
		}
		t->height =  updateHeight(t);
		//balance
		if(balanceFactor(t) == 2 && balanceFactor(t->lChild) == 1) {
			return LLRotation(t);
		} else if (balanceFactor(t) == 2 && balanceFactor(t->lChild) == -1){
	        return LRRotation(t);
	    } else if (balanceFactor(t) == -2 && balanceFactor(t->rChild) == -1){
	        return RRRotation(t);
	    } else if (balanceFactor(t) == -2 && balanceFactor(t->rChild) == 1){
	        return RLRotation(t);
	    }
		return t;
	}
