#include <iostream>
using namespace std;

struct NodeMatrix {
	int col;
	int data;
	NodeMatrix* next;
};

class Matrix {
	public:
		Matrix(int numOfRow, int numOfCol) {
			this->numOfRow = numOfRow;
			this->numOfCol = numOfCol;
		};
		
		void add(int r, int c, int x) {
			NodeMatrix* t = new NodeMatrix;
			t->col = c;
			t->data = x;
			t->next = NULL;
			if(!arrOfRow[r]) {
				arrOfRow[r] = t;
			} else {
				NodeMatrix* p = arrOfRow[r];
				while (p->next) {
					p = p->next;
				}
				p-> next = t;
			}
		}
		
		void create() {
			arrOfRow = new NodeMatrix*[numOfRow]{nullptr};
			cout << "Nhap so phan tu cua matrix: ";
			cin >> totalOfElement;
			for(int i = 0; i < totalOfElement; i++) {
				int r, c, data;
				cout << "nhap -ROW-COL-DATA cua moi phan tu: ";
				cin >> r >> c >> data;
				add(r, c, data);
			}
		}
		
		void display() {
			for(int i = 0; i < numOfRow; i++) {
				NodeMatrix* p = arrOfRow[i];
				for(int j = 0; j < numOfCol; j++) {
					if(!p || p->col != j) {
						cout << 0 << "\t";
					} else {
						cout << p->data << "\t";
						p = p->next;
					}
				}
				cout << endl;
			}
		}
		
		~Matrix() {
			for(int i = 0; i < numOfRow; i++) {
				if(!arrOfRow[i]) continue;
				while(arrOfRow[i]) {
					NodeMatrix* q = arrOfRow[i];
					arrOfRow[i] = arrOfRow[i]->next;
					delete q;
				}
			}
			delete arrOfRow;
		}
	
	private:
		int totalOfElement;
		int numOfRow;
		int numOfCol;
		NodeMatrix** arrOfRow;
};


int main() {
	Matrix* matrix = new Matrix(3, 3);
	matrix->create();
	matrix->display();
	delete matrix;
	getchar();
	return 0;
}
