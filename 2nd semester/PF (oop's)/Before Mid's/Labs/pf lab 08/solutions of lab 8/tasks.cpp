#include <iostream>
#include <string>
#include <array>

using namespace std;

void printArray(array<float, 25> A, int s)
{
    cout << A[0];
    for(int j=1; j<s; j+=1)
    {
        cout << ", " << A[j];
    }    
}

int main()
{
    cout.setf(ios::showpoint);
    cout.setf(ios::fixed);
    cout.precision(3);
    
    
    cout << endl << "task 1-----------------" << endl;
	// task 1
    array<float, 25> A;
    int s;
    cout << "Enter a number upto 20: ";
    cin >> s;
    A[0] = 0;
    for(int j=1; j<s; j+=1)
    {
        A[j] = 1.0/float(j);
    }
    printArray(A, s);
    
    cout << endl << "task 2-----------------" << endl;
	// task 2
    int n;
    cout << "Enter a different number upto " << s << ": ";
    cin >> n;
    float t = A[n];
    A[n] = A[s-1];
    A[s-1] = t;
    printArray(A, s);
    
    cout << endl << "task 3-----------------" << endl;
	// task 3
    // alreay declared, using int n;
    cout << "Enter a different number upto " << s << ": ";
    cin >> n;
    for(int j=s-1; j>=n; j-=1)
    {
        A[j+1] = A[j];
    }
    A[n] = n*n;
    s += 1;
    printArray(A, s);
    
    cout << endl << "task 4-----------------" << endl;
	// task 4
    // alreay declared, using int n;
    n = s/2;
    for(int j=n-1; j<s; j+=1)
    {
        A[j] = A[j+1];
    }
    s -= 1;
    printArray(A, s);

    cout << endl << "end   -----------------" << endl;
    
	return 0;
}
