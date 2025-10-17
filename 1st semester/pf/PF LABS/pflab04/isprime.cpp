#include <iostream>
using namespace std;

bool isprime(int n) {
    if (n <= 1) return false;
    bool r = true;
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            r = false;
            break;
        }
    }
    return r;
}

int main() {
    cout << "Prime numbers less than 10000:" << endl;
    for (int num = 2; num < 10000; num++) {
        if (isprime(num)) {
            cout << num << " ";
        }
    }
    cout << endl;
    return 0;
}
