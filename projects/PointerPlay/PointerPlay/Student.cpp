#include <iostream>
using namespace std;
#include "Student.h"


Student::Student(int id, string name) {
	setId(id);
	setName(name);
}

int Student::getId() {
	return id;
}

string Student::getName() {
	return name;
}

string Student::getDep() {
	return dep;
}

void Student::setDep(string s) {
	dep = s;
}

void Student::setId(int i) {
	id = i;
}

void Student::setName(string s) {
	name = s;
}