#include <iostream>
#include <cmath>
#include <array>
#include <string>
using namespace std;



constexpr int qsize {100};
int k = qsize - 1;

class Stack1
{
	protected:
		array<char,qsize> arr;
		int n;
	public:
		Stack1():n(0){
		}


		int size()
		{
			return n;
		}
		
		
		char outqueue()
		{
			char a=arr[n-1];
			arr[n-1] = 0;
			n--;
			return a;
		}
		
		void enqueue(char iteam)
		{
			arr[n]=iteam;
			n++;
		}


	    void displays1()
		{	
	        cout << "Display:\n";
	        for (int i = 0; i < n; i++)
			{
	            cout << arr[i] << endl;
	        }
    	}

};








constexpr int Qsize {100};
int j = Qsize - 1;

class Stack
{
	protected:
		array<char,Qsize> arr;
		int n;
	public:
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
		
		char top()const
		{
			return arr[0];
		}
		
		char pop()
		{
			char a=arr[n-1];
			arr[n-1] = 0;
			n--;
			return a;
		}
		
		void push(char iteam)
		{
			arr[n]=iteam;
			n++;
		}
		
		void search(Stack1 &backup)
		{
			    char a,p;
			    cout<<"enter the alphabet which you wants to search :";
			    cin>>a;
			cout<<"searching...\n";
			for(int i=0 ; i<n ; i++)
			{
				if(arr[i]==a)
				{
					cout<<"the element is founded :"<<arr[i];
					p=arr[i];
				}
				else
				{
					backup.enqueue(arr[i]);
				}
			}
			if(p!=a)
				{
           				 cout << "Element not found." << endl;
        		}
					
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
	Stack1 backup;
    Stack s;
    s.push('a');
    s.push('b');
    s.push('c');
	
    s.display();

    cout << "Top element: " << s.top() << endl;

    cout << "Popped element: " << s.pop() << endl;
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

    s.search(backup);
    cout<<endl;
    backup.displays1();

    return 0;
}