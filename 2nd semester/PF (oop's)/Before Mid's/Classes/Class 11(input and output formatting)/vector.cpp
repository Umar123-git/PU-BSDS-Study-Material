#include <iostream>
using namespace std;

// Forward declaration for manipulators
class Vector;
ostream& parentheses(ostream& os);
ostream& ijk(ostream& os);

// Vector class definition
class Vector {
private:
    double x, y, z; // Vector components
public:
    Vector(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}

    // Getter methods for components (if needed elsewhere)
    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }

    // Overloaded output operator for the default format
    friend ostream& operator<<(ostream& os, const Vector& v) {
        // Check the state of the stream to decide formatting
        if (os.iword(0) == 1) {
            os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
        } else if (os.iword(0) == 2) {
            os << v.x << "i + " << v.y << "j + " << v.z << "k";
        } else {
            os << "(" << v.x << ", " << v.y << ", " << v.z << ")"; // Default
        }
        return os;
    }
};

// Manipulators to toggle formatting
ostream& parentheses(ostream& os) {
    os.iword(0) = 1; // Set flag to 1 for "(x, y, z)" format
    return os;
}

ostream& ijk(ostream& os) {
    os.iword(0) = 2; // Set flag to 2 for "xi + yj + zk" format
    return os;
}

int main() {
    Vector v1(3.5, -2.0, 4.5);

    cout << "Default format: " << v1 << endl;

    // Use parentheses format
    cout << parentheses << v1 << endl;

    // Use ijk format
    cout << ijk << v1 << endl;

    return 0;
}
