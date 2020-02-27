#include <iostream>
using namespace std;
#include "Student.h"

// Prototypes
//void swapIntegers(int&, int&);
//void swapIntegerPointers(int*&, int*&);
//void swapStudentIds(Student&, Student&);

int main() {
	//int a = 2, b = 7, * c = &a, * d = &b;
	//Student s(001, "Ahmet"), r(002, "Mehmet"), * x = &s, * y = &r;
	//
	//cout << "a = " << a << " b = " << b << endl;
	//swapIntegers(a, b);
	//cout << "a = " << a << " b = " << b << endl;

	//cout << "*c = " << *c << " *d = " << *d << endl;
	//swapIntegerPointers(c, d);
	//cout << "*c = " << *c << " *d = " << *d << endl;

	//cout << "s: " << s.getId() << " r : " << r.getId() << endl;
	//swapStudentIds(s, r);
	//cout << "s: " << s.getId() << " r : " << r.getId() << endl;

	//int a = 1, b = 2;
	//const int* x = &a;
	//int* const y = &b;

	//cout << *y << endl;

	Student* s0 = new Student(201802030, "Baykam");
	Student s1(1, "a");

	cout << (*s0).getId() << endl;


	delete s0;
	return 0;
}

//void swapIntegers(int& i0, int& i1) {
//	int i2 = i0;
//	i0 = i1;
//	i1 = i2;
//}
//
//void swapIntegerPointers(int*& p0, int*& p1) {
//	int* p2 = p0;
//	p0 = p1;
//	p1 = p2;
//}
//
//void swapStudentIds(Student& s0, Student& s1) {
//	int id0 = s0.getId();
//	s0.setId(s1.getId());
//	s1.setId(id0);
//}