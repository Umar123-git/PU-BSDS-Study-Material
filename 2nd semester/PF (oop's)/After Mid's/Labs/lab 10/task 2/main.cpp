#include <iostream>
#include "bank.h"
#include <string>
using namespace std;

int main() {
    Bank b;
    b.display();
    b.deposit();
    b.display();
    cout << "\nCheck Balance (>=500)? " << (b.check() ? "Yes" : "No") << endl;
    b.withdraw();
    b.display();

    Bank b1;
    b1.display();
    b1.deposit();
    b1.display();
    cout << "\nCheck Balance (>=500)? " << (b1.check() ? "Yes" : "No") << endl;
    b1.withdraw();
    b1.display();

    return 0;
}
