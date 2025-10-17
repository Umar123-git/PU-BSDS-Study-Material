#include <iostream>
using namespace std;

class Point {
public:
    int x, y;

    Point(int x = 0, int y = 0) : x(x), y(y) {}
    void display() const {
        cout << "Point(" << x << ", " << y << ")" << endl;
    }
};

class Circle {
private:
    Point* center; // Owned by Circle
    int radius;

public:
    Circle(int x, int y, int r) {
        center = new Point(x, y); // Dynamically allocated, tied lifecycle
        radius = r;
    }

    ~Circle() {
        delete center; // Explicitly managed
    }

    void display() const {
        cout << "Circle Center: ";
        center->display();
        cout << "Radius: " << radius << endl;
    }
};

// Test Code
int main() {
    Circle circle(5, 10, 20);
    circle.display();

    return 0;
}
