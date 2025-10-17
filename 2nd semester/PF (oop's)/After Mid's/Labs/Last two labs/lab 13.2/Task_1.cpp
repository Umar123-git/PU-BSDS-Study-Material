#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    fstream file;
    file.open("fellows1.txt", ios::app);
    if (!file.is_open()) {
        cout << "Unable to open file." << endl;
        return 1;
    }

    string roll, name;
    float cgpa;
    char more = 'y';

    while (more == 'y' || more == 'Y') {
        cout << "Enter roll number: ";
        getline(cin, roll);
        cout << "Enter full name: ";
        getline(cin, name);
        cout << "Enter CGPA: ";
        cin >> cgpa;
        cin.ignore();
        if(cgpa < 0 || cgpa > 4.0) {
            cout << "Invalid CGPA. Please enter a value between 0 and 4.0." << endl;
            continue; 
        }
        // Clear newline from input buffer

        file << roll << ", " << name << ", " << cgpa << endl;

        cout << "Do you want to enter more data (y/n): ";
        cin >> more;
        cin.ignore(); // Clear newline from input buffer
    }

    file.close();
    return 0;
}