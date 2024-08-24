#include <iostream>
using namespace std;

int main() {
    int month, year;

    cout << "Enter month number (1-12): ";
    cin >> month;

    cout << "Enter year number: ";
    cin >> year;

    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            cout << "Number of days in month " << month << " is 29";
        else
            cout << "Number of days in month " << month << " is 28";
    } else if (month == 4 || month == 6 || month == 9 || month == 11)
        cout << "Number of days in month " << month << " is 30";
    else
        cout << "Number of days in month " << month << " is 31";

    return 0;
}