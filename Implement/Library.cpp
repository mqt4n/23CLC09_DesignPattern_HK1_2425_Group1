#include "../Header/Library.h"

Library::Library() {}

Library::~Library() {
    for (auto book : Books) {
        delete book;
    }
}

void Library::AddBook(Book* bk) {
    Books.push_back(bk);
}

vector<Book*> Library::SearchByTitle(string title) {
    std::vector<Book*> result;
    for (Book* book : Books) {
        if (book->GetTitle() == title) {
            result.push_back(book);
        }
    }
    return result;
}

vector<Book*> Library::SearchByAuthor(string author) {
    vector<Book*> result;
    for (Book* book : Books) {
        if (book->GetAuthor() == author) {
            result.push_back(book);
        }
    }
    return result;
}

// std::vector<Book*> Library::SearchByType(string type) {
//     std::vector<Book*> result;
//     for (Book* book : Books) {
//         if (book->GetType() == type) {
//             result.push_back(book);
//         }
//     }
//     return result;
// }