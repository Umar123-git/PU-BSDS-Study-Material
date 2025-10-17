#include "Point3d.h"
#include <iostream>
#include <string>
#include <exception> // For exception handling

using namespace std;

int main() {
    try {
        // Create points
        Point3d p1, p2(3, 4, 5);

        // Test constructors
        cout << "Default point: " << p1 << endl;
        cout << "Parameterized point: " << p2 << endl;

        // Test displacement
        p1.displace(1, 2, 3);
        cout << "After displacement: " << p1 << endl;

        // Test distance calculation
        cout << "Distance between points: " << p1.distance(p2) << endl;

        // Test equality and inequality
        cout << "Are points equal? " << (p1 == p2 ? "Yes" : "No") << endl;
        cout << "Are points not equal? " << (p1 != p2 ? "Yes" : "No") << endl;

        // Test scaling
        Point3d p3 = p2 * 2;
        cout << "Point scaled up: " << p3 << endl;

        Point3d p4 = p2 / 2;
        cout << "Point scaled down: " << p4 << endl;

        // Test input
        Point3d p5;
        cin >> p5;
        cout << "You entered: " << p5 << endl;

    } catch (const exception &e) {
        cerr << e.what() << endl; // Output exception message
    }

    return 0;
}
