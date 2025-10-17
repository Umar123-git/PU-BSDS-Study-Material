#include <iostream>
#include "Queue.h"
using namespace std;

int main() {
    cout << "=== Queue Testing Program ===\n";

    // 1. Create a queue of capacity 5
    Queue<int> q(5);
    cout << "\nEnqueueing 5 elements (1 to 5):\n";
    for (int i = 1; i <= 5; i++) {
        q.enqueue(i);
        q.display();
        cout << "   (size=" << q.size() << ")\n";
    }

    // 2. Try enqueue on a full queue
    cout << "\nTrying to enqueue 6 on full queue:\n";
    q.enqueue(6);

    // 3. Front and Rear
    cout << "\nFront element: " << q.front() << endl;
    cout << "Rear element: " << q.rear() << endl;

    // 4. Dequeue 2 elements
    cout << "\nDequeuing 2 elements:\n";
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    q.display(); cout << "   (size=" << q.size() << ")\n";

    // 5. Enqueue more to test circular behavior
    cout << "\nEnqueueing 6 and 7 (circular check):\n";
    q.enqueue(6);
    q.enqueue(7);
    q.display(); cout << "   (size=" << q.size() << ")\n";

    // 6. Copy constructor
    cout << "\nTesting copy constructor:\n";
    Queue<int> q2 = q;
    q2.display(); cout << "   (size=" << q2.size() << ")\n";

    // 7. Assignment operator
    cout << "\nTesting assignment operator:\n";
    Queue<int> q3;
    q3 = q;
    q3.display(); cout << "   (size=" << q3.size() << ")\n";

    // 8. Resize the original queue
    cout << "\nResizing queue from capacity 5 to 10:\n";
    q.resize(10);
    q.display(); cout << "   (size=" << q.size() << ")\n";

    // 9. Enqueue more after resize
    cout << "\nEnqueueing 8, 9, 10 after resize:\n";
    q.enqueue(8);
    q.enqueue(9);
    q.enqueue(10);
    q.display(); cout << "   (size=" << q.size() << ")\n";

    // 10. Dequeue all elements
    cout << "\nDequeuing everything until empty:\n";
    while (!q.isEmpty()) {
        cout << "Dequeued: " << q.dequeue() << endl;
    }

    cout << "\nFinal queue state: ";
    q.display(); 
    cout << "   (size=" << q.size() << ")\n";

    cout << "\n=== Testing Complete ===\n";
    return 0;
}
