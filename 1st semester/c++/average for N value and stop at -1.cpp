#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	float i=0.0,x,sum=0.0,avg;
	while(x!=-1)
	{
		cin>>x;
		if(x!=-1)
		{
			
			sum=sum+x;
			i=i+1;
			
		}
	}
	avg=sum/i;	
	cout<<"average ="<<avg;
	return 0;        
}