#include "point3d.h"
#include<cmath>
using namespace std;


	    Point :: Point()
		{
			cout<<"default constructor of Point \n";
			x=0;
			y=0;
			z=0;
		//	disply();
		}
		 Point :: Point(const Point &p)
		{
			cout<<"single parameter constructor of Point  \n";
			x=p.x;
			y=p.y;
			z=p.z;
		}
		 Point :: Point(double p, double q, double r)
		{
			cout<<"triple parameter constructor of Point  \n";
			x=p;
			y=q;
			z=r;
		}
		 Point :: ~Point()
		{
			cout<<"Distroying \n";
		}
		
		void Point ::  disply() const
		{
			cout<<"disply()  ("<<x<<","<<y<<","<<z<<")\n";
		}
		double Point ::  distance(const Point &p)
		{
			double d;
			d=sqrt(pow(p.x-x,2)+pow(p.y-y,2)+pow(p.z-z,2));
			cout<<"Distance between two points = "<<d<<endl;
			return d;
		}		
  		
  		
  		Point  Point ::  operator=(const Point &p)
  		{
  			x=p.x;
  			y=p.y;
  			z=p.z;
  			cout<<"operator=  \n";
  			return *this;
		}
  		bool Point ::  operator==(const Point &p)
  		{
  			bool b=false;
  			if(x==p.x || y==p.y || z==p.z)
  			{
  				b=true;
			}
  		
  			cout<<"operator==  "<<b<<endl;
  			return b;
		}		
  		
  		Point  Point :: operator+(const Point &p)
  		{
  			x=x+p.x;
  			y=y+p.y;
  			z=z+p.z;
  			cout<<"operator+ \n";
  			return *this;
		}
		Point Point ::  operator-(const Point &p)
		{
			x=x-p.x;
			y=y-p.y;
			z=z-p.z;
			cout<<"operator- \n";
			return *this;
		}
		
		ostream & operator<<(ostream & strm, Point & p)
		{
			cout<<"operator<<  ";
			strm<<"("<<p.x<<","<<p.y<<","<<p.z<<")\n";
			return strm;
		}