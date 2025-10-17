#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <string>
using namespace std;

class Bank {
private:
    string name;
    string accountnum;
    double balance;

public:
    Bank();
    void deposit();
    void display();
    void withdraw();
    bool check();
};

#endif
