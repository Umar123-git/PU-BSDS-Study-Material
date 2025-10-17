#include<iostream>
using namespace std;

int main()
{
	double a;
	double conversion;
	cout<<"enter temperature in celsius :";
	cin>>a;
	conversion=(1.8*a)+32;
	cout<<"in fahrenheit temperature is :";
	cout<<conversion<<endl;
	
	double b;
	double conversiona;
	cout<<"enter temperature in fahrenheit :";
	cin>>b;
	conversiona=(b-32)*5/9;
	cout<<"in celsius temperature is :";
	cout<<conversiona<<endl;
	return 0;
}