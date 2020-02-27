#include <iostream>
#include "Book.h"
using namespace std;

Book::Book() {
	head = NULL;
	name = "";
}

Book::Book(const string name) {
	head = NULL;
	this->name = name;
}

Book::~Book() {
	AuthorNode* temp;

	for (head; head != NULL; head = temp) {
		temp = head->next;
		delete head;
	}
}

Book::Book(const Book& bookToCopy) {
	name = bookToCopy.getName();
	if (bookToCopy.head == NULL) {
		head = NULL;
	}
	else {
		head = new AuthorNode;
		head->a = bookToCopy.head->a;

		AuthorNode* iterThis = head;

		for (AuthorNode* iterBTC = bookToCopy.head->next;
			iterBTC != NULL; iterBTC = iterBTC->next) {
			iterThis->next = new AuthorNode;
			iterThis = iterThis->next;
			iterThis->a = iterBTC->a;
		}
		iterThis->next = NULL;
	}
}

void Book::operator=(const Book& right) {
	
	if (right.head == NULL) {
		this->~Book();
		name = right.getName();
		head = NULL;
	}
	else {
		name = right.getName();

		if (head == NULL) {
			head = new AuthorNode;
			head->next = NULL;
		}
		AuthorNode* iterThis = head;
		AuthorNode* iterRight = right.head;

		iterThis->a = iterRight->a;
		iterRight = iterRight->next;

		for (iterRight; iterThis->next != NULL && iterRight != NULL;
			iterRight = iterRight->next) {
			iterThis = iterThis->next;
			iterThis->a = iterRight->a;
		}

		if (iterRight != NULL) {

			for (iterRight; iterRight != NULL; iterRight = iterRight->next) {
				iterThis->next = new AuthorNode;
				iterThis = iterThis->next;
				iterThis->a = iterRight->a;
			}
		}
		else if (iterThis->next != NULL) {
			AuthorNode* temp1 = iterThis->next;

			for (AuthorNode* temp2 = temp1; temp2 != NULL; temp2 = temp1) {
				temp1 = temp2->next;
				delete temp2;
			}
		}
		iterThis->next = NULL;
	}
}

string Book::getName() const {
	return name;
}

void Book::setName(const string bookName) {
	name = bookName;
}

bool Book::addAuthor(const int id, const string name) {
	if (findAuthor(id) != NULL) {
		cout << "Warning: an author with the same id already exists!" << endl;
		return false;
	}

	head = new AuthorNode{ Author(id, name), head };

	return true;
}

bool Book::removeAuthor(const int id) {
	if (head != NULL) {
		AuthorNode* iter = head;

		if (head->a.getID() == id) {
			head = head->next;
			delete iter;
			return true;
		}
		else {
			for (iter; iter->next != NULL; iter = iter->next) {
				if (iter->next->a.getID() == id) {
					AuthorNode* temp = iter->next;
					iter->next = iter->next->next;
					delete temp;
					return true;
				}
			}
		}
	}
	cout << "Warning: an author with this id does not exist!" << endl;
	return false;
}

void Book::displayAuthors() const {
	if (head == NULL) {
		cout << "--EMPTY--" << endl;
	}
	else {
		for (AuthorNode* iter = head; iter != NULL; iter = iter->next) {
			cout << "Author " << iter->a.getID() 
				<< ", Author " << iter->a.getName() << endl;
		}
	}
}

void Book::displayAuthorsIndented() const {
	if (head == NULL) {
		cout << "\t--EMPTY--" << endl;
	}
	else {
		for (AuthorNode* iter = head; iter != NULL; iter = iter->next) {
			cout << "\tAuthor " << iter->a.getID()
				<< ", Author " << iter->a.getName() << endl;
		}
	}
}

bool Book::hasAuthor(int id) {
	return findAuthor(id) != NULL;
}

string Book::findAuthorName(int id) {
	AuthorNode* author = findAuthor(id);
	
	if (author) {
		return author->a.getName();
	}
	else {
		return "";
	}
}

Book::AuthorNode* Book::findAuthor(int id) {
	
	for (AuthorNode* iter = head; iter != NULL; iter = iter->next) {
		if (iter->a.getID() == id) {
			return iter;
		}
	}

	return NULL;
}