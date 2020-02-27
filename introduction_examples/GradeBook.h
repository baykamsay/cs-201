class GradeBook{
public:
	GradeBook( int no );
	void displayMessage( int no );
	void displayMessage();
	void setCourseNo( int no );
	int getCourseNo();

	// determines the average of grades entered by the user
	// until a negative grade is entered
	double determineCourseAverage();

	// determines the average of grades entered by the user
	// the number of students is specified as a parameter
	double determineCourseAverage(int courseSize);

	// determines the average of grades entered by the user
	// the number of students is specified as a parameter
	// the grades enteres should be valid (in between 0 and 100)
	double determineCourseAverageWithValidation(int courseSize);

	// takes the letter grades from the user
	// stops when an invalid character is entered
	// finds the distribution (from the beginning of the program)
	void findLetterGradeDistribution();

	// takes the grades from the user
	// stops when an invalid number (<0 or >100) is is entered
	// finds the corresponding letter of each grade
	// finds the distribution (from the beginning of the program)
	void findGradeDistribution();

	void displayLetterGradeReport();

private:
	int courseNo;
	int aCount, bCount, cCount, dCount, fCount;
};
