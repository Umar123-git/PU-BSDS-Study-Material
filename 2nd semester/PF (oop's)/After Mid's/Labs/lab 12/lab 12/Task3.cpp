#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

class Shape {
public:
    virtual float boundaryLength() = 0; 
    virtual void display(int i) = 0;    
    virtual ~Shape() {}             
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

    float area() {
        return length * width;
    }

    void display(int i) override {
        cout << left << setw(5) << i
             << setw(15) << "Rectangle"
             << setw(15) << fixed << setprecision(2) << area()
             << setw(15) << "Length: " + to_string(length) + ", Width: " + to_string(width) << endl;
        cout <<left<< setw(50) << "Boundary Length: " << boundaryLength() << endl;
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

    float area() { 
        return M_PI * radius * radius;
    }

    void display(int i) override {
        cout << left << setw(5) << i
             << setw(15) << "Circle"
             << setw(15) << fixed << setprecision(2) << area()
             << setw(15) << "Radius: " + to_string(radius) << endl;
        cout << left << setw(50) << "Boundary Length: " << boundaryLength() << endl;
    }
};

int main() {

    Shape* shapes[6];
    shapes[0] = new Rectangle(2, 4);
    shapes[1] = new Circle(3);
    shapes[2] = new Rectangle(5, 6);
    shapes[3] = new Circle(7);
    shapes[4] = new Rectangle(8, 9);
    shapes[5] = new Circle(10);


    cout << left << setw(5) << "Sr#"
         << setw(15) << "Type"
         << setw(15) << "Area"
         << setw(15) << "Data" << endl;
    cout << left << setw(5) << "----"
         << setw(15) << "----"
         << setw(15) << "----"
         << setw(15) << "-------------------" << endl;


    for (int i = 0; i < 6; i++) {
      
        if (Rectangle* rect = dynamic_cast<Rectangle*>(shapes[i])) {
            rect->display(i + 1);
        } else if (Circle* circ = dynamic_cast<Circle*>(shapes[i])) {
            circ->display(i + 1);
        }
        cout << endl;
    }


    for (int i = 0; i < 6; i++) {
        delete shapes[i];
    }

    return 0;
}