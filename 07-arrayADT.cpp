#include <iostream>
using namespace std;
void display(int* arr, int n);
int binarySearch(int* arr, int l, int r, int x);
int binarySearchRecursion(int* arr, int l, int r, int x);
int linearSearch(int* arr, int n, int x);
void reverse(int* arr, int n);
void insertElement(int* arr, int n, int x, int* newArr);


int main() {
	int arr[] = { 1,2,4,7,11,12,13,18,21,27,33 };
	const int length = sizeof(arr) / sizeof(int);
	cout << "index of x: " << binarySearchRecursion(arr, 0, length - 1, 11) << endl;
	cout << "index of x: "<< linearSearch(arr, length - 1, 11) << endl;
	//reverse(arr, sizeof(arr) / sizeof(int));
	display(arr, length);
	int newArr[length + 1];
	insertElement(arr, length, 8, newArr);
	display(newArr, sizeof(newArr) / sizeof(int));
	return 0;
}

void inputArr(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "] = ";
		cin >> *(arr + i);
	}
}

void display(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << *(arr + i) << "\t";
	}
	cout << endl;
}

int binarySearch(int* arr, int l, int r, int x) {
	while (l <= r) {
		int m = (l + r) / 2;
		if (x == arr[m]) return m;
		else if (x > arr[m]) l = m + 1;
		else r = m - 1;
	}
	return -1;
}

int binarySearchRecursion(int* arr, int l, int r, int x) {
	if (l > r) return -1;
	int m = (l + r) / 2;
	if (x == arr[m]) return m;
	else if (x >= arr[m]) return binarySearchRecursion(arr, m + 1, r, x);
	else return binarySearchRecursion(arr, l, m - 1, x);
}

int linearSearch(int* arr, int n, int x) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == x) return i;
	}
	return -1;
}

void reverse(int* arr, int n) {
	int md = 0;
	for (int i = 0; i < (n / 2); i++) {
		md = *(arr + n - 1 - i);
		*(arr + n - 1 - i) = *(arr + i);
		*(arr + i) = md;
	}
}

void insertElement(int* arr, int n, int x, int* newArr) { //arr sorted
	int i = n - 1;
	while (x < arr[i]) {
		newArr[i + 1] = arr[i];
		i--;
	}
	newArr[i + 1] = x;
	while (i >= 0) {
		newArr[i] = arr[i];
		i--;
	}
}