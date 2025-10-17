#include<iostream>
#include<array>
using namespace std;


int main()
{
	int size , sum;

	int *p;
	for(int i=-3 ; i<3 ; i++)
	{
		cin >> *p;
		sum=sum+ *p;
	}
	
	cout<<sum;
	
	
delete [] p;

	return 0;
}