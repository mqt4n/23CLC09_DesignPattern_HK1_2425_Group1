#include "Header/Library.h"
#include "Header/Book.h"
#include "Header/Novel.h"
#include "Header/TextBook.h"
#include "Header/Factory.h"
#include "Header/Facade.h"
#include "Header/States.h"

vector<Book*> GetBook() {
    vector<Book*> books;
    BookFactory* factory;
    ifstream readStream("DATA/storage.txt");
    string line;
    stringstream ss;
    while(getline(readStream, line)) {
        ss.str(line);
        string type;
        ss >> type;
        type.erase(type.size() - 1);
        if(type == "novel") {
            factory = new NovelFactory();
        } else {
            factory = new TextBookFactory();
        }
        Book* book = factory->CreateBook(line);
        books.push_back(book);
        delete factory;
        cout << type << endl;
    }

    return books;
}

int main() {
    vector<Book*> books = GetBook();
    for (auto book : books) {
        book->DisplayInfor();
    }
    return 0;
}
