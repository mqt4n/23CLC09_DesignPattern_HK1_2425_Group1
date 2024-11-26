#include "../Header/Factory.h"

Book* NovelFactory::CreateBook(string line) {
    string type, name, author, genre, state;
    int year;

    stringstream ss(line);
    getline(ss, type, ',');
    getline(ss, name, ',');
    getline(ss, author, ',');
    ss >> year;
    ss.ignore(1); // Ignore comma after year
    getline(ss, genre, ',');
    getline(ss, state, ',');

    // Trim spaces
    auto trim = [](std::string& str) {
        str.erase(0, str.find_first_not_of(" \t"));
        str.erase(str.find_last_not_of(" \t") + 1);
    };

    trim(type);
    trim(name);
    trim(author);
    trim(genre);
    trim(state);

    BookState* st;

    if (state == "available") st = new AvailableState;
    else st = new BorrowedState;

    return new Novel(name, author, year, st, genre);
}

Book* TextBookFactory::CreateBook(string line) {
    string type, name, author, subject, state;
    int year;

    stringstream ss(line);
    getline(ss, type, ',');
    getline(ss, name, ',');
    getline(ss, author, ',');
    ss >> year;
    ss.ignore(1); // Ignore comma after year
    getline(ss, subject, ',');
    getline(ss, state, ',');

    // Trim spaces
    auto trim = [](std::string& str) {
        str.erase(0, str.find_first_not_of(" \t"));
        str.erase(str.find_last_not_of(" \t") + 1);
    };

    trim(type);
    trim(name);
    trim(author);
    trim(subject);
    trim(state);

    BookState* st;

    if (state == "available") st = new AvailableState;
    else st = new BorrowedState;

    return new TextBook(name, author, year, st, subject);
}