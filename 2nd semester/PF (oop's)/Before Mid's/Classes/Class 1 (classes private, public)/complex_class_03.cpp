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
		realValue = r;
	}
	void setImagValue(double i)
	{
		imagValue = i;
	}
	
	void display() const
	{
		cout << realValue << "," << imagValue;
	}
	
	Complex conjugate() const
	{
		Complex t;
		t.realValue = realValue;
		t.imagValue = -imagValue;
		return t;
	}
	
	void setComplex(double r, double i)
	{
		realValue = r;
		imagValue = i;
	}
	
	Complex add(const Complex &rhs) const
	{
		Complex res;
		
		res.setRealValue(getRealValue() + rhs.getRealValue());
		res.imagValue = imagValue + rhs.imagValue;
		
		return res;
	}
};


int main()
{
	Complex x;
	x.display();
	Complex w;
	w.display();
	cout << endl;
	w.setComplex(20,12);
	w.display();
	x.setComplex(10,2);
	x.display();
	cout << endl;
	w.conjugate().display();
	cout << endl;
	x.add(w).display();
	cout << endl;
}

