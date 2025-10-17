#include <iostream>
#include <cmath>
using namespace std;

struct Complex
{
	double realValue;
	double imagValue;
};

void display(const Complex &c)
{
	if (c.realValue == 0 && c.imagValue == 0)
		cout << "0" << endl;
	else if (c.realValue == 0)
		cout << c.imagValue << "i" << endl;
	else if (c.imagValue == 0)
		cout << c.realValue << endl;
	else
	{
		if (c.imagValue > 0)
			cout << c.realValue << "+" << c.imagValue << "i" << endl;
		else if (c.imagValue < 0)
			cout << c.realValue << c.imagValue << "i" << endl;
	}
}

Complex conjugate(const Complex &c)
{
	Complex conj = c;
	if (c.imagValue != 0)
		conj.imagValue *= -1;

	return conj;
}

Complex sum(const Complex &c1, const Complex &c2)
{
	Complex c3;
	c3.realValue = c1.realValue + c2.realValue;
	c3.imagValue = c1.imagValue + c2.imagValue;
	return c3;
}
Complex difference(const Complex &c1,const Complex &c2)
{
	Complex c3;
	c3.realValue = c1.realValue - c2.realValue;
	c3.imagValue = c1.imagValue - c2.imagValue;
	return c3;
}
Complex multiply(const Complex &c1,const Complex &c2)
{
	Complex c3;
	c3.realValue = (c1.realValue * c2.realValue) - ((c1.imagValue * c2.imagValue));
	c3.imagValue = (c1.realValue*c2.imagValue) + (c1.imagValue*c2.realValue);
	return c3;
}

int main()
{
	Complex w;
	w.realValue = 2;
	w.imagValue = 0;
	display(w);
	cout << endl;

	Complex x;
	x.realValue = -4;
	x.imagValue = -2;
	display(x);
	cout << endl;

	Complex y;
	y.realValue = 5;
	y.imagValue = -1;
	display(y);
	cout << endl;

	Complex z;
	z.realValue = 0;
	z.imagValue = -1;
	display(z);
	cout << endl;

	Complex result = difference(multiply(sum(w, z), conjugate(x)), y);
	cout << "Result = ";
	display(result);

	return 0;
}

