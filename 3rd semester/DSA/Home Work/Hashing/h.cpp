#include <iostream>
#include <vector>
#include <list>
#include <climits>
using namespace std;

class HashTable {
private:
    int size;

    // Separate chaining
    vector<list<int>> chainTable;

    // Linear & Quadratic Probing (-1 empty, -2 deleted)
    vector<int> probeTable;

    // Double Hashing
    vector<int> doubleHashTable;

public:
    // =============================
    // Constructor
    // =============================
    HashTable(int s) : size(s) {
        chainTable.resize(size);
        probeTable.assign(size, -1);
        doubleHashTable.assign(size, -1);
    }

    // =============================
    // Hash functions
    // =============================
    int hash1(int key) { return key % size; }
    int hash2(int key) { return 5 - (key % 5); } // for double hashing

    // =============================
    // 1. Separate Chaining
    // =============================
    void insertChaining(int key) {
        chainTable[hash1(key)].push_back(key);
    }

    bool searchChaining(int key) {
        int idx = hash1(key);
        for (int x : chainTable[idx])
            if (x == key) return true;
        return false;
    }

    void deleteChaining(int key) {
        chainTable[hash1(key)].remove(key);
    }

    void displayChaining() {
        cout << "\n=== Separate Chaining ===\n";
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            for (int x : chainTable[i]) cout << x << " -> ";
            cout << "NULL\n";
        }
    }

    // =============================
    // 2. Linear Probing
    // =============================
    void insertLinear(int key) {
        int idx = hash1(key), start = idx;
        while (probeTable[idx] != -1 && probeTable[idx] != -2) {
            idx = (idx + 1) % size;
            if (idx == start) { cout << "Table Full (Linear)\n"; return; }
        }
        probeTable[idx] = key;
    }

    bool searchLinear(int key) {
        int idx = hash1(key), start = idx;
        while (probeTable[idx] != -1) {
            if (probeTable[idx] == key) return true;
            idx = (idx + 1) % size;
            if (idx == start) break;
        }
        return false;
    }

    void deleteLinear(int key) {
        int idx = hash1(key), start = idx;
        while (probeTable[idx] != -1) {
            if (probeTable[idx] == key) { probeTable[idx] = -2; return; }
            idx = (idx + 1) % size;
            if (idx == start) break;
        }
    }

    void displayLinear() {
        cout << "\n=== Linear Probing ===\n";
        for (int i = 0; i < size; i++) cout << i << ": " << probeTable[i] << "\n";
    }

    // =============================
    // 3. Quadratic Probing
    // =============================
    void insertQuadratic(int key) {
        int idx = hash1(key);
        for (int i = 0; i < size; i++) {
            int newIdx = (idx + i * i) % size;
            if (probeTable[newIdx] == -1 || probeTable[newIdx] == -2) {
                probeTable[newIdx] = key;
                return;
            }
        }
        cout << "Table Full (Quadratic)\n";
    }

    bool searchQuadratic(int key) {
        int idx = hash1(key);
        for (int i = 0; i < size; i++) {
            int newIdx = (idx + i * i) % size;
            if (probeTable[newIdx] == key) return true;
            if (probeTable[newIdx] == -1) return false;
        }
        return false;
    }

    void deleteQuadratic(int key) {
        int idx = hash1(key);
        for (int i = 0; i < size; i++) {
            int newIdx = (idx + i * i) % size;
            if (probeTable[newIdx] == key) { probeTable[newIdx] = -2; return; }
            if (probeTable[newIdx] == -1) return;
        }
    }

    void displayQuadratic() { displayLinear(); } // same probeTable

    // =============================
    // 4. Double Hashing
    // =============================
    void insertDouble(int key) {
        int idx = hash1(key), step = hash2(key);
        for (int i = 0; i < size; i++) {
            int newIdx = (idx + i * step) % size;
            if (doubleHashTable[newIdx] == -1 || doubleHashTable[newIdx] == -2) {
                doubleHashTable[newIdx] = key;
                return;
            }
        }
        cout << "Table Full (Double Hashing)\n";
    }

    bool searchDouble(int key) {
        int idx = hash1(key), step = hash2(key);
        for (int i = 0; i < size; i++) {
            int newIdx = (idx + i * step) % size;
            if (doubleHashTable[newIdx] == key) return true;
            if (doubleHashTable[newIdx] == -1) return false;
        }
        return false;
    }

    void deleteDouble(int key) {
        int idx = hash1(key), step = hash2(key);
        for (int i = 0; i < size; i++) {
            int newIdx = (idx + i * step) % size;
            if (doubleHashTable[newIdx] == key) { doubleHashTable[newIdx] = -2; return; }
            if (doubleHashTable[newIdx] == -1) return;
        }
    }

    void displayDouble() {
        cout << "\n=== Double Hashing ===\n";
        for (int i = 0; i < size; i++) cout << i << ": " << doubleHashTable[i] << "\n";
    }

    // =============================
    // 5. Classic Hash Problems (Chaining only, without sets/maps)
    // =============================

    // Count occurrences
    int countOccurrencesChaining(int key) {
        int count = 0;
        int idx = hash1(key);
        for (int x : chainTable[idx])
            if (x == key) count++;
        return count;
    }

    // Has duplicate
    bool hasDuplicateChaining() {
        for (int i = 0; i < size; i++)
            for (auto it1 = chainTable[i].begin(); it1 != chainTable[i].end(); ++it1)
                for (int j = i; j < size; j++) {
                    auto start = (i == j ? next(it1) : chainTable[j].begin());
                    for (auto it2 = start; it2 != chainTable[j].end(); ++it2)
                        if (*it1 == *it2) return true;
                }
        return false;
    }

    // First unique
    int firstUniqueChaining() {
        for (int i = 0; i < size; i++)
            for (auto it1 = chainTable[i].begin(); it1 != chainTable[i].end(); ++it1) {
                bool unique = true;
                for (int j = 0; j < size; j++)
                    for (int x : chainTable[j])
                        if (j != i || &x != &(*it1))
                            if (x == *it1) unique = false;
                if (unique) return *it1;
            }
        return -1;
    }

    // Count distinct
    int countDistinctChaining() {
        int count = 0;
        for (int i = 0; i < size; i++)
            for (auto it1 = chainTable[i].begin(); it1 != chainTable[i].end(); ++it1) {
                bool found = false;
                for (int j = 0; j < i; j++)
                    for (int x : chainTable[j])
                        if (x == *it1) found = true;
                for (auto it2 = chainTable[i].begin(); it2 != it1; ++it2)
                    if (*it2 == *it1) found = true;
                if (!found) count++;
            }
        return count;
    }

    // Remove duplicates
    void removeDuplicatesChaining() {
        for (int i = 0; i < size; i++)
            for (auto it1 = chainTable[i].begin(); it1 != chainTable[i].end(); ++it1) {
                auto it2 = next(it1);
                while (it2 != chainTable[i].end()) {
                    if (*it2 == *it1) it2 = chainTable[i].erase(it2);
                    else ++it2;
                }
            }

        // Across buckets
        for (int i = 0; i < size; i++)
            for (auto it1 = chainTable[i].begin(); it1 != chainTable[i].end(); ++it1)
                for (int j = i + 1; j < size; j++) {
                    auto it2 = chainTable[j].begin();
                    while (it2 != chainTable[j].end()) {
                        if (*it2 == *it1) it2 = chainTable[j].erase(it2);
                        else ++it2;
                    }
                }
    }

    // Max
    int maxChaining() {
        int mx = INT_MIN;
        for (int i = 0; i < size; i++)
            for (int x : chainTable[i]) if (x > mx) mx = x;
        return mx;
    }

    // Min
    int minChaining() {
        int mn = INT_MAX;
        for (int i = 0; i < size; i++)
            for (int x : chainTable[i]) if (x < mn) mn = x;
        return mn;
    }

    // Total integers
    int totalChaining() {
        int total = 0;
        for (int i = 0; i < size; i++) total += chainTable[i].size();
        return total;
    }

    // Two-sum
    bool twoSumChaining(int target) {
        for (int i = 0; i < size; i++)
            for (auto it1 = chainTable[i].begin(); it1 != chainTable[i].end(); ++it1)
                for (int j = i; j < size; j++) {
                    auto start = (i == j ? next(it1) : chainTable[j].begin());
                    for (auto it2 = start; it2 != chainTable[j].end(); ++it2)
                        if (*it1 + *it2 == target) return true;
                }
        return false;
    }
};
int main() {
    // Create a hash table of size 10
    HashTable ht(10);

    // ===========================
    // Insert integers (chaining)
    // ===========================
    int arr[] = {15, 25, 35, 15, 5, 20, 25};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < n; i++)
        ht.insertChaining(arr[i]);

    // Display chaining table
    ht.displayChaining();

    // Classic problems
    cout << "\nCount of 15: " << ht.countOccurrencesChaining(15) << "\n";
    cout << "Has duplicates? " << (ht.hasDuplicateChaining() ? "Yes" : "No") << "\n";
    cout << "First unique: " << ht.firstUniqueChaining() << "\n";
    cout << "Count distinct: " << ht.countDistinctChaining() << "\n";
    cout << "Max value: " << ht.maxChaining() << "\n";
    cout << "Min value: " << ht.minChaining() << "\n";
    cout << "Total elements: " << ht.totalChaining() << "\n";
    cout << "Two-sum 30 exists? " << (ht.twoSumChaining(30) ? "Yes" : "No") << "\n";

    // Remove duplicates and display again
    ht.removeDuplicatesChaining();
    cout << "\nAfter removing duplicates:\n";
    ht.displayChaining();

    // ===========================
    // Linear probing example
    // ===========================
    for(int i = 0; i < n; i++)
        ht.insertLinear(arr[i]);

    ht.displayLinear();

    // ===========================
    // Quadratic probing example
    // ===========================
    // Clear probe table first
    ht = HashTable(10);
    for(int i = 0; i < n; i++)
        ht.insertQuadratic(arr[i]);

    ht.displayQuadratic();

    // ===========================
    // Double hashing example
    // ===========================
    ht = HashTable(10);
    for(int i = 0; i < n; i++)
        ht.insertDouble(arr[i]);

    ht.displayDouble();

    return 0;
}