#ifndef __GRADEBOOK_H
#define __GRADEBOOK_H

#include <string>
using namespace std;

class GradeBook {
public:
	const static int studentNo = 10;
	GradeBook(const int[], int no = 0);
	void setCourseNo(int no);
	int getCourseNo();
	void displayMessage(string msg);
	void displayMessage();
	double computeAvg();

private:
	int grades[studentNo];
	int courseNo;
};

#endif