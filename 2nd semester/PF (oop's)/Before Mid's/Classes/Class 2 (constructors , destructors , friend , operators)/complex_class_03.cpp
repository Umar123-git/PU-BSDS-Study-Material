/*
In this code we learn the concept of members functions.
The functions related to the Complex class are placed inside
the class, and now they are invoked using an object
rather accepting object as parameter. The object invoke or
call a member function, is available in function as caller
object (which is un-named and hidden), and directly access
its data members (also function members)
*/

#include <iostream>
#include <cmath>
using namespace std;

class Complex
{
protected: // change private to protected
	double realValue;
	double imagValue;
public:
	double getRealValue() const
	{
		return realValue;
	}

	void setRealValue(double r)
	{
		realValue = r;
	}

	double getImagValue() const
	{
		return imagValue;
	}
    
	void setImagValue(double i)
	{
		imagValue = i;
	}
	
	void setComplex(double r, double i)
	{
		setRealValue(r);
		setImagValue(i);
	}
	
	void display() const
	{
		cout << "(" << realValue << ", " << imagValue << ")";
	}
	
	Complex conjugate() const
	{
		Complex t;
		t.setRealValue(realValue);
		t.setImagValue(-imagValue);
		return t;
	}
	
	Complex add(const Complex &rhs) const
	{
		Complex res;
		
		res.realValue = realValue + rhs.realValue;
		res.imagValue = imagValue + rhs.imagValue;
		
		return res;
	}
};


int main()
{
	Complex x;
	x.display();
	cout << endl;
	Complex w;
	w.display();
	cout << endl;
    // in above code complex objects have garbage
	w.setComplex(20,12);
	w.display();
	cout << endl;
	x.setComplex(10,2);
	x.display();
	cout << endl;
	w.conjugate().display();
	cout << endl;
	x.add(w).display();
	cout << endl;
}





