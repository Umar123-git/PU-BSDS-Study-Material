#include <iostream>
#include <cmath>
using namespace std;

class Complex
{
private:
	double realValue;
	double imagValue;
public:
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
		realValue =r;
	}
	void setImagValue(double i)
	{
		imagValue = i;
	}

};

void display(const Complex &c)
{
	if (c.getRealValue() == 0 && c.getImagValue() == 0)
		cout << "0" << endl;
	else if (c.getRealValue() == 0)
		cout << c.getImagValue() << "i" << endl;
	else if (c.getImagValue() == 0)
		cout << c.getRealValue() << endl;
	else
	{
		if (c.getImagValue() > 0)
			cout << c.getRealValue() << "+" << c.getImagValue() << "i" << endl;
		else if (c.getImagValue() < 0)
			cout << c.getRealValue() << c.getImagValue() << "i" << endl;
	}
}

Complex conjugate(const Complex &c)
{
	Complex conj = c;
	if (c.getImagValue() != 0)
		conj.setImagValue(c.getImagValue() * -1);

	return conj;
}

Complex sum(const Complex &c1, const Complex &c2)
{
	Complex c3;
	c3.setRealValue(c1.getRealValue() + c2.getRealValue());
	c3.setImagValue(c1.getImagValue() + c2.getImagValue());
	return c3;
}
Complex difference(const Complex &c1,const Complex &c2)
{
	Complex c3;
	c3.setRealValue(c1.getRealValue() - c2.getRealValue());
	c3.setImagValue(c1.getImagValue() - c2.getImagValue());
	return c3;
}
Complex multiply(const Complex &c1,const Complex &c2)
{
	Complex c3;
	c3.setRealValue((c1.getRealValue() * c2.getRealValue()) - ((c1.getImagValue() * c2.getImagValue())));
	c3.setImagValue((c1.getRealValue()*c2.getImagValue()) + (c1.getImagValue()*c2.getRealValue()));
	return c3;
}

int main()
{
	Complex w;
	w.setRealValue(2);
	w.setImagValue(0);
	display(w);
	cout << endl;

	Complex x;
	x.setRealValue(-4);
	x.setImagValue(-2);
	display(x);
	cout << endl;

	Complex y;
	y.setRealValue(5);
	y.setImagValue(-1);
	display(y);
	cout << endl;

	Complex z;
	z.setRealValue(0);
	z.setImagValue(-1);
	display(z);
	cout << endl;

	Complex result = difference(multiply(sum(w, z), conjugate(x)), y);
	cout << "Result = ";
	display(result);

	return 0;
}

