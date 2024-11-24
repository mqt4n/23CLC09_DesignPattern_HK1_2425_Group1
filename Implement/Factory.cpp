#include "../Header/Factory.h"

Book* NovelFactory::CreateBook(string line) {
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

Book* TextBookFactory::CreateBook(string line) {
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