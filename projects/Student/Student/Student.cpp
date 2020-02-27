#include <iostream>
using namespace std;

//Student* findStudent(const Student* stuArr, const int size, const int key);

class Student {
	int id;

public:
	Student(int id = 1);
	void setId(int i);
	int getId();
};

Student::Student(int id) {
	setId(id);
}

void Student::setId(int i) {
	id = i;
}

int Student::getId() {
	return id;
}

Student* findStudent(Student* stuArr, const int size, const int key) {
	for (int i = 0; i < size; i++) {
		if (stuArr[i].getId == key)
			return &stuArr[i];
	}
	return NULL;
}

int main() {
	return 0;
}