#pragma once

#include "StandardLibrary.h"

class Book {
protected:  
    string title;
    string Author;
    int year;
public:
    Book();
    Book(string, string, int);
    Book(const Book&);
    
    string GetTitle();
    string GetAuthor();

    virtual ~Book() {}
    virtual void DisplayInfor() = 0;
};
