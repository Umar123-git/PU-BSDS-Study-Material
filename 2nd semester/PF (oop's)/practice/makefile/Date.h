#ifndef assignment_2_part_a_date_h
#define assignment_2_part_a_date_h
 
#include<iostream>
using namespace std;


class Date {
private:
    int day;
    int month;
    int year;

public:
    // Default constructor
    Date() ;

    // Parameterized constructor
    Date(int d, int m, int y) ;
    // Copy constructor
    Date(const Date& other) ;

    // Assignment operator
    Date& operator=(const Date& other);

    // Getter methods
    int getDay() const ;
    int getMonth() const ;
    int getYear() const ;

    // Display date (for internal use)
    void displayDate(ostream& out) const;

    // Friend function for input stream operator overloading
    friend istream& operator>>(istream& in, Date& date);
    // Friend function for output stream operator overloading
    friend ostream& operator<<(ostream& out, const Date& date);
};



#endif