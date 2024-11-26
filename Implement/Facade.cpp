#include "../Header/Facade.h"
#include "../Header/Factory.h"
#include "../Header/Book.h"

Facade::Facade() {
    library = new Library;
    string url = "DATA/storage.txt";
    BookFactory* factory;
    ifstream readStream(url);
    string line;
    stringstream ss;
    while(getline(readStream, line)) {
        ss.str(line);
        string type;
        ss >> type;
        if (type == "novel") {
            delete factory;
            factory = new NovelFactory;
        }
        else if (type == "textbook") {
            delete factory;
            factory = new TextBookFactory;
        }
        else 
            continue;
        
        Book* book = factory->CreateBook(line);
        library->AddBook(book);
    }
}

Facade::~Facade() {
    delete library;
}

void Facade::SearchByTitle(string title) {
    vector<Book*> books = library->SearchByTitle(title);
    if (books.empty()) {
        cout << "No books found with title: " << title << std::endl;
    } else {
        for (Book* book : books) {
            book->DisplayInfor();
            cout << endl;
        }
    }
}

void Facade::SearchByAuthor(const std::string& author) {
    std::vector<Book*> books = library->SearchByAuthor(author);
    if (books.empty()) {
        std::cout << "No books found by author: " << author << std::endl;
    } else {
        for (Book* book : books) {
            book->DisplayInfor();
            cout << endl;
        }
    }
}

// void Facade::SearchByType(const std::string& type) {
//     std::vector<Book*> books = library->SearchByType(type);
//     if (books.empty()) {
//         std::cout << "No books found of type: " << type << std::endl;
//     } else {
//         for (Book* book : books) {
//             book->DisplayInfor();
//             cout << endl;
//         }
//     }
// }
