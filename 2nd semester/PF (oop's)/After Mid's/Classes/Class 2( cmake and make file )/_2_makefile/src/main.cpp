#include <iostream>
#include "complex.h"

using namespace std;

int main()
{
	Complex w;
	w.setComplex(3,-4);
	w.display();
	cout << endl;
	
	Complex k;
	k = w;
	k.display();
	cout << endl;
	
	
	double d;
	d = (double)w;
	cout << d << endl;
}
