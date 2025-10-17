#include<iostream>
#include<array>
#include<cmath>
using namespace std;





int main()
{
	array<float,25> arr1;
	array<float,25> arr2;
	int a,b,a1,b1;
	cout<<"Enter the number between 0-20 :";
	cin>>a;
	if(a<0 || a>20)
		{
			cout<<"the entered value is invalid ";
			return 1;
		}
	for(int i=1 ; i<=a ; i++)
	{
		b=i;
		
		if(b!=0)
		{
			arr1[i]=float(1)/b;
		}
		
	}
	
	
	cout<<"output \n";
	for(int i=1 ; i<=a ; i++)
	{
		cout<<arr1[i]<<",";
	}
	cout<<endl;
	
	
	
	
	cout<<"Enter the number between 0-20 :";
	cin>>a1;
	if(a1<0 || a1>20 || a1>a)
		{
			cout<<"the entered value is invalid ";
			return 1;
		}
		
		if(a1!=0)
		{
			swap(arr1[a1],arr1[a]);
			//arr1[a]=a1;
		}
		
	cout<<"output \n";
	for(int i=1 ; i<=a ; i++)
	{
		cout<<arr1[i]<<",";
	}
	
	
	return 0;
}