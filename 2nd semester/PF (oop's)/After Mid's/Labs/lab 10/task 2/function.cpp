#include <iostream>
#include "bank.h"
#include <string>
using namespace std;

Bank::Bank() {
    name = "*******";
    balance = 100;
    accountnum = "*********";
}

void Bank::deposit() {
    double amount;
    cout << "\nEnter amount to deposit: ";
    cin >> amount;
    if (amount > 0) {
        balance += amount;
    } else {
        cout << "Invalid amount. Deposit failed.\n";
    }
}

void Bank::withdraw() {
    double amount;
    cout << "\nAvailable balance: " << balance << endl;

    if (balance >= 500) {
        cout << "Enter amount to withdraw: ";
        cin >> amount;

        if (amount <= balance && amount > 0) {
            balance -= amount;
            cout << "Withdrawal successful.\n";
        } else {
            cout << "Invalid or insufficient balance.\n";
        }
    } else {
        cout << "Withdrawal not allowed. Minimum balance of 500 required.\n";
    }
}

bool Bank::check() {
    return (balance >= 500);
}

void Bank::display() {
    cout << "\nHolder Name: " << name
         << "\nAccount Number: " << accountnum
         << "\nCurrent Balance: " << balance << endl;
}
