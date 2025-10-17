#include <iostream>
#include <cmath>
#include <array>
#include <string>
using namespace std;

constexpr int Qsize {100};
int j = Qsize - 1;
string reverse(string b, int j);

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
			string a = arr[n-1];
		//	cout<<a<<endl;
			reverse(a,j);
			n--;
			j++;
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
array<string,100>a;
string reverse(string b, int j)
{
	
	a[j]=b[0];
	return a[j];
}
void disply(int len)
{
	cout<<"reversed string :";
	for(int i=0 ; i<len ; i++)
	{
		cout<<a[i];
	}
}

int main() {
    Stack s;
    Stack r;
    string a;
    a="abcd";
    int len=a.length();
    for(int i=0 ; i<len ; i++)
    {
    	s.push(a[i]);
	}
    
    

    s.display();

    cout << "Top element: " << s.top() << endl;
	for(int i=0 ; i<len ; i++)
	{
	s.pop();
	}
	cout<<endl;
  //  cout << "Popped element: " << s.pop() << endl;
    
    cout << "Top element: " << s.top() << endl;
    cout << "Is full: " << s.isFull() << endl;
    cout << "Is empty: " << s.isEmpty() << endl;
    cout << "Size: " << s.size() << endl;

  /*  s.push('d');
    s.push('e');
    s.push('f');
    s.push('g');*/

    disply(len);
	
    return 0;
}