#include <iostream>
using namespace std;

class Matrix {
	public:
		Matrix(int m = 2, int n = 2, int total = 0) {
			this->row = m;
			this->col = n;
			this-> total = total;
			subMatrix = new int*[total];
		}
		
		void create() {
			for(int i = 0; i < this->total; i++) {
				int iIndex, jIndex, value;
				cout << "Nhap \"vi tri row\" - \"vi tri col\" - \"gia tri\" cua phan tu thu: " << i + 1 << "= ";
				cin >> iIndex >> jIndex >> value;
				this->set(iIndex,jIndex, value);
			}
		} 
		
		void set(int iIndex, int jIndex, int value) {
			subMatrix[this->index] = new int[3];
			(subMatrix[this->index])[0] = iIndex;
			(subMatrix[this->index])[1] = jIndex;
			(subMatrix[this->index])[2] = value;
			this->index += 1;
		}
		
		int get(int iIndex, int jIndex) {
			for(int i = 0; i < this->total; i++) {
				if((subMatrix[i])[0] == iIndex && (subMatrix[i])[1] == jIndex) {
					return (subMatrix[i])[2];
				}
			}
			return 0;
		}
		
		void display() {
			int k = 0;
			for(int i = 0; i < this->row; i++) {
				for(int j = 0; j < this->col; j++) {
					if((subMatrix[k])[0] == i && (subMatrix[k])[1] == j) {
						cout << (subMatrix[k])[2] << "\t";
						k++;
					} else {
						cout << 0 << "\t";
					}
				}
				cout << endl;
			}
		}
		
		~Matrix() {
			for(int i = 0; i < total; i++) {
				delete[] subMatrix[i];
			}
			delete[] subMatrix;
		}

	private:
		int row, col, total;
		int index = 0;
		int** subMatrix;	
};

int main() {
	int n = 2;
	Matrix* matrix = new Matrix(8, 9, n);
	matrix->create();
	cout << matrix->get(2, 5) << endl;
	matrix->display();
	delete matrix;
	
	int kkkk;
	cin >> kkkk;
	getchar();
	return 0;
}
