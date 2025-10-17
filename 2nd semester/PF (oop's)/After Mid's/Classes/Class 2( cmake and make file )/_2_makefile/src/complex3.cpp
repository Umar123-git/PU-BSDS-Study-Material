#include <iostream>
#include <cmath>
#include "complex.h"

using namespace std;

void Complex::display() const
{
	cout << realValue << "," << imagValue;
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
	
	res.realValue = realValue - rhs.realValue;
	res.imagValue = imagValue - rhs.imagValue;
	
	return res;
}

Complex operator-(const Complex &lhs, const Complex &rhs)
{
	Complex res;
	
	res.setRealValue(lhs.getRealValue() + rhs.getRealValue());
	res.setImagValue(lhs.getImagValue() + rhs.getImagValue());
	
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
	 strm << '(' << number.getRealValue() << "," << number.getImagValue() << ')';
	 return strm;
}
