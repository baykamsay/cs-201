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

	//films = new Film[size];
	//for (int i = 0; i < noOfFilms; i++) {
	//	films[i] = fcToCopy.films[i]; // copy constructor?
	//}
}

FC::~FC() {
	delete[] films;
	cout << "Deleting FC!" << endl;
}

void FC::operator=(const FC& right) {
	noOfFilms = right.getFilms(films);
	size = right.size;
}

bool FC::addFilm(const string fTitle, const string fDirector,
	const unsigned int fYear, const unsigned int fDuration) {

	if (checkFilm(fTitle, fDirector)) {
		return false;
	}

	if (noOfFilms == size) {
		Film* newFilms = new Film[size * 2];

		for (int i = 0; i < noOfFilms; i++) {
			newFilms[i] = films[i];
		}
		delete[] films;
		films = newFilms;
	}
	Film* mal = new Film(fTitle, fDirector, fYear, fDuration);
	films[noOfFilms] = *mal;
}

bool FC::checkFilm(const string fTitle, const string fDirector) {
	for (int i = 0; i < noOfFilms; i++) {
		if (films[i].getTitle() == fTitle || films[i].getDirector() == fDirector) {
			return true;
		}
	}

	return false;
}