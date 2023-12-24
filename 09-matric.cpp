#include <iostream>
using namespace std;


class DiagonalMatric {
	private:
		int*  arr;
		int n;	
	public:
		DiagonalMatric(int a = 2) {
			n = a;
			arr = new int[a];
		}
		
		void set(int i, int j, int x) {
			if(i == j) arr[i - 1] = x;
		};
		
		int get(int i, int j) {
			if( i == j) {
				return arr[i - 1];
			}
		};
		
		void display() {
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					if( i == j) {
						cout << arr[i] << "\t";
					} else {
						cout << 0 << "\t";
					}
				}
			cout << endl;
			}
		};
		
		~DiagonalMatric() {
			delete[] arr;
			cout << "deleted diagonal matric !!!" <<  endl;
		};	
};

class LowerTriangularMatric {
	private:
		int n;
		int* arr;
	public:
		LowerTriangularMatric(int n) {
			this->n = n* (n + 1) / 2;
			arr = new int[this->n];
		};
		~LowerTriangularMatric() {
			delete[] arr;
			cout << "deleted lower triangular matric !!!" << endl;
		}
		void set(int i, int j, int x) {
			if(i >= j) {
				int index = i*(i - 1) / 2 + (j - 1);
				arr[index] = x;
			}
		}
		int get(int i, int j) {
			if(i>= j) {
				int index = i*(i - 1) / 2 + (j - 1);
				return arr[index];
			}
		}
		void display() {
			for(int i = 1; i <= n; i++) {
				for(int j = 1; j <= n; j++) {
					if(i>= j) {
						int index = i*(i - 1) / 2 + (j - 1);
						cout << arr[index] << "\t";
					} else {
						cout << 0 << "\t";
					}
				}
				cout << endl;
			}
		}
};


int main() {
	int n = 5;
//	DiagonalMatric* diagonal = new DiagonalMatric(n);
//	for(int i = 1; i <= n; i++) {
//		int value;
//		cout <<"set gia tri m[" << i << "][" << i << "] = ";
//		cin >> value;
// 		diagonal->set(i, i, value);
//	}
//	cout << diagonal->get(2,2) << endl;
//	diagonal->display();
//	delete diagonal;

	LowerTriangularMatric* lowerTriangular = new LowerTriangularMatric(n);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(i >= j) {
				int value;
				cout <<"set gia tri m[" << i << "][" << j << "] = ";
				cin >> value;
 				lowerTriangular->set(i, j, value);
			}
		}
	}
	cout << lowerTriangular->get(3,2) << endl;
	lowerTriangular->display();
	delete lowerTriangular;
	return 0;
}

 
