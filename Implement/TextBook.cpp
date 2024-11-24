#include "../Header/TextBook.h"

TextBook::TextBook() : Book(), subject("") {}
TextBook::TextBook(string t, string a, int y, string s) : Book(t, a, y), subject(s) {}
TextBook::TextBook(const TextBook& other) : Book(other), subject(other.subject) {}

void TextBook::DisplayInfor() {
    cout << "Type: TextBook, Subject: " << subject << ", Title: " << title
    << ", Author: " << Author << ", Year: " << year << endl;
}