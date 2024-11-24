#pragma once

#include "Library.h"
#include "Book.h"

class TextBook : public Book {
private:
    string subject;
public:
    TextBook();
    TextBook(string, string, int, string);
    TextBook(const TextBook&);
    ~TextBook() {}
    void DisplayInfor();
};