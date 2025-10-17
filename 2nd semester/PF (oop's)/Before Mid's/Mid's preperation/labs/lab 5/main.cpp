#include<iostream>
using namespace std;

class stack
{
	private:
		char st[50];
		int n;
	public:
		stack()
		{
			n=0;
		}
		
		void push(char c)
		{
			st[n]=c;
			n=n+1;
		}
		void pop()
		{
			n=n-1;
			st[n]=0;
		}
		void top()
		{
			cout<<"top : "<<st[n-1];
		}
		
		bool brackets()
		{
			int arr[6];
			int num=0;
			for(int i=0 ; i<n ; i++)
			{
				if(st[i]=='[')
				{
					arr[num]=1;
					num=num+1;
				}
				if(st[i]==']')
				{
					arr[num]=6;
					num=num+1;
				}
				if(st[i]=='{')
				{
					arr[num]=2;
					num=num+1;
				}
				if(st[i]=='}')
				{
					arr[num]=5;
					num=num+1;
				}
				if(st[i]=='(')
				{
					arr[num]=3;
					num=num+1;
				}
				if(st[i]==')')
				{
					arr[num]=4;
					num=num+1;
				}
				
			}
			for(int i=0 ; i<num ; i++)
				{
					cout<<arr[i]<<" ";
				}
			bool check=true;
				for(int i=1 ; i<num ; i++)
				{
					if(arr[i-1]>arr[i])
					{
						check=false;
						return check;
					}
				}
				
				return check;		
		}
		
		  bool palindrome() {
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            if (st[i] != st[j]) {
                return false;
            }
        }
        return true;
    }
		
		void display()
		{
			cout<<endl;
			for(int i=0 ; i<n ; i++)
			{
				cout<<st[i]<<",";
			}
			cout<<"\n";
		}
		
};

int main()
{
	stack s;
	string st;
	cin>> st;
	for(int i=0 ; i<st.length() ; i++)
	{
		s.push(st[i]);
	}
	cout<<"\n";
	
//	s.display();
	//s.top();
	
	//s.pop();
	//s.display();
	
	cout<<s.brackets();
	
	
	stack s1;
	
}