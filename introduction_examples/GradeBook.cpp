#include <iostream>
using namespace std;

#include "GradeBook.h" // include definition of class GradeBook

GradeBook::GradeBook( int no ){
	setCourseNo(no);
	aCount = bCount = cCount = dCount = fCount = 0;
}
void GradeBook::displayMessage( int no ){
	cout << "Welcome to the grade book for CS " << no << "!" << endl;
}
void GradeBook::displayMessage(){
	cout << "Welcome to the grade book for CS " << getCourseNo() << "!" << endl;
}
void GradeBook::setCourseNo( int no ){
	if ((no >= 100) && (no <= 999))
		courseNo = no;
	else{
		cout << endl << no << " is an invalid course no" << endl;
		cout << "Course no is set to be 0\n\n";
		courseNo = 0;
	}
}
int GradeBook::getCourseNo(){
	return courseNo;
}
double GradeBook::determineCourseAverage(){
	int grade, counter = 0;
	double avg = 0.0;
	// WHAT HAPPENS IF AVG IS DEFINED AS AN INTEGER?
	
	cout << "Enter the grade of student " << counter+1 << ": ";
	cin >> grade;
	while (grade >= 0){
		avg += grade;
		counter++;
		cout << "Enter the grade of student " << counter+1 << ": ";
		cin >> grade;
	}
	if (counter > 0)
		return avg / counter;
	else{
		cout << "No grade is entered" << endl;
		return 0.0;
	}
}
double GradeBook::determineCourseAverage(int courseSize){
	int i, grade;
	double avg = 0.0;			
	
	for (i = 0; i < courseSize; i++){
		cout << "Enter the grade of student " << i+1 << ": ";
		cin >> grade;
		avg += grade;
	}
	if (courseSize > 0)
		return avg / courseSize;
	else{
		cout << "Non-positive courseSize" << endl;
		return 0.0;
	}
}
double GradeBook::determineCourseAverageWithValidation(int courseSize){
	int i, grade;
	double avg = 0.0;			
	
	for (i = 0; i < courseSize; i++){
		cout << "Enter the grade of student " << i+1 << ": ";
		cin >> grade;
		while ((grade < 0) || (grade > 100)){
			cout << "Invalid entry, re-enter the grade of student " << i+1 << ": ";
			cin >> grade;
		}
		avg += grade;
	}
	if (courseSize > 0)
		return avg / courseSize;
	else{
		cout << "Non-positive courseSize" << endl;
		return 0.0;
	}
}
void GradeBook::findLetterGradeDistribution(){
	char grade;
	bool invalid = false;
	
	cout << "Enter the letter grades" << endl
		 << "Enter an invalid character to end input" << endl;

	while (!invalid){
		cin >> grade;
		if ((grade == ' ') || (grade == '\t') || (grade == '\n'))
			continue;
		switch (grade){
			case 'A': case 'a':
				aCount++;
				break;		// necessary to exit switch
			case 'B': case 'b':
				bCount++;
				break;
			case 'C': case 'c':
				cCount++;
				break;
			case 'D': case 'd':
				dCount++;
				break;
			case 'F': case 'f':
				fCount++;
				break;
			default: 
				invalid = true;
				break; // optional; will exit switch anyway
		}
	}
}
void GradeBook::findGradeDistribution(){
	int grade;
	
	cout << "Enter the numerical grades" << endl
		 << "Enter an invalid number to end input" << endl;
	while (true){
		cin >> grade;
		if ((grade < 0) || (grade > 100))
			break;
		grade = grade / 10;

		switch (grade){
			case 10: case 9:
				aCount++;
				break;		// necessary to exit switch
			case 8:
				bCount++;
				break;
			case 7:
				cCount++;
				break;
			case 6:
				dCount++;
				break;
			default: 
				fCount++;
				break; // optional; will exit switch anyway
		}
	}
}
void GradeBook::displayLetterGradeReport(){
	cout << "\n\nNumber of students who received each letter grade:" 
		 << "\nA: " << aCount
		 << "\nB: " << bCount
		 << "\nC: " << cCount
		 << "\nD: " << dCount
		 << "\nF: " << fCount
		 << endl;
}

