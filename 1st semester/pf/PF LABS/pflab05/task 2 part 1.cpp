#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main()
{
	
	int a[5] ;
	int b=0;
	int i=0;
	while(i<=5)
	{
		cin>>a[i];
		if(abs(a[i]>7000))
		{
			b++;
		}
		i++;
	}
	b=b+1;
	cout << "Number of rejected values (absolute value > 7000): " << b << endl;
	return 0;
}