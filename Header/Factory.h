#pragma once

#include "Library.h"
#include "Book.h"
#include "Novel.h"
#include "TextBook.h"

class BookFactory {
public:
    virtual ~BookFactory() {} 
    virtual Book* CreateBook(string) = 0;
};


class NovelFactory : public BookFactory {
public:
    
    Book* CreateBook(string);
};

class TextBookFactory : public BookFactory {
public:
    Book* CreateBook(string);
};