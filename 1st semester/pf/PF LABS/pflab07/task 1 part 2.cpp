#include<iostream>
#include <cmath>
using namespace std;

struct Ratio
{

	int num;
	int den;
};

void inRatio(Ratio &r)
{
	cout<<"enter the numerator :"<<endl;
	cin>>r.num;
	cout<<"enter the denominator ;"<<endl;
	cin>>r.den;
while(r.den==0)
   {
	cout<<"denominator cannot be 0 please enter the value again :"<<endl;
	cin>>r.den;
   }
}


void outRatio( Ratio &r)
{
	cout<< r.num <<"/"<< r.den <<endl;
}

void additiveinverse(Ratio &r)
{
	cout << -r.num <<"/"<<r.den <<endl;
}

void reciprocal(Ratio &r)
{
	cout << r.den <<"/"  << r.num <<endl;
}


void multiply(Ratio &r1, Ratio &r2)
{
	cout <<  r1.num*r2.num << "/"  << r1.den*r2.den <<endl ;
}

void addinteger(Ratio &r, int integer)
{
	cout << "enter the integer :";
	
	cout <<  r.num + integer * r.den <<"/"<< r.den << endl;
}


int gcd(int a, int b) {
    return b == 0 ? abs(a) : gcd(b, a % b);
}

Ratio simplify(Ratio r) {
    int commonDivisor = gcd(r.num, r.den);
    return { r.num / commonDivisor, r.den / commonDivisor };
}


Ratio integerToRatio(int integer) {
    return { integer, 1 };
}


float ratioToFloat(const Ratio &r) {
    return static_cast<float>(r.num) / r.den;
}

void equalratios(Ratio &r1, Ratio &r2)
{
	if(r1.num == r2.num  ||  r1.den==r2.den)
	{
		cout << " ratios are equal"<<endl;
	}
	else
	{
		cout<<"ratios are not equal"<<endl;
	}
 } 
 
 
 void firstislessthansecond(Ratio &r1, Ratio &r2)
 {
 	if(r1.num < r2.num && r2.den < r1.den )
 	{
 		cout<< "ratio 1st is lessthan 2nd ratio"<<endl;
	 }
	 else
	 cout<<"both the ratios are equal or 2nd ratio is lessthan 1st ratio"<<endl;
 }
 
 
 

 
 
 
 int main()
 {
 	Ratio r1,r2;
 	int integer;
 	cout<<"enter a ratio ;"<<endl;
	inRatio(r1);
	cout<<"the ratio is :";
	outRatio(r1);
	 cout << "Enter the second ratio:" << endl;
    inRatio(r2);
    cout << "The second ratio is: ";
    outRatio(r2);
	cout<<"additive inverse enter ratio"<<endl;
	additiveinverse(r1);
	cout<<"reciprocal enter the ratio"<<endl;
	reciprocal(r1);
	cout<<"multiply two ratios"<<endl;
	multiply(r1,r2);
	cout<<"adding integer to ratio"<<endl;
	addinteger(r1,integer);
	Ratio simplifiedR1 = simplify(r1);
    cout << "The simplified form of the first ratio is: ";
    outRatio(simplifiedR1);


    cout << "Enter an integer to convert to a ratio: ";
    cin >> integer;
    Ratio intToRatio = integerToRatio(integer);
    cout << "The ratio form of the integer is: ";
    outRatio(intToRatio);


    float floatValue = ratioToFloat(r1);
    cout << "The float value of the first ratio is: " << floatValue << endl;
    
    
    cout<<"to campare the ratios are equal"<<endl;
    equalratios(r1,r2);
    
    cout<<"to compare the ratio is lessthan second one"<<endl;
    firstislessthansecond(r1,r2);
	return 0;
 }