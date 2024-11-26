#pragma once
#include "generalClass.h"
#include "state.h"
#include "standardLibrary.h"

class Novel : public Book 
{
 private:
  string genre;

 public:
  void inputSpecificDetails(ifstream&) override;
  void display() const override;
  void addDetailBook() override;
  string getSpecificDetails() const override;
  string isType() const override;
};

class Textbook : public Book 
{
 private:
  string subject;

 public:
  void inputSpecificDetails(ifstream&) override;
  void display() const override;
  void addDetailBook() override;
  string getSpecificDetails() const override;
  string isType() const override;
};

class BookFactory {
 public:
  virtual ~BookFactory() = default;
  virtual Book* createBook() const = 0; 
};

class NovelFactory : public BookFactory 
{
 public:
  Book* createBook() const override;
};

class TextbookFactory : public BookFactory 
{
 public:
  Book* createBook() const override;
};