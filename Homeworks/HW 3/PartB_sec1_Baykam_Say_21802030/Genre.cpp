#include <iostream>
#include "Genre.h"
using namespace std;

Genre::Genre(const string gname) {
	head = NULL;
	genreName = gname;
}

Genre::~Genre() {
	BookNode* temp;

	for (head; head != NULL; head = temp) {
		temp = head->next;
		delete head;
	}
}

Genre::Genre(const Genre& genreToCopy) {
	genreName = genreToCopy.getGenreName();

	if (genreToCopy.head == NULL) {
		head = NULL;
	}
	else {
		head = new BookNode;
		head->b = genreToCopy.head->b;

		BookNode* iterThis = head;

		for (BookNode* iterBTC = genreToCopy.head->next;
			iterBTC != NULL; iterBTC = iterBTC->next) {
			iterThis->next = new BookNode;
			iterThis = iterThis->next;
			iterThis->b = iterBTC->b;
		}
		iterThis->next = NULL;
	}
}

void Genre::operator=(const Genre& right) {

	if (right.head == NULL) {
		this->~Genre();
		genreName = right.getGenreName();
		head = NULL;
	}
	else {
		genreName = right.getGenreName();

		if (head == NULL) {
			head = new BookNode;
			head->next = NULL;
		}
		BookNode* iterThis = head;
		BookNode* iterRight = right.head;

		iterThis->b = iterRight->b;
		iterRight = iterRight->next;

		for (iterRight; iterThis->next != NULL && iterRight != NULL;
			iterRight = iterRight->next) {
			iterThis = iterThis->next;
			iterThis->b = iterRight->b;
		}

		if (iterRight != NULL) {

			for (iterRight; iterRight != NULL; iterRight = iterRight->next) {
				iterThis->next = new BookNode;
				iterThis = iterThis->next;
				iterThis->b = iterRight->b;
			}
		}
		else if (iterThis->next != NULL) {
			BookNode* temp1 = iterThis->next;

			for (BookNode* temp2 = temp1; temp2 != NULL; temp2 = temp1) {
				temp1 = temp2->next;
				delete temp2;
			}
		}
		iterThis->next = NULL;
	}
}

string Genre::getGenreName() const {
	return genreName;
}

void Genre::setGenreName(const string gName) {
	genreName = gName;
}

bool Genre::addBook(const string bName) {
	string lowerCase = "";

	for (int i = 0; bName[i] != '\0'; i++) {
		lowerCase += tolower(bName[i]);
	}

	if (findBook(lowerCase) != NULL) {
		cout << "Warning: a book with the same name already exists!" << endl;
		return false;
	}

	head = new BookNode{ Book(lowerCase), head };

	return true;
}

bool Genre::removeBook(const string bName) {
	string lowerCase = "";

	for (int i = 0; bName[i] != '\0'; i++) {
		lowerCase += tolower(bName[i]);
	}

	if (head != NULL) {
		BookNode* iter = head;

		if (head->b.getName() == lowerCase) {
			head = head->next;
			delete iter;
			return true;
		}
		else {
			for (iter; iter->next != NULL; iter = iter->next) {
				if (iter->next->b.getName() == lowerCase) {
					BookNode* temp = iter->next;
					iter->next = iter->next->next;
					delete temp;
					return true;
				}
			}
		}
	}
	cout << "Warning: a book with this name does not exist!" << endl;
	return false;
}

void Genre::displayBooks() const {
	if (head == NULL) {
		cout << "--EMPTY--" << endl;
	}
	else {
		for (BookNode* iter = head; iter != NULL; iter = iter->next) {
			cout << "Book " << iter->b.getName() << endl;
			iter->b.displayAuthorsIndented();
		}
	}
}

void Genre::addAuthor(string bookName, int authorID, string authorName) {
	string lowerCase = "";

	for (int i = 0; bookName[i] != '\0'; i++) {
		lowerCase += tolower(bookName[i]);
	}

	BookNode* book = findBook(lowerCase);

	if (book) {
		book->b.addAuthor(authorID, authorName);
	}
	else {
		cout << "Warning: a book with this name does not exist!" << endl;
	}
}

void Genre::removeAuthor(string bookName, int authorID) {
	string lowerCase = "";

	for (int i = 0; bookName[i] != '\0'; i++) {
		lowerCase += tolower(bookName[i]);
	}

	BookNode* book = findBook(lowerCase);

	if (book) {
		book->b.removeAuthor(authorID);
	}
	else {
		cout << "Warning: a book with this name does not exist!" << endl;
	}
}

string Genre::getBooksWithAuthor(int authorID) {
	string result = "";

	for (BookNode* iter = head; iter != NULL; iter = iter->next) {
		if (iter->b.hasAuthor(authorID)) {
			result += "\tBook " + iter->b.getName() + "\n";
		}
	}
	return result;
}

string Genre::findAuthorName(int authorID) {
	for (BookNode* iter = head; iter != NULL; iter = iter->next) {
		string name = iter->b.findAuthorName(authorID);
		if (name != "") {
			return name;
		}
	}

	return "";
}

Genre::BookNode* Genre::findBook(string bName) {

	for (BookNode* iter = head; iter != NULL; iter = iter->next) {
		if (iter->b.getName() == bName) {
			return iter;
		}
	}

	return NULL;
}