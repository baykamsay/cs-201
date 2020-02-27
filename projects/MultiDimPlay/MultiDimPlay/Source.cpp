#include <iostream>
using namespace std;

int** takeTriangle(int** arr, int size);

int main() {
	const int SIZE_1 = 5;
	const int SIZE_2 = 5;

	int** arr = new int*[SIZE_1];

	for (int i = 0; i < 5; i++) {
		arr[i] = new int[SIZE_2];
	}

	for (int i = 0; i < SIZE_1; i++) {
		for (int j = 0; j < SIZE_2; j++) {
			arr[i][j] = i*5 + j;
		}
	}

	for (int i = 0; i < SIZE_1; i++) {
		for (int j = 0; j < SIZE_2; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}

	cout << endl;

	int** tri = takeTriangle(arr, SIZE_1);

	for (int i = 0; i < SIZE_1; i++) {
		for (int j = 0; j < SIZE_1 - i; j++) {
			cout << tri[i][j] << "\t";
		}
		cout << endl;
	}

	//for (int i = 0; i < SIZE_1; i++) {
	//	for (int j = 0; j < SIZE_1 - i; j++) {
	//		delete[] tri[i];
	//	}
	//}

	delete[] tri;

	for (int i = 0; i < 5; i++) {
		delete[] arr[i];
	}

	delete[] arr;
}

int** takeTriangle(int** arr, int size) {
	int** result;

	result = new int* [size];

	for (int i = 0; i < size; i++) {
		result[i] = new int[size - i];
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			result[i][j] = arr[i][j];
		}
	}

	return result;
}
