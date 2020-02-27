#include <iostream>
#include "IntArray.h"
using namespace std;

IntArray::IntArray(const int aSize) {
	if (aSize > 0) {
		size = aSize;
	}
	else {
		size = 10;
	}

	ints = new int[size];

	for (int i = 0; i < size; i++) {
		ints[i] = 0;
	}
}

IntArray::IntArray(const IntArray& arrToCopy) {
	int size = arrToCopy.getSize();
	
	ints = new int[size];

	for (int i = 0; i < size; i++) {
		ints[i] = arrToCopy.ints[i];
	}
}

IntArray::~IntArray() {
	if (ints) {
		delete[] ints;
	}
}

IntArray* IntArray::operator=(const IntArray& right) {
	
}

