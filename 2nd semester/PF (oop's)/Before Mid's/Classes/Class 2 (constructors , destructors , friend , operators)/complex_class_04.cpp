/*
In this code we learn the concept of constructors
and destructors. Also, in between the lines the 
concept of function overloading is also discussed.
We made several overloaded constructors. 

The concept of explicit is revealed here too.
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
	
	Complex add(const Complex &rhs) const
	{
		Complex res;
		
		res.realValue = this->realValue + rhs.realValue;
		res.imagValue = this->imagValue + rhs.imagValue;
		
		return res;
	}
	
	Complex(double r, double i) // natural constructor
	{
		this->realValue = r;
		this->imagValue = i;		
	}

	Complex() // default constructor 
	{
		this->realValue = 0;
		this->imagValue = 0;		
	}

    // explicit
	Complex(double r) // type cast constructor
	{
		this->realValue = r;
		this->imagValue = 0;		
	}

	Complex(const Complex &c) // copy constructor customization
	{
		this->realValue = c.realValue;
		this->imagValue = c.imagValue;		
	}

	~Complex() // destructor
	{
		cout << "\n[dying . . . (";
		this->display();
		cout << ") . . . . died!]\n";
	}
};


int main()
{
	Complex w(99,20);
	w.display();
	cout << endl;
	w.setComplex(7,2);
	w.display();
	cout << endl;
	w.conjugate().display();
	cout << endl;
	w.add(w).display();
	cout << endl;
}

