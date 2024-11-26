#pragma once

#include "StandardLibrary.h"
#include "Book.h"

class Novel : public Book {
private:
    string genre;
public:
    Novel();
    Novel(string, string, int, string);
    Novel(const Novel&);
    ~Novel() {}
    void DisplayInfor();
};