#include<cmath>
#include "complex.h"

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
