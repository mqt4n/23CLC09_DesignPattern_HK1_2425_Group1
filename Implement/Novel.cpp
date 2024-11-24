#include "../Header/Novel.h"

Novel::Novel() : Book(), genre("") {}
Novel::Novel(string t, string a, int y, string g) : Book(t, a, y), genre(g) {}
Novel::Novel(const Novel& other) : Book(other), genre(other.genre) {}

void Novel::DisplayInfor() {
    cout << "Type: Novel, Genre: " << genre << ", Title: " << title
    << ", Author: " << Author << ", Year: " << year << endl;
}