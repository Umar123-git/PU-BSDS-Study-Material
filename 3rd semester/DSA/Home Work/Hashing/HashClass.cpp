#include <iostream>
#include "Linear_Single_LinkedList.h"
using namespace std;

template <typename T>
class Hash_Table {
private:
    int Totalbuckets;
    list<T>* table;

    int HashFunction(int key) {
        return key % Totalbuckets;
    }

public:

    Hash_Table(int buckets = 10) {
        Totalbuckets = buckets;
        table = new list<T>[buckets];
    }

    // ---------------- INSERT ----------------
    void Insert(int key, T obj) {
        int index = HashFunction(key);
        table[index].push_back(obj);
    }

    // ---------------- REMOVE ----------------
    bool Remove(int key, T obj) {
        int index = HashFunction(key);

        if (table[index].search(obj) == -1)
            return false;

        table[index].pop(obj);
        return true;
    }

    // ---------------- SEARCH ----------------
    bool Search(int key, T obj) {
        int index = HashFunction(key);
        return table[index].search(obj) != -1;
    }

    // ---------------- UPDATE ----------------
    bool Update(int key, T oldVal, T newVal) {
        int index = HashFunction(key);
        if (table[index].search(oldVal) != -1) {
            table[index].updateNode(oldVal, newVal);
            return true;
        }
        return false;
    }

    // ---------------- DISPLAY ----------------
    void Display() {
        cout << "\n----- HASH TABLE -----\n";
        for (int i = 0; i < Totalbuckets; i++) {
            cout << "[" << i << "] --> ";
            table[i].display();
        }
        cout << "-----------------------\n";
    }

    void DisplayBucket(int key) {
        int index = HashFunction(key);
        cout << "[" << index << "] --> ";
        table[index].display();
    }

    // ---------------- INFORMATIONAL FUNCTIONS ----------------
    
    bool IsEmpty() {
        for (int i = 0; i < Totalbuckets; i++)
            if (!table[i].isEmpty()) return false;
        return true;
    }

    bool IsBucketEmpty(int key) {
        return table[HashFunction(key)].isEmpty();
    }

    int BucketSize(int key) {
        return table[HashFunction(key)].countNodes();
    }

    int TotalElements() {
        int total = 0;
        for (int i = 0; i < Totalbuckets; i++)
            total += table[i].countNodes();
        return total;
    }

    double LoadFactor() {
        return (double)TotalElements() / Totalbuckets;
    }

    int MaxBucketSize() {
        int mx = 0;
        for (int i = 0; i < Totalbuckets; i++)
            mx = max(mx, table[i].countNodes());
        return mx;
    }

    int MinBucketSize() {
        int mn = INT_MAX;
        for (int i = 0; i < Totalbuckets; i++)
            mn = min(mn, table[i].countNodes());
        return (mn == INT_MAX) ? 0 : mn;
    }

    int EmptyBucketsCount() {
        int c = 0;
        for (int i = 0; i < Totalbuckets; i++)
            if (table[i].isEmpty()) c++;
        return c;
    }

    // ---------------- REHASH ----------------
    void Rehash(int newBucketCount) {
        list<T>* oldTable = table;
        int oldCount = Totalbuckets;

        Totalbuckets = newBucketCount;
        table = new list<T>[Totalbuckets];

        for (int i = 0; i < oldCount; i++) {
            Node<T>* temp = oldTable[i].head;
            while (temp) {
                Insert(temp->data.length(), temp->data);  
                temp = temp->next;
            }
        }
        delete[] oldTable;
    }

    ~Hash_Table() {
        delete[] table;
    }
};

// ---------------- MAIN ----------------
int main() {
    Hash_Table<string> p(5);

    p.Insert(2, "Farham");
    p.Insert(3, "Ali");
    p.Insert(2, "Ahmad");
    p.Insert(7, "Zain");

    p.Display();

    cout << (p.Search(2, "Ahmad") ? "Found" : "Not Found") << endl;

    p.Remove(2, "Ahmad");

    p.Display();
}
