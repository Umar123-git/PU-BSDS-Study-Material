#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main() {
    
    ifstream fin("fellows2.txt");
    vector<string> lines;
    string line;
    while (getline(fin, line)) {
        lines.push_back(line);
    }
    fin.close();

    
    if (lines.size() < 2) {
        cout << "Not enough records to change the 2nd last." << endl;
        return 1;
    }
    lines[lines.size() - 2] = "BCDF99H999, Bara Admi, 4.00";

    
    ofstream fout("fellows2.txt", ios::out | ios::ate);
    if (!fout.is_open()) {
        cout << "Unable to open fellows2.txt for writing." << endl;
        return 1;
    }
    
    fout.seekp(0);
    for (const auto& l : lines) {
        fout << l << endl;
    }
    fout.close();

    cout << "2nd last record updated successfully." << endl;
    return 0;
}