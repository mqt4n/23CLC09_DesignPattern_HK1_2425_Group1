#include "../Header/Member.h"

int Member::staticID = 0;

Member::Member() : Human(), ID(0) {}
Member::Member(string fullname, int day, int month, int year) : 
Human(fullname, day, month, year) { ID = staticID++; }
Member::Member(const Member& member) :
Human(member.fullname, member.day, member.month, member.year), ID(member.ID) {}
Member::~Member() {}

int Member::getID() {return ID;}
void Member::displayInfo() {
    cout << "ID: " << ID << endl;
    cout << "Fullname: " << fullname << endl;
    cout << "Date of birth: " << day << "/" << month << "/" << year << endl;
    cout << "Borrowed books: " << borrowedBooks.size() << endl;
}
void Member::borrowBook(Book* book) {
    borrowedBooks.push_back(book);
    book->setBorrowed(true);
}