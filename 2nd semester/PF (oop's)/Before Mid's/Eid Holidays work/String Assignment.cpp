#include<iostream>
#include<string>
#include<array>
#include<cmath>
using namespace std;


class Text
{
	protected:
		int n;
	
		char* arr;
		
	
	public:
		Text()
		{
			n=10;
			arr=new char[n];
			cout<<"default constructor \n";
		}
		~Text()
		{
			cout<<"\nDestructor\n";
			delete[] arr;
		}
		void sinle_use_add(string& a)
		{
			delete[] arr; 
				n=a.length();
				arr = new char[n];
				for(int i=0 ; i<n ; i++)
				{
					arr[i]=a[i];
				}
			//	arr[n]=' ';
		}
		
		void multip_use_adder(string& a)
		{
			char* temp = new char[n];
			memcpy(temp , arr , n*sizeof(char));
			delete[] arr;
			
			int size=this->n;
			n=1+n+a.length();
				arr = new char[n];
				memcpy(arr , temp , n*sizeof(char));
				
				for(int i=0 ; i<a.length() ; i++)
				{
					arr[size+i+1]=a[i];
				}
			arr[size]=' ';
			delete[] temp;
				
		}
		
		
		
		void length_of_string()
		{
			cout<<"Length of string is :"<<n;
		}
		
		void display()
		{
			cout<<"\ndisplay :";
			for(int i=0 ; i<n ; i++)
			{
				cout<<arr[i];	
			}
			
			cout<<"\n";
		}	
	
	
};

int main()
{
	Text t;
	string a;
	cout<<"Enter the Text : ";
	getline(cin,a);
	t.sinle_use_add(a);
	t.length_of_string();
	t.display();
	
	cout<<"You wants to add more text in it? (Y or N) :";
	char m;  
	cin>>m;
	cin.ignore();
	if(m == 'Y' || m == 'y')
	{         
		getline(cin,a);
		t.multip_use_adder(a);
		t.length_of_string();
		t.display();
	}
	else
	{
		return 0;
	}
	
	
	
	return 0;
}