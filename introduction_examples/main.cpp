#include <iostream>
using namespace std;

#include "GradeBook.h" // include definition of class GradeBook

void averageForMultipleSetsOfGrades(GradeBook G){
	int cnt;
	double avg;
	char answer;
	
	cnt = 1;
	do{
		avg = G.determineCourseAverage();
		cout << "\nAverage of course " << cnt++ << " is " << avg << endl << endl;
		do{
			cout << "Do you want to continue (y or n)?";
			cin >> answer;
		} while ((answer != 'y') && (answer != 'n') && (answer != 'Y') && (answer != 'N'));
		cout << endl << endl;
	} while ((answer == 'y') || (answer == 'Y'));
}
// function main begins program execution
int main(){
	int no;
	GradeBook gb1(101);
	GradeBook gb2(201);

	cout << endl;
	gb1.displayMessage();
	cout << "Please enter the new course no: ";
	cin >> no;
	gb1.setCourseNo(no);
	gb1.displayMessage();
	cout << endl;

	gb2.displayMessage();
	cout << endl << endl;
	
	cout << "Course average is " << gb2.determineCourseAverage() << endl << endl;
	cout << "Course average is " << gb2.determineCourseAverage(5) << endl << endl;
	cout << "Course average is " << gb2.determineCourseAverageWithValidation(5) << endl << endl;

	averageForMultipleSetsOfGrades(gb1);

	gb1.findLetterGradeDistribution();
	gb1.displayLetterGradeReport();
	cout << endl;

	gb1.findGradeDistribution();
	gb1.displayLetterGradeReport();
	cout << endl;

	return 0;
}
