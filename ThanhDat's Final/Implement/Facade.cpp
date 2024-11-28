#include "../Header/Facade.h"

LibraryFacade::LibraryFacade() {
    ifstream file("DATA/storage.txt");
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string type;
        getline(ss, type, ',');
        BookFactory* factory = nullptr;
        if (type == "novel") 
            factory = new NovelFactory();
        else if (type == "textbook") 
            factory = new TextBookFactory();
        if (factory) {
            books.push_back(factory->createBook(line));
            delete factory;
        }
    }
}

LibraryFacade::~LibraryFacade() {
    for (Book* book : books) 
        delete book;
}

void LibraryFacade::search() {
    // type = 1: search by title
    // type = 2: search by author
    // type = 3: search by type
    searchStrategy* strategy = nullptr;
    string str;
    int type = 0;
    cout << "Choose search type: " << endl;
    cout << "1. Search by title" << endl;
    cout << "2. Search by author" << endl;
    cout << "3. Search by type" << endl;
    cout << "Choose an option: ";
    cin >> type;
    cout << "Enter search key: ";
    cin.ignore();
    getline(cin, str);
    if (type == 1)
        strategy = new searchByTitle();
    else if (type == 2)
        strategy = new searchByAuthor();
    else if (type == 3)
        strategy = new searchByType();
    else {
        cout << "Invalid search type" << endl;
        return;
    }
    vector<Book*> res = strategy->searchBook(books, str);
    delete strategy;
    if (res.empty()) 
        cout << "No result found" << endl;
    else
        for (Book* book : res) 
            book->displayInfo();
}

void LibraryFacade::displayAllBooks() {
    if (books.empty()) 
        cout << "No books in library" << endl;
    else
        for (Book* book : books) 
            book->displayInfo();
}

void LibraryFacade::displayAllMembers() {
    if (members.empty()) 
        cout << "No members in library" << endl;
    else
        for (Member* member : members) 
            member->displayInfo();
}

void LibraryFacade::addBook() {
    BookFactory* factory = nullptr;
    string type, name, author, str, state;
    bool borrowed;
    int year;
    cout << "Enter book type (novel/textbook): ";
    cin >> type;
    cout << "Enter book name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter author: ";
    getline(cin, author);
    cout << "Enter year: ";
    cin >> year;
    cout << "Enter genre/subject: ";
    cin.ignore();
    getline(cin, str);
    cout << "Enter state (available/borrowed): ";
    cin >> state;

    borrowed = (state == "available") ? false : true;
    
    if (type == "novel") 
        factory = new NovelFactory();
    else if (type == "textbook") 
        factory = new TextBookFactory();
    
    if (factory) {
        books.push_back(factory->createBook(type + "," + name + "," + author + "," + to_string(year) + "," + str + "," + state));
        delete factory;
    }
    else cout << "Invalid type" << endl;
}

void LibraryFacade::addMember() {
    string fullname;
    int day, month, year;
    cout << "Enter fullname: ";
    cin.ignore();
    getline(cin, fullname);
    cout << "Enter day of birth: ";
    cin >> day;
    cout << "Enter month of birth: ";
    cin >> month;
    cout << "Enter year of birth: ";
    cin >> year;
    members.push_back(new Member(fullname, day, month, year));
}

bool LibraryFacade::borrowBook() {
    int ID;
    string title;
    searchStrategy* strategy = new searchByTitle();

    cout << "Enter member ID: ";
    cin >> ID;
    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, title);

    vector<Book*> res = strategy->searchBook(books, title);
    delete strategy;
    if (res.empty()) {
        cout << "No result found" << endl;
        return false;
    }
    Book* book = res[0];

    for (Member* member : members) {
        if (member->getID() == ID) {
            member->borrowBook(book);
            return true;
        }
    }
    return false;
}