#include <iostream>
#include "SimpleBookCollection.h"
using namespace std;

int main() {
	BookCollection b1;
	BookCollection* b2;
	BookCollection b3;
	

	b1.displayGenres();

	b1.setName("Cool Genres");
	b1.addGenre("Sci Fi");
	b1.addGenre("RomaNce");
	b1.addGenre("Adventure");

	b1.displayGenres();

	cout << endl << "b2" << endl << endl;

	b2 = new BookCollection(b1);
	b2->displayGenres();
	
	cout << endl << "b3" << endl << endl;

	b3.addGenre("Action");
	b3.addGenre("comedY");
	b3.displayGenres();
	cout << "----" << endl;
	b3 = b1;
	cout << b3.getName() << endl;
	b3.displayGenres();
	
	cout << endl << "b1" << endl << endl;
	b1.removeGenre("adventure");
	b1.displayGenres();
	b1.removeGenre("sci fi");
	b1.removeGenre("romance");
	b1.displayGenres();

	delete b2;
	return 0;
}