#include <iostream>
#include <string>
#include "queue.h"

using namespace std;

int main()
{
    try
    {
        Queue nq;
        nq.enqueue(23);
        nq.enqueue(78);
        nq.enqueue(39);
        nq.enqueue(27);
        cout << nq.front() << endl;
        cout << nq.front() << endl;
        cout << nq.dequeue() << endl;
        cout << nq.dequeue() << endl;
        cout << nq.front() << endl;
        cout << nq.front() << endl;
        cout << nq.isFull() << endl;
        cout << nq.isEmpty() << endl;
        cout << nq.size() << endl;
        nq.enqueue(91);
        nq.enqueue(31);
        nq.enqueue(22);
        nq.enqueue(50);
        while(!nq.isEmpty())
        {
            cout << nq.dequeue() << endl;
        }
        cout << nq.isEmpty() << endl;
        cout << nq.front() << endl;
    }
    catch(string se)
    {
        cout << "Exception occured: " << se << endl;
        cout << "This is line number " << __LINE__ << " in file " << __FILE__ << endl;
    }
        
    return 0;
}
