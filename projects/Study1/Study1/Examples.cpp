#include <iostream>
using namespace std;

int factorial(int n) {
	int result = 1;

	for (int i = 1; i <= n; i++) {
		result *= i;
	}

	return result;
}

char gradeToLetter(int grade) {
	char letter;

	if (grade < 0 || grade > 100)
		return 'E'; // for error

	switch (grade / 10) {
		case 10:
		case 9: letter = 'A'; break;
		case 8: letter = 'B'; break;
		case 7: letter = 'C'; break;
		case 6: letter = 'D'; break;
		default: letter = 'F'; break;
	}

	return letter;
}

int findMax(int x, int y) {
	if (x > y)
		return x;
	else
		return y;
}

void nextIntByReference(int& y) {
	y++;
}

void computeSumProduct(int x, int y, int& sum, int& product) {
	sum = x + y;
	product = x * y;
}

int main() {
	//char input;
	//int n;

	//cout << "Enter integers to calculate the factorial: ";

	//do {
	//	cin >> n;
	//	cout << factorial(n) << endl;

	//	do {
	//		cout << "Would you like to stop (Y or N) ? ";
	//		cin >> input;
	//	} while (input != 'y' && input != 'Y' && input != 'n' && input != 'N');
	//	
	//} while (input == 'n' || input == 'N');
	//
	//int grade;

	//cin >> grade;

	//cout << gradeToLetter(grade) << endl;

	//cout << findMax(3, 10) << endl;

	//int x = 10;
	//cout << x << endl;

	//nextIntByReference(x);

	//cout << x << endl;

	int s, p, a = 2, b = 3;

	computeSumProduct(a, b, s, p);

	cout << "2 + 3: " << s << "\n2 * 3: " << p << endl;
	
	return 0;
}