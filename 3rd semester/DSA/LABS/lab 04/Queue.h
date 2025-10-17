#ifndef Queue_H
#define Queue_H
#include<process.h>

#include <iostream>
using namespace std;



template<typename T>
class Queue
{
private:
    T* data;
    int capacity;
    int noofelements;
    int frontIndex;
    int rearIndex;

public:
    Queue()
    {
        data = nullptr;
        capacity = 0;
        noofelements = 0;
        frontIndex = 0;
        rearIndex = -1;
    }

    Queue(int c)
    {
        data = new T[c];
        capacity = c;
        noofelements = 0;
        frontIndex = 0;
        rearIndex = -1;
    }

    ~Queue()
    {
        delete[] data;
        data = nullptr;
    }

    void enqueue(T x)
    {
        if (!isFull()) {
            rearIndex = (rearIndex + 1) % capacity;
            data[rearIndex] = x;
            noofelements++;
        }
        else {
            cout << "The Queue is full\n";
        }
    }

    T dequeue()
    {
        if (!isEmpty()) {
            T value = data[frontIndex];
            frontIndex = (frontIndex + 1) % capacity;
            noofelements--;
            return value;
        }
        throw runtime_error("Queue is empty");
    }

    T front()
    {
        if (!isEmpty()) {
            return data[frontIndex];
        }
        throw runtime_error("Queue is empty");
    }

    T rear()
    {
        if (!isEmpty()) {
            return data[rearIndex];
        }
        throw runtime_error("Queue is empty");
    }

    bool isFull() const
    {
        return noofelements == capacity;
    }

    bool isEmpty() const
    {
        return noofelements == 0;
    }

    int size() const {
        return noofelements;
    }

    // Correct Copy constructor
    Queue(const Queue& r)
    {
        noofelements = r.noofelements;
        capacity = r.capacity;
        frontIndex = 0;
        rearIndex = noofelements - 1;
        data = new T[capacity];
        for (int i = 0; i < noofelements; i++) {
            data[i] = r.data[(r.frontIndex + i) % r.capacity];
        }
    }

    // Correct resize
    void resize(int s)
    {
        if (s <= capacity) {
            cout << "\nThe original capacity is already larger than or equal to the new one";
            return;
        }
        T* data1 = new T[s];
        for (int i = 0; i < noofelements; i++) {
            data1[i] = data[(frontIndex + i) % capacity];
        }
        delete[] data;
        data = data1;
        capacity = s;
        frontIndex = 0;
        rearIndex = noofelements - 1;
    }

    // Correct assignment operator
    Queue& operator=(const Queue& r)
    {
        if (this != &r)
        {
            delete[] data;
            noofelements = r.noofelements;
            capacity = r.capacity;
            frontIndex = 0;
            rearIndex = noofelements - 1;
            data = new T[capacity];
            for (int i = 0; i < noofelements; i++) {
                data[i] = r.data[(r.frontIndex + i) % r.capacity];
            }
        }
        return *this;
    }

    void display() const {
        if (!isEmpty()) {
            int count = noofelements;
            int f = frontIndex;
            for (int i = 0; i < count; i++) {
                cout << data[(f + i) % capacity];
                if (i != count - 1) cout << " , ";
            }
        }
    }
};

#endif
