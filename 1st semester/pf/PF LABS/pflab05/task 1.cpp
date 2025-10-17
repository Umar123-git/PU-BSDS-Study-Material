#include<iostream>
#include<string>
using namespace std;

int digit(int n)
{
	int sum=0;
    while(n>0)
{
	sum=sum+n%10;
	n=n/10;
	
}
return sum;
}

int main()
{
	int b;
	cout<<"enter the integer :";
	cin>> b;
	
	int print=digit(b);
	cout<<"sum is :"<<print<<endl;
	
	
	return 0;
}



