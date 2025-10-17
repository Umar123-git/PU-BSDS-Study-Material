#include <iostream>
#include <cmath>
using namespace std;

const int MAX_RECTANGLES = 100;
const float PI = 3.141592653589793f;

enum Color {black, blue, green, red, yellow, white, golden, silver};

class Point2D {
public:
    float x;
    float y;

    Point2D(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}

    friend ostream& operator<<(ostream& os, const Point2D& point) {
        os << "(" << point.x << ", " << point.y << ")";
        return os;
    }
};

class Shape
{
public:
    Color color;
};

class Rectangle : public Shape {
private:
    Point2D topLeft;
    float width;
    float height;

public:
    Rectangle(const Point2D& tl = Point2D(), float w = 0.0f, float h = 0.0f, Color c = white)
        : topLeft(tl), width(w), height(h)
    {
        color = c;
    }

    float area() const {
        return width * height;
    }

    float perimeter() const {
        return 2 * (width + height);
    }

    friend ostream& operator<<(ostream& os, const Rectangle& rect) {
        os << "Rectangle at " << rect.topLeft
           << ", color code: " << rect.color
           << ", width: " << rect.width
           << ", height: " << rect.height
           << ", area: " << rect.area()
           << ", perimeter: " << rect.perimeter();
        return os;
    }
};

class Circle {
private:
    Point2D center;
    float radius;

public:
    Circle(const Point2D& c = Point2D(), float r = 0.0f)
        : center(c), radius(r) {}

    float area() const {
        return PI * radius * radius;
    }

    float perimeter() const {  // Circumference
        return 2 * PI * radius;
    }

    friend ostream& operator<<(ostream& os, const Circle& circle) {
        os << "Circle at " << circle.center
           << ", radius: " << circle.radius
           << ", area: " << circle.area()
           << ", perimeter: " << circle.perimeter();
        return os;
    }
};

class Canvas {
private:
    Rectangle rectangles[MAX_RECTANGLES];
    int count;

public:
    Canvas() : count(0) {}

    bool addRectangle(const Rectangle& rect) {
        if (count < MAX_RECTANGLES) {
            rectangles[count++] = rect;
            return true;
        }
        return false;
    }

    friend ostream& operator<<(ostream& os, const Canvas& canvas) {
        os << "Canvas contains " << canvas.count << " rectangles:\n";
        for (int i = 0; i < canvas.count; ++i) {
            os << "  " << canvas.rectangles[i] << "\n";
        }
        return os;
    }
};

// Example usage
int main() {
    Canvas canvas;

    // Add multiple rectangles
    canvas.addRectangle(Rectangle(Point2D(0, 0), 5, 10, red));
    canvas.addRectangle(Rectangle(Point2D(2, 3), 3, 6, blue));
    canvas.addRectangle(Rectangle(Point2D(5, 5), 4, 4, red));
    canvas.addRectangle(Rectangle(Point2D(-2, -1), 2, 8, black));
    canvas.addRectangle(Rectangle(Point2D(10, 0), 6, 3, silver));

    // Output canvas and circle info
    cout << "Canvas info: " << canvas << endl;

    // Create a circle separately
    Circle c1(Point2D(1, 1), 4);
    cout << "Circle info: " << c1 << endl;

    return 0;
}
