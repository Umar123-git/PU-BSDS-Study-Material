#include<iostream>
#include<array>
using namespace std;


void Task1()
{
	array<float,25> arr;
	int integer;
	cin>>integer;
	if(integer>20)
	{
		return ;
	}
	arr[0]=0;
	for(int i=1 ; i<integer ; i++)
	{
		arr[i] = 1.0/i;
	}
	cout<<endl;
	for(int i=0 ; i<integer ; i++)
	{
		cout<<arr[i]<<",";
	}
	

	int it;
	cin>>it;

	swap(arr[it],arr[integer-1]);
	cout<<endl;
	for(int i=0 ; i<integer ; i++)
	{
		cout<<arr[i]<<",";
	}
	
	cin>>it;
	float temp=arr[it];
	arr[it]=it*it;
	arr[integer]=temp;
	cout<<endl;
		for(int i=0 ; i<=integer ; i++)
	{
		cout<<arr[i]<<",";
	}
	
	
	int mid=integer/2;
	arr[mid-1]=0;
	swap(arr[mid-1],arr[integer]);
	cout<<endl;
		for(int i=0 ; i<integer ; i++)
	{
		cout<<arr[i]<<",";
	}
	
}





int main()
{
	Task1();
	
	
	
	
	
	
	return 0;
}