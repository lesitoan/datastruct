#include <iostream>
using namespace std;

long int fibonacci(int n);
long int fibonacci2(int n); //cach2
long int combination(int k, int n); //to hop
void towerOfHaNoi(int n, std::string a, std::string b, std::string c);

int main() {
	std::cout << "fibonacci N: " << fibonacci(10) << std::endl;
	std::cout << "fibonacci2 n: " << fibonacci2(10) <<std::endl;
	std::cout << "combination nck: " << combination(2, 5) <<std::endl;
	towerOfHaNoi(3, "a", "b", "c");
	//getchar();
	return 0;
}


// fibonacci cach 1
long int fibonacci(int n) {
	if (n <= 2) {
		return 1;
	}
	else {
		return fibonacci(n - 2) + fibonacci(n - 1);
	}
};

// fibonacci cach 2
long int arr[100] = { 0 };
long int fibonacci2(int n) {
	if (n <= 2) {
		return arr[n] = 1;
	}
	if (arr[n - 2] == 0) {
		arr[n - 2] == fibonacci2(n - 2);
	}
	if (arr[n - 1] == 0) {
		arr[n - 1] = fibonacci2(n - 1);
	}
	arr[n] = arr[n - 2] + arr[n - 1];
	return arr[n - 2] + arr[n - 1];
};

long int combination(int k, int n) {
	if (k == 0 || k == n) {
		return 1;
	}
	else {
		return combination(k - 1, n - 1) + combination(k, n - 1);
	}
};

void towerOfHaNoi(int n, std::string a, std::string b, std::string c) {
	if (n == 0) return;
	towerOfHaNoi(n - 1, a, c, b);
	std::cout << a << "->" << c << std::endl;
	towerOfHaNoi(n - 1, b, a, c);
}