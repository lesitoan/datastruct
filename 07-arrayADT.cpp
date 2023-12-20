#include <iostream>
#include <algorithm>
using namespace std;

void display(int* arr, int n);
int binarySearch(int* arr, int l, int r, int x);
int binarySearchRecursion(int* arr, int l, int r, int x);
int linearSearch(int* arr, int n, int x);
void reverse(int* arr, int n);
void insertElement(int* arr, int n, int x, int* newArr);
bool isSorted(int* arr, int n);
void sortNegativePositive(int* arr, int n);
void merge2Array(int* arr1, int n1, int* arr2, int n2, int* newArr); //2 arr sorted
int findSingleMissingElement(int* arr, int n); // tìm 1 phần tử bị thiếu ( arr gồm n số tự nhiên liên tiếp )
void findMultipleMissingElement(int* arr, int n); // tìm n phần tử bị thiếu trong dãy số liên tiếp
void findMultipleMissingElementNoSort(int* arr, int n);
void findDuplicates(int* arr, int n); //sorted
void findDuplicatesHashTable(int* arr, int n); // cách 2 - sorted and unsort
void findDuplicates2(int* arr, int n); // unsort o(n^2)
void findAPairOfElementHashTable(int* arr, int n, int x); // vd: 10 = 7 + 3 = 6 + 5


int main() {
	/*
	int arr[] = { 1,2,4,7,11,12,13,18,21,27,33 };
	const int length = sizeof(arr) / sizeof(int);

	cout << "index of x: " << binarySearchRecursion(arr, 0, length - 1, 11) << endl;
	cout << "index of x: "<< linearSearch(arr, length - 1, 11) << endl;

	//reverse(arr, sizeof(arr) / sizeof(int));

	display(arr, length);
	int newArr[length + 1];
	insertElement(arr, length, 8, newArr);
	display(newArr, sizeof(newArr) / sizeof(int));

	if (isSorted(arr, length)) cout << "Arr sorted" << endl;
	else cout << "Arr not sort" << endl;

	int arr2[] = { 1,-4,0,-7,2,8,-8,15,7,-1 };
	sortNegativePositive(arr2, sizeof(arr2) / sizeof(int));
	display(arr2, sizeof(arr2) / sizeof(int));

	//merge
	int arr3[] = { 5,8,12,17};
	const int lengthArrMerge = length + (sizeof(arr3) / sizeof(int));
	int arrMerge[lengthArrMerge];
	merge2Array(arr, length, arr3, sizeof(arr3) / sizeof(int), arrMerge);
	display(arrMerge, lengthArrMerge);
	*/

	// find element missing in arr
	//int arr4[] = { 6,7,8,10,11,12,13 };
	//cout << "Element missing: " << findSingleMissingElement(arr4, sizeof(arr4) / sizeof(int)) << endl;

	// find multiple element in array sorted
	//int arr5[] = { 1,2,3,4,5,8,12,20};
	//findMultipleMissingElement(arr5, sizeof(arr5) / sizeof(int));

	// find multiple element in array unsort
	//int arr6[] = {8,2,5,9,15};
	//findMultipleMissingElementNoSort(arr6, sizeof(arr6) / sizeof(int));

	//find duplicates
	//int arr7[] = { 3,4,4,5,5,5,7,9,10,10,10 ,10};
	//findDuplicates(arr7, sizeof(arr7) / sizeof(int));
	//findDuplicatesHashTable(arr7, sizeof(arr7) / sizeof(int));

	// find duplicates arr unsort
	int arr8[] = { 4,5,8,4,5,1,2,2,2,0 };
	//findDuplicates2(arr8, sizeof(arr8) / sizeof(int));
	findAPairOfElementHashTable(arr8, sizeof(arr8) / sizeof(int), 10);
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

bool isSorted(int* arr, int n) {
	for (int i = 0; i < (n-1); i++) {
		if (*(arr + i) > *(arr + i + 1)) return false;
	}
	return true;
}

void sortNegativePositive(int* arr, int n) {
	int i = 0, j = n - 1;
	while (i < j) {
		while(*(arr + i) < 0) i++;
		while(*(arr + j) >= 0) j--;
		int md = *(arr + i);
		*(arr + i) = *(arr + j);
		*(arr + j) = md;
		i++;
		j--;
	}
}

void merge2Array(int* arr1, int n1, int* arr2, int n2, int* newArr) { 
	int i = 0, j = 0, k = 0;
	while (i < n1 && j < n2) {
		if (*(arr1 + i) < *(arr2 + j)) {
			*(newArr + k) = *(arr1 + i);
			i++;
		} else {
			*(newArr + k) = *(arr2 + j);
			j++;
		}
		k++;
	}
	while (i < n1) {
		*(newArr + k) = *(arr1 + i);
		i++; k++;
	};
	while (j < n2) {
		*(newArr + k) = *(arr2 + j);
		j++; k++;
	}
}

int findSingleMissingElement(int* arr, int n) {
	// KC = giá trị - index => const
	const int space = arr[0];
	for (int i = 1; i < n; i++) {
		if ((arr[i] - i) != space) {
			return i + space;
			break;
		}
	}
}

void findMultipleMissingElement(int* arr, int n) {
	int space = arr[0];
	for (int i = 1; i < n; i++) {
		while ((arr[i] - i) > space) {
			cout << space + i << "\t";
			space++;
		}
	}
	cout << endl;
}

void findMultipleMissingElementNoSort(int* arr, int n) {
	int max = arr[0];
	int min = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] > max) max = arr[i];
		if (arr[i] < min) min = arr[i];
	}
	int* arr1 = new int[max + 1] {0};
	for (int i = 0; i < n; i++) {
		arr1[arr[i]] = arr[i];
	}
	for (int i = min; i < max + 1; i++) {
		if(arr1[i] == 0) {
			cout << i << "\t";
		}
	}
	cout << endl;
	delete[] arr1;
}

void findDuplicates(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		if (*(arr + i) == *(arr + i + 1)) {
			int j = i + 1;
			while (*(arr + j) == *(arr + i)) j++;
			cout << *(arr + i) << " duplicates: " << j - i << endl;
			i = j - 1;
		}
	}
}

void findDuplicatesHashTable(int* arr, int n) {
	int max = arr[0];
	int min = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] > max) max = arr[i];
		if (arr[i] < min) min = arr[i];
	}
	int* arr1 = new int[max + 1] {0};
	for (int i = 0; i < n; i++) {
		arr1[arr[i]]++;
	}
	for (int i = min; i < max + 1; i++) {
		if (arr1[i] > 1) {
			cout << i << " duplicates: " << arr1[i] << endl;
		}
	}
	delete[] arr1;
}

void findDuplicates2(int* arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		if (arr[i] != -1) {
			int count = 1;
			for (int j = i + 1; j < n; j++) {
				if (arr[i] == arr[j]) {
					arr[j] = -1;
					count++;
				}
			}
			if (count != 1) {
				cout << arr[i] << " duplicates: " << count << endl;
			}
		}
	}
}

void findAPairOfElementHashTable(int* arr, int n, int x) {
	int max = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] > max) max = arr[i];
	}
	int* arr1 = new int[max + 1] {0};
	display(arr1, max + 1);
	for (int i = 0; i < n; i++) {
		if ((arr1[x - arr[i]] != 0) && (x - arr[i] <= max)) {
			cout << x - arr[i] << " + " << arr[i] << " = " << x << endl;
		}
		arr1[arr[i]]++;
	}
	delete[] arr1;
}




