#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    if(a%b==0 ||  b%a==0)
    {
    	cout<<"multiple";
	}
	else
	{
		cout<<"not";
	}
	
	return 0;
}