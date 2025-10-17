#include <iostream>
using namespace std;

int main() {
    int num = 7;
    int *p1 = &num;
    int *p = p1;

    cout << "Pointer p address " << p << endl;
    cout << "Pointer dereference " << *p << endl;
    cout << "Pointer p1 address " << p1 << endl;
    cout << "Pointer p1 dereference " << *p1 << endl;

    cout << endl << endl;

    // Correctly access value through p
    cout << "Access value through p " << *p << endl;

    return 0;
}
