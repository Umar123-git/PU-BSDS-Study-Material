#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

class HashTable {
private:
    vector<bool> occupied; 
    int size;

public:
    HashTable(int s) : size(s), occupied(s, false) {}

    bool insert(int key) {
        int index = key % size;
        if (occupied[index]) {
            return false; 
        }
        occupied[index] = true;
        return true;
    }
};


int runExperiment(int tableSize) {
    HashTable ht(tableSize);
    int count = 0;

    while (true) {
        int num = rand() % 100 + 1; 
        if (!ht.insert(num)) {
            break; 
        }
        count++;
    }
    return count;
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    const int numExperiments = 50;

    cout << "Table Size\tAverage Inserts Before Collision\n";
    cout << "----------\t-------------------------------\n";

    // Try table sizes 10, 20, ..., 100
    for (int S = 10; S <= 100; S += 10) {
        double total = 0.0;
        for (int i = 0; i < numExperiments; i++) {
            total += runExperiment(S);
        }
        double average = total / numExperiments;
        cout << setw(5) << S << "\t\t" << fixed << setprecision(2) << average << endl;
    }

    return 0;
}