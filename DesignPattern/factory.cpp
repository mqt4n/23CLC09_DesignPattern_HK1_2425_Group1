#include "factory.h"

void Novel::inputSpecificDetails(ifstream& in) {
  getline(in, genre);
}

void Textbook::inputSpecificDetails(ifstream& in) {
  getline(in, subject);
}

void Novel::display() const {
  cout << "Title: " << title << endl;
  cout << "Author: " << author << endl;
  cout << "Year: " << year << endl;
  cout << "Genre: " << genre << endl;
  cout << "Status: ";
  displayStatus();
}

void Textbook::display() const {
  cout << "Title: " << title << endl;
  cout << "Author: " << author << endl;
  cout << "Year: " << year << endl;
  cout << "Subject: " << subject << endl;
  cout << "Status: ";
  displayStatus();
}

Book* NovelFactory::createBook() const {
  return new Novel();
}

Book* TextbookFactory::createBook() const {
  return new Textbook();
}

void Novel::addDetailBook() {
  cout << "Enter the genre of the book: ";
  getline(cin, genre);
}

void Textbook::addDetailBook() {
  cout << "Enter the subject of the book: ";
  getline(cin, subject);
}

string Novel::getSpecificDetails() const {
  return genre;
}

string Textbook::getSpecificDetails() const {
  return subject;
}

string Novel::isType() const {
  return "Novel";
}

string Textbook::isType() const {
  return "Textbook";
}