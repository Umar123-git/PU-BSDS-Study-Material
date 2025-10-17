#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("fellows2.txt"); // or "fellows1.txt"
    if (!file.is_open()) {
        cout << "Unable to open file." << endl;
        return 1;
    }

    string line;
    int count = 1;
    while (getline(file, line)) {
        // Assuming format: Roll , Name , CGPA
        size_t pos1 = line.find(',');
        size_t pos2 = line.rfind(',');

        if (pos1 == string::npos || pos2 == string::npos || pos1 == pos2) {
            continue; // skip malformed lines
        }

        string roll = line.substr(0, pos1);
        string name = line.substr(pos1 + 1, pos2 - pos1 - 1);
        string cgpa = line.substr(pos2 + 1);

        // Trim spaces
        while (!name.empty() && (name[0] == ' ' || name[0] == ',')) name = name.substr(1);
        while (!cgpa.empty() && (cgpa[0] == ' ' || cgpa[0] == ',')) cgpa = cgpa.substr(1);

        cout << count << " " << name << ", " << roll << endl;
        cout << "   CGPA: " << cgpa << endl;
        count++;
    }

    file.close();
    return 0;
}