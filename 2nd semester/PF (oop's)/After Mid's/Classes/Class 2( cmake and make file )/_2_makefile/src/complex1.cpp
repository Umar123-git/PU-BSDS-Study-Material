#include "complex.h"

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
