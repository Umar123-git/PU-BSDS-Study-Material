#include<iostream>
#include<array>
#include<cmath>
using namespace std;





int main()
{
	array<float,25> arr;
	int a,b;
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
			arr[i]=float(1)/b;
		}
		
	}
	cout<<"output \n";
	for(int i=1 ; i<=a ; i++)
	{
		cout<<arr[i]<<",";
	}
	
	
	
	return 0;
}