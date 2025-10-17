#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

template<typename T>
class Stack {
private:
    T* data;
    int capacity;
    int top;

public:
    Stack()
    {
        data = new T[0];
        capacity = 0;
        top = 0;
        data = nullptr;
    }
    Stack(int c) {
        top = 0;
        data = new T[c];
        capacity = c;
    }

    ~Stack() {
        delete[] data;
    }

    void push(const T& d) {
        if (top == capacity) {
            cout << "The capacity is full\n";
            return;
        }
        data[top++] = d;
    }

    T pop() {
        if (top == 0) {
            throw runtime_error("Stack is empty");
        }
        return data[--top];
    }

    bool isfull() const {
        return top == capacity;
    }

    bool isempty() const {
        return top == 0;
    }

    int size() const {
        return top;
    }

    // Copy constructor
    Stack(const Stack &r) {
        top = r.top;
        capacity = r.capacity;
        data = new T[capacity];
        for (int i = 0; i < top; i++) {
            data[i] = r.data[i];
        }
    }

    // Assignment operator
    Stack& operator=(const Stack &r) {
        if (this != &r) {
            delete[] data;
            top = r.top;
            capacity = r.capacity;
            data = new T[capacity];
            for (int i = 0; i < top; i++) {
                data[i] = r.data[i];
            }
        }
        return *this;
    }

    // Optional: peek/top function
    T peek() const {
        if (top == 0) {
            throw runtime_error("Stack is empty");
        }
        return data[top - 1];
    }
};

#endif // STACK_H
