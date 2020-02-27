#include <iostream>
using namespace std;

class Test {
public:
	Test(int i = 0);
	void setNext(Test* nval);
	Test* getNext();
	int getId();
private:
	int id;
	Test* next;
};

Test* returnObjectAdress(int oid);

Test::Test(int i) {
	id = i;
	next = NULL;
}

void Test::setNext(Test* nval) {
	next = nval;
}

Test* Test::getNext() {
	return next;
}

int Test::getId() {
	return id;
}

int main() {
	Test t;
	t.setNext(returnObjectAdress(2));

	cout << t.getNext()->getId() << endl;

	delete t.getNext();

	return 0;
}

Test* returnObjectAdress(int oid) {
	Test* t = new Test(oid);

	return t;
}