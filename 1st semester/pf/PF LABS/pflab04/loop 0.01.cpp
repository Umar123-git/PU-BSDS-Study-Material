#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main()
{
	float r,a,c,s,f;
	float i=0;
	float pi=3.14;
	cout<<"r :";
	cin>>r;
	while(i<=r)
	{
		f=(i*3.141)/180;
		
	
		s=sin(f);
		s=s*s;
		c=cos(f);
		c=c*c;
		a=s+c;
		cout<<a<<endl;
			i=i+1;
	}
	
	
	
return 0;
}