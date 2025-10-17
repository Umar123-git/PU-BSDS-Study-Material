#include<iostream>
#include<cmath>
#include<array>
using namespace std;

class Bag
{
	protected:
		array<float,25> arr1;
		array<float,26> arr2;
		array<float,26> arr3;
	public:
		
		Bag()
		{
			cout<<"default constructor \n";
		}
		
		Bag(const int a , int n)
		{
			cout<<"constructor \n"<<n<<endl;
	 		arr1[n]=a;
			cout<<arr1[n]<<endl;
			n++;
		}
		
		~Bag()
		{
			cout<<"destructor \n";
		}
		

		
		void populate(const int& a)
		{
			int b;
			if(a<0 || a>20)
				{
					cout<<"the entered value is invalid ";
					//return 1;
				}
			for(int i=1 ; i<=a ; i++)
			{
				b=i;
				
				if(b!=0)
				{
					arr1[i]=float(1)/b;
				}
				
			}		
		} 
		
		
	void insert(const int& a1, const int& a) 
	{
		
		
		if(a1!=0)
		{
			float val=arr1[a1];
			
			for(int i=1 ; i<=a ; i++)
			{
				arr2[i]=arr1[i];
			}
			
			arr1[a1]=arr1[a1]*arr1[a1];
			
			for(int i=a ; i<a1 ; i--)
			{
				arr2[i]=arr2[i-1];
			}
			
		}
	}
	
	float extract(int& a) 
	{
		int mid;
		cout<<"\ndeleting the midle value\n";
		if(a%2==0)
		{
			cout<<"\neven No. :"<<a<<endl;
			mid=a/2;
			cout<<"mid No. :"<<mid<<endl;
			
			arr1[mid]=0;
		for(int i=1 ; i<mid ; i++)
			{
				arr3[i]=arr1[i];
			}
		for(int i=1 ; i<=mid ; i++)
			{
				arr3[mid+(i-1)]=arr1[mid+(i)];
			}
		}
		else
		{
			cout<<"\nodd No. :"<<a<<endl;
			mid=(a+1)/2;
			cout<<"mid No. :"<<mid<<endl;
			
				arr1[mid]=0;
		for(int i=1 ; i<mid ; i++)
			{
				arr3[i]=arr1[i];
			}
		for(int i=1 ; i<mid ; i++)
			{
				arr3[mid+(i-1)]=arr1[mid+i];
			}
		}
		
		
	}

	void display1(const int& a)const
	{
		cout<<"display \n";
		for(int i=1 ; i<=a ; i++)
			{
				cout<<arr1[i]<<",";			
			}
			cout<<endl;
	}
	void display2(const int& a)const
	{
		cout<<"display \n";
		for(int i=1 ; i<=a ; i++)
			{
				cout<<arr2[i]<<",";			
			}
			cout<<endl;
	}
	void display3(const int& a)const
	{
		cout<<"display \n";
		for(int i=1 ; i<a ; i++)
			{
				cout<<arr2[i]<<",";			
			}
			cout<<endl;
	}

	
};

int main()
{	
	Bag t1;
	int a,a1;
	cout<<"Enter the number between 0-20 :";
	cin>>a;
	t1.populate(a);
	t1.display1(a);
	
	Bag t2;
	cout<<"Enter the number between 0-20 :";
		cin>>a1;
		if(a1<0 || a1>20 || a1>a)
		{
			cout<<"the entered value is invalid ";
			return 1;
		}
		
	t2.insert(a1,a);
	t2.display2(a+1);
	
	Bag t3;
	t3.extract(a);
	t3.display3(a);
	
	
	
	
	return 0;
}