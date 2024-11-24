#pragma once

#include "Library.h"

class Book {
protected:
    string title;
    string Author;
    int year;
public:
    Book();
    Book(string, string, int);
    Book(const Book&);
    virtual ~Book() {}
    virtual void DisplayInfor() = 0;
};
