#include<iostream>
#include<array>
using namespace std;

int main()
{
	int i=1,s=0,x;
	cin>>x;
	while(i<100)
	{
		
		i=i+1;
	}
	cout<<s<<endl;
	
	return 0;
}
int pow(x,i)
{
	int p;
	p=x^i;
	s=s+pow(x,i)/(i*i);
}