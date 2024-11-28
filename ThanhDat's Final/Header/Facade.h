#pragma ocne

#include "StandardLibrary.h"
#include "Book.h"
#include "Strategy.h"
#include "Factory.h"

class LibraryFacade {
private:
    vector<Book*> books;
    vector<Member*> members;
public:
    LibraryFacade();
    ~LibraryFacade();

    void search();
    void displayAllBooks();
    void displayAllMembers();
    void addBook();
    void addMember();
    bool borrowBook();
};