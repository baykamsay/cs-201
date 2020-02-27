#include <iostream>
#include <math.h>
#include <chrono>

using namespace std;

int sequentialSearch(int* arr, int N, int value);
int binarySearch(int* arr, int N, int value);
void fillArr(int*& arr, int size); // fills the array with numbers from 0 to size-1
double measureSequentialSearch(int* arr, int N, int value);
double measureBinarySearch(int* arr, int N, int value);

int main() {

	const int SIZE = 9;
	int* sizes = new int[SIZE];
	int* arrs[SIZE];

	for (int i = 0; i < SIZE; i++) {
		sizes[i] = (int) pow(10, i + 1);
	}

	for (int i = 0; i < SIZE; i++) {
		arrs[i] = new int[sizes[i]];
		fillArr(arrs[i], sizes[i]);
	}

	for (int i = 0; i < SIZE; i++) {
		measureSequentialSearch(arrs[i], sizes[i], 0);
		measureBinarySearch(arrs[i], sizes[i], 0);
	}

	for (int i = 0; i < SIZE; i++) {
		cout << "Array size: " << sizes[i] << ", value: " << 0 << endl;
		cout << "Sequential search took " << measureSequentialSearch(arrs[i], sizes[i], 0) << " ms." << endl;
		cout << "Binary search took " << measureBinarySearch(arrs[i], sizes[i], 0) << " ms." << endl;
		cout << endl;
	}

	for (int i = 0; i < SIZE; i++) {
		cout << "Array size: " << sizes[i] << ", value: " << sizes[i] / 2 << endl;
		cout << "Sequential search took " << measureSequentialSearch(arrs[i], sizes[i], sizes[i] / 2) << " ms." << endl;
		cout << "Binary search took " << measureBinarySearch(arrs[i], sizes[i], sizes[i] / 2) << " ms." << endl;
		cout << endl;
	}

	for (int i = 0; i < SIZE; i++) {
		cout << "Array size: " << sizes[i] << ", value: " << sizes[i] - 1<< endl;
		cout << "Sequential search took " << measureSequentialSearch(arrs[i], sizes[i], sizes[i] - 1) << " ms." << endl;
		cout << "Binary search took " << measureBinarySearch(arrs[i], sizes[i], sizes[i] - 1) << " ms." << endl;
		cout << endl;
	}

	for (int i = 0; i < SIZE; i++) {
		cout << "Array size: " << sizes[i] << ", value: " << -1 << endl;
		cout << "Sequential search took " << measureSequentialSearch(arrs[i], sizes[i], -1) << " ms." << endl;
		cout << "Binary search took " << measureBinarySearch(arrs[i], sizes[i], -1) << " ms." << endl;
		cout << endl;
	}

	for (int i = 0; i < SIZE; i++) {
		delete[] arrs[i];
	}

	delete[] sizes;

	return 0;
}

int sequentialSearch(int* arr, int N, int value) {
	for (int i = 0; i < N; i++)
		if (arr[i] == value)
			return i;
	return -1;
}

int binarySearch(int* arr, int N, int value) {
	int low = 0, high = N - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] < value)
			low = mid + 1;
		else if (arr[mid] > value)
			high = mid - 1;
		else
			return mid;
	}
	return -1;
}

void fillArr(int*& arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = i;
	}
}

double measureSequentialSearch(int* arr, int N, int value) {

	//Declare necessary variables
	std::chrono::time_point< std::chrono::system_clock > startTime;
	std::chrono::duration< double, milli > elapsedTime;

	//Store the starting time
	startTime = std::chrono::system_clock::now();

	//Code block
	sequentialSearch(arr, N, value);

	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	//cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;
	return elapsedTime.count();
}

double measureBinarySearch(int* arr, int N, int value) {

	//Declare necessary variables
	std::chrono::time_point< std::chrono::system_clock > startTime;
	std::chrono::duration< double, milli > elapsedTime;

	//Store the starting time
	startTime = std::chrono::system_clock::now();

	//Code block
	binarySearch(arr, N, value);

	//Compute the number of seconds that passed since the starting time
	elapsedTime = std::chrono::system_clock::now() - startTime;
	//cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;
	return elapsedTime.count();
}
