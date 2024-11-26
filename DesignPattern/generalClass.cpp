#include "generalClass.h"

void Book::inputBookDetails(ifstream& in) {
  getline(in, title, ',');
  getline(in, author, ',');
  in >> year;
  in.ignore();
  string state;
  getline(in, state, ',');
  if (state == "Available") {
    this->state = new AvailableState();
  } else if (state == "Borrowed") {
    this->state = new BorrowedState();
  } else {
    cout << "Invalid book state." << endl;
    this->state = nullptr;
  }
  inputSpecificDetails(in);
}

string Book::getState() const { return state->isState(); }

void Book::addBook() {
  cout << "Enter the title of the book: ";
  getline(cin, title);
  cout << "Enter the author of the book: ";
  getline(cin, author);
  cout << "Enter the year of publication: ";
  cin >> year;
  cin.ignore();
  this->state = new AvailableState();
  addDetailBook();
}

Book::~Book() {
  if (state) delete state;
}

void Book::setState(BookState* state) {
  delete this->state;
  this->state = state;
}

void Book::borrowBook(const string& borrower) {
  state->borrowBook(this, borrower);
}

void Book::returnBook() { state->returnBook(this); }

void Book::displayStatus() const {
  if (state != nullptr)
    state->displayStatus();
  else
    cout << "Invalid book state." << endl;
}

void Member::borrowBook(Book* book) {
  if (book->getState() == "Available") {
    book->borrowBook(name);
    borrowedBooks.push_back(book);
  } else {
    cout << "This book is not available." << endl;
  }
}

void Member::returnBook(Book* book) {
  book->returnBook();
  for (int i = 0; i < borrowedBooks.size(); i++) {
    if (borrowedBooks[i] == book) {
      borrowedBooks.erase(borrowedBooks.begin() + i);
      break;
    }
  }
}

void Member::display() const {
  cout << "Name: " << name << endl;
  cout << "ID: " << id << endl;
  cout << "Borrowed books: " << endl;
  for (Book* book : borrowedBooks) {
    cout << book->getTitle() << endl;
  }
}