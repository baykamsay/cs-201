#include <iostream>
using namespace std;

void initArr(int arr[], int size, int value);
void dispArr(int arr[], int size);
double* createArray();
void copyArr(int* arr, const int size, int*& output);
void partition(int arr[], int size, int pivot);

int main() {
	double* arr = createArray();

	delete[] arr;
	return 0;
}

void initArr(int arr[], int size, int value) {
	for (int i = 0; i < size; i++) {
		arr[i] = value;
	}
}

void dispArr(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << ", ";
	}
	cout << endl;
}

double* createArray() {
	return new double[5];
}

void copyArr(int* arr, const int size, int*& output) {
	output = new int[size];
	for (int i = 0; i < size; i++) {
		output[i] = arr[i];
	}
}

void partition(int arr[], int size, int pivot) {

}