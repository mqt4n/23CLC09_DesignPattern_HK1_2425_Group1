#include "../Header/Book.h"

Book::Book() : title(""), author(""), year(0) {}
Book::Book(string title, string author, int year, bool Borrowed) : 
title(title), author(author), year(year), isBorrowed(Borrowed) {}
Book::Book(const Book& book) :
title(book.title), author(book.author), year(book.year), isBorrowed(book.isBorrowed) {}
Book::~Book() {}

string Book::getTitle() {return title;}
string Book::getAuthor() {return author;}
void Book::setBorrowed(bool Borrowed) {isBorrowed = Borrowed;}