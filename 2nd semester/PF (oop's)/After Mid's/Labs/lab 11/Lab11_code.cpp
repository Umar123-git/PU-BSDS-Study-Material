#include <iostream>
#include <cmath>
using namespace std;

const int MAX_RECTANGLES = 100;
const float PI = 3.141592653589793f;

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

class shape {
public:
    enum Color { black, blue, green, red, white, yellow };

private:
    Color color;

public:
    shape() : color(black) {}  // Default constructor sets default color

    void setColor(Color c) {
        color = c;
    }

    Color getColor() const {
        return color;
    }

    string getColorName() const {
        switch (color) {
            case black: return "Black";
            case blue: return "Blue";
            case green: return "Green";
            case red: return "Red";
            case white: return "White";
            case yellow: return "Yellow";
        }
    }
};

class Rectangle:public shape
{
private:
    Point2D topLeft;
    float width;
    float height;
	Color color;
public:
    Rectangle(const Point2D& tl = Point2D(), float w = 0.0f, float h = 0.0f, Color c = black)
        : topLeft(tl), width(w), height(h) {
        setColor(c);  
    }
    float area() const {
        return width * height;
    }

    float perimeter() const {
        return 2 * (width + height);
    }

    friend ostream& operator<<(ostream& os, const Rectangle& rect) {
        os << "Rectangle at " << rect.topLeft
           << ", width: " << rect.width
           << ", height: " << rect.height
           << ", area: " << rect.area()
           << ", perimeter: " << rect.perimeter()
           << ", color: " << rect.getColorName();
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
    canvas.addRectangle(Rectangle(Point2D(0, 0), 5, 10, shape::blue));
    canvas.addRectangle(Rectangle(Point2D(2, 3), 3, 6, shape::green));
    canvas.addRectangle(Rectangle(Point2D(5, 5), 4, 4, shape::red));
    canvas.addRectangle(Rectangle(Point2D(-2, -1), 2, 8, shape::white));
    canvas.addRectangle(Rectangle(Point2D(10, 0), 6, 3, shape::yellow));

    
    // Output canvas and circle info
    cout << "Canvas info: " << canvas << endl;

    // Create a circle separately
    Circle c1(Point2D(1, 1), 4);
    cout << "Circle info: " << c1 << endl;

    return 0;
}
