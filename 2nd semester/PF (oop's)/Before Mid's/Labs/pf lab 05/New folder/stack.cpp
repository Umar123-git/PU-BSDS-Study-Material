#include <iostream>
#include <cmath>
#include <array>
#include <string>
using namespace std;

constexpr int Qsize {100};
int j = Qsize - 1;


class Stack
{
	protected:
		array<string,Qsize> arr;
		int n;
	public:
		int j=0;
		Stack():n(0){
		}

		bool isFull()
		{
			return n==Qsize;
		}
		bool isEmpty()
		{
			return n==0;
		}
		int size()
		{
			return n;
		}
		
		string top()const
		{
			return arr[0];
		}
		
		string pop()
		{
			string a=arr[n-1];
			arr[n-1] = "null";
			n--;
			return a;
		}
		
		void push(char iteam)
		{
			arr[n]=iteam;
			n++;
		}


	    void display()
		{	
	        cout << "Display:\n";
	        for (int i = 0; i < n; i++)
			{
	            cout << arr[i] << endl;
	        }
    	}


};




int main() {
    Stack s;
    Stack r;
    s.push('a');
    s.push('b');
    s.push('c');
	
    s.display();

    cout << "Top element: " << s.top() << endl;
    cout << "Popped element: " << s.pop() << endl;
    
    cout << "Top element: " << s.top() << endl;
    cout << "Is full: " << s.isFull() << endl;
    cout << "Is empty: " << s.isEmpty() << endl;
    cout << "Size: " << s.size() << endl;

    s.push('d');
    s.push('e');
    s.push('f');
    s.push('g');

    s.display();
	
    return 0;
}