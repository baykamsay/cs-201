#ifndef __INTARRAY_H
#define __INTARRAY_H

#include <iostream>
using namespace std;

class IntArray {
public:
	IntArray(const int aSize = 10);
	IntArray(const IntArray&);
	~IntArray();
	IntArray* operator=(const IntArray&);
	int& operator[](const int);
	int getSize() const;

private:
	int size;
	int* ints;

	friend istream& operator>>(istream&, IntArray&);
	friend ostream& operator<<(ostream&, IntArray&);
};

#endif // !__INTARRAY_H

