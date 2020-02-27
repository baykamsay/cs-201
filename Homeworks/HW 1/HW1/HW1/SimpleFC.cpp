#include <iostream>
using namespace std;
#include "SimpleFC.h"

FC::FC() {
	noOfFilms = 0;
	size = 1;
	films = new Film[size];
}

FC::FC(const FC& fcToCopy) {
	noOfFilms = fcToCopy.getFilms(films);
	size = fcToCopy.size;
}

FC::~FC() {
	delete[] films;
	//cout << "Deleting FC!" << endl;
}

void FC::operator=(const FC& right) {
	noOfFilms = right.getFilms(films);
	size = right.size;
}

bool FC::addFilm(const string fTitle, const string fDirector,
	const unsigned int fYear, const unsigned int fDuration) {
	
	if (checkFilm(fTitle, fDirector) >= 0) {
		return false;
	}

	if (noOfFilms == size) {
		size *= 2;
		Film* newFilms = new Film[size];

		for (int i = 0; i < noOfFilms; i++) {
			newFilms[i] = films[i];
		}
		delete[] films;
		films = newFilms;
	}
	
	films[noOfFilms] = Film(fTitle, fDirector, fYear, fDuration);
	noOfFilms++;
	
	return true;
}

bool FC::removeFilm(const string fTitle, const string fDirector) {
	int index = checkFilm(fTitle, fDirector);
	
	if (index == -1) {
		return false;
	}
	
	size--;

	Film* newFilms = new Film[size];

	for (int i = 0; i < index; i++) {
		newFilms[i] = films[i];
	}

	for (int i = index; i < noOfFilms; i++) {
		newFilms[i] = films[i + 1];
	}

	noOfFilms--;

	delete[] films;
	films = newFilms;

	return true;
}

unsigned int FC::getFilms(Film*& allFilms) const {

	allFilms = new Film[size];

	for (int i = 0; i < noOfFilms; i++) {
		allFilms[i] = films[i];
	}

	return noOfFilms;
}

int FC::checkFilm(const string fTitle, const string fDirector) {
	for (int i = 0; i < noOfFilms; i++) {
		if (films[i].getTitle() == fTitle && films[i].getDirector() == fDirector) {
			return i;
		}
	}

	return -1;
}