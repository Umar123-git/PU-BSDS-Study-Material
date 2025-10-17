#include <iostream>
#include <cmath>
using namespace std;

bool isPerfectSquare(int n) {
    if (n < 0) return false;
    int sqrt_n = sqrt(n);
    return (sqrt_n * sqrt_n == n);
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isPerfectSquare(num)) {
        cout << num << " is a perfect square." << endl;
    } else {
        cout << num << " is not a perfect square." << endl;
    }

    return 0;
}
