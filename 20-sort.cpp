#include <iostream>
#include <stack>
using namespace std;

void swap(int& a, int& b);
void displayArr(int* arr, int n);
int partition(int* arr, int l, int r);
void mergeTwoList(int* arr, int l, int mid, int r);


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

//QUICK SORT
void quickSort(int* arr, int l, int r) {
	if(l < r) {
		int indexOfEleSorted = partition(arr, l, r);
		displayArr(arr, 9);
		quickSort(arr, l, indexOfEleSorted-1);
		quickSort(arr, indexOfEleSorted+1, r);
	}
}

//MERGE SORT
void mergeSort(int* arr, int n) {
	int p = 2;
	for(p; p<=n; p*=2) {
		int i = 0, l, r, mid;
		for(i; i+p-1<n; i= i+p) {
			l = i;
			r = i+p-1;
			mid = (l + r - 1) / 2;
			mergeTwoList(arr,l, mid, r);
		}
		if(n-i>p/2) { 
			l = i;
			r = i+p-1;
			int mid = (l + r - 1) / 2;
			mergeTwoList(arr, i, mid, n-1); 
		} 
	}
	if(p/2 < n-1) {
		mergeTwoList(arr,0, p/2-1, n-1);
	}
}

//MERGE SORT RECURSIVE
void mergeSortRecursive(int* arr, int l, int r) {
	if(l < r) {
		int mid = (l + r) / 2;
		mergeSortRecursive(arr, l, mid);
		mergeSortRecursive(arr, mid+1, r);
		mergeTwoList(arr, l, mid, r);
	}
}


int main() {
	int n = 12;
	int arr[n] = {10,5,2,4,7,3,8,9, 11, 1, -10, -20};
//	bubbleSort(arr, n);
//	insertSort(arr, n);
//	selectionSort(arr, n);
//	quickSort(arr, 0, n);
//	mergeSort(arr, n);
	mergeSortRecursive(arr, 0, 11);
	displayArr(arr, n);
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

void mergeTwoList(int* arr, int l, int mid, int r) {
	stack<int> st;
	int i = l, j = mid+1;
	while(i <= mid && j <= r) {
		if(arr[i] < arr[j]) {
			st.push(arr[i]);
			i++;
		} else {
			st.push(arr[j]);
			j++;
		}
	}
	while(i <= mid) {
		st.push(arr[i]);
		i++;
	}
	while(j <= r) {
		st.push(arr[j]);
		j++;
	}
	while(!st.empty()) {
		arr[r] = st.top();
		st.pop();
		r--;
	}
}
