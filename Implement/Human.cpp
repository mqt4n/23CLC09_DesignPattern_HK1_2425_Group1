#include "../Header/Human.h"

Human::Human(string n, int d, int m, int y) : 
FullName(n), day(d), month(m), year(y) {}

string Human::GetFullName() {return FullName;}
int Human::GetDay() {return day;}
int Human::GetMonth() {return month;}
int Human::GetYear() {return year;}