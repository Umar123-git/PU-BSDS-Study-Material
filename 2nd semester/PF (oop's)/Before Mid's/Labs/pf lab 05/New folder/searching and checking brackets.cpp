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
		
		bool isValidExpression(string expr) 
		{
		    Stack s;
		
		    for (char ch : expr) 
			{
		        if (ch=='('|| ch=='{' || ch=='[') 
				{
		            s.push(ch); 
		        } 
		        else if (ch==')' || ch=='}' || ch==']') 
				{
		            if (s.isEmpty())
					{
						return false;
					 } 
		            
		            char top = s.pop();
		
		
		            if ((ch==')' && top!='(') || (ch=='}' && top!='{') ||  (ch==']' && top!='['))
					{
		                return false;
		            }
		       		 }
		        
		        
		    }
		
		    return s.isEmpty();
		}
		


	    void display()
		{	
	        cout << "Display:\n";
	        for (int i = 0; i < n; i++)
			{
	            cout << arr[i] ;
	        }
	        cout<<endl;
    	}

};








int main() {

    Stack s;
	string a;
	a= "2+[3*(9/3–(6+1{}+5]";
//	getline(cin,a);
	int length=a.length();
	for(int i=0 ; i<length ; i++)
	{
		s.push(a[i]);
	}
	
//    s.display();

    cout << "Top element: " << s.top() << endl;

    cout << "Popped element: " << s.pop() << endl;
    cout << "Popped element: " << s.pop() << endl;
    cout << "Top element: " << s.top() << endl;
    cout << "Is full: " << s.isFull() << endl;
    cout << "Is empty: " << s.isEmpty() << endl;
    cout << "Size: " << s.size() << endl;


    s.display();
	cout<<endl<<endl;
    cout<<s.isValidExpression(a);
    


    return 0;
}