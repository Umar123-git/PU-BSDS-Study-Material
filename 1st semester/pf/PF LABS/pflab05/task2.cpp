#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int conversion(int octalno)
{
	int decimal=0;
	int base=1;
	int remainder;
	while(octalno>0)
	{
		remainder=octalno%10;
		decimal=decimal+remainder*base;
		base=base*8;
		octalno=octalno/10;
		
		
	}
	
	return decimal;
}

int main()
{
	int a,oct;
	cout<<"enter the octal no. :";
	cin>>a;
	oct=conversion(a);
	cout<<"decimal no. :"<<oct<<endl;
	return 0;
}






