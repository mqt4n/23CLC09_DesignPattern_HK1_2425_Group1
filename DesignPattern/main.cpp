#include "factory.h"
#include "generalClass.h"
#include "standardLibrary.h"
#include "state.h"

int main() {
  vector<Book*> books;
  vector<Member*> borrowBookList;
  BookFactory* novelFactory = new NovelFactory();
  BookFactory* textbookFactory = new TextbookFactory();

  ifstream in("dataBook.txt");
  if (!in) {
    cout << "Cannot open the input file." << endl;
    return 0;
  }

  string temp;
  getline(in, temp);

  string type;

  while (getline(in, type, ',')) {
    Book* book;
    if (type == "Novel") {
      book = novelFactory->createBook();
    } else if (type == "Textbook") {
      book = textbookFactory->createBook();
    } else {
      cout << "Invalid book type." << endl;
      continue;
    }
    book->inputBookDetails(in);
    books.push_back(book);
  }

  in.close();

  vector<string> menu = {
      "Show information of one book",
      "Show information of all books",
      "Show list of available books",
      "Show information of all members",
      "Add a new book",
      "Add a new member",
      "Borrow a book",
      "Return a book",
      "Exit",
  };
  string InputTitle;
  int choice = 0;
  while (choice != 9) {
    cout << "----------MENU----------" << endl;

    for (int i = 0; i < menu.size(); i++) {
      cout << i + 1 << ". " << menu[i] << endl;
    }
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore();

    switch (choice) {
      case 1:
        cout << "Enter the title of the book: ";
        getline(cin, InputTitle);
        for (Book* book : books) {
          if (book->getTitle() == InputTitle) {
            book->display();
            break;
          }
        }
        break;
      case 2:
        for (Book* book : books) {
          book->display();
          cout << endl;
        }
        break;
      case 3:
        for (Book* book : books) {
          if (book->getState() == "Available") {
            book->display();
            cout << endl;
          }
        }
        break;
      case 5:
        cout << "Enter the type of the book (Novel/Textbook): ";
        getline(cin, type);
        Book* book;
        if (type == "Novel") {
          book = novelFactory->createBook();
        } else if (type == "Textbook") {
          book = textbookFactory->createBook();
        } else {
          cout << "Invalid book type." << endl;
          break;
        }
        book->addBook();
        books.push_back(book);
        break;
      case 9:
        cout << "Goodbye!" << endl;
        break;
      default:
        cout << "Invalid choice." << endl;
        break;
    }
  }
  ofstream out("dataBook.txt");
  if (!out) {
    cout << "Cannot open the output file." << endl;
    return 0;
  }
  out << "Type,Title,Author,Year,State,Specific" << endl;
  for (Book* book : books) {
    out << book->isType() << ",";
    out << book->getTitle() << ",";
    out << book->getAuthor() << ",";
    out << book->getYear() << ",";
    out << book->getState() << ",";
    out << book->getSpecificDetails();
    if (book != books.back()) out << endl;
  }

  for (Book* book : books) {
    delete book;
  }

  delete novelFactory;
  delete textbookFactory;

  return 0;
}