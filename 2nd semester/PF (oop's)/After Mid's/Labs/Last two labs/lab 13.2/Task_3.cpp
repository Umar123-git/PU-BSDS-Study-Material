#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    fstream file;
    file.open("fellows2.txt", ios::in);
    if (!file.is_open()) {
        cout << "Unable to open file." << endl;
        return 1;
    }

    int recordNum;
    cout << "Enter fellow number (starting from 1): ";
    cin >> recordNum;

    
    string line;
    int current = 1;
    bool found = false;
    while (getline(file, line)) {
        if (current == recordNum) {
            
            size_t pos1 = line.find(',');
            size_t pos2 = line.rfind(',');

            string roll = line.substr(0, pos1);
            string name = line.substr(pos1 + 1, pos2 - pos1 - 1);
            string cgpa = line.substr(pos2 + 1);


            cout << "Fellow Number: " << recordNum << endl;
            cout << "Roll Number: " << roll << endl;
            cout << "Name: " << name << endl;
            cout << "CGPA: " << cgpa << endl;
            found = true;
            break;
        }
        current++;
    }

    if (!found) {
        cout << "Record not found." << endl;
    }

    file.close();
    return 0;
}