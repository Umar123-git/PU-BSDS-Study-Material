#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

void heapifyDownMax(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapifyDownMax(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    // Start from last non-leaf node down to root
    for (int i = n/2 - 1; i >= 0; i--) {
        heapifyDownMax(arr, n, i);
    }
}

class MaxHeap
{
private:
    int *arr;
    int capacity;
    int no_of_elements;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    // Move element upward if it violates max-heap property
    void heapifyUp(int i)
    {
        while (i != 0 && arr[parent(i)] < arr[i])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    // Move element downward if it violates max-heap property
    void heapifyDown(int i)
    {
        int l = left(i);
        int r = right(i);
        int largest = i;

        if (l < no_of_elements && arr[l] > arr[largest])
            largest = l;

        if (r < no_of_elements && arr[r] > arr[largest])
            largest = r;

        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            heapifyDown(largest);
        }
    }

public:
    MaxHeap(int cap)
    {
        capacity = cap;
        no_of_elements = 0;
        arr = new int[cap];
    }

    ~MaxHeap()
    {
        delete[] arr;
    }

    bool isEmpty() const { return no_of_elements == 0; }
    bool isFull() const { return no_of_elements == capacity; }

    int getHeight() const
    {
        if (no_of_elements == 0)
            return -1;
        return floor(log2(no_of_elements));
    }

    // Insert new value
    void insert(int key)
    {
        if (isFull())
        {
            cout << "Heap Overflow\n";
            return;
        }

        arr[no_of_elements] = key;
        heapifyUp(no_of_elements);
        no_of_elements++;
    }

    // Returns the maximum element (root)
    int getMax() const
    {
        if (isEmpty())
        {
            cout << "Heap is empty\n";
            return -1;
        }
        return arr[0];
    }

    // Extract maximum (root)
    int extractMax()
    {
        if (isEmpty())
        {
            cout << "Heap is empty\n";
            return -1;
        }

        int root = arr[0];
        arr[0] = arr[no_of_elements - 1];
        no_of_elements--;

        heapifyDown(0);
        return root;
    }

    // Extract element from ANY index
    int extractAtIndex(int i)
    {
        if (i < 0 || i >= no_of_elements)
        {
            cout << "Invalid index\n";
            return -1;
        }

        int removedVal = arr[i];
        arr[i] = arr[no_of_elements - 1];
        no_of_elements--;

        // Decide direction
        if (i != 0 && arr[i] > arr[parent(i)])
        {
            heapifyUp(i);
        }
        else
        {
            heapifyDown(i);
        }

        return removedVal;
    }

    // Decrease a key → for MaxHeap: new_val must be smaller
    void decreaseKey(int i, int new_val)
    {
        if (i >= no_of_elements || new_val > arr[i])
        {
            cout << "Invalid decreaseKey\n";
            return;
        }

        arr[i] = new_val;
        heapifyDown(i);
    }

    // Increase a key → new_val must be bigger
    void increaseKey(int i, int new_val)
    {
        if (i >= no_of_elements || new_val < arr[i])
        {
            cout << "Invalid increaseKey\n";
            return;
        }

        arr[i] = new_val;
        heapifyUp(i);
    }

    // Delete value at index i
    void deleteKey(int i)
    {
        if (i < 0 || i >= no_of_elements)
        {
            cout << "Invalid index\n";
            return;
        }

        increaseKey(i, INT_MAX); // make it maximum
        extractMax();
    }

    void printHeap() const
    {
        for (int i = 0; i < no_of_elements; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main()
{
    MaxHeap h(20);

    h.insert(30);
    h.insert(10);
    h.insert(50);
    h.insert(40);
    h.insert(20);

    h.printHeap();

    cout << "Max: " << h.getMax() << endl;

    cout << "Extracted index 2: " << h.extractAtIndex(2) << endl;
    h.printHeap();

    cout << "Extracted Max: " << h.extractMax() << endl;
    h.printHeap();

    return 0;
}
