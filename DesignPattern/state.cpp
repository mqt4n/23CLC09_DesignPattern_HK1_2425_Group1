#include "state.h"

void AvailableState::borrowBook(Book* book, const string& borrower) {
  book->setState(new BorrowedState());
  cout << book->getTitle() << " has been borrowed by " << borrower << endl;
}

void AvailableState::returnBook(Book* book) {
  cout << book->getTitle() << " is already available" << endl;
}

void AvailableState::displayStatus() const {
  cout << "Available" << endl;
}

void BorrowedState::borrowBook(Book* book, const string& borrower) {
  cout << book->getTitle() << " is already borrowed" << endl;
}

void BorrowedState::returnBook(Book* book) {
  book->setState(new AvailableState());
  cout << book->getTitle() << " has been returned" << endl;
}

void BorrowedState::displayStatus() const {
  cout << "Borrowed" << endl;
}