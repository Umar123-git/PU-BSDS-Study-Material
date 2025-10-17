#include <iostream>
#include <cmath>
using namespace std;

class Complex
{
protected:
	double realValue;
	double imagValue;
public:
	double getRealValue() const;
	double getImagValue() const;
	void setRealValue(double r);
	void setImagValue(double i);
	void setComplex(double r, double i);

	Complex();
	explicit Complex(double d);
	explicit operator double();

	void display() const;
	Complex conjugate() const;

	Complex operator+(const Complex &rhs) const;
	friend Complex operator-(const Complex &lhs, const Complex &rhs);
	Complex& operator=(const Complex &rhs);
	friend ostream & operator<<(ostream & strm, const Complex &number);
};

int main()
{
	Complex w;
	w.setComplex(3,-4);
	w.display();
	cout << endl;
	
	double d = (double)w;
	cout << d << endl;
}


double Complex::getRealValue() const
{
	return realValue;
}

double Complex::getImagValue() const
{
	return imagValue;
}

void Complex::setRealValue(double r)
{
	realValue =r;
}

void Complex::setImagValue(double i)
{
	imagValue = i;
}

void Complex::setComplex(double r, double i)
{
	realValue = r;
	imagValue = i;
}

Complex::Complex()
{
	
}

Complex::Complex(double d)
{
	this->realValue = d;
	this->imagValue = 0;
}

Complex::operator double()
{
	return sqrt(this->realValue*this->realValue+this->imagValue*this->imagValue);
}

void Complex::display() const
{
	cout << "(" << realValue << ", " << imagValue << ")";
}

Complex Complex::conjugate() const
{
	Complex t;
	t.realValue = realValue;
	t.imagValue = -imagValue;
	return t;
}

Complex Complex::operator+(const Complex &rhs) const
{
	Complex res;
	
	res.realValue = realValue + rhs.realValue;
	res.imagValue = imagValue + rhs.imagValue;
	
	return res;
}

Complex operator-(const Complex &lhs, const Complex &rhs)
{
	Complex res;
	
	res.realValue = lhs.realValue - rhs.realValue;
	res.imagValue = lhs.imagValue - rhs.imagValue;
	
	return res;
}

Complex& Complex::operator=(const Complex &rhs)
{
	if(this != &rhs)
	{
		this->realValue = rhs.realValue;
		this->imagValue = rhs.imagValue;
	}
	return *this;
}

ostream & operator<<(ostream & strm, const Complex &number)
{
	 strm << number.realValue << "+" << number.imagValue << endl;
	 return strm;
}
