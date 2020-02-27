#include <string>
#include <iostream>
#include "SimpleBookCollection.h"
using namespace std;

BookCollection::BookCollection() {
	name = "";
	genreCount = 0;
	head = new GenreNode;
	head->next = NULL;
}

BookCollection::~BookCollection() {
	GenreNode* temp;

	for (int i = 0; i < genreCount; i++) {
		temp = head->next; 
		delete head;
		head = temp;
	}
}

BookCollection::BookCollection(const BookCollection& bcToCopy) {
	name = bcToCopy.name;
	genreCount = bcToCopy.genreCount;
	head = new GenreNode;

	if (!genreCount) {
		head->next = NULL;
	}
	else {
		GenreNode* iter;
		GenreNode* temp;
		iter = bcToCopy.head;
		head->g = iter->g;
		head->next = NULL;

		iter = iter->next;

		for (int i = 0; i < genreCount - 1; i++) {
			temp = head;
			head = new GenreNode;
			head->g = iter->g;
			head->next = temp;
			iter = iter->next;
		}
	}
}

void BookCollection::operator=(const BookCollection& right) {
	name = right.name;
	GenreNode* iterThis = head;
	GenreNode* iterRight = right.head;
	GenreNode* last = NULL;

	if (genreCount >= right.genreCount) {

		for (iterRight; iterRight != NULL; iterRight = iterRight->next) {
			iterThis->g = iterRight->g;

			if (iterRight->next == NULL) {
				last = iterThis;
			}
			iterThis = iterThis->next;
		}

		last->next = NULL;

		GenreNode* temp;

		for (iterThis; iterThis != NULL; iterThis = temp) {
			temp = iterThis->next;
			delete iterThis;
		}
	}
	else {
		for (iterThis; iterThis != NULL; iterThis = iterThis->next) {
			iterThis->g = iterRight->g;

			if (iterThis->next == NULL) {
				last = iterThis;
			}
			iterRight = iterRight->next;
		}

		iterThis = last;

		for (iterRight; iterRight != NULL; iterRight = iterRight->next) {
			iterThis->next = new GenreNode;
			iterThis = iterThis->next;
			iterThis->g = iterRight->g;
		}
		iterThis->next = NULL;
	}

	genreCount = right.genreCount;
}

void BookCollection::displayGenres() const {
	if (genreCount == 0) {
		cout << "--EMPTY--" << endl;
	}
	else {
		GenreNode* iter = head;

		for (iter; iter != NULL; iter = iter->next) {
			cout << "Genre " << iter->g.getGenreName() << endl;
		}
	}
}

bool BookCollection::addGenre(const string genreName) {
	string lowerCase = "";

	//for (char c : genreName) {
	//	lowerCase += tolower(c);
	//}

	for (int i = 0; genreName[i] != '\0'; i++) {
		lowerCase += tolower(genreName[i]);
	}

	if (findGenre(lowerCase) != NULL) {
		cout << "Warning: This genre already exists!" << endl;
		return false;
	}

	if (genreCount) {
		GenreNode* temp = new GenreNode;
		
		temp->g.setGenreName(lowerCase);
		temp->next = head;
		head = temp;
	}
	else {
		head->g.setGenreName(lowerCase);
	}
	genreCount++;
	return true;
}

bool BookCollection::removeGenre(const string genreName) {
	string lowerCase = "";

	//for (char c : genreName) {
	//	lowerCase += tolower(c);
	//}

	for (int i = 0; genreName[i] != '\0'; i++) {
		lowerCase += tolower(genreName[i]);
	}

	if (genreCount) {
		GenreNode* iter = head;
		if (iter->g.getGenreName() == lowerCase) {
			head = head->next;
			delete iter;
			genreCount--;
			return true;
		}
		else {
			GenreNode* prev = iter;

			for (iter = iter->next; iter->next != NULL; iter = iter->next) {
				if (iter->g.getGenreName() == lowerCase) {
					prev->next = iter->next;
					delete iter;
					genreCount--;
					return true;
				}
				prev = prev->next;
			}
			if (iter->g.getGenreName() == lowerCase) {
				prev->next = NULL;
				delete iter;
				genreCount--;
				return true;
			}
		}
	}
	
	cout << "Warning: This genre does not exist!" << endl;
	return false;
}

string BookCollection::getName() const {
	return name;
}

void BookCollection::setName(const string bcName) {
	name = bcName;
}

BookCollection::GenreNode* BookCollection::findGenre(string genreName) {
	if (genreCount) {
		GenreNode* iter = head;

		for (iter; iter != NULL; iter = iter->next) {
			if (iter->g.getGenreName() == genreName) {
				return iter;
			}
		}
	}

	return NULL;
}
