#include <iostream>
#include <cmath>
using namespace std;

class Student
{

public:
    double cgpa; 
    int rollNo;  
    Student()
    {
        cgpa = 0.0;
        rollNo = 0;
    }
    Student(int r, double c)
    {
        rollNo = r;
        cgpa = c;
    }
};
class StudentMaxHeap
{
private:
    Student *st;  
    int currSize; 
    int maxSize;
    bool isGreater(const Student &a, const Student &b)
    {
        if (a.cgpa > b.cgpa)
        {
            return true;
        }
        else if (a.cgpa == b.cgpa)
        {
            if (a.rollNo < b.rollNo)
            {
                return true;
            }
        }
        return false;
    }
    void heapifyUp(int index)
    {
        while (index > 0)
        {
            int parent = (index - 1) / 2;
            if (isGreater(st[index], st[parent]))
                swap(st[index], st[parent]);
            else
                break;
            index = parent;
        }
    }
    void heapifyDown(int index)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < currSize && isGreater(st[left], st[largest]))
            largest = left;
        if (right < currSize && isGreater(st[right], st[largest]))
            largest = right;
        if (largest != index)
        {
            swap(st[index], st[largest]);
            heapifyDown(largest);
        }
    }

public:
    StudentMaxHeap(int size)
    {
        st = new Student[size];
        currSize = 0;
        maxSize = 50;
    }
    ~StudentMaxHeap()
    {
        delete[] st;
    }
    bool isEmpty()
    {
        return currSize == 0;
    }
    bool isFull()
    {
        return currSize == maxSize;
    }
    bool insert(int rollNo, double cgpa)
    {
        if (isFull())
        {
            cout << "Heap is full" << endl;
            return false;
        }
        st[currSize] = Student(rollNo, cgpa);
        heapifyUp(currSize);
        currSize++;
        return true;
    }
    bool removeBestStudent(int &rollNo, double &cgpa)
    {
        if (isEmpty())
        {
            cout << "Heap is empty" << endl;
            return false;
        }
        Student root = st[0];
        rollNo = root.rollNo;
        cgpa = root.cgpa;
        st[0] = st[currSize - 1];
        currSize--;
        heapifyDown(0);
        return true;
    }
    void levelOrder()
    {
        for (int i = 0; i < currSize; i++)
            cout << "ROLLNO" << st[i].rollNo << "     " << "CGPA" << st[i].cgpa << endl;
    }
    int height()
    {
        return int(log2(currSize))+1;
    }
};

int main()
{
    StudentMaxHeap heap(20);

    cout<<"\n---------------Task 1------------------\n";
    heap.insert(10, 3.2);
    heap.insert(5, 3.9);
    heap.insert(12, 3.5);
    heap.insert(3, 3.9); 
    heap.insert(7, 2.8);
    heap.insert(18, 3.7);
    heap.insert(1, 4.0); 
    heap.insert(20, 3.4);
    heap.insert(11, 3.7); 
    heap.insert(4, 3.8);

    heap.levelOrder();
    cout << endl;
    cout << "\nHeight of the heap: " << heap.height() << endl;

    
    int roll;
    double cg;

    cout<<"\n---------------Task 1.2------------------\n";
    if (heap.removeBestStudent(roll, cg))
    {
        cout << "Removed Student - Roll No: " << roll
             << ", CGPA: " << cg << endl;
    }

    if (heap.removeBestStudent(roll, cg))
    {
        cout << "Removed Student - Roll No: " << roll
             << ", CGPA: " << cg << endl;
    }

    cout<<"\n---------------Task 1.3------------------\n";
    
    heap.levelOrder();

    cout << "\nHeight of the heap: " << heap.height() << endl;

    return 0;
}