#ifndef assignment_2_part_a_SaleLine_h
#define assignment_2_part_a_SaleLine_h
 
#include<iostream>
#include<string>
using namespace std;


class SaleLine {
private:
    int serialNumber;
    string description;
    int quantity;
    double rate;
    double amount;

public:
    // Default constructor
    SaleLine();
    // Parameterized constructor
    SaleLine(int sn, const string& desc, int qty, double rt);

    // Copy constructor
    SaleLine(const SaleLine& other);

    // Assignment operator
    SaleLine& operator=(const SaleLine& other) ;

    // Getter methods
     int getSerialNumber() const ;
    string getDescription() const ;
    int getQuantity() const ;
    double getRate() const ;
    double getAmount() const ;

    // Display sale line (for internal use)
    void displaySaleLine(ostream& out) const ;
    // Friend function for input stream operator overloading
    friend istream& operator>>(istream& in, SaleLine& saleLine);
    // Friend function for output stream operator overloading
    friend ostream& operator<<(ostream& out, const SaleLine& saleLine);
};



#endif