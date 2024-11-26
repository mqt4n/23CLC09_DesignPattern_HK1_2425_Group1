#pragma once
#include "standardLibrary.h"
#include "generalClass.h"

class Book;

class BookState {
 public:
  virtual ~BookState() {}
  virtual void borrowBook(Book* book, const string& borrower) = 0;
  virtual void returnBook(Book* book) = 0;
  virtual void displayStatus() const = 0;
  virtual string isState() const = 0;
};

class AvailableState : public BookState 
{
 public:
  void borrowBook(Book* book, const string& borrower) override;
  void returnBook(Book* book) override;
  void displayStatus() const override;
  string isState() const override { return "Available"; }
};

class BorrowedState : public BookState 
{
 public:
  void borrowBook(Book* book, const string& borrower) override;
  void returnBook(Book* book) override;
  void displayStatus() const override;
  string isState() const override { return "Borrowed"; }
};