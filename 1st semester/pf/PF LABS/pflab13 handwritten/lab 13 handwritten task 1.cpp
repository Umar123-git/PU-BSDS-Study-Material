#include<iostream>
#include<array>
using namespace std;


int main()
{
	int size , sum=0;
	cout<<"enter the size of array :";
	cin>>size;
	int *p = new int[size];
	for(int i=0 ; i<size ; i++)
	{
		cin >> *p;
		sum=sum+ *p;
	}
	
	cout<<sum;
	
	
delete [] p;

	return 0;
}