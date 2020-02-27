#ifndef __STUDENT_H
#define __STUDENT_H

#include <iostream>
using namespace std;

class Student {
	int id;
	string name;
	string dep;

	void setName(string s);
public:
	Student(int id, string name);
	int getId();
	string getName();
	string getDep();
	void setDep(string s);
	void setId(int i);
};

#endif // !__STUDENT_H
