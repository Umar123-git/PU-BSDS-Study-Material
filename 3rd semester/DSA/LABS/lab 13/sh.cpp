#include <iostream>
#include <cmath>
using namespace std;

class Student
{

public:
    double cgpa; // Student’s CGPA
    int rollNo;  // Student’s roll number
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
    Student *st;  // Array of students which will be arranged like a Max Heap
    int currSize; // Current number of students present in the heap
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

    // ---- Add multiple sample students ----
    heap.insert(10, 3.2);
    heap.insert(5, 3.9);
    heap.insert(12, 3.5);
    heap.insert(3, 3.9); // Same CGPA as roll 5 (tie-break: smaller
    heap.insert(7, 2.8);
    heap.insert(18, 3.7);
    heap.insert(1, 4.0); // Highest CGPA
    heap.insert(20, 3.4);
    heap.insert(11, 3.7); // Same CGPA as roll 18 (tie-break)
    heap.insert(4, 3.8);

    cout << "===== Level Order After Insertions =====\n";
    heap.levelOrder();
    cout << endl;
    cout << "\nHeight of the heap: " << heap.height() << endl;

    // ---- Remove top student twice ----
    int roll;
    double cg;

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

    cout << "\n===== Level Order After Two Removals =====\n";
    heap.levelOrder();

    cout << "\nHeight of the heap: " << heap.height() << endl;

    return 0;
}





int first_non_repeating(vector<int>& vec){
    vector<int> freq;
    freq.resize(2001);

    for(int i : freq) i=0;


    for(int x : vec)freq[x+1000]++; 


    for(int x:vec){
        if(freq[x+1000]==1) return x;
    }

    return -1;
}


cout<<"---------------Task 2--------------\n";
    vector<int> a={4,5,6,6,4,2,6,5,6,4,5,5,6};

    cout<<first_non_repeating(a);