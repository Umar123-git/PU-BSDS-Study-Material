#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

void heapifyDownMin(int arr[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapifyDownMin(arr, n, smallest);
    }
}

void buildMinHeap(int arr[], int n) {
    // Start from last non-leaf node down to root
    for (int i = n/2 - 1; i >= 0; i--) {
        heapifyDownMin(arr, n, i);
    }
}

class MinHeap {
private:
    int *arr;              // dynamic array to store heap
    int capacity;          // max storage
    int no_of_elements;    // current number of elements

    // Index helpers
    int parent(int i) { return (i - 1) / 2; }
    int left(int i)   { return (2 * i + 1); }
    int right(int i)  { return (2 * i + 2); }

    // Maintain heap property (Move up)
    void heapifyUp(int i) {
        while (i != 0 && arr[parent(i)] > arr[i]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    // Maintain heap property (Move down)
    void heapifyDown(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;

        if (l < no_of_elements && arr[l] < arr[smallest])
            smallest = l;

        if (r < no_of_elements && arr[r] < arr[smallest])
            smallest = r;

        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    // Constructor
    MinHeap(int cap) {
        capacity = cap;
        no_of_elements = 0;
        arr = new int[cap];
    }

    // Destructor
    ~MinHeap() {
        delete[] arr;
    }

    bool isEmpty() const { return no_of_elements == 0; }
    bool isFull()  const { return no_of_elements == capacity; }

    // Return height of heap
    int getHeight() const {
        if (no_of_elements == 0) return -1; // empty heap convention
        return floor(log2(no_of_elements));
    }

    // Insert new key
    void insert(int key) {
        if (isFull()) {
            cout << "Heap Overflow\n";
            return;
        }

        arr[no_of_elements] = key;
        heapifyUp(no_of_elements);
        no_of_elements++;
    }

    // Get minimum
    int getMin() const {
        if (isEmpty()) {
            cout << "Heap is empty\n";
            return -1;
        }
        return arr[0];
    }

    // Extract minimum
    int extractMin() {
        if (isEmpty()) {
            cout << "Heap is empty\n";
            return -1;
        }

        int root = arr[0];
        arr[0] = arr[no_of_elements - 1];
        no_of_elements--;

        heapifyDown(0);
        return root;
    }
    int extractAtIndex(int i) {
    if (i < 0 || i >= no_of_elements) {
        cout << "Invalid index\n";
        return -1;
    }

    int removedValue = arr[i];

    // Move last element to position i
    arr[i] = arr[no_of_elements - 1];
    no_of_elements--;

    // Fix heap property on the replaced element
    if (i != 0 && arr[i] < arr[parent(i)]) {
        // Violates upward property → heapify up
        heapifyUp(i);
    } else {
        // Might violate downward property → heapify down
        heapifyDown(i);
    }

    return removedValue;
}


    // Decrease key at index i
    void decreaseKey(int i, int new_val) {
        if (i >= no_of_elements || new_val > arr[i]) {
            cout << "Invalid decreaseKey operation\n";
            return;
        }
        arr[i] = new_val;
        heapifyUp(i);
    }

    // Delete key at index i
    void deleteKey(int i) {
        if (i >= no_of_elements) {
            cout << "Invalid index\n";
            return;
        }
        decreaseKey(i, INT_MIN);
        extractMin();
    }

    // Display heap content
    void printHeap() const {
        for (int i = 0; i < no_of_elements; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    MinHeap h(20);

    h.insert(10);
    h.insert(40);
    h.insert(5);
    h.insert(30);
    h.insert(20);

    h.printHeap();

    cout << "Min: " << h.getMin() << endl;
    cout << "Height: " << h.getHeight() << endl;

    h.extractMin();
    h.printHeap();

    return 0;
}
