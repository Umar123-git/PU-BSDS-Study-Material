#ifndef pk_edu_nc_pucit_queue_fifo_lect11
#define pk_edu_nc_pucit_queue_fifo_lect11
 
#include <array>

using namespace std;

constexpr int QSIZE {100};

class Queue
{
protected:
    array<double, QSIZE> q;
	int n;
    
    void advance();
public:
    Queue();
	bool isEmpty() const;
	bool isFull() const;
	int size() const;
    double front() const;
	void enqueue(double);
    double dequeue();
};
 
#endif

