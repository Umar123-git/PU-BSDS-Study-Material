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
			//cout<<arr[n];
			n++;
		}
		
		
		bool comparison(int &mid , string &a ,int l)
		{
		//	bool com = false;
		//	cout<<mid<<a;
		//	int j=mid+1;
			l=l-1;
			for(int i=0 ; i<mid ; i++)
			{
				cout<<"int "<<i<<endl;
				if(arr[i]!=a[l])
				{
					cout<<"arr["<<i<<"]"<<arr[i]<<   "   a["<<l<<"]"<<a[l]<<endl;
					return false;
					
				}
				l=l-1;
			}
			return true;
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
    string a;
	cout<<"Write the word you wants to test as it is palindrome : ";
	cin>>a;
	int mid=0;
	int length = a.length();
 	if(length%2==1)
 	{
 		mid=length/2;
		 cout<<mid+1<<endl;	
	}
	else
	{
		mid=length/2;
		cout<<mid<<endl;
	}
	
	for(int i=0 ; i<mid ; i++)
	{
		s.push(a[i]);
	}
   
    s.display();
 	cout<<s.comparison(mid , a, length);
    return 0;
}