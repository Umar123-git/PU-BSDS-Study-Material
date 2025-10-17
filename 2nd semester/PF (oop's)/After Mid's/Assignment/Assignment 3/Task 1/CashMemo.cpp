#include "CashMemo.h"
#include <iomanip>
#include <iostream>

using namespace std;

int CashMemo::nextReceiptNumber = 1;

void CashMemo::initializeReceiptNumber(int start) {
    nextReceiptNumber = start;
}

CashMemo::CashMemo()
    : receiptNumber(nextReceiptNumber++), saleDate(make_unique<Date>()),
      customerName(""), customerAddress(""), saleLines(nullptr),
      saleLinesCount(0), saleLinesCapacity(0) {}

CashMemo::CashMemo(const string& name, const string& address)
    : receiptNumber(nextReceiptNumber++), saleDate(make_unique<Date>()),
      customerName(name), customerAddress(address), saleLines(nullptr),
      saleLinesCount(0), saleLinesCapacity(0) {}

CashMemo::CashMemo(Date* date, const string& name, const string& address)
    : receiptNumber(nextReceiptNumber++), saleDate(date),
      customerName(name), customerAddress(address), saleLines(nullptr),
      saleLinesCount(0), saleLinesCapacity(0) {}

CashMemo::CashMemo(unique_ptr<Date> date, const string& name, const string& address)
    : receiptNumber(nextReceiptNumber++), saleDate(std::move(date)),
      customerName(name), customerAddress(address), saleLines(nullptr),
      saleLinesCount(0), saleLinesCapacity(0) {}

CashMemo::CashMemo(const CashMemo& other)
    : receiptNumber(other.receiptNumber),
      saleDate(other.saleDate ? make_unique<Date>(*other.saleDate) : nullptr),
      customerName(other.customerName), customerAddress(other.customerAddress),
      saleLines(nullptr), saleLinesCount(other.saleLinesCount),
      saleLinesCapacity(other.saleLinesCount) {
    if (other.saleLinesCount > 0) {
        saleLines = new SaleLine[saleLinesCapacity];
        for (int i = 0; i < saleLinesCount; ++i) {
            saleLines[i] = other.saleLines[i];
        }
    }
}

CashMemo::CashMemo(CashMemo&& other) noexcept
    : receiptNumber(other.receiptNumber), saleDate(std::move(other.saleDate)),
      customerName(std::move(other.customerName)), customerAddress(std::move(other.customerAddress)),
      saleLines(other.saleLines), saleLinesCount(other.saleLinesCount),
      saleLinesCapacity(other.saleLinesCapacity) {
    other.receiptNumber = 0;
    other.saleLines = nullptr;
    other.saleLinesCount = 0;
    other.saleLinesCapacity = 0;
}

CashMemo& CashMemo::operator=(const CashMemo& other) noexcept {
    if (this != &other) {
        receiptNumber = other.receiptNumber;
        if (other.saleDate) {
            if (!saleDate) {
                saleDate = make_unique<Date>(*other.saleDate);
            } else {
                *saleDate = *other.saleDate;
            }
        } else {
            saleDate.reset();
        }
        customerName = other.customerName;
        customerAddress = other.customerAddress;
        delete[] saleLines;
        saleLinesCount = other.saleLinesCount;
        saleLinesCapacity = other.saleLinesCount;
        saleLines = new SaleLine[saleLinesCapacity];
        for (int i = 0; i < saleLinesCount; ++i) {
            saleLines[i] = other.saleLines[i];
        }
    }
    return *this;
}

CashMemo& CashMemo::operator=(CashMemo&& other) noexcept {
    if (this != &other) {
        receiptNumber = other.receiptNumber;
        saleDate = std::move(other.saleDate);
        customerName = std::move(other.customerName);
        customerAddress = std::move(other.customerAddress);
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

CashMemo::~CashMemo() {
    delete[] saleLines;
}

void CashMemo::addSaleLine(const SaleLine& line) {
    if (saleLinesCount >= saleLinesCapacity) {
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

void CashMemo::addSaleLine(int serial, const string& desc, int qty, double rt) {
    SaleLine newLine(serial, desc, qty, rt);
    addSaleLine(newLine);
}

double CashMemo::calculateTotal() const {
    double total = 0.0;
    for (int i = 0; i < saleLinesCount; ++i) {
        total += saleLines[i].getAmount();
    }
    return total;
}

void CashMemo::displayCashMemo(ostream& out) const {
    out << "\n\t\t  CASH MEMO\n";
    out << "-----------------------------------------\n";
    out << "Receipt No: " << setw(10) << receiptNumber << endl;
    out << "Date:       ";
    if (saleDate) {
        saleDate->displayDate(out);
    } else {
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

istream& operator>>(istream& in, CashMemo& cashMemo) {
    cout << "Enter Customer Name: ";
    //in.ignore();
    getline(in, cashMemo.customerName);
    cout << "Enter Customer Address: ";
    getline(in, cashMemo.customerAddress);
    int day, month, year;
    cout << "Enter Date (DD MM YYYY): ";
    in >> day >> month >> year;
    cashMemo.saleDate = make_unique<Date>(day, month, year);
    int numItems;
    cout << "Enter the number of items: ";
    in >> numItems;

    delete[] cashMemo.saleLines;
    cashMemo.saleLines = nullptr;
    cashMemo.saleLinesCount = 0;
    cashMemo.saleLinesCapacity = 0;

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
