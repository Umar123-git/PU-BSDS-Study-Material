#include "student.h" // Assuming student.h is in the same directory
#include<iostream>
#include <string>
using namespace std;

    Student::Student()
    {
        name = "Null";
        roll = "*******";
        cgpa = 0.0;
    }
    void Student::setdetails(string n, string r, float c)
    {
        name = n;
        roll = r;
        cgpa = c;
    }
    
    void Student::check(float cgpa) const
    {
        if(cgpa>=3.5)
        {
            cout << "You are eligible for scholarship." << endl;
        }
        else
        {
            cout << "You are not eligible for scholarship." << endl;
        }
    }
    void Student::display() const
    {
        cout << "Name: " << name << endl;
        cout << "Roll: " << roll << endl;
        cout << "CGPA: " << cgpa << endl;
        Student::check(cgpa);
    }
