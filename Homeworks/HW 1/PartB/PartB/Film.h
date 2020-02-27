#ifndef __FILM_H
#define __FILM_H
#include "Actor.h"
class Film {
public:
	Film(const string fTitle = "", const string fDirector = "",
		const unsigned int fYear = 0,
		const unsigned int fDuration = 0);
	Film(const Film& fToCopy);
	~Film();
	void operator=(const Film& right);
	string getFilmTitle() const;
	string getFilmDirector() const;
	unsigned int getFilmYear() const;
	unsigned int getFilmDuration() const;
	unsigned int calculateAverageActorAge() const;
	unsigned int getNoOfActors() const;
	bool addActor(const string aName, const string aBirthPlace,
		const unsigned int aBirthYear);
	bool checkActor(const string aName);
	bool removeActors();
	friend ostream& operator<<(ostream& out, const Film& f);
private:
	string title;
	string director;
	unsigned int year;
	unsigned int duration;
	Actor* actors;
	unsigned int noOfActors;
	unsigned int size;
};
#endif