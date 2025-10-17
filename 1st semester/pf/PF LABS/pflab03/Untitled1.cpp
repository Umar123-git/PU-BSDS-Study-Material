#include <iostream>
using namespace std;
int factorial(int n)
{
	int r;
	int i = 1;
while ( i < n )
	{
	r = n+i;
	i=i+1;
	
	}
	
	
	return r;
	
}
int main()
{
	int r,n;
	cin>>n;
	r=factorial(n);
	cout<<r<<endl;
	return 0;
	
	
}