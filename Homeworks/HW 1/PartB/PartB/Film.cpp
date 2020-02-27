#include <iostream>
#include "Film.h"

using namespace std;

Film::Film(const string fTitle, const string fDirector,
	const unsigned int fYear, const unsigned int fDuration) {
	title = fTitle;
	director = fDirector;
	year = fYear;
	duration = fDuration;
	size = 1;
	actors = new Actor[size];
	noOfActors = 0;
}

Film::Film(const Film& fToCopy) {
	title = fToCopy.getFilmTitle();
	director = fToCopy.getFilmDirector();
	year = fToCopy.getFilmYear();
	duration = fToCopy.getFilmDuration();

	if (!fToCopy.getNoOfActors()) {
		size = 1;
		actors = new Actor[size];
		noOfActors = 0;
	}
	else {
		noOfActors = fToCopy.getNoOfActors();
		size = noOfActors;
		actors = new Actor[size];

		for (int i = 0; i < noOfActors; i++) {
			actors[i] = fToCopy.actors[i];
		}
	}
}

Film::~Film() {
	delete[] actors;
	//cout << "Deleting film " << title;
}

void Film::operator=(const Film& right) {
	title = right.getFilmTitle();
	director = right.getFilmDirector();
	year = right.getFilmYear();
	duration = right.getFilmDuration();

	if (actors)
		delete[] actors;

	if (!right.getNoOfActors()) {
		size = 1;
		actors = new Actor[size];
		noOfActors = 0;
	}
	else {
		noOfActors = right.getNoOfActors();
		size = noOfActors;
		actors = new Actor[size];

		for (int i = 0; i < noOfActors; i++) {
			actors[i] = right.actors[i];
		}
	}
}

string Film::getFilmTitle() const {
	return title;
}

string Film::getFilmDirector() const {
	return director;
}

unsigned int Film::getFilmYear() const {
	return year;
}

unsigned int Film::getFilmDuration() const {
	return duration;
}

unsigned int Film::calculateAverageActorAge() const {
	if (noOfActors) {
		int totalAge = 0;
		
		for (int i = 0; i < noOfActors; i++) {
			int birthYear = actors[i].getBirthYear();
			totalAge += year - birthYear;
		}

		return totalAge / noOfActors;
	}
	else {
		return 0;
	}
}

unsigned int Film::getNoOfActors() const {
	return noOfActors;
}

bool Film::addActor(const string aName, const string aBirthPlace,
	const unsigned int aBirthYear) {
	if (checkActor(aName))
		return false;

	if (noOfActors == size) {
		size *= 2;
		Actor* temp = new Actor[size];

		for (int i = 0; i < noOfActors; i++) {
			temp[i] = actors[i];
		}

		delete[] actors;
		actors = temp;
	}

	actors[noOfActors] = Actor(aName, aBirthPlace, aBirthYear);
	noOfActors++;

	return true;
}

bool Film::removeActors() {
	if (noOfActors == 0)
		return false;

	size = 1;
	Actor* temp = new Actor[size];
	delete[] actors;
	actors = temp;
	noOfActors = 0;

	return true;
}

bool Film::checkActor(const string aName) {
	for (int i = 0; i < noOfActors; i++) {
		if (actors[i].getName() == aName)
			return true;
	}

	return false;
}

ostream& operator<<(ostream& out, const Film& f) {
	out << f.getFilmTitle() << ", " << f.getFilmDirector() << ", "
		<< f.getFilmYear() << ", " << f.getFilmDuration() << endl;

	for (int i = 0; i < f.getNoOfActors(); i++) {
		out << "\t" << f.actors[i];
	}

	return out;
}