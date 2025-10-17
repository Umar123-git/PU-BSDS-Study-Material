#include <iostream>
using namespace std;

int main() {
    int n, sum = 0;
    cout << "Enter a natural number: ";
    cin >> n;

    cout << "Factors of " << n << " are: ";
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            cout << i << " ";
            sum += i;
        }
    }

    cout << "\nSum of the factors: " << sum << endl;
    return 0;
}
