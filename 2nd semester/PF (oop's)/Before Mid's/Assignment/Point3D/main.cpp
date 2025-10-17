#include "point3d.h"
#include<iostream>
#include<cmath>
using namespace std;


int main()
{
	Point p1(1,2,3),p2	(4,5,6);

/*	p1.setX(1);
	p1.setY(2);
	p1.setZ(3);
	p2.setX(4);
	p2.setY(5);
	p2.setZ(6);
	p2.disply();
	*/
	p1.distance(p2);
	
	p2=p1;
	p2.disply();
	Point s=p1+p2;
	cout<<s;
	
	s=p1-p2;
	cout<<s;


	p1.disply();
	p1==p2;
//	cout<<s;
	
	return 0;
}