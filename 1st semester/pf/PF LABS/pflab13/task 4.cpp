#include<iostream>
#include<array>
#include<string>
using namespace std;

int main()
{
	int i,j;
	cout<<"enter the two real number :";
	cin>>i>>j;
	int *p1=&i;
	int *p2=&j;
	if(*p1>*p2)
	{
		cout<<"*p1 is the greater number:"<<*p1;
	}
	else
	{
		cout<<"*p2 is the greater number:"<<*p2;	
	}
	
	
	
	
	
	return 0;
}