#include<iostream>
#include<string>
using namespace std;

int conversion(int a)
{
	float r;
	r=(a*3.141)/180;
	return r;
	
	
	
}
int main()
{
	float a,r;
	cout<<"enter angle in degree :";
	cin>>a;
	cout<<conversion(a);
	
	
	
	return 0;
}