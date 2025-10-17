
#include <iostream>
#include <string>
#include <exception> // For exception handling

using namespace std;

class Point3d
{
protected:
    float x, y, z;
public:
    Point3d() : x(0), y(0), z(0) {}
    Point3d(float x, float y, float z) : x(x), y(y), z(z) {}
    void displace(float dx, float dy, float dz) {
    x += dx;
    y += dy;
    z += dz;
}
    float distance(const Point3d &other) const {
    return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2) + pow(z - other.z, 2));
}
    bool operator==(const Point3d &other) const {
    return x == other.x && y == other.y && z == other.z;
}
    bool operator!=(const Point3d &other) const {
    return !(*this == other);
}
    Point3d operator*(float scale) const {
    return Point3d(x * scale, y * scale, z * scale);
}
    friend Point3d operator*(float scale, const Point3d &point) {
    return Point3d(point.x * scale, point.y * scale, point.z * scale);
}
    Point3d operator/(float scale) const {
    if (scale == 0) {
        throw invalid_argument("Error: Division by zero is not allowed.");
    }
    return Point3d(x / scale, y / scale, z / scale);
}
    friend ostream & operator<<(ostream &strm, const Point3d &point) {
    return strm << "(" << point.x << ", " << point.y << ", " << point.z << ")";
}

    friend istream & operator>>(istream &strm, Point3d &point) {
    cout << "Enter x, y, z: ";
    strm >> point.x >> point.y >> point.z;
    if (!strm) {
        throw invalid_argument("Error: Invalid input for Point3d.");
    }
    return strm;
}












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

