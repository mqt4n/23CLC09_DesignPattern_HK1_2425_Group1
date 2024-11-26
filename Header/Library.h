#pragma once

#include "StandardLibrary.h"
#include "Book.h"

class Library {
private:
    vector<Book*> Books;
public:
    Library();
    ~Library();

    void AddBook(Book*);
    vector<Book*> SearchByTitle(string);
    vector<Book*> SearchByAuthor(string);
    // vector<Book*> SearchByType(string);
};