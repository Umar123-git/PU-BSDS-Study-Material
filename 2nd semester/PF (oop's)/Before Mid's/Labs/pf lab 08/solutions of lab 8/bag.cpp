#include <iostream>
#include <string>
#include <array>

using namespace std;

class Bag
{
    protected:
        array<float, 25> A;
        int s;
    public:
        int getSize() const
        {
            return s;
        }
        float getNumber(int j) const // return jth number in array
        {
            return A[j];
        }
        float setNumber(int j, float n) // set jth number in array
        {
            A[j] = n;
        }
        Bag():s{0}
        {}
        void insert(int j, float n) // insert at jth index
        {
            int k;
            for(k=s-1; k>=j; k-=1)
            {
                A[k+1] = A[k];
            }
            A[j] = n;            
        }
        float extract(int j) // extract at jth index
        {
            s -= 1;
            float t = A[j];
            A[j] = A[s];
            A[s] = t;
            return t;
        }
        void addAtEnd(float n) // insert as a new last
        {
            A[s] = n;
            s += 1;
        }
        float extractFromEnd() // extract the last
        {
            s -= 1;
            return A[s];
        }
        void printBag()
        {
            cout << A[0];
            for(int j=1; j<s; j+=1)
            {
                cout << ", " << A[j];
            }    
        }
};

int main()
{
    cout.setf(ios::showpoint);
    cout.setf(ios::fixed);
    cout.precision(3);
    
    Bag g;
    cout << endl << "task 1-----------------" << endl;
	// task 1
    int s;
    cout << "Enter a number upto 20: ";
    cin >> s;
    for(int j=0; j<s; j+=1)
    {
        g.addAtEnd(1.0/float(j));
    }
    g.printBag();
    
    cout << endl << "task 2-----------------" << endl;
	// task 2
    cout << "No a suitable implementation";
    
    cout << endl << "task 3-----------------" << endl;
	// task 3
    int n;
    cout << "Enter a different number upto " << s << ": ";
    cin >> n;
    g.insert(n, n*n);
    g.printBag();
    
    cout << endl << "task 4-----------------" << endl;
	// task 4
    // alreay declared, using int n;
    n = g.getSize()/2;
    cout << "Extracted from middle is number " << g.extract(n) << endl;
    g.printBag();

    cout << endl << "end   -----------------" << endl;
    
	return 0;
}
