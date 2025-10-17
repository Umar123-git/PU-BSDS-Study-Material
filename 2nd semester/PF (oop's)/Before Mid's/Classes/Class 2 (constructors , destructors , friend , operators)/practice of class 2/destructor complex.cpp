#include<iostream>
#include<cmath>
using namespace std;

class Complex
{
private:
	double realValue;
	double imagValue;
public:
	 Complex() : realValue(0), imagValue(0) {} // Default constructor
	
	Complex (double r , double i)
{
	realValue = r;
	imagValue = i;
}

	~Complex()
	{
		cout<<"i am dying ...\n";
	}
	
	double getRealValue() const
	{
		return realValue;
	}
	double getImagValue() const
	{
		return imagValue;
	}	
	void setRealValue(double r)
	{
		realValue=r;
	}
	void setImagValue(double i)
	{
		imagValue=i;
	}
	
friend	Complex sum(const Complex &c1, const Complex &c2);
friend  Complex conjugate(const Complex &c);
friend  Complex difference(const Complex &c1, const Complex &c2);
friend  Complex multiply(const Complex &c1, const Complex &c2);





};

void display(const Complex &c)
{
	if(c.getRealValue() == 0 && c.getImagValue() == 0)
		cout<<"0"<<endl;
	
	else if(c.getRealValue() == 0)
		cout<<c.getImagValue()<<"i"<<endl;
		
	else if(c.getImagValue() == 0)
		cout<<c.getRealValue()<<endl;
		
    if(c.getImagValue()>0)
		cout<<c.getRealValue()<<"+"<<c.getImagValue()<<"i"<<endl;          

	else if(c.getImagValue()<0)
		cout<<c.getRealValue()<<c.getImagValue()<<"i"<<endl;		
}

Complex sum(const Complex &c1, const Complex &c2)
{
	Complex c3;
	c3.setRealValue(c1.realValue+c2.realValue);
	c3.setImagValue(c1.imagValue+c2.imagValue);
	return c3;
}


Complex conjugate(const Complex &c)
{
	Complex conj = c;
	if(c.imagValue!=0)
		conj.setImagValue(c.imagValue*-1);
	return conj;
}


Complex multiply(const Complex &c1, const Complex &c2)
{
	Complex c3;
	c3.setRealValue((c1.realValue*c2.realValue) - (c1.imagValue*c2.imagValue));
	c3.setImagValue((c1.realValue*c2.imagValue) + (c1.imagValue*c2.realValue));
	return c3;
}


Complex difference(const Complex &c1, const Complex &c2)
{
	Complex c3;
	c3.setRealValue(c1.realValue-c2.realValue);
	c3.setImagValue(c1.imagValue-c2.imagValue);
	return c3;
	
}

int main()
{
	Complex w={2 , 0} , x={-4 , -2} , y={5 , -1} , z={0 , -1};

	display(w);
	
	display(x);
	
	display(y);
	
	display(z);
	
	sum(w,z);
	
/*	w.setRealValue(2);
	w.setImagValue(0);
	display(w);
	
	Complex x;
	x.setRealValue(-4);
	x.setImagValue(-2);
	display(x);
	
	Complex y;
	y.setRealValue(5);
	y.setImagValue(-1);
	display(y);
	
	Complex z;
	z.setRealValue(0);
	z.setImagValue(-1);
	display(z);
*/	
	Complex result = difference(multiply(sum(w, z), conjugate(x)), y);
	cout<<"Result = ";
	display(result);
	
	return 0;
}