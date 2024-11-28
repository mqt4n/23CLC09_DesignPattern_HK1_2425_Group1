#pragma once

#include "StandardLibrary.h"
#include "Book.h"

class TextBook : public Book {
private:
    string subject;
public:
    TextBook();
    TextBook(string, string, int, string, bool);
    TextBook(const TextBook&);
    ~TextBook();

    string getType();
    void displayInfo();
};