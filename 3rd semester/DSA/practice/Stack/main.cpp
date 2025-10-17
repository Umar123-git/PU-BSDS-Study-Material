#include "Stack.h"

int main() {
    Stack<int> s(5);

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Size: " << s.size() << endl;
    cout << "Peek: " << s.peek() << endl;
    cout << "Pop: " << s.pop() << endl;
    cout << "Pop: " << s.pop() << endl;
    cout << "Is empty? " << (s.isempty() ? "Yes" : "No") << endl;

    return 0;
}
