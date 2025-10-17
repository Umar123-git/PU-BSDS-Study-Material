#include<iostream>
using namespace std;



int accumulate(int arr[] , int size)
{
	int sum=0;
	for(int i=0 ; i<size ; i++)
	{
		sum=sum+arr[i];
	}

	cout<<endl<<"sum of this values is :" << sum;
	return sum;
}



int main()
{
	int arr[5];
	cout<<"the values entered are :";
	for(int i=0 ; i<5 ; i++)
	{
		arr[i]=i;
		cout<<i<<"  ";
	}
	int *p=arr;
	int size = 5;
	accumulate(p , size );

	return 0;
}