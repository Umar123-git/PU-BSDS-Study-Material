#include <iostream>
using namespace std;

const double PI = 3.141592653589793;

int main() {
    double radius;
    cout << "Enter the radius of the circle: ";
    cin >> radius;

    double area = PI * radius * radius;
    cout << "The area of the circle is: " << area << std::endl;

    return 0;
}
