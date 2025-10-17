//#ifndef MYHEADER_H
//#define MYHEADER_H


#include<iostream>
#include<cmath>
using namespace std;

class Point
{
	private:
		double x , y , z;	
	public:
		void setX(double _x)
		{
			x=_x;
		}
		void setY(double _y)
		{
			y=_y;
		}
		void setZ(double _z)
		{
			z=_z;
		}
		double getX() const
		{
			return x;
		}
		double getY() const
		{
			return y;
		}
		double getZ() const
		{
			return z;
		}
		
		Point()
		{
			cout<<"default constructor of Point \n";
			x=0;
			y=0;
			z=0;
		//	disply();
		}
		Point(const Point &p)
		{
			cout<<"single parameter constructor of Point  \n";
			x=p.x;
			y=p.y;
			z=p.z;
		}
		Point(double p, double q, double r)
		{
			cout<<"triple parameter constructor of Point  \n";
			x=p;
			y=q;
			z=r;
		}
		~Point()
		{
			cout<<"Distroying \n";
		}
		
		void disply() const
		{
			cout<<"disply()  ("<<x<<","<<y<<","<<z<<")\n";
		}
		double distance(const Point &p)
		{
			double d;
			d=sqrt(pow(p.x-x,2)+pow(p.y-y,2)+pow(p.z-z,2));
			cout<<"Distance between two points = "<<d<<endl;
			return d;
		}		
  		
  		
  		Point operator=(const Point &p)
  		{
  			x=p.x;
  			y=p.y;
  			z=p.z;
  			cout<<"operator=  \n";
  			return *this;
		}
  		bool operator==(const Point &p)
  		{
  			bool b=false;
  			if(x==p.x || y==p.y || z==p.z)
  			{
  				b=true;
			}
  		
  			cout<<"operator==  "<<b<<endl;
  			return b;
		}		
  		
  		Point operator+(const Point &p)
  		{
  			x=x+p.x;
  			y=y+p.y;
  			z=z+p.z;
  			cout<<"operator+ \n";
  			return *this;
		}
		Point operator-(const Point &p)
		{
			x=x-p.x;
			y=y-p.y;
			z=z-p.z;
			cout<<"operator- \n";
			return *this;
		}
		
		friend ostream & operator<<(ostream & strm, Point & p)
		{
			cout<<"operator<<  ";
			strm<<"("<<p.x<<","<<p.y<<","<<p.z<<")\n";
			return strm;
		}

};




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