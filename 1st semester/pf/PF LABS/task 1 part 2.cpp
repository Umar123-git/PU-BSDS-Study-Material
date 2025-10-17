#include <iostream>
#include <cmath> 
using namespace std;

struct Ratio {
    int num;
    int den;
};


void inRatio(Ratio &r) {
    cout << "Enter numerator: ";
    cin >> r.num;
    cout << "Enter denominator (cannot be 0): ";
    cin >> r.den;
    while (r.den == 0) {
        cout << "Denominator cannot be 0. Please enter again: ";
        cin >> r.den;
    }
}

void outRatio(const Ratio &r) {
    cout << r.num << "/" << r.den << endl;
}


Ratio additiveInverse(const Ratio &r) {
    return { -r.num, r.den };
}


Ratio reciprocal(const Ratio &r) {
    return { r.den, r.num };
}
 
 
Ratio multiply(const Ratio &r1, const Ratio &r2) {
    return { r1.num * r2.num, r1.den * r2.den };
}


Ratio addInteger(const Ratio &r, int integer) {
    return { r.num + integer * r.den, r.den };
}


int gcd(int a, int b) {
    return b == 0 ? abs(a) : gcd(b, a % b);
}

Ratio simplify(Ratio r) {
    int commonDivisor = gcd(r.num, r.den);
    return { r.num / commonDivisor, r.den / commonDivisor };
}


Ratio integerToRatio(int integer) {
    return { integer, 1 };
}


float ratioToFloat(const Ratio &r) {
    return static_cast<float>(r.num) / r.den;
}


bool areEqual(const Ratio &r1, const Ratio &r2) {
    Ratio sr1 = simplify(r1);
    Ratio sr2 = simplify(r2);
    return sr1.num == sr2.num && sr1.den == sr2.den;
}


bool isLessThan(const Ratio &r1, const Ratio &r2) {
    return static_cast<float>(r1.num) / r1.den < static_cast<float>(r2.num) / r2.den;
}

int main() {
    Ratio r1, r2;
    

    cout << "Enter the first ratio:" << endl;
    inRatio(r1);
    cout << "The first ratio is: ";
    outRatio(r1);


    cout << "Enter the second ratio:" << endl;
    inRatio(r2);
    cout << "The second ratio is: ";
    outRatio(r2);

    
    Ratio inverseR1 = additiveInverse(r1);
    cout << "The additive inverse of the first ratio is: ";
    outRatio(inverseR1);


    Ratio reciprocalR1 = reciprocal(r1);
    cout << "The reciprocal of the first ratio is: ";
    outRatio(reciprocalR1);


    Ratio product = multiply(r1, r2);
    cout << "The product of the two ratios is: ";
    outRatio(product);


    int integer;
    cout << "Enter an integer to add to the first ratio: ";
    cin >> integer;
    Ratio sumWithInt = addInteger(r1, integer);
    cout << "The sum of the first ratio and the integer is: ";
    outRatio(sumWithInt);


    Ratio simplifiedR1 = simplify(r1);
    cout << "The simplified form of the first ratio is: ";
    outRatio(simplifiedR1);


    cout << "Enter an integer to convert to a ratio: ";
    cin >> integer;
    Ratio intToRatio = integerToRatio(integer);
    cout << "The ratio form of the integer is: ";
    outRatio(intToRatio);


    float floatValue = ratioToFloat(r1);
    cout << "The float value of the first ratio is: " << floatValue << endl;


    bool equal = areEqual(r1, r2);
    cout << "The two ratios are " << (equal ? "equal" : "not equal") << "." << endl;

 
    bool lessThan = isLessThan(r1, r2);
    cout << "The first ratio is " << (lessThan ? "less than" : "not less than") << " the second ratio." << endl;

    return 0;
}
