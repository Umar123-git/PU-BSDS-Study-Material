#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <memory> // for unique pointers

using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    // Default constructor
    Date() {
        time_t now = time(0);
        tm* ltm = localtime(&now);
        year = 1900 + ltm->tm_year;
        month = 1 + ltm->tm_mon;
        day = ltm->tm_mday;
    }

    // Parameterized constructor
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    // Copy constructor
    Date(const Date& other) : day(other.day), month(other.month), year(other.year) {}

    // Assignment operator
    Date& operator=(const Date& other) {
        if (this != &other) {
            day = other.day;
            month = other.month;
            year = other.year;
        }
        return *this;
    }

    // Getter methods
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    // Display date (for internal use)
    void displayDate(ostream& out) const {
        out << setfill('0') << setw(2) << day << setfill(' ')<< "-"
            << setfill('0') << setw(2) << month << setfill(' ') << "-"
            << year;
    }

    // Friend function for input stream operator overloading
    friend istream& operator>>(istream& in, Date& date);
    // Friend function for output stream operator overloading
    friend ostream& operator<<(ostream& out, const Date& date);
};

istream& operator>>(istream& in, Date& date) {
    cout << "Enter date (DD MM YYYY): ";
    in >> date.day >> date.month >> date.year;
    return in;
}

ostream& operator<<(ostream& out, const Date& date) {
    date.displayDate(out);
    return out;
}

class SaleLine {
private:
    int serialNumber;
    string description;
    int quantity;
    double rate;
    double amount;

public:
    // Default constructor
    SaleLine() : serialNumber(0), description(""), quantity(0), rate(0.0), amount(0.0) {}

    // Parameterized constructor
    SaleLine(int sn, const string& desc, int qty, double rt)
        : serialNumber(sn), description(desc), quantity(qty), rate(rt) {
        amount = quantity * rate;
    }

    // Copy constructor
    SaleLine(const SaleLine& other)
        : serialNumber(other.serialNumber), description(other.description),
          quantity(other.quantity), rate(other.rate), amount(other.amount) {}

    // Assignment operator
    SaleLine& operator=(const SaleLine& other) {
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
    int getSerialNumber() const { return serialNumber; }
    string getDescription() const { return description; }
    int getQuantity() const { return quantity; }
    double getRate() const { return rate; }
    double getAmount() const { return amount; }

    // Display sale line (for internal use)
    void displaySaleLine(ostream& out) const {
        out << setw(5) << serialNumber << setw(15) << description
            << setw(8) << quantity << setw(10) << fixed << setprecision(2) << rate
            << setw(12) << fixed << setprecision(2) << amount;
    }

    // Friend function for input stream operator overloading
    friend istream& operator>>(istream& in, SaleLine& saleLine);
    // Friend function for output stream operator overloading
    friend ostream& operator<<(ostream& out, const SaleLine& saleLine);
};

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
    static void initializeReceiptNumber(int start = 1) {
        nextReceiptNumber = start;
    }

    // Default constructor
    CashMemo() : receiptNumber(nextReceiptNumber++), saleDate(make_unique<Date>()), customerName(""), customerAddress(""), saleLines(nullptr), saleLinesCount(0), saleLinesCapacity(0) {}

    // Parameterized constructor
    CashMemo(const string& name, const string& address)
        : receiptNumber(nextReceiptNumber++), saleDate(make_unique<Date>()), customerName(name), customerAddress(address), saleLines(nullptr), saleLinesCount(0), saleLinesCapacity(0) {}

    // Constructor with date
    CashMemo(Date* date, const string& name, const string& address)
        : receiptNumber(nextReceiptNumber++), saleDate(date), customerName(name), customerAddress(address), saleLines(nullptr), saleLinesCount(0), saleLinesCapacity(0) {}

    // Constructor with date
     CashMemo(unique_ptr<Date> date, const string& name, const string& address)
        : receiptNumber(nextReceiptNumber++), saleDate(move(date)), customerName(name), customerAddress(address), saleLines(nullptr), saleLinesCount(0), saleLinesCapacity(0) {}

    // Copy constructor (Rule of 5 - Copy constructor)
    CashMemo(const CashMemo& other)
        : receiptNumber(other.receiptNumber),
          saleDate(other.saleDate ? make_unique<Date>(*other.saleDate) : nullptr),
          customerName(other.customerName),
          customerAddress(other.customerAddress),
          saleLines(nullptr), // Initialize to nullptr first
          saleLinesCount(other.saleLinesCount),
          saleLinesCapacity(other.saleLinesCount) { // Allocate same capacity as count
        if (other.saleLinesCount > 0) {
            saleLines = new SaleLine[saleLinesCapacity];
            for (int i = 0; i < saleLinesCount; ++i) {
                saleLines[i] = other.saleLines[i]; // Copy each SaleLine object
            }
        }
    }

    // Move constructor (Rule of 5 - Move constructor)
    CashMemo(CashMemo&& other) noexcept
        : receiptNumber(other.receiptNumber),
          saleDate(move(other.saleDate)),
          customerName(move(other.customerName)),
          customerAddress(move(other.customerAddress)),
          saleLines(other.saleLines),
          saleLinesCount(other.saleLinesCount),
          saleLinesCapacity(other.saleLinesCapacity) {
        other.receiptNumber = 0;
        other.saleLines = nullptr;
        other.saleLinesCount = 0;
        other.saleLinesCapacity = 0;
    }

    // Assignment operator (Rule of 5 - Copy assignment)
    CashMemo& operator=(const CashMemo& other) {
        if (this != &other) {
            receiptNumber = other.receiptNumber;
            if (other.saleDate) {
                if (!saleDate) {
                    saleDate = make_unique<Date>(*other.saleDate);
                }
                else {
                    *saleDate = *other.saleDate;
                }
            }
            else {
                saleDate.reset();
            }
            customerName = other.customerName;
            customerAddress = other.customerAddress;

            // Clear existing sale lines
            delete[] saleLines;
            saleLines = nullptr;
            saleLinesCount = 0;
            saleLinesCapacity = 0;

            saleLinesCount = other.saleLinesCount;
            saleLinesCapacity = other.saleLinesCapacity;
            if (saleLinesCount > 0) {
                saleLines = new SaleLine[saleLinesCapacity];
                for (int i = 0; i < saleLinesCount; ++i) {
                    saleLines[i] = other.saleLines[i]; // Copy each SaleLine
                }
            }
        }
        return *this;
    }

    // Move assignment operator (Rule of 5 - Move assignment)
    CashMemo& operator=(CashMemo&& other) noexcept {
        if (this != &other) {
            receiptNumber = other.receiptNumber;
            saleDate = move(other.saleDate);
            customerName = move(other.customerName);
            customerAddress = move(other.customerAddress);

            delete[] saleLines;
            saleLines = other.saleLines;
            saleLinesCount = other.saleLinesCount;
            saleLinesCapacity = other.saleLinesCapacity;

            other.receiptNumber = 0;
            other.saleLines = nullptr;
            other.saleLinesCount = 0;
            other.saleLinesCapacity = 0;
        }
        return *this;
    }

    // Destructor (Rule of 5)
    ~CashMemo() {
        delete[] saleLines;
    }

    // Function to add a sale line
    void addSaleLine(const SaleLine& line) {
        if (saleLinesCount >= saleLinesCapacity) {
            // Resize the array
            int newCapacity = (saleLinesCapacity == 0) ? 1 : saleLinesCapacity * 2;
            SaleLine* newSaleLines = new SaleLine[newCapacity];
            for (int i = 0; i < saleLinesCount; ++i) {
                newSaleLines[i] = saleLines[i];
            }
            delete[] saleLines;
            saleLines = newSaleLines;
            saleLinesCapacity = newCapacity;
        }
        saleLines[saleLinesCount++] = line;
    }

     void addSaleLine(int serial, const string& desc, int qty, double rt) {
        SaleLine newLine(serial, desc, qty, rt);
        addSaleLine(newLine);
    }

    // Calculate total amount
    double calculateTotal() const {
        double total = 0.0;
        for (int i = 0; i < saleLinesCount; ++i) {
            total += saleLines[i].getAmount();
        }
        return total;
    }

    // Display cash memo (for internal use)
    void displayCashMemo(ostream& out) const {
        out << "\n\t\t  CASH MEMO\n";
        out << "-----------------------------------------\n";
        out << "Receipt No: " << setw(10) << receiptNumber << endl;
        out << "Date:       ";
        if (saleDate) {
            saleDate->displayDate(out);
        }
        else {
            out << "N/A";
        }
        out << endl;
        out << "Customer:   " << customerName << endl;
        out << "Address:    " << customerAddress << endl;
        out << "-----------------------------------------\n";
        out << setw(5) << "S.No." << setw(15) << "Description"
            << setw(8) << "Qty" << setw(10) << "Rate"
            << setw(12) << "Amount" << endl;
        out << "-----------------------------------------\n";
        for (int i = 0; i < saleLinesCount; ++i) {
            saleLines[i].displaySaleLine(out);
            out << endl;
        }
        out << "-----------------------------------------\n";
        out << setw(40) << "Total Amount: "
            << setw(12) << fixed << setprecision(2) << calculateTotal() << endl;
        out << "-----------------------------------------\n";
        out << "\t\tThank You!\n";
    }

    // Friend function for input stream operator overloading
    friend istream& operator>>(istream& in, CashMemo& cashMemo);
    // Friend function for output stream operator overloading
    friend ostream& operator<<(ostream& out, const CashMemo& cashMemo);
};

// Initialize the static member outside the class definition
int CashMemo::nextReceiptNumber = 1;

istream& operator>>(istream& in, CashMemo& cashMemo) {
    cout << "Enter Customer Name: ";
    in.ignore();
    getline(in, cashMemo.customerName);
    cout << "Enter Customer Address: ";
    getline(in, cashMemo.customerAddress);
    // Input for Date
    int day, month, year;
    cout << "Enter Date (DD MM YYYY): ";
    in >> day >> month >> year;
    cashMemo.saleDate = make_unique<Date>(day, month, year);

    int numItems;
    cout << "Enter the number of items: ";
    in >> numItems;

    // Clear any existing sale lines
    delete[] cashMemo.saleLines;
    cashMemo.saleLines = nullptr;
    cashMemo.saleLinesCount = 0;
    cashMemo.saleLinesCapacity = 0;

    // Read SaleLine items
    for (int i = 0; i < numItems; ++i) {
        SaleLine item;
        cout << "\nEnter details for item " << i + 1 << ":\n";
        in >> item;
        cashMemo.addSaleLine(item);
    }
    return in;
}

ostream& operator<<(ostream& out, const CashMemo& cashMemo) {
    cashMemo.displayCashMemo(out);
    return out;
}

int main() {
    CashMemo cm;
    cin >> cm;
    cout << cm;
    return 0;
}
