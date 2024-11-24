#include "../Header/Book.h"

Book::Book() : title(""), Author(""), year(0) {}
Book::Book(string t, string a, int y) : title(t), Author(a), year(y) {}
Book::Book(const Book& other) : title(other.title), Author(other.Author), year(other.year) {}
