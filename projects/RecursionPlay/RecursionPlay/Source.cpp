#include <iostream>
using namespace std;

void reverseString(char*);
int fibonacci(int);
int binarySearch(int*& arr, int min, int max, int key);
void subsets(int*& arr, int n, int k, int iN, int iK);

int main() {
	char str[] = "Hello World!";
	reverseString(str);
	cout << endl;

	cout << fibonacci(7) << endl;

	int* arr = new int[100];

	for (int i = 0; i < 100; i++) {
		arr[i] = i;
	}

	cout << binarySearch(arr, 0, 100, -9);

	return 0;
}

void reverseString(char* str) {
	if (*str == '\0') {
		return;
	}

	reverseString(str + 1);
	cout << *str;
}

// 1 1 2 3 5 8 13 21
int fibonacci(int n) {
	if (n < 3)
		return 1;

	return fibonacci(n - 1) + fibonacci(n - 2);
}

int binarySearch(int*& arr, int min, int max, int key)
{
	if (min > max) {
		return -1;
	}
	int mid = (min + max) / 2;

	if (key == arr[mid]) {
		return mid;
	}

	if (min == max) {
		return -1;
	}

	if (key < arr[mid]) {
		return binarySearch(arr, min, mid-1, key);
	}
	else {
		return binarySearch(arr, mid+1, max, key);
	}
}

void subsets(int*& arr, int n, int k, int iN, int iK) {
	if (iN > n - k) {
		return;
	}

	if (iK == k) 

	
	subsets(arr, n, k, iN + 1);
	cout << arr[iK];
}



