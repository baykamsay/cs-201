#include <iostream>
using namespace std;
#include "GradeBook.h"

GradeBook::GradeBook(const int stuArr[], int no) {
	setCourseNo(no);
	for (int i = 0; i < studentNo; i++) {
		grades[i] = stuArr[i];
	}
}

void GradeBook::setCourseNo(int no) {
	if (no > 99 && no < 1000) {
		courseNo = no;
	}
	else {
		cout << "Invalid course no!" << endl;
		courseNo = 0;
	}
}

int GradeBook::getCourseNo() {
	return courseNo;
}

void GradeBook::displayMessage(string msg) {
	cout << msg << " " << getCourseNo() << "!" << endl;
}

void GradeBook::displayMessage() {
	cout << "Welcome to CS " << getCourseNo() << "!" << endl;
}

double GradeBook::computeAvg() {
	int grade, sum = 0, count = 0;

	cout << "Enter the grades, enter a negative value to stop: ";
	cin >> grade;

	while (grade >= 0) {
		sum += grade;
		count++;
		cin >> grade;
	}

	if (count)
		return (double) sum / count;
	else
		return -1;
}
