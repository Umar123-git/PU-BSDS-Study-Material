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
    Point* center; // Shared, not owned by Circle
    int radius;

public:
    Circle(Point* p, int r) : center(p), radius(r) {} // Pointer passed into Circle

    void display() const {
        cout << "Circle Center: ";
        center->display();
        cout << "Radius: " << radius << endl;
    }
};

// Test Code
int main() {
    Point sharedPoint(5, 10); // Created independently
    sharedPoint.display();
    Circle circle(&sharedPoint, 20); // Passed into Circle
    circle.display();

    return 0;
}
