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


int partition(int* arr, int l, int r) {
	int key = l;
	l++;
	do {
		while(arr[l] < arr[key]) l++;
		while(arr[r] > arr[key]) r--;
		if(l < r) {
			swap(arr[l], arr[r]);
			l++; r--;
		}
	} while(l < r);
	swap(arr[key], arr[r]);
	return r;
}

void quickSort(int* arr, int l, int r) {
	
	if(l < r) {
		int indexOfEleSorted = partition(arr, l, r);
		displayArr(arr, 9);
		quickSort(arr, l, indexOfEleSorted-1);
		quickSort(arr, indexOfEleSorted+1, r);
	}
}


int main() {
	int arr[9] = {1,2,3,4,5,6,7,8,9};
//	bubbleSort(arr, 5);
//	insertSort(arr, 9);
//	selectionSort(arr, 9);
	quickSort(arr, 0, 8);
//	displayArr(arr, 9);
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
