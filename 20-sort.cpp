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

//INSERT SORT
void insertSort(int* arr, int n) {
	for(int i = 1; i < n; i++) {
		int key = arr[i];
		int j = i - 1;
		while(j > -1 && key < arr[j]) {
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

//SELECTION SORT
void selectionSort(int* arr, int n) {
	for(int i = 0; i < n - 1; i++) {
		int min = i;
		for(int j = i + 1; j < n; j++) {
			if(arr[j] < arr[min]) min = j;
		}
		swap(arr[i], arr[min]);
	}
}


int main() {
	int arr[9] = {8,5,7,3,2, -10, 100, 5, 50};
//	bubbleSort(arr, 5);
//	insertSort(arr, 9);
	selectionSort(arr, 9);
	displayArr(arr, 9);
	
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
