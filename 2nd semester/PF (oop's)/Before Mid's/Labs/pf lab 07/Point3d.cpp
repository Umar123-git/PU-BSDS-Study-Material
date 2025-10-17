#include "Point3d.h"
#include <cmath>

using namespace std;

// Default constructor
Point3d::Point3d() : x(0), y(0), z(0) {}

// Parameterized constructor
Point3d::Point3d(float x, float y, float z) : x(x), y(y), z(z) {}

// Displace the point by specified amounts
void Point3d::displace(float dx, float dy, float dz) {
    x += dx;
    y += dy;
    z += dz;
}

// Calculate distance to another point
float Point3d::distance(const Point3d &other) const {
    return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2) + pow(z - other.z, 2));
}

// Check if two points are equal
bool Point3d::operator==(const Point3d &other) const {
    return x == other.x && y == other.y && z == other.z;
}

// Check if two points are not equal
bool Point3d::operator!=(const Point3d &other) const {
    return !(*this == other);
}

// Scale point by a factor
Point3d Point3d::operator*(float scale) const {
    return Point3d(x * scale, y * scale, z * scale);
}

// Friend function to scale point using a scalar
Point3d operator*(float scale, const Point3d &point) {
    return Point3d(point.x * scale, point.y * scale, point.z * scale);
}
// Divide point coordinates by a factor
Point3d Point3d::operator/(float scale) const {
    if (scale == 0) {
        throw invalid_argument("Error: Division by zero is not allowed.");
    }
    return Point3d(x / scale, y / scale, z / scale);
}

// Overload for output operator
ostream &operator<<(ostream &strm, const Point3d &point) {
    return strm << "(" << point.x << ", " << point.y << ", " << point.z << ")";
}

// Overload for input operator
istream &operator>>(istream &strm, Point3d &point) {
    cout << "Enter x, y, z: ";
    strm >> point.x >> point.y >> point.z;
    if (!strm) {
        throw invalid_argument("Error: Invalid input for Point3d.");
    }
    return strm;
}
