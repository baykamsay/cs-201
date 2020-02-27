#include <iostream>
#include "BookCollection.h"
using namespace std;

BookCollection::BookCollection() {
	head = NULL;
	genreCount = 0;
}

BookCollection::~BookCollection() {
	GenreNode* temp;

	for (head; head != NULL; head = temp) {
		temp = head->next;
		delete head;
	}
}

BookCollection::BookCollection(const BookCollection& bcToCopy) {
	genreCount = bcToCopy.genreCount;

	if (bcToCopy.head == NULL) {
		head = NULL;
	}
	else {
		head = new GenreNode;
		head->g = bcToCopy.head->g;

		GenreNode* iterThis = head;

		for (GenreNode* iterBTC = bcToCopy.head->next;
			iterBTC != NULL; iterBTC = iterBTC->next) {
			iterThis->next = new GenreNode;
			iterThis = iterThis->next;
			iterThis->g = iterBTC->g;
		}
		iterThis->next = NULL;
	}
}

void BookCollection::operator=(const BookCollection& right) {

	if (right.head == NULL) {
		this->~BookCollection();
		genreCount = 0;
		head = NULL;
	}
	else {
		genreCount = right.genreCount;

		if (head == NULL) {
			head = new GenreNode;
			head->next = NULL;
		}
		GenreNode* iterThis = head;
		GenreNode* iterRight = right.head;

		iterThis->g = iterRight->g;
		iterRight = iterRight->next;

		for (iterRight; iterThis->next != NULL && iterRight != NULL;
			iterRight = iterRight->next) {
			iterThis = iterThis->next;
			iterThis->g = iterRight->g;
		}

		if (iterRight != NULL) {

			for (iterRight; iterRight != NULL; iterRight = iterRight->next) {
				iterThis->next = new GenreNode;
				iterThis = iterThis->next;
				iterThis->g = iterRight->g;
			}
		}
		else if (iterThis->next != NULL) {
			GenreNode* temp1 = iterThis->next;

			for (GenreNode* temp2 = temp1; temp2 != NULL; temp2 = temp1) {
				temp1 = temp2->next;
				delete temp2;
			}
		}
		iterThis->next = NULL;
	}
}

void BookCollection::addGenre(string genreName) {
	string lowerCase = "";

	for (int i = 0; genreName[i] != '\0'; i++) {
		lowerCase += tolower(genreName[i]);
	}

	if (findGenre(lowerCase) != NULL) {
		cout << "Warning: a genre with the same name already exists!" << endl;
	}
	else {
		head = new GenreNode{ Genre(lowerCase), head };
		genreCount++;
	}
}

void BookCollection::removeGenre(string genreName) {
	string lowerCase = "";

	for (int i = 0; genreName[i] != '\0'; i++) {
		lowerCase += tolower(genreName[i]);
	}

	if (head != NULL) {
		GenreNode* iter = head;

		if (head->g.getGenreName() == lowerCase) {
			head = head->next;
			delete iter;
			genreCount--;
			return;
		}
		else {
			for (iter; iter->next != NULL; iter = iter->next) {
				if (iter->next->g.getGenreName() == lowerCase) {
					GenreNode* temp = iter->next;
					iter->next = iter->next->next;
					delete temp;
					genreCount--;
					return;
				}
			}
		}
	}
	cout << "Warning: a genre with this name does not exist!" << endl;
}

void BookCollection::displayAllGenres() const {
	if (head == NULL) {
		cout << "--EMPTY--" << endl;
	}
	else {
		for (GenreNode* iter = head; iter != NULL; iter = iter->next) {
			cout << "Genre " << iter->g.getGenreName() << endl;
		}
	}
}

void BookCollection::addBook(string genreName, string bookName) {
	string lowerCase = "";

	for (int i = 0; genreName[i] != '\0'; i++) {
		lowerCase += tolower(genreName[i]);
	}

	GenreNode* genre = findGenre(lowerCase);

	if (genre) {
		genre->g.addBook(bookName);
	}
	else {
		cout << "Warning: a genre with this name does not exist!" << endl;
	}
}

void BookCollection::removeBook(string genreName, string bookName) {
	string lowerCase = "";

	for (int i = 0; genreName[i] != '\0'; i++) {
		lowerCase += tolower(genreName[i]);
	}

	GenreNode* genre = findGenre(lowerCase);

	if (genre) {
		genre->g.removeBook(bookName);
	}
	else {
		cout << "Warning: a genre with this name does not exist!" << endl;
	}
}

void BookCollection::addAuthor(string genreName, string bookName,
	int authorID, string authorName) {
	string lowerCase = "";

	for (int i = 0; genreName[i] != '\0'; i++) {
		lowerCase += tolower(genreName[i]);
	}

	GenreNode* genre = findGenre(lowerCase);

	if (genre) {
		genre->g.addAuthor(bookName, authorID, authorName);
	}
	else {
		cout << "Warning: a genre with this name does not exist!" << endl;
	}
}

void BookCollection::removeAuthor(string genreName, string bookName, 
	int authorID) {
	string lowerCase = "";

	for (int i = 0; genreName[i] != '\0'; i++) {
		lowerCase += tolower(genreName[i]);
	}

	GenreNode* genre = findGenre(lowerCase);

	if (genre) {
		genre->g.removeAuthor(bookName, authorID);
	}
	else {
		cout << "Warning: a genre with this name does not exist!" << endl;
	}
}

void BookCollection::displayGenre(string genreName) {
	string lowerCase = "";

	for (int i = 0; genreName[i] != '\0'; i++) {
		lowerCase += tolower(genreName[i]);
	}

	GenreNode* genre = findGenre(lowerCase);

	if (genre) {
		cout << "Genre " << genre->g.getGenreName() << endl;
		genre->g.displayBooks();
	}
	else {
		cout << "Warning: a genre with this name does not exist!" << endl;
	}
}

void BookCollection::displayAuthor(int authorID) {
	cout << "Author " << authorID 
		<< ", Author "<< findAuthorName(authorID) << endl; // really?
	bool empty = true;

	for (GenreNode* iter = head; iter != NULL; iter = iter->next) {
		string books = iter->g.getBooksWithAuthor(authorID);
		if (books != "") {
			cout << "Genre " << iter->g.getGenreName() << endl;
			cout << books;
			empty = false;
		}
	}

	if (empty) {
		cout << "--EMPTY--" << endl;
	}
}

string BookCollection::findAuthorName(int authorID) {
	for (GenreNode* iter = head; iter != NULL; iter = iter->next) {
		string name = iter->g.findAuthorName(authorID);
		if (name != "") {
			return name;
		}
	}

	return "Unknown";
}

BookCollection::GenreNode* BookCollection::findGenre(string genreName) {
	for (GenreNode* iter = head; iter != NULL; iter = iter->next) {
		if (iter->g.getGenreName() == genreName) {
			return iter;
		}
	}

	return NULL;
}