#include<iostream>
using namespace std;

int main()
{
	float a,b,avg,i=1,sum=0;
	cout<<"Enter count values :";
	cin>>a;
	while(i<=a)
	{
		cin>>b;
		sum=sum+b;
		i=i+1;
	}
	i=i-1;
	avg=sum/i;
	cout<<"average ="<<avg<<endl;
	return 0;
}