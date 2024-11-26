#pragma once

#include "Library.h"
#include "StandardLibrary.h"

class Facade {
private:
    Library* library;
public:
    Facade();
    ~Facade();

    void SearchByTitle(string title);
    void SearchByAuthor(const std::string& author);
    // void searchByType(const std::string& type);

};

