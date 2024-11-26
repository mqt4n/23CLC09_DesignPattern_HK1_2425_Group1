#pragma once

#include "StandardLibrary.h"
#include "Book.h"

class TextBook : public Book {
private:
    string subject;
public:
    TextBook();
    TextBook(string, string, int, BookState*, string);
    TextBook(const TextBook&);
    ~TextBook() {}
    void DisplayInfor();
};