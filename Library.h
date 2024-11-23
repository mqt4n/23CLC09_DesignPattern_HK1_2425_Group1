#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
#include <fstream>
using namespace std;

// Interface base class: Book
class Book {
protected:
    string title;
    string Author;
    int year;
public:
    Book() : title(""), Author(""), year(0) {}
    Book(string t, string a, int y) : title(t), Author(a), year(y) {}
    Book(const Book& other) : title(other.title), Author(other.Author), year(other.year) {}
    virtual ~Book() {}
    virtual void DisplayInfor() {
        cout << "Title: " << title << ", Author: " << Author << ", Year: " << year << endl;
    }
};

// Abstract factory: BookFactory
class BookFactory {
public:
    virtual ~BookFactory() {}
    virtual Book* CreateBook(string line) = 0;
};

// Derived class: Novel
class Novel : public Book {
private:
    string genre;
public:
    Novel() : Book(), genre("") {}
    Novel(string t, string a, int y, string g) : Book(t, a, y), genre(g) {}
    Novel(const Novel& other) : Book(other), genre(other.genre) {}

    void DisplayInfor() override {
        cout << "Type: Novel, Genre: " << genre << ", Title: " << title
             << ", Author: " << Author << ", Year: " << year << endl;
    }
};

// Derived factory: NovelFactory
class NovelFactory : public BookFactory {
public:
    Book* CreateBook(string line) override {
        string type, name, author, genre;
        int year;

        stringstream ss(line);
        getline(ss, type, ',');
        getline(ss, name, ',');
        getline(ss, author, ',');
        ss >> year;
        ss.ignore(1); // Ignore comma after year
        getline(ss, genre, ',');

        // Trim spaces
        auto trim = [](std::string& str) {
            str.erase(0, str.find_first_not_of(" \t"));
            str.erase(str.find_last_not_of(" \t") + 1);
        };

        trim(type);
        trim(name);
        trim(author);
        trim(genre);

        return new Novel(name, author, year, genre);
    }
};

// Derived class: TextBook
class TextBook : public Book {
private:
    string subject;
public:
    TextBook() : Book(), subject("") {}
    TextBook(string t, string a, int y, string s) : Book(t, a, y), subject(s) {}
    TextBook(const TextBook& other) : Book(other), subject(other.subject) {}

    void DisplayInfor() override {
        cout << "Type: TextBook, Subject: " << subject << ", Title: " << title
             << ", Author: " << Author << ", Year: " << year << endl;
    }
};

// Derived factory: TextBookFactory
class TextBookFactory : public BookFactory {
public:
    Book* CreateBook(string line) override {
        string type, name, author, subject;
        int year;

        stringstream ss(line);
        getline(ss, type, ',');
        getline(ss, name, ',');
        getline(ss, author, ',');
        ss >> year;
        ss.ignore(1); // Ignore comma after year
        getline(ss, subject, ',');

        // Trim spaces
        auto trim = [](std::string& str) {
            str.erase(0, str.find_first_not_of(" \t"));
            str.erase(str.find_last_not_of(" \t") + 1);
        };

        trim(type);
        trim(name);
        trim(author);
        trim(subject);

        return new TextBook(name, author, year, subject);
    }
};