#include <iostream>
#include "BookCollection.h"
using namespace std;

int main() {
	BookCollection bc;

	bc.addGenre("GENRE1");
	bc.addGenre("genre2");
	bc.addGenre("Genre3");

	bc.addBook("Genre2", "book1");
	bc.addBook("genre2", "Book2");
	bc.addBook("Genre2", "book3");
	bc.addBook("genre3", "book1");
	bc.addBook("genre3", "book4");

	bc.addAuthor("genre2", "bOok1", 0, "Author0");
	bc.addAuthor("genre2", "book1", 1, "Author1");
	bc.addAuthor("genre2", "book3", 1, "Author1");
	bc.addAuthor("genre2", "book3", 2, "Author2");
	bc.addAuthor("genre3", "book1", 0, "Author0");
	bc.addAuthor("genre3", "book1", 1, "Author1");
	bc.addAuthor("genre3", "book4", 4, "Author4");

	cout << "displayAllGenres()" << endl;
	bc.displayAllGenres();

	cout << endl << "displayGenre('genre1')" << endl;
	bc.displayGenre("genre1");

	cout << endl << "displayGenre('genre2')" << endl;
	bc.displayGenre("genre2");

	cout << endl << "displayAuthor(1)" << endl;
	bc.displayAuthor(1);

	cout << endl << "displayAuthor(23)" << endl;
	bc.displayAuthor(23);

	cout << endl << "copy constructor" << endl;
	BookCollection bc2(bc);
	bc2.displayAllGenres();
	bc2.displayGenre("GEnre2");

	cout << endl << "assignment operator" << endl;
	BookCollection bc3;
	bc3.addGenre("GENRE4");
	bc3.addGenre("genre5");


	bc3.addBook("Genre5", "book-1");
	bc3.addBook("genre5", "Book-2");
	bc3.addBook("Genre5", "book-3");


	bc3.addAuthor("genre5", "bOok-1", 9, "Author9");
	bc3.addAuthor("genre5", "book-1", 8, "Author8");
	bc3.addAuthor("genre5", "book-3", 8, "Author8");
	bc3.addAuthor("genre5", "book-3", 7, "Author7");

	cout << endl << "before assignment operator" << endl;
	bc3.displayAllGenres();
	bc3.displayGenre("GEnre2");

	bc3 = bc;
	cout << endl << "after assignment operator" << endl;
	bc3.displayAllGenres();
	bc3.displayGenre("GEnre2");

	return 0;
}