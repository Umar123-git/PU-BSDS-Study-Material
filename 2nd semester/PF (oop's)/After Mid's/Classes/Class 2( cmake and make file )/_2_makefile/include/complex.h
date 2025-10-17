#ifndef pk_edu_nc_pucit_bsef19oop_lect09
#define pk_edu_nc_pucit_bsef19oop_lect09
 
#include <iostream>

using namespace std;

class Complex
{
private:
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
	Complex& operator=(const Complex &rhs);
};

// global functions examples related to Complex
Complex operator-(const Complex &lhs, const Complex &rhs);
ostream & operator<<(ostream & strm, const Complex &number);
 
#endif

