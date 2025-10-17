#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int a,b;
	cin>>a;
	if(a<18)
	{
		cout<<"too young to vote";
	}
	if(a>=18)
	{
		cout<<"you has ID card? :";
		cin>>b;
		if(b='yes')
		{
			cout<<"You can vote";
		}
		else
		{
			cout<<"You cannot vote without ID card";
		}
		
	}
	return 0;
}