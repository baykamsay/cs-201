#ifndef __GENRE_H
#define __GENRE_H

#include <string>
#include "Book.h"
using namespace std;

class Genre {
public:
	Genre(const string gname = "");
	~Genre();
	Genre(const Genre& genreToCopy);
	void operator=(const Genre& right);
	string getGenreName() const;
	void setGenreName(const string gName);

	// added
	bool addBook(const string bName);
	bool removeBook(const string bName);
	void displayBooks() const;
	void addAuthor(string bookName, int authorID, string authorName);
	void removeAuthor(string bookName, int authorID);
	string getBooksWithAuthor(int authorID);
	string findAuthorName(int authorID);
private:
	struct BookNode {
		Book b;
		BookNode* next;
	};
	BookNode* head;
	string genreName;

	BookNode* findBook(string bName);
};
#endif