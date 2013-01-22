// data_t.cpp
// Using objects of class Date.

#include <iostream>
using namespace std;

#include "date.h"

int
main()
{
    const Date today;
    cout << "Today's date: ";
    today.print();

    const Date birthday(12, 11, 1997);
    cout << "\n Felix's birthday: ";
    birthday.print();

    cout << "------------------------------\n"
            "Some testing outputs:" << endl;

    Date aDate;
    aDate = today;              // Assignment ok
    aDate.print();

    const Date *pDate = &birthday;    // Pointer to birthday
    pDate->print();
}
