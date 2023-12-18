#include <iostream>
using namespace std;

int binarySearch(int* arr, int l, int r, int x);
int binarySearchRecursion(int* arr, int l, int r, int x);

int main() {
	int arr[] = { 1,2,4,7,11,12,13,18,21,27,33 };
	cout << "index of x: "<< binarySearchRecursion(arr, 0, sizeof(arr) / sizeof(int) -1, 11) << endl;
	return 0;
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

