#include<iostream>
#include<cmath>
using namespace std;

class polynomial {
private:
    double* arr;
    int arrsize;
    int degree;
    double coefficient;

public:
    polynomial() {
        arr = nullptr;
        degree = 0;
        coefficient = 0;
        arrsize = 0;
    }

    polynomial(int d, double c) {
        arr = new double[d + 1];
        degree = d;
        coefficient = c;

        for (int i = 0; i <= d; i++) {
            arr[i] = (i == d) ? c : 0;
        }

        arrsize = d + 1;
    }

    ~polynomial() {
        delete[] arr;
    }

    int getDegree() {
        return degree;
    }

    double getCofficient(int p) {
        if (p < arrsize) {
            return arr[p];
        } else {
            cout << "\nthere is no such data in array ";
            return 0;
        }
    }

    double operat(int val) {
        double p = 0;
        if (arrsize == 0) {
            cout << "\nthe array or the polynomial is empty ";
            return p;
        } else {
            for (int i = 0; i < arrsize; i++) {
                p += pow(val, i) * arr[i];
            }
        }
        return p;
    }

    void derivative() {
        if (arrsize == 0) {
            cout << "\nthe polynomial is empty so, determinant = 0";
            return;
        } else {
            for (int i = arrsize - 1; i >= 1; i--) {
                int q = arr[i] * i;
                if (q == 0) continue;
                if (arr[i] > 0) cout << " +";
                cout << q << "X" << i - 1;
            }
        }
    }

    void antiDerivative() {
        if (arrsize == 0) {
            cout << "\nthe polynomial is empty so, determinant = 0";
            return;
        } else {
            for (int i = arrsize - 1; i >= 0; i--) {
                int q = arr[i] / (i + 1);
                if (q == 0) continue;
                if (q > 0) cout << " +";
                cout << q << "X" << i + 1;
            }
            cout << " + C";
        }
    }

    void addToCoefficient(double c, int p) {
        if (p >= arrsize) {
            cout << "there is no polynomial having power " << p;
            return;
        } else {
            arr[p] += c;
        }
    }

    void clear() {
        if (arrsize == 0) {
            cout << "\nthe polynomial is empty ";
            return;
        } else {
            for (int i = 0; i < arrsize; i++) {
                arr[i] = 0;
            }
            coefficient = 0;
        }
    }

    void setCofficient(double c, int p) {
        if (p < arrsize) {
            arr[p] = c;
        } else {
            int newSize = p + 1;
            double* arr1 = new double[newSize];
            for (int i = 0; i < newSize; i++) {
                arr1[i] = (i < arrsize) ? arr[i] : 0;
            }
            arr1[p] = c;
            delete[] arr;
            arr = arr1;
            arrsize = newSize;
        }
    }

    void addoperation(polynomial p1, polynomial p2) {
        if (p1.arrsize == 0 || p2.arrsize == 0) {
            cout << "\none of the polynomial is empty";
            return;
        } else {
            cout << p1.arr[0] + p2.arr[0];
            for (int i = 1; i < p1.arrsize || i < p2.arrsize; i++) {
                double s = 0;
                if (i < p1.arrsize) s += p1.arr[i];
                if (i < p2.arrsize) s += p2.arr[i];
                if (s != 0) {
                    if (s > 0) cout << " + ";
                    cout << s << "X" << i;
                }
            }
        }
    }

   void substract(polynomial p1, polynomial p2) {
        if (p1.arrsize == 0 || p2.arrsize == 0) {
            cout << "\none of the polynomial is empty";
            return;
        } else {
            cout << p1.arr[0] - p2.arr[0];
            for (int i = 1; i < p1.arrsize || i < p2.arrsize; i++) {
                double s = 0;
                if (i < p1.arrsize) s += p1.arr[i];
                if (i < p2.arrsize) s -= p2.arr[i];
                if (s != 0) {
                    if (s > 0) cout << " + ";
                    cout << s << "X" << i;
                }
            }
        }
    }

    friend ostream& operator<<(ostream& os, const polynomial& p) {
        for (int i = 0; i < p.arrsize; i++) {
            if (p.arr[i] != 0) {
                if (i > 0 && p.arr[i] > 0) os << " + ";
                os << p.arr[i];
                if (i > 0) os << "X" << i;
            }
        }
        return os;
    }
};


int main() {
    polynomial p1(2, 3);
    polynomial p2(3, 4);

    cout << "Degree of p1: " << p1.getDegree() << endl;
    cout << "Coefficient of x^2 in p1: " << p1.getCofficient(2) << endl;

    cout << "p1(2) = " << p1.operat(2) << endl;

    p1.addToCoefficient(2.5, 2);
    cout << "Updated coefficient of x^2 in p1: " << p1.getCofficient(2) << endl;

    p1.setCofficient(1.5, 4);
    cout << "Coefficient of x^4 in p1: " << p1.getCofficient(4) << endl;

    cout << "Derivative of p1: ";
    p1.derivative();
    cout << endl;

    cout << "Antiderivative of p1: ";
    p1.antiDerivative();
    cout << endl;

    cout << "Sum of p1 and p2: ";
    p1.addoperation(p1, p2);
    cout << endl;

    p1.clear();
    cout << "After clearing p1, p1(2) = " << p1.operat(2) << endl;

    cout << "Substracting P1 from P2: ";
    p1.substract(p1,p2);
    cout << endl;

    return 0;
}

