/*
In this code we learn the concept of operator overloading.
As example, we overlaod and use a few operators. Here, we 
also get the concepts of friends of the class
*/

#include <iostream>
#include <cmath>
using namespace std;

class Complex
{
protected:
	double realValue;
	double imagValue;
public:
    double getRealValue() const
    {
        return this->realValue;
    }

	double getImagValue() const
	{
		return this->imagValue;
	}

	void setRealValue(double r)
	{
		this->realValue = r;
	}
    
	void setImagValue(double i)
	{
		this->imagValue = i;
	}
	
	void display() const
	{
		cout << "(" << realValue << ", " << imagValue << ")";
	}
	
	Complex conjugate() const
	{
		Complex t;
		t.realValue = this->realValue;
		t.imagValue = -this->imagValue;
		return t;
	}
	
	void setComplex(double r, double i)
	{
		this->realValue = r;
		this->imagValue = i;
	}
	
	Complex operator+(const Complex &rhs) const
	{
		Complex res;
		
		res.realValue = this->realValue + rhs.realValue;
		res.imagValue = this->imagValue + rhs.imagValue;
		
		return res;
	}

	friend Complex operator-(const Complex &lhs, const Complex &rhs)
	{
		Complex res;
		
		res.realValue = lhs.realValue - rhs.realValue;
		res.imagValue = lhs.imagValue - rhs.imagValue;
		
		return res;
	}

	Complex& operator=(const Complex &rhs)
	{
		if(this != &rhs)
		{
			this->realValue = rhs.realValue;
			(*this).imagValue = rhs.imagValue;
		}
		return *this;
	}
	
	friend ostream & operator<<(ostream & strm, const Complex &number)
	{
		 strm << number.realValue << "," << number.imagValue << endl;
		 return strm;
	}

};

int main()
{
	Complex w;
	w.setComplex(-4,2);
	Complex x;
	x.setComplex(2,8);
	Complex y;
	y.setComplex(3,-1);
	Complex z;
	
	//z = operator+(x, y).operator-(w);

	//z = x.operator+(y).operator-(w);
	cout << x + y - w;
/*	
	w.display();
	cout << endl;
	x.display();
	cout << endl;
	y.display();
	cout << endl;
	z.display();
	cout << endl;*/
}

