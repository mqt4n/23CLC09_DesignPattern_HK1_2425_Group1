#include "Header/Library.h"
#include "Header/Book.h"
#include "Header/Novel.h"
#include "Header/TextBook.h"
#include "Header/Factory.h"

int main() {
    ifstream readStream("DATA/storage.txt");
    string s;
    getline(readStream, s);
    cout << s;
    return 0;
}
