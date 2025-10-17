#ifndef Task_1_
#define Task_1_

#include <string>
#include <iostream>
using namespace std;


class Student
{
    private:
        string name;
        string roll;
        float cgpa;
    public:
        Student();
        void setdetails(string n, string r, float c);
        void display() const;
        void check(float cgpa) const;

        
};

#endif