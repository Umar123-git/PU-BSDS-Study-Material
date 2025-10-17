#include<iostream>
#include<array>
#include<cmath>
using namespace std;





int main()
{
	array<float,25> arr1;
	array<float,26> arr2;
	array<float,25> arr3;
	int a,b,a1,b1,mid;
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
			float val=arr1[a1];
			arr1[a1]=arr1[a1]*arr1[a1];
			
			for(int i=1 ; i<=a ; i++)
			{
				arr2[a1+i]=arr1[a1+(i-1)];
			}
			for(int i=1 ; i<=a1 ; i++)
			{
				arr2[i]=arr1[i];
			}
			arr2[a1+1]=val;
			arr2[a+1]=arr1[a];
		}
		
		
		
	cout<<"output \n";
	for(int i=1 ; i<=a ; i++)
	{
		cout<<arr1[i]<<",";
	}
	
	cout<<"\noutput \n";
	for(int i=1 ; i<=a+1 ; i++)
	{
		cout<<arr2[i]<<",";
	}
	
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
		
			
			
		
		
		
		
		cout<<"\noutput \n";
	for(int i=1 ; i<a ; i++)
	{
		cout<<arr3[i]<<",";
	}
	
	return 0;
}