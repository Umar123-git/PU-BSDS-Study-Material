#include"Date.h"
#include <istream>
#include <iostream>
#include <iomanip>
using namespace std;


    Date::Date() {
        time_t now = time(0);
        tm* ltm = localtime(&now);
        year = 1900 + ltm->tm_year;
        month = 1 + ltm->tm_mon;
        day = ltm->tm_mday;
    }

    // Parameterized constructor
   Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

    // Copy constructor
    Date::Date(const Date& other) : day(other.day), month(other.month), year(other.year) {}

    // Assignment operator
    Date& Date::operator=(const Date& other) {
        if (this != &other) {
            day = other.day;
            month = other.month;
            year = other.year;
        }
        return *this;
    }

    // Getter methods
    int Date::getDay() const { return day; }
    int Date::getMonth() const { return month; }
    int Date::getYear() const { return year; }

    // Display date (for internal use)
    void Date::displayDate(ostream& out) const {
        out << setfill('0') << setw(2) << day << setfill(' ')<< "-"
            << setfill('0') << setw(2) << month << setfill(' ') << "-"
            << year;
    }

    // Friend function for input stream operator overloading
    istream& operator>>(istream& in, Date& date);
    // Friend function for output stream operator overloading
    ostream& operator<<(ostream& out, const Date& date);




istream& operator>>(istream& in, Date& date) {
    cout << "Enter date (DD MM YYYY): ";
    in >> date.day >> date.month >> date.year;
    return in;
}

ostream& operator<<(ostream& out, const Date& date) {
    date.displayDate(out);
    return out;
}