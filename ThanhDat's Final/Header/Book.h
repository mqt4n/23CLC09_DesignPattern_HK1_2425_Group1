#pragma once

#include "StandardLibrary.h"

class Book {
protected:
    string title;
    string author;
    int year;
    bool isBorrowed;
public:
    Book();
    Book(string, string, int, bool);
    Book(const Book&);

    string getTitle();
    string getAuthor();
    void setBorrowed(bool);
    
    virtual ~Book();
    virtual string getType() = 0;
    virtual void displayInfo() = 0;
};