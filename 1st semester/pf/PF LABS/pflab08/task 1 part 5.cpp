#include <iostream>
#include <array>
#include <string>

using namespace std;



struct Student {
    int rollno;
    string name;
    float percent;
};



void sortStudents(Student students[], int size) {
    int i = 0;
    while (i < size ) {
        int j = i ;
        while (j < size) {
            if (students[i].percent < students[j].percent) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
            j++;
        }
        i++;
    }
}




int main() {
    int size;
    cout << "Enter number of students: ";
    cin >> size;
    Student students[100];


    int i = 0;
    while (i < size) {
        cout << "Enter details for student " << i + 1 << endl;
        cout << "Roll number: ";
        cin >> students[i].rollno;
        cout << "Name: ";
        cin>>students[i].name;
        cout << "Percent marks: ";
        cin >> students[i].percent;
        i++;
    }


    sortStudents(students, size);



    cout << "Sorted list of students by percent marks (descending):\n";
    i = 0;
    while (i < size) {
        cout << "Roll Number: " << students[i].rollno << ", Name: " << students[i].name
             << ", Percent Marks: " << students[i].percent << endl;
        i++;
    }

    return 0;
}
