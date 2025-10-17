#include <iostream>
using namespace std;

struct Ratio {
    int num;
    int den; 
};


void inRatio(Ratio &r) {
    cin >> r.num >> r.den;
    while (r.den == 0) {
        cout << "Denominator cannot be 0. Please enter again: ";
        cin >> r.den;
    }
}


void outRatio(const Ratio &r) {
    cout << r.num << "/" << r.den;
}


Ratio multiply(const Ratio &r1, const Ratio &r2) {
    return { r1.num * r2.num, r1.den * r2.den };
}


Ratio productOfRatios(Ratio arr[], int size) {
    Ratio product = {1, 1}; 
    int i = 0;
    while (i < size) {
        product = multiply(product, arr[i]);
        i++;
    }
    return product;
}

int main() {
    const int size = 5; 
    Ratio arr[size];
    int i = 0;


    while (i < size) {
        cout << "Enter ratio " << i + 1 << " (num and den): ";
        inRatio(arr[i]);
        i++;
    }


    Ratio product = productOfRatios(arr, size);

 
    cout << "The product of the ratios is: ";
    outRatio(product);
    cout << endl;

    return 0;
}
