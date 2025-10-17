#include <iostream>
using namespace std;

// Function to print the geometric sequence
void printGeometricSequence(int start, int ratio, int count) {
    int term = start;
    for (int i = 0; i < count; i++) {
        cout << term << " ";
        term *= ratio; // Multiply the term by the common ratio
    }
    cout << endl;
}

int main() {
    // Test the function with different cases
    cout << "Test 1: Start = 2, Ratio = 3, Count = 5" << endl;
    printGeometricSequence(2, 3, 5); // Output: 2 6 18 54 162

    cout << "Test 2: Start = 1, Ratio = 2, Count = 7" << endl;
    printGeometricSequence(1, 2, 7); // Output: 1 2 4 8 16 32 64

    cout << "Test 3: Start = 5, Ratio = -2, Count = 4" << endl;
    printGeometricSequence(5, -2, 4); // Output: 5 -10 20 -40

    cout << "Test 4: Start = 10, Ratio = 1, Count = 6" << endl;
    printGeometricSequence(10, 1, 6); // Output: 10 10 10 10 10 10

    cout << "Test 5: Start = 3, Ratio = 0, Count = 5" << endl;
    printGeometricSequence(3, 0, 5); // Output: 3 0 0 0 0

    return 0;
}

