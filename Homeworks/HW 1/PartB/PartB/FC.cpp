#include <iostream>
#include "FC.h"

using namespace std;

FC::FC() {
	noOfFilms = 0;
	size = 1;
	films = new Film[size];
}

FC::FC(const FC& fcToCopy) {
	noOfFilms = fcToCopy.noOfFilms;

	if (noOfFilms) {
		size = noOfFilms;
		films = new Film[size];

		for (int i = 0; i < noOfFilms; i++) {
			films[i] = fcToCopy.films[i];
		}
	}
	else {
		size = 1;
		films = new Film[size];
	}
}

FC::~FC() {
	delete[] films;
	//cout << "Deleting FC" << endl;
}

void FC::operator=(const FC& right) {
	noOfFilms = right.noOfFilms;

	if (films)
		delete[] films;

	if (noOfFilms) {
		size = noOfFilms;
		films = new Film[size];

		for (int i = 0; i < noOfFilms; i++) {
			films[i] = right.films[i];
		}
	}
	else {
		size = 1;
		films = new Film[size];
	}
}

bool FC::addFilm(const string fTitle, const string fDirector,
	const unsigned int fYear,
	const unsigned int fDuration) {
	
	if (checkFilm(fTitle, fDirector) >= 0) {
		return false;
	}

	if (noOfFilms == size) {
		size *= 2;
		Film* temp = new Film[size];

		for (int i = 0; i < noOfFilms; i++) {
			temp[i] = films[i];
		}

		delete[] films;
		films = temp;
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

bool FC::addActor(const string fTitle, const string fDirector,
	const string aName, const string aBirthPlace,
	const unsigned int aBirthYear) {
	int index = checkFilm(fTitle, fDirector);

	if (index == -1) {
		return false;
	}

	return films[index].addActor(aName, aBirthPlace, aBirthYear);
}

bool FC::removeActors(const string fTitle, const string fDirector) {
	int index = checkFilm(fTitle, fDirector);

	if (index == -1) {
		return false;
	}

	return films[index].removeActors();;
}

unsigned int FC::calculateAverageDuration() const {
	if (noOfFilms == 0) {
		return 0;
	}

	unsigned int totalDuration = 0;
	
	for (int i = 0; i < noOfFilms; i++) {
		totalDuration += films[i].getFilmDuration();
	}

	return totalDuration / noOfFilms;
}

int FC::checkFilm(const string fTitle, const string fDirector) {
	for (int i = 0; i < noOfFilms; i++) {
		if (films[i].getFilmTitle() == fTitle 
			&& films[i].getFilmDirector() == fDirector) {
			return i;
		}
	}

	return -1;
}