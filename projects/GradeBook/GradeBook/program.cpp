#include <iostream>
#include "GradeBook.h"

int main() {
	int arr[GradeBook::studentNo];

	arr[0] = 100;
	arr[1] = 10;
	arr[2] = 80;
	arr[3] = 30;
	arr[4] = 50;
	arr[5] = 90;
	arr[6] = 75;
	arr[7] = 68;
	arr[8] = 44;
	arr[9] = 32;

	GradeBook g(arr, 201);

	return 0;
}