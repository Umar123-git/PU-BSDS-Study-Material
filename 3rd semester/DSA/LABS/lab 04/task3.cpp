#include <iostream>
#include "Queue.h"
using namespace std;

int main() {
    Queue<int> q(5);
    q.enqueue(14); 
    q.enqueue(22); 
    q.enqueue(13); 
    q.enqueue(-6); 
    q.display(); 
    cout<<"Deleted Value = "<<q.dequeue()<<endl; 
    cout<<"Deleted Value = "<<q.dequeue()<<endl; 
    q.display(); 
    
    q.enqueue(9); 
    q.enqueue(20); 
    q.enqueue(5); 
    q.display();
    return 0;
}
