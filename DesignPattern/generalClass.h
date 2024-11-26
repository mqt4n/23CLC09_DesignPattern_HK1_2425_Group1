#pragma once
#include "standardLibrary.h"
#include "state.h"

class BookState;

class Book {
 protected:
  string title;
  string author;
  int year;
  BookState* state;

 public:
  virtual ~Book();
  virtual void inputSpecificDetails(ifstream&) = 0;
  virtual void display() const = 0;
  void inputBookDetails(ifstream&);
  void addBook();
  virtual void addDetailBook() = 0;
  string getTitle() const { return title; }
  string getAuthor() const { return author; }
  int getYear() const { return year; }
  virtual string getSpecificDetails() const = 0;
  void setState(BookState* state);
  string getState() const;
  void borrowBook(const string& borrower);
  void returnBook();
  void displayStatus() const;
  virtual string isType() const = 0;
};

class Member {
 protected:
  string name;
  string id;
  vector<Book*> borrowedBooks;

 public:
  Member(const string& name, const string& id) : name(name), id(id) {}
  void borrowBook(Book* book);
  void returnBook(Book* book);
  void display() const;
};

