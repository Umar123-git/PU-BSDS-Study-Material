#include <iostream>
#include <cmath>
#include <array>
using namespace std;

class Polynomial {
protected:
    array<float, 10> arr;
    array<float, 10> ar;
    int n;

public:
    Polynomial() {
        n = 0;
        for (int i = 0; i < 10; i++) {
            arr[i] = 0;
            ar[i] = 0;
        }
    }

    ~Polynomial() { cout << "\nDestructor\n"; }

    void setcofficient() {
        float a;
        int k;
        cout << "Enter the maximum degree of polynomial: ";
        cin >> n;
        for (int i = 0; i <= n; i++) {
            cout << "Enter the exponent of X: ";
            cin >> k;
            if (k > n || k < 0) {
                cout << "Invalid power of X\n";
                return;
            }
            cout << "Enter coefficient of X of power " << k << ": ";
            cin >> a;
            arr[k] = a;
        }
    }

    bool bigger(const Polynomial &p2) {
        return this->n > p2.n;
    }

    void sum(const Polynomial &p2) {
        int maxDegree = max(n, p2.n);
        for (int i = 0; i <= maxDegree; i++) {
            arr[i] = arr[i] + p2.arr[i];
        }
    }

    void product(const Polynomial &p2) {
        array<float, 10> temp = {0};
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= p2.n; j++) {
                if (i + j < 10) { // Ensure index stays within bounds
                    temp[i + j] += arr[i] * p2.arr[j];
                }
            }
        }
        ar = temp;
    }

    void detrivative() {
        for (int i = 1; i <= n; i++) {
            ar[i - 1] = arr[i] * i;
        }
        ar[n] = 0; // Highest term vanishes
    }

    void display() const {
        cout << "\nDisplay: (";
        for (int i = n; i >= 0; i--) {
            if (arr[i] != 0) {
                cout << arr[i] << "x^" << i;
                if (i > 0) cout << " + ";
            }
        }
        cout << ")\n";
    }

    void displa() const {
        cout << "\nDispla: (";
        for (int i = 0; i < 10; i++) {
            if (ar[i] != 0) {
                cout << ar[i] << "x^" << i;
                if (i < 9) cout << " + ";
            }
        }
        cout << ")\n";
    }
};

int main() {
    Polynomial p1, p2;
    p1.setcofficient();
    p1.display();

    p2.setcofficient();
    p2.display();

    cout << "\nIs p1 bigger than p2? " << (p1.bigger(p2) ? "Yes" : "No") << endl;

    p1.sum(p2);
    cout << "\nAfter Addition:";
    p1.display();

    p1.product(p2);
    cout << "\nAfter Multiplication:";
    p1.displa();

    p1.detrivative();
    cout << "\nAfter Derivative:";
    p1.displa();

    return 0;
}
