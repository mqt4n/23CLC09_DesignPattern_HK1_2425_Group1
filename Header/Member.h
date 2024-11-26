#include "StandardLibrary.h"
#include "Human.h"
#include "Book.h"

class Member : public Human {
private:
    string ID;
    string address;
    string phone;
    vector<Book*> borrowedBooks;
public:
    Member(string, int, int, int, string, string, string);
    void DisplayInfor();
};