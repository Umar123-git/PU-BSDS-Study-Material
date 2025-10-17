#include "queue.h"

Queue::Queue() : n(0)
{
}
void Queue::advance()
{
    int i = 0;
    while (i < this->size())
    {
        this->q[i] = this->q[i+1];
        i = i+1;
    }

}
bool Queue::isEmpty() const
{
    return this->n == 0;
}
bool Queue::isFull() const
{
    return this->n == QSIZE;
}
int Queue::size() const
{
    return this->n;
}
double Queue::front() const
{
    if (this->size() > 0)
    {
        return this->q[0];
    }
    else
    {
        throw string("Empty");
    }
}
void Queue::enqueue(double item)
{
    if (this->size() < QSIZE)
    {
        this->q[this->n] = item;
        this->n += 1;
    }
    else
    {
        throw string("Full");
    }
}
double Queue::dequeue()
{
    double item = this->front();
    this->n -= 1;
    this->advance();
    return item;
}

