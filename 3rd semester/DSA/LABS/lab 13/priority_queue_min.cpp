#include <iostream>
#include <climits>
using namespace std;


class MinHeap {
private:
    int *arr;
    int capacity;
    int no_of_elements;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i)   { return 2 * i + 1; }
    int right(int i)  { return 2 * i + 2; }

    void heapifyUp(int i) {
        while (i != 0 && arr[parent(i)] > arr[i]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int l = left(i), r = right(i), smallest = i;

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
    MinHeap(int cap) {
        capacity = cap;
        no_of_elements = 0;
        arr = new int[cap];
    }

    ~MinHeap() { delete[] arr; }

    bool isEmpty() const { return no_of_elements == 0; }
    bool isFull() const { return no_of_elements == capacity; }

    void insert(int key) {
        if (isFull()) {
            cout << "Heap Overflow\n";
            return;
        }
        arr[no_of_elements] = key;
        heapifyUp(no_of_elements);
        no_of_elements++;
    }

    int getMin() const {
        if (isEmpty()) {
            cout << "Heap is empty\n";
            return INT_MIN;
        }
        return arr[0];
    }

    int extractMin() {
        if (isEmpty()) {
            cout << "Heap is empty\n";
            return INT_MIN;
        }
        int root = arr[0];
        arr[0] = arr[no_of_elements - 1];
        no_of_elements--;
        heapifyDown(0);
        return root;
    }

    int size() const { return no_of_elements; }
};


class MinPriorityQueue {
private:
    MinHeap heap;

public:
    MinPriorityQueue(int cap) : heap(cap) {}

    void push(int x) { heap.insert(x); }

    void pop() { heap.extractMin(); }

    int top() const { return heap.getMin(); }

    bool empty() const { return heap.isEmpty(); }

    int size() const { return heap.size(); }
};


int main() {
    MinPriorityQueue pq(20);

    pq.push(10);
    pq.push(5);
    pq.push(20);
    pq.push(3);

    cout << "Top element: " << pq.top() << endl; 

    pq.pop(); 
    cout << "Top element after pop: " << pq.top() << endl; 

    cout << "Size: " << pq.size() << endl; 

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
}
