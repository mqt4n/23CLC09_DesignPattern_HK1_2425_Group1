#include "../Header/Member.h"

Member::Member(string n, int d, int m, int y, string id, string add, string ph) :
Human(n, d, m, y), ID(id), address(add), phone(ph) {}

void Member::DisplayInfor() {
    cout << "Member: " << FullName << ", ID: " << ID << ", Address: " << address
    << ", Phone: " << phone << endl;
    cout << "Borrowed books: \n" << endl;
    for (auto book : borrowedBooks) {
        book->DisplayInfor();
    }
}