#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;


class Shape {
public:
    virtual float boundaryLength() = 0;
    virtual float area() { return -1; } 
    virtual void display() = 0;         
};


class Rectangle : public Shape {
protected:
    float length;
    float width;

public:
    Rectangle(float l, float w) : length(l), width(w) {}

    float boundaryLength() override {
        return 2 * (length + width);
    }

    float area() override {
        return length * width;
    }

    void display() override {
        cout << "Length: " << length << endl;
        cout << "Width: " << width << endl;
        cout << "Boundary Length: " << boundaryLength() << endl;
        cout << "Area: " << area() << endl;
    }
};

class Circle : public Shape {
protected:
    float radius;

public:
    Circle(float r) : radius(r) {}

    float boundaryLength() override {
        return 2 * M_PI * radius;
    }

    float area() override {
        return M_PI * radius * radius;
    }

    void display() override {
        cout << "Radius: " << radius << endl;
        cout << "Boundary Length: " << boundaryLength() << endl;
        cout << "Area: " << area() << endl;
    }
};

class Triangle : public Shape {
protected:
    float side1;
    float side2;
    float side3;

public:
    Triangle(float s1, float s2, float s3) : side1(s1), side2(s2), side3(s3) {}

    float boundaryLength() override {
        return side1 + side2 + side3;
    }

    float area() override {
        float s = (side1 + side2 + side3) / 2;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    void display() override {
        cout << "Side 1: " << side1 << endl;
        cout << "Side 2: " << side2 << endl;
        cout << "Side 3: " << side3 << endl;
        cout << "Boundary Length: " << boundaryLength() << endl;
        cout << "Area: " << area() << endl;
    }
};


class Pentagon : public Shape {
protected:
    float side;

public:
    Pentagon(float s) : side(s) {}

    float boundaryLength() override {
        return 5 * side;
    }

    float area() override {
        return (sqrt(5 * (5 + 2 * sqrt(5))) * side * side) / 4;
    }

    void display() override {
        cout << "Side: " << side << endl;
        cout << "Boundary Length: " << boundaryLength() << endl;
        cout << "Area: " << area() << endl;
    }
};

int main() {
    
    Shape* s[5];
    s[0] = new Rectangle(2, 4);
    s[1] = new Circle(3);
    s[2] = new Triangle(3, 4, 5);
    s[3] = new Pentagon(5);
    s[4] = new Rectangle(5, 6);

    
    for (int i = 0; i < 5; i++) {
        cout << "Shape " << i + 1 << ":" << endl;
        s[i]->display();
        cout << endl;
    }

   
    for (int i = 0; i < 5; i++) {
        delete s[i];
    }

    return 0;
}