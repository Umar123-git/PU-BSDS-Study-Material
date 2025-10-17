#include<iostream>
using namespace std;

struct Ratio
  {
       int num;
       int den;
  };

void inRatio(Ratio &r)
{
cout<<"enter the numerator ;"<<endl;
cin>>r.num;
cout<<"enter the denomintor :"<<endl;
cin>>r.den;
while(r.den==0)
   {
	cout<<"denominator cannot be 0 please enter the value again :"<<endl;
	cin>>r.den;
   }
}


void outRatio( Ratio r)
{
	cout<< r.num <<"/"<< r.den <<endl;
}

int main()
{
	Ratio r;
	cout<<"enter a ratio ;"<<endl;
	inRatio(r);
	cout<<"the ratio is :";
	outRatio(r);
	return 0;
}