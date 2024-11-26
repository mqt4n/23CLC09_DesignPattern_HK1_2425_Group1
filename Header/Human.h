#pragma once

#include "StandardLibrary.h"

class Human {
protected:
    string FullName;
    int day;
    int month;
    int year;
public:
    Human(string, int, int, int);
    
    string GetFullName();
    int GetDay();
    int GetMonth();
    int GetYear();

    virtual ~Human() {}
    virtual void DisplayInfor() = 0;
};