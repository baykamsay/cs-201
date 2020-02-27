#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
	LinkedList* l = new LinkedList();

	l->add(5);
	l->add(12);
	l->add(32);
	l->add(-4);

	for (int i = 0; i < l->getLenght(); i++) {
		cout << l->get(i) << endl;
	}

	return 0;
}