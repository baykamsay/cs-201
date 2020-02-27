#include <string>
#include "SimpleGenre.h"
using namespace std;

Genre::Genre(const string gname) {
	genreName = gname;
}

Genre::~Genre() {

}

Genre::Genre(const Genre& genreToCopy) {
	setGenreName(genreToCopy.getGenreName());
}

void Genre::operator=(const Genre& right) {
	setGenreName(right.getGenreName());
}

string Genre::getGenreName() const {
	return genreName;
}

void Genre::setGenreName(const string gName) {
	genreName = gName;
}