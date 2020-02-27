#include <iostream>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList() {
	head = new Node;

	head->item = 0;
	head->next = NULL;
	size = 0;
}

int LinkedList::getLenght() const {
	return size;
}

void LinkedList::add(itemType item) {
	if (size == 0) {
		head->item = item;
	}
	else {
		Node* newHead = new Node;
		newHead->item = item;
		newHead->next = head;

		head = newHead;
	}

	size++;
}

bool LinkedList::insert(int index, itemType item) {
	return false;
}

itemType LinkedList::get(int index) const {
	if (index < size) {
		Node* n = head;

		for (int i = 0; i < index; i++) {
			n = n->next;
		}

		return n->item;
	}
	else {
		return 0;
	}
}