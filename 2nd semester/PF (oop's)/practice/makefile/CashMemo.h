#ifndef assignment_2_part_a_CashMemo_h
#define assignment_2_part_a_CashMemo_h
#include <iostream>
#include <string>
#include <iomanip>
#include <memory>  // ✅ Required for std::make_unique
#include "Date.h"
#include "SaleLine.h"
using namespace std;



class CashMemo {
private:
    static int nextReceiptNumber;
    int receiptNumber;
    unique_ptr<Date> saleDate;
    string customerName;
    string customerAddress;
    SaleLine* saleLines; //  Dynamic array of SaleLine pointers
    int saleLinesCount;
    int saleLinesCapacity;

public:
    // Static member initialization
    static void initializeReceiptNumber(int start = 1);

    // Default constructor
    CashMemo();

    // Parameterized constructor
    CashMemo(const string& name, const string& address);

    // Constructor with date
    CashMemo(Date* date, const string& name, const string& address);

    // Constructor with date
     CashMemo(unique_ptr<Date> date, const string& name, const string& address);

    // Copy constructor (Rule of 5 - Copy constructor)
    CashMemo(const CashMemo& other);

    // Move constructor (Rule of 5 - Move constructor)
    CashMemo(CashMemo&& other)noexcept;

    // Assignment operator (Rule of 5 - Copy assignment)
    CashMemo& operator=(const CashMemo& other)noexcept ;

    // Move assignment operator (Rule of 5 - Move assignment)
    CashMemo& operator=(CashMemo&& other) noexcept ;

    // Destructor (Rule of 5)
    ~CashMemo() ;

    // Function to add a sale line
    void addSaleLine(const SaleLine& line) ;

     void addSaleLine(int serial, const string& desc, int qty, double rt) ;

    // Calculate total amount
    double calculateTotal() const ;
    // Display cash memo (for internal use)
    void displayCashMemo(ostream& out) const ;

    // Friend function for input stream operator overloading
    friend istream& operator>>(istream& in, CashMemo& cashMemo);
    // Friend function for output stream operator overloading
    friend ostream& operator<<(ostream& out, const CashMemo& cashMemo);
};





#endif