#include"SaleLine.h"
#include <istream>
#include <iostream>

#include <iomanip>

using namespace std;


    SaleLine::SaleLine() : serialNumber(0), description(""), quantity(0), rate(0.0), amount(0.0) {}

    // Parameterized constructor
    SaleLine::SaleLine(int sn, const string& desc, int qty, double rt)
        : serialNumber(sn), description(desc), quantity(qty), rate(rt) {
        amount = quantity * rate;
    }

    // Copy constructor
    SaleLine::SaleLine(const SaleLine& other)
        : serialNumber(other.serialNumber), description(other.description),
          quantity(other.quantity), rate(other.rate), amount(other.amount) {}

    // Assignment operator
    SaleLine& SaleLine::operator=(const SaleLine& other) {
        if (this != &other) {
            serialNumber = other.serialNumber;
            description = other.description;
            quantity = other.quantity;
            rate = other.rate;
            amount = other.amount;
        }
        return *this;
    }

    // Getter methods
    int SaleLine::getSerialNumber() const { return serialNumber; }
    string SaleLine::getDescription() const { return description; }
    int SaleLine::getQuantity() const { return quantity; }
    double SaleLine::getRate() const { return rate; }
    double SaleLine::getAmount() const { return amount; }

    // Display sale line (for internal use)
    void SaleLine::displaySaleLine(ostream& out) const {
        out << setw(5) << serialNumber << setw(15) << description
            << setw(8) << quantity << setw(10) << fixed << setprecision(2) << rate
            << setw(12) << fixed << setprecision(2) << amount;
    }

    // Friend function for input stream operator overloading
    istream& operator>>(istream& in, SaleLine& saleLine);
    // Friend function for output stream operator overloading
    ostream& operator<<(ostream& out, const SaleLine& saleLine);


istream& operator>>(istream& in, SaleLine& saleLine) {
    cout << "Enter Serial Number: ";
    in >> saleLine.serialNumber;
    cout << "Enter Description: ";
    in.ignore(); // Consume the newline character
    getline(in, saleLine.description);
    cout << "Enter Quantity: ";
    in >> saleLine.quantity;
    cout << "Enter Rate: ";
    in >> saleLine.rate;
    saleLine.amount = saleLine.quantity * saleLine.rate;
    return in;
}

ostream& operator<<(ostream& out, const SaleLine& saleLine) {
    saleLine.displaySaleLine(out);
    return out;
}
