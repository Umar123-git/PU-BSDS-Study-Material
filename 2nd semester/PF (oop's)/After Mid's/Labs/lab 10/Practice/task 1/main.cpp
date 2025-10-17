#include "student.h" // Assuming student.h is in the same directory
#include<iostream>
#include <string>
using namespace std;



int main()
{
    Student s1,s2,s3;
    //s1.display();
    s1.setdetails("Alice", "CS101", 3.8);
    s1.display();
    s2.setdetails("Bob", "CS102", 3.2); 
    s2.display();
    s3.setdetails("Charlie", "CS103", 3.6);
    s3.display();
    

    return 0;
}