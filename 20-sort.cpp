#include <iostream>
using namespace std;

void swap(int& a, int& b);
void displayArr(int* arr, int n);


//BUBBLE SORT
void bubbleSort(int* arr, int n) {
	int flag = 0;
	for(int i = 0; i < n - 1; i++) {
		flag = 0;
		for(int j = 0; j < n - 1 - i; j++) {
			if(arr[j] > arr[j+1]) {
				swap(arr[j], arr[j+1]);
				flag = 1;
			}
		}
		if(flag == 0) return;
	} 
}


int main() {
	int arr[5] = {1,2,3,4,5};
	bubbleSort(arr, 5);
	displayArr(arr, 5);
	
	getchar();
	return 0;
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp; 
}

void displayArr(int* arr, int n) {
	for(int i = 0; i < n; i++) {
		cout << arr[i] << "\t";
	}
	cout<< endl;
}
